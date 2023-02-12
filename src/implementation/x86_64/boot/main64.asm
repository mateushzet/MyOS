global long_mode_start
global input
extern kernel_main
extern handle_input

section .text
bits 64             ; setting bits to 64
long_mode_start:
; we need to load zero into some data segment registers so that all the cpu instructions will function correctly
    mov ax, 0
    mov ss, ax
    mov es, ax
    mov ds, ax
    mov fs, ax
    mov gs, ax

    call kernel_main
    hlt

    ; Read a scancode from the keyboard
    read_scancode:
        in al, 0x60 ; Read a scancode from the keyboard controller
        mov [scancode], al
        shr al, 7
        jnz read_scancode
        ret

    ; Wait for a key to be pressed
    wait_for_keypress:
        in al, 0x60
        mov byte [oldvalue], al
        call read_scancode
        mov al, byte [scancode]
        mov bl, byte [oldvalue]
        cmp al, bl
        je wait_for_keypress
        ret

    get_char:
        call wait_for_keypress
        mov eax, [scancode]
        ret

    input:
        call get_char
        mov rdi, rax
        call handle_input
        ret

section .data
    scancode db 0
    oldvalue db 0