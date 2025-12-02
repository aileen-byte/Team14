ENTRY(_start)

SECTIONS
{
    /* Program begins at 0x00000000 */
    . = 0x00000000;

    /* Code section */
    .text : {
        *(.text .text.*)
        *(.rodata .rodata.*)
    }

    /* Initialized data */
    .data : {
        *(.data .data.*)
    }

    /* Uninitialized data (zero-filled) */
    .bss : {
        *(.bss .bss.*)
        *(COMMON)
    }

    /* Stack at top of memory (adjust size as needed) */
    . = ALIGN(4);
    _stack_top = . + 0x1000;   /* 4KB stack */
}
