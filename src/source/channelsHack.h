#ifndef SOURCE_CHANNELS_HACK_H_
#define SOURCE_CHANNELS_HACK_H_

#include <stdint.h>
#include <stddef.h>
#include "ibus_telemetry.h"
#define TOTAL_CHANNELS 14
#define MODEL_MAX_CHANNELS 0x2000119C

typedef void (*applaySwitchesHookFun)(int32_t * targetArray);
const applaySwitchesHookFun applaySwitches = (applaySwitchesHookFun)0x0800B2EC+1;
typedef int32_t * (*getSensorFun)(int32_t * result, int id, int index);
const getSensorFun getSensor = (getSensorFun)0x080064C4+1;

//channelsFrame
uint16_t reallocatedChannelsData[TOTAL_CHANNELS];

uint16_t reallocatedChannelsData2[TOTAL_CHANNELS];

uint32_t __attribute__((section (".mod_channelsArrayRef1"))) channelsArrayRef1 = (uint32_t)&reallocatedChannelsData;
uint32_t __attribute__((section (".mod_channelsArrayRef2"))) channelsArrayRef2 = (uint32_t)&reallocatedChannelsData;
uint32_t __attribute__((section (".mod_channelsArrayRef3"))) channelsArrayRef3 = (uint32_t)&reallocatedChannelsData;
uint32_t __attribute__((section (".mod_channelsArrayRef4"))) channelsArrayRef4 = (uint32_t)&reallocatedChannelsData;
uint32_t __attribute__((section (".mod_channelsArrayRef5"))) channelsArrayRef5 = (uint32_t)&reallocatedChannelsData;
uint32_t __attribute__((section (".mod_channelsArrayRef6"))) channelsArrayRef6 = (uint32_t)&reallocatedChannelsData;
uint32_t __attribute__((section (".mod_channelsArray2Ref1"))) channelsArray2Ref1 = (uint32_t)&reallocatedChannelsData2;

uint8_t __attribute__((section (".mod_channelsArray2BytesToCopy"))) channelsArray2BytesToCopy = TOTAL_CHANNELS * sizeof(uint16_t);
//uint8_t __attribute__((section (".mod_maxChannels"))) maxChannels = 12 - 6;


 __attribute__((section (".remove_channelsHack"))) void keepChannelHackReferences();
uint8_t getSensor2(int32_t id, int32_t* result);
int mapSNR();
void applaySwitchesHook(int32_t targetArray[]);

/*
int mapSNR();
int mapError();

*/


#endif
