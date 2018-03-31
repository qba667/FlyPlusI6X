.syntax unified
.arch armv6-m
.cpu cortex-m0
.section .mod_check4BytesSensor, "a"
.align 1
.globl __mod_check4BytesSensor
BL              is4BytesSensor
CMP             R0, #1
