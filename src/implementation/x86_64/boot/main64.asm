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
    mov es, ax
    mov fs, ax
    mov gs, ax

    call kernel_main    ; callin our C function
    hlt