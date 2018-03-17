#include <stdint.h>
#include <stddef.h>
/*
#define ADC_VAL 0x20000F00
#define ADC_READING 0x20000F24
#define RX_BUFFER 0x20000EE4
#define RX_BUFFER_LENGTH 28
#define TX_BUFFER 0x1FFFFDBA
#define TX_BUFFER_LENGTH 38
#define MODEL_SETTINGS 0x200002A4
#define ADC_VAR_A 0x20000F10
#define ADC_SW_C 0x20000F1C
#define ADC_SW_B 0x20000F20
#define ADC_CH1 0x20000F00
#define ADC_CH2 0x20000F04
#define ADC_CH3 0x20000F08
#define ADC_CH4 0x20000F0C
#define SENSOR_ARRAY 0x200001A4
#define CHANNEL_VALUE 0x1FFFFDE0 // signed int -10k ... +10k
#define CHANNEL_VALUE_RADIO 0x1FFFFD54
#define PPM_IN_BUFFER 0x1FFFFCC0 //6 * 32bit signed
#define PPM_IN_BUFFER_CH6 0x1FFFFCD4
#define GFX_ARRAY 0x1FFFF8C0
#define INPUT_STATES 0x1FFFF89C  //uint bits
#define TEMP_INPUT_STATES 0x1FFFF898 //uint bits
#define USED_MODEL_PTR 0x2000002C //PTR to current model
#define CURRENT_MODEL_INDEX 0x200002AD
#define ARROW_GFX_INFO 0xCBF8
#define SW_B_C 0xf63e

#define AUX_CH_TEXT 0xcc5a
#define SOURCE_STRING 0xCAEE
#define MEM_20000000 0x20000000
#define TIMER_SYS_TIM 0x1FFFF8B0 //SYS_TIM
#define LAST_ALARM_TIMER 0x2000003C
#define TELEMETRY_UPDATE_TIMER 0x2000001C

#define GFX_ARROW 0xCBF8
#define TEXT_VALUE 0xCAE1
#define TEXT_CHANNEL 0x9650
#define TEXT_OFF	0xCA87
#define TEXT_TIMMER	0xDCB7
#define TEXT_END_POINTS 0xCCE0
#define TEXT_HOLD 0xCAB3
#define TEXT_MIX 0xCA93
#define TEXT_ADJ 0xDBA1
#define FORMAT_TEMP 0x5530

#define KEY_SHORT_UP 9
#define KEY_SHORT_DOWN  8

#define KEY_SHORT_OK 10
#define KEY_SHORT_CANCEL 11

#define KEY_LONG_UP 23
#define KEY_LONG_DOWN 24

#define KEY_LONG_OK 22
#define KEY_LONG_CANCEL 25

#define ALARM_GT 1
#define ALARM_LT 0


typedef struct gfxInfo
{
   int width;
   int height;
   int address;
} gfxInfo;

typedef struct manuEntry{
	const char* namePtr;
	void* thumbAddress;
} manuEntry;


typedef void* (*memcpyFun)(void *dest, const void *source, size_t n);
typedef void* (*memcpyFun2)(void *source, void *target, uint32_t n);
typedef int (*sprintfFun)(char* buffer, const char* format, ...);
typedef void (*voidFun)(void);
typedef size_t (*strLenFun)(const char * str);
typedef char* (*strcatFun)(char * str, const char* source);
typedef void * (*memSetFun)(void *str, int c, size_t n);
typedef uint32_t (*divFun)(uint32_t a, uint32_t b);
typedef int32_t (*divSignedFun)(int32_t a, int32_t b);
typedef uint32_t (*divBy10Fun)(uint32_t a);
typedef int (*intVoidFun)(void);
typedef int (*eepromFun)(uint8_t * target, int16_t eepromOffset, int length);
typedef int (*gfxFun)(gfxInfo* gfx, int x, int y);
typedef int (*drawFun)(int x1, int y1, int x2, int y2, int value);
typedef int (*pixelFun)(int x1, int y1, int value);
typedef int (*displayText)(char* text, int x, int y, int val);
typedef int (*displayHeader)(char* text);
typedef uint16_t (*sensorValue)(uint8_t sensorID, uint8_t index, int zero);
typedef void (*setSenValue)(char* packet);
typedef void (*formatSensData)(uint8_t sensorID, uint8_t sensorIndex, char* packet);
typedef void (*navPage)(const char* pageName, int numberofitems, manuEntry* menuStruct);
typedef void (*beepFun)(int freq, int duration);
typedef void (*crcFun)(char* data, int length);
typedef void (*formatNumFun)(int number, char* buffer, int digits);
typedef void (*memSetFun2)(void* targetAddress, unsigned int count, uint8_t valueToSet);


__attribute__((section (".mod_MOD_SPACE.LOADSETTINGS"))) const voidFun loadSettingsFromEeprom = (voidFun)0x6005;
__attribute__((section (".mod_MOD_SPACE.CONFIGPINS"))) const voidFun configurePINs = (voidFun)0x2C01;
__attribute__((section (".mod_MOD_SPACE.NAVPAGE"))) const navPage showNavPage = (navPage)0x6DD5;
__attribute__((section (".mod_MOD_SPACE.SETTINGSVALID"))) const voidFun settingsValidation = (voidFun)0x6005;
__attribute__((section (".mod_MOD_SPACE.SPIMETHOD"))) const voidFun someSPImethod = (voidFun)0xA339;
__attribute__((section (".mod_MOD_SPACE.MEMCPY"))) const memcpyFun strcpy_ = (memcpyFun)0x198D;
__attribute__((section (".mod_MOD_SPACE.MEMCPY2"))) const memcpyFun2 memcpy_ = (memcpyFun2)0x1CF5;
__attribute__((section (".mod_MOD_SPACE.RESET"))) const voidFun restartUnit = (voidFun)0x9929;


__attribute__((section (".mod_MOD_SPACE.SPRINTF"))) const sprintfFun sprintfCall = (sprintfFun)0x19F9;
__attribute__((section (".mod_MOD_SPACE.STRCAT"))) const strcatFun strcatCall = (strcatFun)0x1C65;
__attribute__((section (".mod_MOD_SPACE.MEM_SET"))) const memSetFun2 memsetCall = (memSetFun2)0x1E0D;
__attribute__((section (".mod_MOD_SPACE.STRLEN"))) const strLenFun strLenCall = (strLenFun)0x1CB1;
//__attribute__((section (".mod_MOD_SPACE.MEMSET"))) const memSetFun memsetCall = (memSetFun)0x3201;
__attribute__((section (".mod_MOD_SPACE.SEND"))) const voidFun sendPacketWithSysTick = (voidFun)0x9EFD;
__attribute__((section (".mod_MOD_SPACE.SEND"))) const voidFun saveModelSettingsCall = (voidFun)0xABA9;
__attribute__((section (".mod_MOD_SPACE.DIVBY10")))const divBy10Fun divBy10 = (divBy10Fun)0x2165;
__attribute__((section (".mod_MOD_SPACE.DIVMOD"))) const divFun uidivmod = (divFun)0x1E5F;
__attribute__((section (".mod_MOD_SPACE.DIV"))) const divFun div_ = (divFun)0x1E7B;
__attribute__((section (".mod_MOD_SPACE.DIV2"))) const divSignedFun div_1 = (divSignedFun)0xA179;


__attribute__((section (".mod_MOD_SPACE.GETKEY"))) const intVoidFun getKeyCode = (intVoidFun)0x2535;
__attribute__((section (".mod_MOD_SPACE.GETINPUT"))) const intVoidFun getInputStates = (intVoidFun)0x3569;
__attribute__((section (".mod_MOD_SPACE.DMASEND"))) const voidFun callSetupDMAandSend = (voidFun)0x25B5;
__attribute__((section (".mod_MOD_SPACE.EEPROMTREAD"))) const eepromFun readEeprom = (eepromFun)0x3E11;
__attribute__((section (".mod_MOD_SPACE.EEPROMWRITE"))) const eepromFun saveEeprom = (eepromFun)0x3E85;
__attribute__((section (".mod_MOD_SPACE.displayGFX"))) const gfxFun displayGFX = (gfxFun)0x4BA1;
__attribute__((section (".mod_MOD_SPACE.fillRegion"))) const drawFun fillRegion = (drawFun)0x4C71;
__attribute__((section (".mod_MOD_SPACE.drawLine"))) const drawFun drawLine = (drawFun)0x4E8D;
__attribute__((section (".mod_MOD_SPACE.drawRect"))) const drawFun drawRect = (drawFun)0x5019;
__attribute__((section (".mod_MOD_SPACE.setPixel"))) const pixelFun setPixel = (pixelFun)0x4FD9;
__attribute__((section (".mod_MOD_SPACE.displayTextAt"))) const displayText displayTextAt = (displayText)0x505D;
//__attribute__((section (".mod_MOD_SPACE.displaySmallTextAt"))) const displayText displaySmallTextAt = (displayText)0x5175;
__attribute__((section (".mod_MOD_SPACE.displayPageHeader"))) const displayHeader displayPageHeader = (displayHeader)0x6D5D;
__attribute__((section (".mod_MOD_SPACE.getSensorValue"))) const sensorValue getSensorValue = (sensorValue)0x5375;
__attribute__((section (".mod_MOD_SPACE.setSensorValue"))) const setSenValue setSensorValue = (setSenValue)0x57D5;
__attribute__((section (".mod_MOD_SPACE.formatSensorData"))) const formatSensData formatSensorData = (formatSensData)0x53CD;
__attribute__((section (".mod_MOD_SPACE.updateLCD"))) const voidFun LCD_updateCALL = (voidFun)0x25BD;

__attribute__((section (".mod_MOD_SPACE.CheckAlarms"))) const voidFun CheckAlarmsCall = (voidFun)0x61ED;

__attribute__((section (".mod_MOD_SPACE.sPrintNumer"))) const formatNumFun sprintfNumer = (formatNumFun)0xA2E4;

__attribute__((section (".mod_MOD_SPACE.showNavigationPage"))) const navPage showNavigationPage = (navPage)0x6DD5;
__attribute__((section (".mod_MOD_SPACE.beep"))) const beepFun beep = (beepFun)0x9C3D;
__attribute__((section (".mod_MOD_SPACE.beepCheck"))) const intVoidFun beepCheck = (intVoidFun)0x9BC1;
__attribute__((section (".mod_MOD_SPACE.checkCRC"))) const crcFun checkCRC = (crcFun)0xA021;
__attribute__((section (".mod_MOD_SPACE.getCurrentTicks"))) const intVoidFun getCurrentTicks = (intVoidFun)0xA1B1;
__attribute__((section (".mod_MOD_SPACE.someBeepCheck"))) const intVoidFun someBeepCheck = (intVoidFun)0x9BC1;
*/

/*
__aeabi_uidiv 	  ROM 080000F0 0000002C 0000000C FFFFFFF4 R . L . . . .
__aeabi_uidiv_0   ROM 080040F0 0000002C 0000000C FFFFFFF4 R . L . . . .
__aeabi_idiv      ROM 0800411C 00000028 00000010 FFFFFFF0 R . L . . . .
__aeabi_uldivmod  ROM 08004144 00000060 00000030 FFFFFFE8 R . L . . . .
__aeabi_ldivmod   ROM 080041A4 0000004C 00000018 FFFFFFE8 R . L . . . .
__aeabi_lmul      ROM 080041F0 0000007A 00000040 FFFFFFE8 R . L . . . .
__aeabi_memcpy    ROM 0800426A 00000024                   R . L . . . .
__aeabi_memset    ROM 0800428E 0000000E                   R . L . . . .
__aeabi_memclr    ROM 0800429C 00000004                   R . L . . . .
_memset$wrapper   ROM 080042A0 00000012 00000008 FFFFFFF8 R . L . . . .
strcat            ROM 080042B2 00000018                   R . L . . . .
strlen            ROM 080042CA 0000000E                   R . L . . . .
strcmp            ROM 080042D8 0000001C 00000008 FFFFFFF8 R . L . . . .
strcpy            ROM 080042F4 00000012                   R . L . . . .
sscanf            ROM 08004308 00000032 00000048 00000000 R . L . . . .
_scanf_string     ROM 08004344 000000E8 00000030 00000004 R . L . . . .
__aeabi_fadd      ROM 0800442C 000000A2 00000018 FFFFFFE8 R . L . . . .
__aeabi_fsub      ROM 080044CE 00000008                   R . L . . . .
__aeabi_frsub     ROM 080044D6 00000008                   R . L . . . .
__ARM_scalbnf     ROM 080044DE 00000018                   R . L . . . .
__aeabi_fmul      ROM 08004508 0000007A 00000010 FFFFFFF0 R . L . . . .
__aeabi_fdiv      ROM 08004582 0000007C 00000010 FFFFFFF0 R . L . . . .
__aeabi_dadd      ROM 08004600 00000148 00000030 FFFFFFE8 R . L . . . .
__aeabi_dsub      ROM 08004748 0000000C 00000008 FFFFFFF8 R . L . . . .
__aeabi_drsub     ROM 08004754 0000000C 00000008 FFFFFFF8 R . L . . . .
__aeabi_dmul      ROM 08004764 000000CA 00000048 00000015 R . L . . . .
__aeabi_ddiv      ROM 08004834 000000EA 00000028 FFFFFFE8 R . L . . . .
__aeabi_i2f       ROM 08004924 00000016 00000008 FFFFFFF8 R . L . . . .
__aeabi_ui2f      ROM 0800493A 0000000E 00000008 FFFFFFF8 R . L . . . .
__aeabi_i2d       ROM 08004948 00000022 00000010 FFFFFFFC R . L . . . .
__aeabi_ui2d      ROM 08004970 00000018 00000010 FFFFFFFC R . L . . . .
__aeabi_f2iz      ROM 0800498C 00000032                   R . L . . . .
__aeabi_f2uiz     ROM 080049BE 00000028                   R . L . . . .
__aeabi_f2lz      ROM 080049E6 00000040 00000008 FFFFFFF8 R . L . . . .
__aeabi_d2iz      ROM 08004A28 0000003E 00000010 FFFFFFF0 R . L . . . .
__aeabi_d2uiz     ROM 08004A70 00000032 00000008 FFFFFFF8 R . L . . . .
__aeabi_d2lz      ROM 08004AAC 00000048 00000010 FFFFFFF0 R . L . . . .
__aeabi_f2d       ROM 08004AFC 00000028                   R . L . . . .
__aeabi_d2f       ROM 08004B24 00000038 00000008 FFFFFFF8 R . L . . . .
__aeabi_llsl      ROM 08004B5C 00000020 00000008 FFFFFFF8 R . L . . . .
__aeabi_llsr      ROM 08004B7C 00000022 00000008 FFFFFFF8 R . L . . . .
__aeabi_lasr      ROM 08004B9E 00000026 00000008 FFFFFFF8 R . L . . . .
_scanf_char_input ROM 08004BC4 0000000C                   R . L S . . .
__vfscanf_char    ROM 08004BD0 00000018 00000008 FFFFFFF8 R . L . . . .
_sgetc            ROM 08004BF0 00000020                   R . L . . . .
_sbackspace       ROM 08004C10 00000024                   R . L . . . .
_float_round      ROM 08004C34 00000010                   R . L . . . .
_float_epilogue   ROM 08004C44 00000072 0000000C FFFFFFF4 R . L . . . .
_double_round     ROM 08004CB6 0000001A 00000008 FFFFFFF8 R . L . . . .
_double_epilogue  ROM 08004CD0 000000A4 00000030 0000000C R . L . . . .
__aeabi_d2ulz     ROM 08004D74 00000036 00000008 FFFFFFF8 R . L . . . .
__aeabi_cdrcmple  ROM 08004DB4 00000026 00000008 FFFFFFF8 R . L . . . .
isspace           ROM 08004E00 0000000E 00000008 FFFFFFF8 R . L . . . .
__vfscanf         ROM 08004E10 0000032C 00000050 FFFFFFE8 R . L . . . .
__ctype_lookup    ROM 08005148 00000020                   R . L . . . .
__decompress      ROM 0800516C 00000056 00000010 FFFFFFF0 R . L . . . .
clearLCDbuffer          ROM 08005D24 0000000E 00000008 FFFFFFF8 R . . . . . .
displayGFX              ROM 08005D38 000000B0 00000030 FFFFFFE8 R . . . . . .
setPixels               ROM 08005DEC 0000006A 00000000 00000004 R . . . . . .
copyDisplayBuffer       ROM 08005E5C 00000022 00000010 FFFFFFF0 R . . . . . .
lcdMethod               ROM 08005E88 00000348 00000028 00000004 R . . . . . .
setPixel                ROM 080061DC 00000030 00000008 FFFFFFF8 R . . . . . .
displayRect             ROM 08006210 00000044 00000028 00000004 R . . . . . .
displayString           ROM 08006254 000000E0 00000030 FFFFFFEC R . . . . . .
displayText             ROM 0800633C 0000001E 00000018 FFFFFFE8 R . . . . . .
printSmall              ROM 0800635C 000000BA 00000030 FFFFFFE8 R . . . . . .
printCenter             ROM 08006420 0000001E 00000018 FFFFFFE8 R . . . . . .
GetSensorName2          ROM 080065FC 00000080                   R . . . . . .
getSensorName           ROM 08006510 00000080 00000000 00000000 R . . . . . .
getSensorValue          ROM 080064C4 00000044 00000010 FFFFFFF0 R . . . . T .
getSensorByIndexInArray ROM 08006768 00000034                   R . . . . . .
getSensorValue_2byte    ROM 080067A4 00000038 0000000C FFFFFFF4 R . . . . T .
formatSensorValue       ROM 080067E4 0000024A 00000028 FFFFFFEC R . . . . T .
clearSensors            ROM 08006CC0 00000032 00000008 FFFFFFF8 R . . . . . .
updateSensors           ROM 08006D04 00000114 00000020 FFFFFFEC R . . . . . .
updateSensorHelper      ROM 08006E44 00000068 00000010 FFFFFFF0 R . . . . . .
callMemcpy              ROM 08006EB0 00000028                   R . . . . . .
displayGFX2             ROM 08007164 00000074 00000018 FFFFFFEC R . . . . . .
displayHeader           ROM 080071D8 00000076 00000018 FFFFFFEC R . . . . . .
countLeadingZeros       ROM 0800A0DC 0000002E                   R . L . . . .
__0sprintf              ROM 0800A0B4 00000024 00000018 00000000 R . L . . . .
getSwitchChannel        ROM 0800B2EC 00000106 00000020 FFFFFFEC R . . . . . .
free                    ROM 0800BE6C 00000050 00000008 FFFFFFF8 R . L . . . .
getTxVoltage            ROM 0800E574 0000003E 00000010 FFFFFFF0 R . . . . . .
getADCIndex             ROM 0800E9B4 00000038 00000008 FFFFFFF8 R . . . . T .
*/
