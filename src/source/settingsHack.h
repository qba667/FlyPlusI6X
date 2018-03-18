#ifndef SETTINGS_HACK_H_
#define SETTINGS_HACK_H_

#include <stdint.h>
#include <stddef.h>


//eprom stucture
// 0 - 639 RADIO SETTINGS 304u + 4 crc USED_MODEL_PTR
// 640 - 7039 models 320 *20
// 7040 -> 7648 - 608 other settingsHack

//8192 mod memory

#define SELECTED_MODEL_ADDR 0x20001138
#define MOD_EEPROM_START 8192
#define TOTAL_MODELS 20
typedef void (*loadSettingsFun)();
const loadSettingsFun loadSettingsOrg = (loadSettingsFun)0x08006F78+1;

typedef int32_t (*eepromFun)(uint32_t eepromAddress, void* target, uint32_t length);
const eepromFun readEEPROM = (eepromFun)0x0800F378+1;
const eepromFun writeEEPROM = (eepromFun)0x080192C4+1;

typedef int32_t (*crcFun)(uint32_t null, void* target, uint32_t length);
const crcFun crc = (eepromFun)0x08005728+1;


#define precision 15
#define FIXED(val) (val << precision)
#define DECIMAL(val) (val >> precision)
#define TMP_OFFSET 19
#define ALT_MASK 0x7FFFF;
#define R_DIV_G_MUL_10_Q15 UINT64_C(9591506)
#define INV_LOG2_E_Q1DOT31 UINT64_C(0x58b90bfc) // Inverse log base 2 of e

#define ALARM_OPERATOR_LT 0
#define ALARM_OPERATOR_GT 0

#define BATTERY_DEFAULT 0
#define	BATERY_LIPO_1S	1
#define	BATERY_LIPO_2S	2
#define BATERY_NICD_4S	3

#define SENSORS_ARRAY_LENGTH 11
#define VARIO_MAX_GAIN_BITS	4	// do not need the whole byte


typedef struct mixConfStruct{
	int8_t min;
	int8_t subtrim;
	int8_t max;
} mixConfStruct;

typedef struct sensorAlarm
{
	uint8_t sensorID;
	uint8_t operator;
	uint16_t value;
} sensorAlarm;

typedef struct modelConfStruct
{
	uint8_t ch11_12;											//	1
	uint8_t ch13_14;											//	1
	uint16_t timerAlarm;										//	2
	uint8_t timerCH;											//	1
	uint16_t timerStart;										//	2
	sensorAlarm alarm[3];										//	3*4 = 12
	uint32_t initAlt;											// 	4
	uint8_t varioSensorID;										// 1
	uint8_t varioGain : VARIO_MAX_GAIN_BITS;					// 1
	uint8_t reserved_bits : (8 - VARIO_MAX_GAIN_BITS);			// 1
	mixConfStruct mix[4];										// 8*3 = 24
	uint16_t intVoltAdj;
	uint16_t extVoltAdj;
    uint8_t varioDeadBand;
    uint8_t reserved[3];										// 8
    int32_t crc;
} modelConfStruct;


typedef struct configStruct
{
    uint16_t batteryVoltage;
	uint8_t swConfig;
	uint16_t versionMagic;
	modelConfStruct modelConfig[TOTAL_MODELS];
    int32_t crc;
} configStruct;

configStruct modModelConfig;

void loadSettingsHook();

#endif
