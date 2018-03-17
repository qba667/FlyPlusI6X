.syntax unified
.arch armv6-m
.section .firstSection, "a"
.align 2
.globl __firstSection
__firstSection:
.long   __StackTop  /* Top of Stack */
.long   Reset_Handler  
.thumb_func
.align 2
.globl   Reset_Handler
.weak    Reset_Handler
.type    Reset_Handler, %function
Reset_Handler:
ldr   r0,=main
blx   r0