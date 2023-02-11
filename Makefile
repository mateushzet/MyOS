# comands for building operating system

# find all .asm files in x86_64 dir
x86_64_asm_source_files := $(shell find src/implementation/x86_64 -name *.asm)

# compileing .asm files into object files
x86_64_asm_object_files := $(patsubst src/implementation/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

# define what commands we need to run to build one of our object files from the source files
$(x86_64_asm_object_files): build/x86_64/%.o : src/implementation/x86_64/%.asm

# making sure that a directory to holding our compiled file exists
	mkdir -p $(dir $@) && \
# using nasm to compile our assembly code
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/implementation/x86_64/%.asm, $@) -o $@

# phony command which will link our object files into kernel.bin and generate iso file
.PHONY: build-x86_64
build-x86_64: $(x86_64_asm_object_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(x86_64_asm_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso