#ifndef VERSION_H_
#define VERSION_H_

uint32_t __attribute__((section (".mod_stack_addr"))) stack_addr = 0x20003990;
uint16_t __attribute__((section (".mod_version_major"))) version_major = 1;
uint16_t __attribute__((section (".mod_version_minor"))) version_minor = 0;
uint16_t __attribute__((section (".mod_version_release"))) version_release = 42;
uint16_t __attribute__((section (".mod_version_build"))) version_build = 1560;

#endif
