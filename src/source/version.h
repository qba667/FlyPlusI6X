#ifndef VERSION_H_
#define VERSION_H_

uint16_t __attribute__((section (".mod_version_major"))) version_major = 1;
uint16_t __attribute__((section (".mod_version_minor"))) version_minor = 0;
uint16_t __attribute__((section (".mod_version_release"))) version_release = 42;
uint16_t __attribute__((section (".mod_version_build"))) version_build = 1500;

#endif
