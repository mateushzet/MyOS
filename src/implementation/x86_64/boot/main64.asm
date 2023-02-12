global long_mode_start
extern kernel_main

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
    call writeing_loop

    hlt

    ; Read a scancode from the keyboard
    read_scancode:
        in al, 0x60 ; Read a scancode from the keyboard controller
        mov [scancode], al
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

    writeing_loop:
        call get_char
        mov dword[0xb8000], eax
        jmp writeing_loop

section .data
    scancode db 0
    oldvalue db 0