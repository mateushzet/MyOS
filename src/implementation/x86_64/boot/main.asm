global start
extern long_mode_start

section .text ; code section
bits 32
start:
     mov esp, stack_top ; store the address of the top of the stack in stack pointer register (there are currently no frames on the stack)

    ; switching kernel into 64-bit mode before linking to c code

    call check_multiboot  ; confirm that we have been loaded by a multi-boot 2 loader
    call check_cpuid ; check cpu id instuction that provides various cpu information
    call check_long_mode  ; use cpu id to check for long mode support

    ; we need paging to enter 64-bit mode
    call setup_page_tables
    call enable_paging

    ; load the global descriptor table
    lgdt [gdt64.pointer]    ; loading its pointer

    ; loading code segment into the code selector to finish everything off
    jmp gdt64.code_segment:long_mode_start  ; specyfing code segment offset, cpu will jump to 64bit asm code

    hlt ; halt the cpu

check_multiboot:
    cmp eax, 0x36d76289  ; check if bootloader store magic number in eax register
    jne .no_multiboot   ; if not euqal jump to no_multiboot label
    ret                 ; else return into subrutine
.no_multiboot:          ;  handling no multi-boot problem
    mov al, "M"         ; puting error message into al register
    jmp error           ; displaying error

check_cpuid:
    ; try to flip the id bit of the flags register and if we can flip it then cpu id is available
    pushfd  ; pushing the flags register onto the stack
    pop eax ; poping the stack into eax register
    mov ecx, eax    ; copy eax register into ecx for final comparison
    xor eax, 1 << 21    ; using xor to flip the id bit on the eax register
    push eax    ; copying this back to the flags register by pushing into the stack
    popfd       ; and poping it into flags register
    pushfd      ; pushing flags register into the stack
    pop eax     ; poping it into eax regsiter
    push ecx    ; pushing our first copy of flags register
    popfd       ; and poping it into flags register
    cmp eax, ecx    ; if the id bit remains flipped and the cpu didn't reverse it then we know that the cpu supports it
    je .no_cpuid    ; if values stay the same cpu dont supprot the cpu id
    ret

.no_cpuid:  ;  handling no cpu id problem
    mov al, "C"
    jmp error

check_long_mode:
    ; check if cpu id supports extended processor info

    mov eax, 0x80000000 ; argument stored for cpu id instruction
    cpuid   ; in eax regsiter cpuid will store back a number grater than argument if the cpu supports extended processor info
    cmp eax, 0x80000001 ; checking that
    jb .no_long_mode    ; if the eax is lesser, cpu do not supports extended processor info

    ; using extended processor info to chceck if it supports long mode
    mov eax, 0x80000001
    cpuid   ; cpu id will store a value into the edx register, and if the lm bit is set then long mode is available
    test edx, 1 << 29   ; test if the lm bit is set
    jz .no_long_mode    ; if it is not set, cpu do not supports long mode

    ret
.no_long_mode:   ;  handling no long mode problem
    mov al, "L"
    jmp error

; identity maping, physical address are map to the exact same virtual address
; becouse paging will be activated automatically as soon as we enable long mode
; then the cpu will read the following instructions to execute and the address of this instruction
; will be based on a physical address it already has from before paging was enabled
; since the cpu will now treat this as a virtual address we will map a chunk of these virtual addresses
; to the same physical addresses so our instructions will continue executing fluidly
setup_page_tables:
    mov eax, page_table_L3  ; getting address of page 3 table
    ; becouse of align 4096, first 12 bits of every entry is always going to be zero
    ; and the cpu uses these bits to store flags instead
    or eax, 0b11 ; enabling present and writable flags
    mov [page_table_L4], eax    ; moving that address with setted flags into first entry of L4 table

    mov eax, page_table_L2
    or eax, 0b11
    mov [page_table_L3], eax

; we dont need to create Level 1 table becouse of enableing the huge page flag on any entry in the level 2 table
; and this allow us to point directly to physical memmory and allocate a huge page that is two megabytes in size
; the spare nine bits in the virtual address will be used on top of the remaining bits as an offset
; into this huge page rather than as an index into a level 1 table
    mov ecx, 0 ;counter
.loop:  ; filling up all 512 entries of the level 2 table, each entry is 2 megabytes each that will be total 1gigabyte

    mov eax, 0x20000000 ; storing number of 2MiB
    mul ecx ; multiplying value in eax by our counter to get address for our next page
    or eax, 0b10000011  ; enabling present, writable and huge page flags
    mov [page_table_L2 + ecx * 8], eax ; puting entry in the L2 table with the offset

    inc ecx ; increment counter
    cmp ecx, 512 ; checks if the whole table is mapped
    jne .loop ; if not, continue

    ret

enable_paging:
    ; pass page table location to cpu (to cr3 register)
    mov eax, page_table_L4
    mov cr3, eax

    ; enable physical address extension that is necessary for 64-bit paging by enableing PAE flag
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ; enable long mode
    mov ecx, 0xC0000080 ; argument for rdmsr
    rdmsr               ; read model specific register instruction that loads efer register into eax register
    or eax, 1 << 8      ; enabling long mode flag
    wrmsr               ; write back modified efer register

    ; enable paging by setting paging flag from cr0 register
    mov eax, cr0
    or eax, 1 << 31
    mov cr0, eax

    ret

error:
    ; print error code
    mov dword [0xb8000], 0x4f524f45
    mov dword [0xb8004], 0x4f3a4f52
    mov dword [0xb8008], 0x4f204f20
    mov byte  [0xb800a], al
    hlt

; reserve bytes section
section .bss
align 4096          ; align all the tables to four kilobytes
; paging tables
page_table_L4:
    resb 4096
page_table_L3:
    resb 4096
page_table_L2:
    resb 4096
stack_bottom:
    resb 4096 * 4   ; reserving 512 bytes for our stack
stack_top:

; read only data section
section .rodata
gdt64:   ; 64 bit global descriptor table
    dq 0 ; zero entry
.code_segment: equ $ - gdt64 ;offset
    dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53) ; executable flag, descriptor type, present flag, 64-bit flag
; pointer to the global descriptor table
.pointer:
    ; it holds 2 bytes of the length of the table
    ; difference between current memory addresswhich is the end of the table ($) minus the start of the table (gdt64)
    dw $ - gdt64 - 1
    dq gdt64    ; store pointer itself once again using the label