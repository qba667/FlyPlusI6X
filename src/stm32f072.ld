MEMORY
{
 ram (rwx) : ORIGIN = 0x20002990, LENGTH = 0x1670
 rom (rx) : ORIGIN = 0x801bc10, LENGTH = 0x43f0
 rom_org (RX) : ORIGIN = 0x08000000, LENGTH = 114785
}
/*0x801cc10 2990  rom (rx) : ORIGIN = 0x801cc10, LENGTH = 16286*/

SECTIONS
{

	.firstSection :
	{
		. = ALIGN(1);
		KEEP(*(.firstSection))     /* Top of Stack */
		. = ALIGN(1);
	} > rom_org

    .remove 0x08004000 : {
        *(.remove);
        *(.remove*)
        KEEP(*(.remove))
    }

    . = ALIGN(1);
    .mod_channelsArrayRef1 0x08008BEC: {
        *(.mod_channelsArrayRef1);
    }
    .mod_channelsArrayRef2 0x0800B95C: {
        *(.mod_channelsArrayRef2);
    }
    .mod_channelsArrayRef3 0x0800C4AC: {
        *(.mod_channelsArrayRef3);
    }
    .mod_channelsArrayRef4 0x0801450C: {
        *(.mod_channelsArrayRef4);
    }
    .mod_channelsArrayRef5 0x08015E94: {
        *(.mod_channelsArrayRef5);
    }
    .mod_channelsArrayRef6 0x08016A74: {
        *(.mod_channelsArrayRef6);
    }
    .mod_channelsArray2Ref1 0x0800B958: {
        *(.mod_channelsArray2Ref1);
    }
    .mod_channelsArray2BytesToCopy 0x0800B93C: {
        *(.mod_channelsArray2BytesToCopy);
    }
    .mod_maxChannels 0x0800E4CA: {
        *(.mod_maxChannels);
    }
    . = ALIGN(2);

    .mod_applySwitchesHook1 0x08008A7E : {
        *(.mod_applySwitchesHook1);
        KEEP(*(.mod_applySwitchesHook1))
    }
    .mod_applySwitchesHook2 0x0800AB92 : {
        *(.mod_applySwitchesHook2);
        KEEP(*(.mod_applySwitchesHook2))
    }
    .mod_applySwitchesHook3 0x0800ACA2 : {
        *(.mod_applySwitchesHook3);
        KEEP(*(.mod_applySwitchesHook3))
    }

    .text : {
        . = ALIGN(4);
        *(.text)           /* .text sections (code) */
        *(.text*)          /* .text* sections (code) */
		 KEEP(*(.text))
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
	    __START_BSS = .;
		__bss_start__ = .;
		*(.bss*)	/* Read-write zero initialized data */
		*(COMMON)
		__bss_end__ = .;
		__END_BSS = .;
    } >ram

	 __StackTop = 0x20003990;
}
