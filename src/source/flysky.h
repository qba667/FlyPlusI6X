#ifndef FLYSKY_H_
#define FLYSKY_H_
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


#define IS_AFHDS2a 0x20001284
#define IS_AFHDS2a 0x20001284
#define VOLTAGE_ALARM_FLAG 0x200003D8
#define VOLTAGE_ALARM_COUNT 0x200003D9
#define BEEP_TASK_ID 0x200003D0

typedef void (*checkAlarms_fun)();
const checkAlarms_fun checkAlarms = (checkAlarms_fun)0x08018E00+1;
typedef bool (*isTelemetryActive_fun)();
const isTelemetryActive_fun isTelemetryActive = (isTelemetryActive_fun)0x0800F2B0+1;


typedef void (*triggerInitMethod_2_fun)(uint32_t taskID, uint32_t* params, uint32_t paramsCount);
const triggerInitMethod_2_fun triggerInitMethod_2 = (triggerInitMethod_2_fun)0x08018F24+1;



typedef int (*__aeabi_uidiv_fun)(unsigned int num, unsigned int den);
typedef int (*__aeabi_idiv_fun)(signed int num, signed int den);
typedef long long (*__aeabi_uldivmod_fun)(uint64_t numerator, uint64_t denominator);
typedef long long (*__aeabi_ldivmod_fun)(int64_t numerator, int64_t denominator);
//missing __aeabi_uidivmod(unsigned numerator, unsigned denominator)
typedef long long (*__aeabi_lmul_fun)(int64_t numerator, int64_t denominator);
typedef void (*__aeabi_memcpy_fun)(void *r0, const void *r1, size_t r2);
typedef void (*__aeabi_memset_fun)(void *r0, size_t r1, int r2);
typedef void (*__aeabi_memclr_fun)(void *r0, size_t r1);
typedef char *(*strcat_fun)(char* strTo, const char* strFrom);
typedef int (*strlen_fun)(char *str);
typedef int (*strcmp_fun)(const char * str1, const char * str2 );
typedef char * (*strcpy_fun)(char * destination, const char * source);
typedef float (*float_fun)(float a, float b);
typedef double (*double_fun)(double a, double b);

typedef float (*i2f_fun)(signed int num);
typedef float (*ui2f_fun)(unsigned int num);
typedef double (*i2d_fun)(signed int num);
typedef double (*ui2d_fun)(unsigned int num);

typedef signed int (*f2i_fun)(float num);
typedef unsigned int (*f2ui_fun)(float num);
typedef long long (*f2l_fun)(float num);
typedef unsigned long long (*f2ul_fun)(float num);

typedef signed int (*d2i_fun)(double num);
typedef unsigned int (*d2ui_fun)(double num);
typedef long long (*d2l_fun)(double num);
typedef unsigned long long (*d2ul_fun)(double num);


typedef float (*d2f_fun)(double num);
typedef double (*f2d_fun)(float num);


typedef long long (*__aeabi_llsl_fun)(unsigned long long val, unsigned int shift);
typedef long long (*__aeabi_llsr_fun)(unsigned long long val, unsigned int shift);


typedef int (*sprintf_fun)(char* buffer, const char* format, ...);


const __aeabi_uidiv_fun __aeabi_uidiv = (__aeabi_uidiv_fun)0x080040F1;
const __aeabi_idiv_fun __aeabi_idiv = (__aeabi_idiv_fun)0x0800411D;
const __aeabi_uldivmod_fun __aeabi_uldivmod = (__aeabi_uldivmod_fun)0x08004145;
const __aeabi_ldivmod_fun __aeabi_ldivmod = (__aeabi_ldivmod_fun)0x080041A5;
const __aeabi_lmul_fun __aeabi_lmul = (__aeabi_lmul_fun)0x080041F1;
const __aeabi_memcpy_fun __aeabi_memcpy = (__aeabi_memcpy_fun)0x0800426B;
const __aeabi_memset_fun __aeabi_memset = (__aeabi_memset_fun)0x0800428F;
const __aeabi_memclr_fun __aeabi_memclr = (__aeabi_memclr_fun)0x0800429D;
const strcat_fun strcat_ = (strcat_fun)0x080042B3;
const strlen_fun strlen_ = (strlen_fun)0x080042CD;
const strcmp_fun strcmp_ = (strcmp_fun)0x080042D9;
const strcpy_fun strcpy_ = (strcpy_fun)0x080042F5;

const float_fun __aeabi_fadd = (float_fun)0x0800442D;
const float_fun __aeabi_fsub = (float_fun)0x080044CF;
const float_fun __aeabi_frsub = (float_fun)0x080044D7;
const float_fun __aeabi_fmul = (float_fun)0x08004509;
const float_fun __aeabi_fdiv = (float_fun)0x08004583;

const double_fun __aeabi_dadd = (double_fun)0x08004601;
const double_fun __aeabi_dsub = (double_fun)0x08004749;
const double_fun __aeabi_drsub = (double_fun)0x08004755;
const double_fun __aeabi_dmul = (double_fun)0x08004765;
const double_fun __aeabi_ddiv = (double_fun)0x08004835;

const i2f_fun __aeabi_i2f = (i2f_fun)0x08004925;
const ui2f_fun __aeabi_ui2f  = (ui2f_fun)0x0800493B;
const ui2d_fun __aeabi_ui2d = (ui2d_fun)0x08004971;
const f2i_fun __aeabi_f2iz = (f2i_fun)0x0800498CD;
const f2ui_fun __aeabi_f2uiz = (f2ui_fun)0x080049BF;
const f2l_fun __aeabi_f2lz = (f2l_fun)0x080049E7;
const d2i_fun  __aeabi_d2iz = (d2i_fun)0x08004A29;
const d2ui_fun  __aeabi_d2uiz = (d2ui_fun)0x08004A71;
const d2l_fun __aeabi_d2lz = (d2l_fun)0x08004AAD;

const f2d_fun __aeabi_f2d = (f2d_fun)0x08004AFD;
const d2f_fun __aeabi_d2f = (d2f_fun)0x08004B25;


const __aeabi_llsl_fun __aeabi_llsl = (__aeabi_llsl_fun)0x08004B5D;
const __aeabi_llsr_fun __aeabi_llsr = (__aeabi_llsr_fun)0x08004B7D;
//__aeabi_lasr      ROM 08004B9E 00000026 00000008 FFFFFFF8 R . L . . . .


typedef struct gfxInfo
{
   int width;
   int height;
   int address;
} gfxInfo;
typedef struct beepInfo
{
   uint16_t duration;
   uint16_t freq;
} beepInfo;

typedef void (*void_fun)(void);
typedef int (*gfx_fun)(gfxInfo* gfx, int x, int y);
typedef int (*fillRect_fun) (int x1, int y1, int x2, int y2, bool clear);
typedef int (*displayText_fun)(char* text, int x, int y, bool clear);
typedef int (*displayTextSmall_fun)(char* text, int x, int y);
typedef int (*crc_fun)(unsigned int alwaysNull, uint8_t *buffer, unsigned int length);
typedef int (*display_header_fun)(char *str);
typedef int (*beep_fun) (uint16_t freq, uint16_t time);
typedef int (*read_EEPROM_fun)(uint32_t startOffset, uint8_t *target, uint32_t ength);
typedef void (*spiSend_fun)(char *buf, int count);

const void_fun clearLCD = (void_fun)0x08005D25;
const gfx_fun displayGFX = (gfx_fun)0x08005D39;
const fillRect_fun fillRect = (fillRect_fun)0x08005DED;
const fillRect_fun drawLine	= (fillRect_fun)0x08005E89;
const fillRect_fun drawRect	= (fillRect_fun)0x08006211;

const displayText_fun displayText = (displayText_fun)0x08006255;
const displayText_fun displayTextCenter = (displayText_fun)0x0800633D;
const displayTextSmall_fun displayTextSmall = (displayTextSmall_fun)0x0800635D;
const void_fun updateLCD = (void_fun)0x08006441;
const crc_fun crc = (crc_fun)0x08005729;
const display_header_fun displayHeader = (display_header_fun)0x080071D9;

const void_fun voltageAlarmCritical = (void_fun)0x08007271;
const void_fun voltageAlarmWarn = (void_fun)0x080072E1;
const void_fun beepKey = (void_fun)0x08007299;
const void_fun beepKey2 = (void_fun)0x08007309;
const beep_fun beep = (beep_fun) 0x08008C19;
const sprintf_fun sprintf_ = (sprintf_fun)0x0800A0B5;
const read_EEPROM_fun readEEPROM = (read_EEPROM_fun)0x0800F379;
const read_EEPROM_fun writeEEPROM = (read_EEPROM_fun)0x080192C5;

const spiSend_fun spiSend = (spiSend_fun)0x08008D75;


uint32_t udivMod(uint32_t val, uint32_t divisor, uint32_t* mod){
	uint32_t result = __aeabi_uidiv(val, divisor);
	__asm("mov %[output], r1" : [output] "=r" (*mod));
	return result;
}
int32_t divMod(int32_t val, int32_t divisor, uint32_t* mod){
	int32_t result = __aeabi_uidiv(val, divisor);
	__asm("mov %[output], r1" : [output] "=r" (*mod));
	return result;
}



/*
int *__fastcall getSensorValue(int *result, int id, int index)
getSensorValue	.data	080064C4	00000044	00000010	FFFFFFF0	R	.	.	.	.	T	.

const char *__fastcall GetSensorName(signed int a1)
GetSensorName	.data	08006510	00000080			R	.	.	.	.	.	.

const char *__fastcall getSensorName2(signed int a1)
getSensorName2	.data	080065FC	00000080			R	.	.	.	.	.	.

getSensorValueByIndex	.data	08006768	00000034			R	.	.	.	.	.	.
int *__fastcall getSensorValueByIndex(int *result, unsigned int a2)

signed int __fastcall getSensorByIdIndex(int a1, int a2, unsigned int *a3)
getSensorByIdIndex	.data	080067A4	00000038	0000000C	FFFFFFF4	R	.	.	.	.	.	.

int __fastcall FormatSensorValue(signed int sensorID, int sensorIndex, _BYTE *bufferPtr)
FormatSensorValue	.data	080067E4	0000024A	00000028	FFFFFFEC	R	.	.	.	.	T	.
*/

/*
0801483A
SUB SP, SP, #76     93B0
080149A8
ADD R6, SP, #32     08AE

0801485C
ADD R0, SP, #64     10A8

08014862
LDR R0, [SP,#64]    1098

08014864
LDR R5, [SP,#68]    119D

080149C6
ADD R0, SP, #64     10A8

080149CC
LDR R0, [SP,#64]    1098

080149DE
STR R0, [SP,#64]    1090

080149E4
LDR R0, [SP,#64]    1098

080149F8
LDR R0, [SP,#64]    1098

08014A2E
ADD SP, SP, #76     13B0

08014A58
ADD R0, SP, #64     10A8

08014A5E
LDR R0, [SP,#64]    1098

08014A68
STR R0, [SP,#64]    1090

08014A8E
LDR R0, [SP,#64]    1098

08014AD0
ADD SP, SP, #76     13B0


*/


#endif
