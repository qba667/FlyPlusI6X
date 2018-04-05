#ifndef ALARM_H_
#define ALARM_H_
#include <stdint.h>
#include <stddef.h>
#include "flysky.h"
#include "channelsHack.h"
#define SNR_ALARM 10
void checkCustomAlarms();
uint32_t  __attribute__((section (".mod_alarmMethodPtr"))) alarmMethodPtr = (uint32_t)(&checkCustomAlarms+1);

#endif
