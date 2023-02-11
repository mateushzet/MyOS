# MyOS
My 64-bit Operating System Kernel

1) Building image with docker - "docker build buildenv -t myos-buildenv"
2) Makeing containter instance of previous iamge - "docker run --rm -it -v ${PWD}:/root/env myos-buildenv"
3) Inside docker container generate the kernel.iso file by command "MAKE BUILD-X86_64"
4) Emulate the operating system using qemu command "qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso"
