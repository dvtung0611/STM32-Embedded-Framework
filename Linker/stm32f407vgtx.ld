ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 1024K
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        _stext = .;

        KEEP(*(.isr_vector))

        *(.text)
        *(.text*)

        *(.rodata)
        *(.rodata*)
        
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;

        *(.data)
        *(.data*)

        . = ALIGN(4);
        _edata = .;
    } > SRAM AT > FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;

        *(.bss)
        *(.bss*)

        *(COMMON)

        . = ALIGN(4);
        _ebss = .;
    } > SRAM
}