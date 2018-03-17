.syntax unified
.arch armv6-m
.cpu cortex-m0
.section .mod_applySwitchesHook2, "a"
.align 1
.globl __mod_applySwitchesHook2

BL applaySwitchesHook
