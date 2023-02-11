/* linker and grub configurations */
ENTRY(start)

SECTIONS
{
    . = 1M;

    .boot :
    {
    KEEP(*(.multiboot_header))
    }

    .text :
    {
        *(.text)
    }
}

