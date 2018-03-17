.syntax unified
.arch armv6-m

.section .remove_resetHandler, "a"
.align 2
.globl __isr_vector
__remove_resetHandler:
.long   Reset_Handler  

.thumb
.thumb_func
.align 2
.globl   Reset_Handler
.weak    Reset_Handler
.type    Reset_Handler, %function
Reset_Handler:
ldr   r0,=main
blx   r0