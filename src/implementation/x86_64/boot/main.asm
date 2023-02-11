global start

section .text
bits 32
start:
     mov esp, stack_top ; store the address of the top of the stack in stack pointer register (there are currently no frames on the stack)

    ; switching kernel into 64-bit mode before linking to c code

    call check_multiboot  ; confirm that we have been loaded by a multi-boot 2 loader
    call check_cpuid ; check cpu id instuction that provides various cpu information
    call check_long_mode  ; use cpu id to check for long mode support


    mov dword[0xb8000], 0x2f4b2f4f  ; writing into video memory cpu will display this on the screen
    hlt ; halt the cpu

check_multiboot:
    cmp eax, 0x36d76289  ; check if bootloader store magic number in eax register
    jne .no_multiboot   ; if not euqal jump to no_multiboot label
    ret                 ; else return into subrutine
.no_multiboot           ;  handling no multi-boot problem
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
.no_long_mode   ;  handling no long mode problem
    mov al, "L"
    jmp error

error:
    ; print error code
    mov dword [0xb8000], 0x4f524f45
    mov dword [0xb8004], 0x4f3a4f52
    mov dword [0xb8008], 0x4f204f20
    mov byte  [0xb800a], al
    hlt

section .bss
stack_bottom:
    resb 4096 * 4
stack_top: