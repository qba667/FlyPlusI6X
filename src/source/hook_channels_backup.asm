syntax unified
.arch armv6-m
.cpu cortex-m0
.section .mod_setChannelValue, "a"
.align 1
.globl __mod_setChannelValue
MOVS            R0, #0
__mod_setChannelValue:
LDR             R3, [R5,#44]
CMP             R3, R0
BLS             setDefaultValue
LSLS            R2, R0, #1
LDRH            R6, [R7,R2]
ADDS            R2, R2, R4
MOVS			R1, #1
STRH            R6, [R2,R1]
B               increment
setDefaultValue:
MOVS			R6, R0
MOVS 			R1, R4
NOP
NOP
MOVS			R0, R6
increment:
ADDS            R0, R0, #1
CMP             R0, #0xE
BLT             __mod_setChannelValue
