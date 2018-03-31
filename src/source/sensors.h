#ifndef SENSORS_H_
#define SENSORS_H_


#include <stdint.h>
#include <stddef.h>
#include "ibus_telemetry.h"
#include "flysky.h"


typedef void (*formatSensValFun)(int32_t sensorID, int32_t sensorIndex, char* bufferPtr);
const formatSensValFun formatSensValOrg = (formatSensValFun)0x080067E4+1;
uint32_t is4BytesSensor(uint32_t sensorID);
int formatSensorValue(char* target, uint32_t index, uint32_t value4Bytes, uint32_t value2Bytes);
__attribute__((section (".mod_getSensorName"))) const char * getSensorName(uint32_t sensor);
__attribute__((section (".mod_getSensorName2"))) const char * getSensorName2(uint32_t sensor);

#define PRESSURE_OFFSET UINT32_C(136)
#define ODO1_OFFSET	UINT32_C(144)
#define COG_OFFSET	UINT32_C(167)
#define ALT_OFFSET	UINT32_C(216)

#define STD_SENSOR 0 << 7
#define CUS_SENSOR 1 << 7
#define SIGNED__	1 << 6
#define UNSIGNED	0 << 6
#define MUL_001		0 << 4
#define MUL_010		1 << 4
#define MUL_100		2 << 4

#define UNIT_NONE 	0
#define UNIT_M 		1
#define UNIT_DEG 	2
#define UNIT_A		3
#define	UNIT_PROC	4
#define UNIT_V		5
#define UNIT_MS		6
#define UNIT_DBM	7
#define UNIT_DB		8
#define UNIT_KMH	9
#define UNIT_CM_S	10
#define UNIT_MAH	11
#define TEMP_TEXT_OFFSET 5
#define ALT_TEXT_OFFSET 15

const uint8_t SENSOR_00[] =
/* 5-byte NULL-terminated strings. The last one has implicit NULL added
/*00@0*/	"IntV\0"
/*01@5*/	"Temp\0"
/*02@10*/	"Mot\0\0"
/*03@15*/	"ExtV\0"
/*04@20*/	"Cell\0"
/*05@25*/	"Curr\0"
/*06@30*/	"Fuel\0"
/*07@35*/	"RPM\0\0"
/*08@40*/	"Head\0"
/*09@45*/	"RoC\0\0"
/*10@50*/	"CoG\0\0"
/*11@55*/	"GPS\0\0"
/*12@60*/	"AccX\0"
/*13@65*/	"AccY\0"
/*14@70*/	"AccZ\0"
/*15@75*/	"Roll\0"
/*16@80*/	"Pit.\0"
/*17@85*/	"Yaw\0\0"
/*18@90*/	"VSpe\0"
/*19@95*/	"GSpe\0"
/*20@100*/	"Dist\0"
/*21@105*/	"Arm.\0"
/*22@110*/	"Mode"	// The last one without \0
;


const uint8_t SENSOR_41[] =
/*41@0*/	"Press.\0"; // another \0 added by compiler
;

const uint8_t SENSORS_7D[] =
/*7c@0*/	"Odo1\0"
/*7d@5*/	"Odo2\0"
/*7e@10*/	"Spe \0"
/*7f@15*/	"Tx V" // The last one without \0
;

const uint8_t SENSORS_80[] =
		"Lat\0\0" /*0x80*/
		"Lon\0\0" /*0x81*/
		"GAlt\0"  /*0x82*/
		"Alt\0\0" /*0x83*/
		"MxAl\0"  /*0x84*/
		"S85\0\0" /*0x85*/
		"S86\0\0" /*0x86*/
		"S87\0\0" /*0x87*/
		"S88\0\0" /*0x88*/
		"S89\0\0" /*0x89*/
		"S90\0"   /*0x8a; the last one without \0*/
;


const uint8_t SENSORS_F9[] =
		"Alt\0\0"
		"SNR\0\0"
		"Noi.\0"
		"RSSI\0"
		"S FD\0"
		"Err.\0"
		"None"	// The last one without \0
;

const uint8_t UNKNOWN_SENSOR[] = "Unknown";
const uint8_t voltageSensors[] = { IBUS_MEAS_TYPE_INTV, IBUS_MEAS_TYPE_EXTV} ;
const uint8_t ARMED[] = "Armed";

const uint8_t flyModesOffset[] = {
	0, 5, 10, 16, 21, 28, 35, 39, 46, 52
};
const uint8_t FLY_MODES[] = {
	/*0@00*/ "Stab\0"
	/*1@05*/ "Acro\0"
	/*2@10*/ "AHold\0"
	/*3@16*/ "Auto\0"
	/*4@21*/ "Guided\0"
	/*5@28*/ "Loiter\0"
	/*6@35*/ "RTL\0"
	/*7@39*/ "Circle\0"
	/*8@46*/ "PHold\0"
	/*9@52*/ "Land"
};

const uint8_t sensorsScreens[] = {
	IBUS_MEAS_TYPE_FLIGHT_MODE,
	IBUS_MEAS_TYPE_ARMED,
	IBUS_MEAS_TYPE_ERR,
	IBUS_MEAS_TYPE_RSSI,
	IBUS_MEAS_TYPE_NOISE,
	IBUS_MEAS_TYPE_SNR,
	IBUS_MEAS_TYPE_TX_V,
	IBUS_MEAS_TYPE_INTV,

	IBUS_MEAS_TYPE_GPS_STATUS,
	IBUS_MEAS_TYPE_GPS_LAT,
	IBUS_MEAS_TYPE_GPS_LON,
	IBUS_MEAS_TYPE_GPS_ALT,
	IBUS_MEAS_TYPE_ALT,
	IBUS_MEAS_TYPE_GPS_DIST,
	IBUS_MEAS_TYPE_CMP_HEAD,
	IBUS_MEAS_TYPE_COG,

	IBUS_MEAS_TYPE_EXTV,
	IBUS_MEAS_TYPE_TEM,
	IBUS_MEAS_TYPE_CELL,
	IBUS_MEAS_TYPE_BAT_CURR,
	IBUS_MEAS_TYPE_FUEL,
	IBUS_MEAS_TYPE_ACC_X,
	IBUS_MEAS_TYPE_ACC_Y,
	IBUS_MEAS_TYPE_ACC_Z,

	IBUS_MEAS_TYPE_ROLL,
	IBUS_MEAS_TYPE_PITCH,
	IBUS_MEAS_TYPE_YAW,
	IBUS_MEAS_TYPE_SPE,
	IBUS_MEAS_TYPE_GROUND_SPEED,
	IBUS_MEAS_TYPE_VERTICAL_SPEED,
	IBUS_MEAS_TYPE_CLIMB_RATE,
	IBUS_MEAS_TYPE_RPM,

	IBUS_MEAS_TYPE_ALT_MAX,
	IBUS_MEAS_TYPE_S85,
	IBUS_MEAS_TYPE_S86,
	IBUS_MEAS_TYPE_S87,
	IBUS_MEAS_TYPE_S88,
	IBUS_MEAS_TYPE_S89,
	IBUS_MEAS_TYPE_S8a,
	IBUS_MEAS_TYPE_UNKNOWN

};


/*
CSMMUUUU
C 1 -custom 0 std
S 1 -signed 0 unsigned
MM mulitplayed by 00=1 10=100
UUUU UNIT
 * */

const uint8_t sensorDesc00[] = {
/*00*/	STD_SENSOR|UNSIGNED|MUL_100|UNIT_V,		//IntV
/*01*/	STD_SENSOR|SIGNED__|MUL_010|UNIT_DEG, 	//Temp
/*02*/	STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE, 	//Mot
/*03*/	STD_SENSOR|UNSIGNED|MUL_100|UNIT_V,		//ExtV
/*04*/	STD_SENSOR|UNSIGNED|MUL_100|UNIT_V,		//Cell
/*05*/	STD_SENSOR|UNSIGNED|MUL_100|UNIT_A,		//Current
/*06*/	STD_SENSOR|UNSIGNED|MUL_001|UNIT_PROC,	//remaining battery percentage / mah drawn otherwise or fuel level no unit!
/*07*/	STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//RPM bat
/*08*/	STD_SENSOR|UNSIGNED|MUL_001|UNIT_DEG,  	//Heading
/*09*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_MS, 	//Climb
/*0a*/	STD_SENSOR|SIGNED__|MUL_001|UNIT_DEG,	//CoG.
/*0b*/	CUS_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//GPS. status
/*0c*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_CM_S, 	//Acc x
/*0d*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_CM_S, 	//Acc y
/*0e*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_CM_S, 	//Acc z
/*0f*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_DEG, 	//roll
/*10*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_DEG, 	//pitch
/*11*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_DEG, 	//yaw
/*12*/	STD_SENSOR|SIGNED__|MUL_100|UNIT_MS, 	//VSpeed
/*13*/	STD_SENSOR|UNSIGNED|MUL_100|UNIT_MS, 	//ground Speed
/*14*/	STD_SENSOR|UNSIGNED|MUL_001|UNIT_M,  	//Dist
/*15*/	CUS_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,  //Armed
/*16*/	CUS_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,  //Mode
};
//0x41 is custom

const uint8_t sensorDesc80[] = {
		CUS_SENSOR|SIGNED__|MUL_001|UNIT_NONE,	//Lat.
		CUS_SENSOR|SIGNED__|MUL_001|UNIT_NONE,	//Lon.
		STD_SENSOR|SIGNED__|MUL_100|UNIT_M,		//Alt -> GPS alt
		STD_SENSOR|SIGNED__|MUL_100|UNIT_M,		//ALT
		STD_SENSOR|SIGNED__|MUL_100|UNIT_M,	//Max Alt
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//s85
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//s86
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//s87
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//s88
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//s89
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//s89
};

const uint8_t sensorDescFA[] = {
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_DB,	//SNR
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_DBM,	//Noise
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_DBM,	//RSSI
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//SensFD
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_PROC,	//Error
		STD_SENSOR|UNSIGNED|MUL_001|UNIT_NONE,	//None
};

const uint8_t formatCoord[] = { '%', 'u', '.', '%', '0', '6', 'u', 0x7f, 0x00};
const uint8_t formatGPS[] = "%u %02u";
const uint8_t formatNumber[] = "%u";
const uint8_t formatNumberFractial[] = "%u.%02u";


//if unit > 0 sub 1
const uint8_t unitsOffsets[] = {
	0, 2, 4, 6, 8, 10, 14, 18, 21, 26, 31
};


const uint8_t units[] = {
	/*1@0*/  'm', 0x00,						//m;
	/*2@2*/  0x7f, 0x00,					//�
	/*3@4*/ 'A', 0x00,						//A
	/*4@6*/ '%', 0x00,						//%
	/*5@8*/ 'V', 0x00,						//V
	/*6@10*/ 'm', '/', 's', 0x00,			//m/s
	/*7@14*/ 'd', 'B', 'm', 0x00,			//dBm
	/*8@18*/ 'd', 'B', 0x00,				//dB
	/*9@21*/ 'k', 'm', '/', 'h', 0x00,		//km/h
	/*10@26*/'c', 'm', '/', 's', 0x00,		//cm/s
	/*11@31*/'m', 'A', 'h', 0x00,
};



#endif
