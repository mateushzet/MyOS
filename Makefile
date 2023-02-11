# comands for building operating system

# find all .c files in kernel dir
kernel_source_files := $(shell find src/implementation/kernel -name *.c)

# compileing .c files into object files
kernel_object_files := $(patsubst src/implementation/kernel/%.c, build/kernel/%.o, $(kernel_source_files))

# find all .c files in x86_64 dir
x86_64_c_source_files := $(shell find src/implementation/x86_64 -name *.c)

# compileing .c files into object files
x86_64_c_object_files := $(patsubst src/implementation/x86_64/%.c, build/x86_64/%.o, $(x86_64_c_source_files))

# find all .asm files in x86_64 dir
x86_64_asm_source_files := $(shell find src/implementation/x86_64 -name *.asm)

# compileing .asm files into object files
x86_64_asm_object_files := $(patsubst src/implementation/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

# variable to hold all x86_64 object files
x86_64_object_files := $(x86_64_c_object_files) $(x86_64_asm_object_files)

# define what commands we need to run to build one of our object files from the source files
$(x86_64_asm_object_files): build/x86_64/%.o : src/implementation/x86_64/%.asm

# making sure that a directory to holding our compiled file exists
# using nasm to compile our assembly code
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/implementation/x86_64/%.asm, $@) -o $@

# define how to build c object files
$(x86_64_c_object_files): build/x86_64/%.o : src/implementation/x86_64/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/interface -ffreestanding $(patsubst build/x86_64/%.o, src/implementation/x86_64/%.c, $@) -o $@

# define how to build kernel object files
$(kernel_object_files): build/kernel/%.o : src/implementation/kernel/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/interface -ffreestanding $(patsubst build/kernel/%.o, src/implementation/kernel/%.c, $@) -o $@


# phony command which will link our object files into kernel.bin and generate iso file
.PHONY: build-x86_64
build-x86_64: $(kernel_object_files) $(x86_64_object_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(kernel_object_files) $(x86_64_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso