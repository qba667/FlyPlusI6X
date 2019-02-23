MEMORY
{
 ram (rwx) : ORIGIN = 0x20002760, LENGTH = 0xE30
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
    .mod_stack_addr 0x08004000: {
        *(.mod_stack_addr);
    }
    .remove 0x08004004 : {
        *(.remove);
        *(.remove*)
        KEEP(*(.remove))
    }

    . = ALIGN(1);
    .mod_version_major 0x08004506: {
        *(.mod_version_major);
    }
    .mod_version_minor 0x08004504: {
        *(.mod_version_minor);
    }
    .mod_version_release 0x08004502: {
        *(.mod_version_release);
    }
    .mod_version_build 0x08004500: {
        *(.mod_version_build);
    }



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

    .mod_alarmMethodPtr 0x0800B468 : {
        *(.mod_alarmMethodPtr);
    }



    .mod_getSensorName 0x08006510 : {
        *(.mod_getSensorName);
        KEEP(*(.mod_getSensorName))
    }

    .mod_getSensorName2 0x080065FC : {
        *(.mod_getSensorName2);
        KEEP(*(.mod_getSensorName2))
    }

    .mod_formatSensor 0x080068B4 : {
        *(.mod_formatSensor);
        KEEP(*(.mod_formatSensor))
    }

    .mod_check4BytesSensor 0x080067EE : {
        *(.mod_check4BytesSensor);
        KEEP(*(.mod_check4BytesSensor))
    }

    .mod_ignoreChannelCount 0x08008B3C : {
        *(.mod_ignoreChannelCount);
        KEEP(*(.mod_ignoreChannelCount))
    }
    .mod_ignoreChannelCount2 0x08008BC0 : {
        *(.mod_ignoreChannelCount2);
        KEEP(*(.mod_ignoreChannelCount2))
    }
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
    .mod_display6chperPage 0x0801691A : {
        *(.mod_display6chperPage);
        KEEP(*(.mod_display6chperPage))
    }

    .mod_loadSettingsHook 0x0800B548 : {
        *(.mod_loadSettingsHook);
        KEEP(*(.mod_loadSettingsHook))
    }
    
    .mod_channelsBugfixHook 0x08008416: {
        *(.mod_channelsBugfixHook);
        KEEP(*(.mod_channelsBugfixHook))
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
