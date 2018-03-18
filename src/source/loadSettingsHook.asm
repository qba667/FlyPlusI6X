.syntax unified
.arch armv6-m
.cpu cortex-m0
.section .mod_loadSettingsHook, "a"
.align 1
.globl __mod_loadSettingsHook

BL loadSettingsHook
