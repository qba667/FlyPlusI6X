MEMORY
{
 ram (rwx) : ORIGIN = 0x20002990, LENGTH = 5744
 rom (rx) : ORIGIN = 0x801bc10, LENGTH = 16286
 rom_org (RX) : ORIGIN = 0x08000000, LENGTH = 114785
}

SECTIONS
{
    .firmware :
    {
     __VECTOR_TABLE = .;
     . = ALIGN(4);
     KEEP(*(.oldCode))
    . = ALIGN(4);
    } > rom_org
    .text : {
        . = ALIGN(4);
        *(.text)           /* .text sections (code) */
        *(.text*)          /* .text* sections (code) */
    } >rom
	.rodata :
    {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
    } >rom
	.data : {
        _data_start = .;
		*(.data*)	   /* Read-write initialized data */
        . = _data_start;   /* Ensure there is no data section, since initialization won't happen */
	} >ram
	.bss : {
		*(.bss*)	/* Read-write zero initialized data */
		*(COMMON)
    } >ram
}

