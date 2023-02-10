global start

section .text
bits 32
start:
    ; writing into video memory cpu will display this on the screen
    mov dword[0xb8000], 0x2f4b2f4
    hlt