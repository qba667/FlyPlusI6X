.syntax unified
.arch armv6-m
.cpu cortex-m0
.section .mod_formatSensor, "a"
.align 1
.globl __mod_formatSensor
MOVS            R2, R3
MOVS            R1, R4
MOV             R0, SP
BL              formatSensorValue
