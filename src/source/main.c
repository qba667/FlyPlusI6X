#include <stdlib.h>
#include "i6x.h"
#include "channelsHack.h"
#include "sensors.h"
#include "alarms.h"
#include "version.h"
 __attribute__((section (".remove_main"))) __attribute__((used)) int main(void) {
     for(uint32_t index = 0; index < TOTAL_CHANNELS; index++){
        reallocatedChannelsData[index] = 1500;
        reallocatedChannelsData2[index] = 1500;
     }
     if(channelsArrayRef1==0){channelsArrayRef1++;}
     if(channelsArrayRef2==0){channelsArrayRef2++;}
     if(channelsArrayRef3==0){channelsArrayRef3++;}
     if(channelsArrayRef4==0){channelsArrayRef4++;}
     if(channelsArrayRef5==0){channelsArrayRef5++;}
     if(channelsArrayRef6==0){channelsArrayRef6++;}

     if(channelsArray2Ref1==0){channelsArray2Ref1++;}
     if(channelsArray2BytesToCopy==0){channelsArray2BytesToCopy++;}
     //char* target, uint32_t sensorID, uint32_t value4Bytes, uint32_t value2Bytes
     uint32_t test[5];
    formatSensorValue(test, 1, 0);
    checkCustomAlarms();
    if(getSensorName(1) == 0){};
    if(version_major==0){version_major++;}
    if(version_minor==0){version_minor++;}
    if(version_release==0){version_release++;}
    if(version_build==0){version_build++;}
    if(stack_addr==0){stack_addr++;}
    if(alarmMethodPtr==0){alarmMethodPtr++;}

}
