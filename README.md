# MyOS
My 64-bit Operating System Kernel

Architecture: x86

Bootloader: multiboot2


Technologies used for emulating:

- Docker

- Qemu


Technologies installed in Docker container:

- nasm
- grub
- xorriso
- gcc cross compiler - "gcc-cross-x86_64-elf"


Process of emulating and launching os:
1) Building containter image with docker - "docker build buildenv -t myos-buildenv"
2) Makeing instance of previous iamge - "docker run --rm -it -v ${PWD}:/root/env myos-buildenv"
3) Inside docker container generate the kernel.iso file by command "make build-x86_64"
4) Emulate the operating system using qemu command "qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso"




