.syntax unified
.arch armv6-m
.cpu cortex-m0
.section .mod_applySwitchesHook3, "a"
.align 1
.globl __mod_applySwitchesHook3

BL applaySwitchesHook
