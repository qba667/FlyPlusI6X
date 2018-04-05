
#include "alarms.h"

unsigned alarmCheckCount;
void snrAlarm(){
    uint32_t tones[2];
    tones[0] = 250 << 16 | 440;
    tones[1] = 250 << 16 | 350;
    triggerInitMethod_2((*(int32_t *)BEEP_TASK_ID), tones, 2);
}

void checkCustomAlarms(){
    int8_t voltAlarmFlag = (*(int8_t *)VOLTAGE_ALARM_FLAG);
    //int8_t voltAlarmCount = (*(int8_t *)VOLTAGE_ALARM_COUNT);
    checkAlarms();
    if(!(*(int8_t *)IS_AFHDS2a)) return;
    if(!isTelemetryActive()) return;
    if(voltAlarmFlag != 1) return;

    //every 1s
    int32_t value;
    if(!getSensor2(IBUS_MEAS_TYPE_SNR, &value)) return;
    value = value & 0xFFFF;
    if(value <= SNR_ALARM){
        snrAlarm();
    }
}
