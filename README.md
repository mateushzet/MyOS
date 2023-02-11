# MyOS
<h1>My 64-bit Operating System Kernel</h1>

Architecture: x86

Bootloader: multiboot2


<h2>Technologies used for creating environment and emulating os:</h2>

- Docker

- Qemu


<h2>Technologies installed in Docker container:</h2>

- <b>grub</b> (booting and loading os kernel and the bootloader)
- <b>xorriso</b> (creating and managing ISO image files)
- <b>nasm</b> (building asm object files)
- <b>gcc cross compiler</b> - "gcc-cross-x86_64-elf" (building c object files)


<h1>Process of emulating and launching os</h1>

1) Building containter image with docker - "docker build buildenv -t myos-buildenv"
  
  
2) Makeing instance of previous iamge - "docker run --rm -it -v ${PWD}:/root/env myos-buildenv"


4) Inside docker container generate the kernel.iso file by command "make build-x86_64"


6) Emulate the operating system using qemu command "qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso"




