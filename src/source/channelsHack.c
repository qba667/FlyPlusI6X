#include "channelsHack.h"
#define MAX_SNR 40
#define MIN_SNR 9

 void keepChannelHackReferences(){
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
     if(maxChannels==0){maxChannels++;}
 }

/*
 int mapSNR(){
 	int snr = getSensorValue(IBUS_MEAS_TYPE_SNR);
 	if(snr == 0x8000 || snr <= MIN_SNR) return -10000;
 	if(snr >= MAX_SNR) return 10000;
 	snr -=9;
 	snr = (snr * 645) - 10000;
 	return snr;
 }
 int mapError(){
    int error = getSensorValue(IBUS_MEAS_TYPE_ERR);
    if(error == 0x8000) return -10000;
    return ((100 - error) * 200) - 10000;
 }


void applaySwitchesHook(int32_t targetArray[]){
    applaySwitches(targetArray);
    //uint32_t maxChannels = *((int32_t *)MODEL_MAX_CHANNELS);
    //if(maxChannels >= 11)
    //targetArray[10] = 1000;
    //targetArray[11] = 2000;
}
*/

uint8_t getSensor2(int32_t id, int32_t* result){

    int index = 0;
    do {
        sensorInfo_s *ptr = (sensorInfo_s *)(SENSORS_ARRAY + 12 *index);
        if(ptr->id == id){
            *result = ptr->value;
            return 1;
        }
        index++;
    } while(index < 32);
    return 0;
}

int mapSNR(){
    int32_t value;
 	if(!getSensor2(IBUS_MEAS_TYPE_SNR, &value))  return -10000;
    uint16_t snr = value & 0xFFFF;
 	if(snr >= MAX_SNR) return 10000;
 	snr -=9;
 	snr = (snr * 645) - 10000;
 	return snr;
}

void applaySwitchesHook(int32_t targetArray[]){
    applaySwitches(targetArray);
    uint32_t maxChannels = *((int32_t *)MODEL_MAX_CHANNELS);
    if(maxChannels >= 11) targetArray[10] = mapSNR();
}
