#include <stdint.h>
#include <stddef.h>


typedef struct switchInfoStruct
{
	uint8_t indexADC;
	uint8_t index;
	uint8_t unknown1;
	uint8_t unknown2;
	uint32_t states; //use 0 for multiple
	uint32_t namePtr;
} switchInfoStruct;


#define TEXT_INPUT_NAME_PTR 0x0801B5AC

#define TEXT_VAR_A_PTR TEXT_INPUT_NAME_PTR
#define TEXT_SW_A_PTR TEXT_INPUT_NAME_PTR + 4
#define TEXT_VAR_B_PTR TEXT_INPUT_NAME_PTR + 8
#define TEXT_SW_B_PTR TEXT_INPUT_NAME_PTR + 12
#define TEXT_SW_C_PTR TEXT_INPUT_NAME_PTR + 16
#define TEXT_SW_D_PTR TEXT_INPUT_NAME_PTR + 20
#define TEXT_NONE_PTR TEXT_INPUT_NAME_PTR + 24

// const uint8_t TEXT_SNR [] = "SNR";
// const uint8_t TEXT_ERR [] = "ERR";
// const uint8_t TEXT_SW_A_B [] = "SwA+B";
// const uint8_t TEXT_SW_C_D [] = "SwC+D";
// const uint8_t TEXT_PPM_1 [] = "PPM 1";
// const uint8_t TEXT_PPM_2 [] = "PPM 2";
// const uint8_t TEXT_PPM_3 [] = "PPM 3";
// const uint8_t TEXT_PPM_4 [] = "PPM 4";
// const uint8_t TEXT_PPM_5 [] = "PPM 5";
// const uint8_t TEXT_PPM_6 [] = "PPM 6";
// const uint8_t TEXT_PPM_7 [] = "PPM 7";
// const uint8_t TEXT_PPM_8 [] = "PPM 8";

// const switchInfoStruct switchInfo[]= {
	// { .indexADC = 12, 	.index = 6, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = TEXT_NONE_PTR },
	// { .indexADC = 6, 	.index = 4, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = TEXT_VAR_A_PTR },
	// { .indexADC = 7, 	.index = 5, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = TEXT_VAR_B_PTR },
	// { .indexADC = 4, 	.index = 0, 	.unknown1 = 0, .unknown2 = 0, .states = 3, .namePtr = TEXT_SW_A_PTR },
	// { .indexADC = 5, 	.index = 1, 	.unknown1 = 0, .unknown2 = 0, .states = 3, .namePtr = TEXT_SW_B_PTR },
	// { .indexADC = 8, 	.index = 2, 	.unknown1 = 0, .unknown2 = 0, .states = 3, .namePtr = TEXT_SW_C_PTR },
	// { .indexADC = 9, 	.index = 3, 	.unknown1 = 0, .unknown2 = 0, .states = 3, .namePtr = TEXT_SW_D_PTR },
	// { .indexADC = 13, 	.index = 7, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_SNR },
	// { .indexADC = 14, 	.index = 8, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_ERR },
	// { .indexADC = 15, 	.index = 9, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_SW_A_B },
	// { .indexADC = 16, 	.index = 10, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_SW_C_D },
	// { .indexADC = 17, 	.index = 11, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_1 },
	// { .indexADC = 18, 	.index = 12, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_2 },
	// { .indexADC = 19, 	.index = 13, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_3 },
	// { .indexADC = 20, 	.index = 14, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_4 },
	// { .indexADC = 21, 	.index = 15, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_5 },
	// { .indexADC = 22, 	.index = 16, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_6 },
	// { .indexADC = 23, 	.index = 17, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_5 },
	// { .indexADC = 24, 	.index = 18, 	.unknown1 = 0, .unknown2 = 0, .states = 0, .namePtr = (uint32_t)&TEXT_PPM_6 },
// };

// const uint32_t __attribute__((section (".mod_switchInfoAddress"))) switchInfoAddress = (uint32_t)switchInfo;

// const uint32_t __attribute__((section (".mod_auxChListAddress1"))) auxChListAddress1 = 0x20002990;
// const uint32_t __attribute__((section (".mod_auxChListAddress2"))) auxChListAddress2 = 0x20002990;


 // __attribute__((section (".mod_startupWarn"))) uint32_t  startupWarn(int a1, int a2, int a3, int a4){
	 // return 1 ;
 // };

  // __attribute__((section (".mod_isSwitchEnabled"))) uint32_t isSwitchEnabled(int id, int* ptr){
	 // *ptr = 0;
	 // return 1;
 // };
 /*
 void hook_create_frame(uint32_t channelIndex, uint32_t frame) {
	((uint16_t*)(frame +1))[channelIndex] = 1000 + channelIndex*100;
	return channelIndex;
 }*/

 /*
typedef int (*getSensorValueFun)(int* result, int id, int index);
const getSensorValueFun getSensorValue = (getSensorValueFun)0x080064C5;


#define MAX_SNR 40
#define MIN_SNR 9
#define IBUS_MEAS_TYPE_SNR	0xfa // SNR

uint16_t mapSNR(){
	int snr = 0;
	getSensorValue(&snr, IBUS_MEAS_TYPE_SNR,0);
	if(snr == 0x8000 || snr <= MIN_SNR) return 1000;
	if(snr >= MAX_SNR) return 2000;
	snr -=9;
	snr = (snr * 32) + 1000;
	return snr;
}

 uint32_t hook_create_frame(uint32_t channelIndex, uint32_t frame) {
	uint16_t value = 1500;
	if(channelIndex ==13) {
		value = mapSNR();
	}
	uint32_t address = frame + channelIndex *2 + 1;

	((uint8_t*)address)[0] = value & 0xF;
	((uint8_t*)address)[1] = value >> 8;
	// ((uint16_t*)(frame +1))[channelIndex] = 1000 + channelIndex*100;
	return channelIndex;
 }
 */
