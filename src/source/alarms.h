#ifndef ALARM_H_
#define ALARM_H_
#include <stdint.h>
#include <stddef.h>

typedef void (*checkAlarms_fun)();
const checkAlarms_fun checkAlarms = (checkAlarms_fun)0x08018E00+1;

void checkCustomAlarms();

uint32_t  __attribute__((section (".mod_alarmMethodPtr"))) alarmMethodPtr = (uint32_t)(&checkCustomAlarms+1);

#endif
