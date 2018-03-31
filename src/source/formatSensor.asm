.syntax unified
.arch armv6-m
.cpu cortex-m0
.section .mod_formatSensor, "a"
.align 1
.globl __mod_formatSensor
LDR             R0, [SP,#0x10]
LDR             R2, [SP,#0x4]
MOV             R3, R4
BL              formatSensorValue
