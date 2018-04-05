#include "sensors.h"



uint32_t is4BytesSensor(uint32_t sensorID){
    //we need to ensure that R1 will not be changed
    __asm("push {r1-r3}");
    uint32_t result = 0;
    switch(sensorID){
        case IBUS_MEAS_TYPE_PRES:
        case IBUS_MEAS_TYPE_ALT_FLYSKY:
        case IBUS_MEAS_TYPE_GPS_LAT:
        case IBUS_MEAS_TYPE_GPS_LON:
        case IBUS_MEAS_TYPE_GPS_ALT:
        case IBUS_MEAS_TYPE_ALT:
        case IBUS_MEAS_TYPE_ALT_MAX:
        case IBUS_MEAS_TYPE_S85:
        case IBUS_MEAS_TYPE_S86:
        case IBUS_MEAS_TYPE_S87:
        case IBUS_MEAS_TYPE_S88:
        case IBUS_MEAS_TYPE_S89:
        case IBUS_MEAS_TYPE_S8a:
            result = 1;
    }
    //if (sensorID == IBUS_MEAS_TYPE_PRES || sensorID == IBUS_MEAS_TYPE_ALT_FLYSKY) result = 1;
    //if (sensorID >= IBUS_MEAS_TYPE_GPS_LAT && sensorID <= IBUS_MEAS_TYPE_S8a) result = 1;
    __asm("pop {r1-r3}");
    return result;
}
void formatSensorValue(uint32_t* params, uint32_t value2Bytes,  uint32_t value4Bytes){
    char* target = (char*)params[4];
    target[0] = '\0';
    uint32_t sensorID = params[2];
    const char* format = (const char*) formatNumber;
    const char* unit = 0;
    uint32_t result = is4BytesSensor(sensorID) ? value4Bytes : value2Bytes;
    uint32_t result2 = 0;
    uint8_t negative = 0;
    uint8_t sensorInfo = STD_SENSOR | UNSIGNED | MUL_001 | UNIT_NONE;
    if (sensorID <= IBUS_MEAS_TYPE_FLIGHT_MODE) {
        sensorInfo = sensorDesc00[sensorID];
        if ((sensorInfo & SIGNED__) != 0 && ((int16_t) result) < 0) {
            negative = 1;
            result = (uint32_t) -((int16_t) result);
        }
    } else if (sensorID == IBUS_MEAS_TYPE_PRES) {
        sensorInfo |= MUL_100;
    } else if (sensorID >= IBUS_MEAS_TYPE_GPS_LAT && sensorID <= IBUS_MEAS_TYPE_S8a) {
        sensorInfo = sensorDesc80[sensorID - IBUS_MEAS_TYPE_GPS_LAT];
        if ((sensorInfo & SIGNED__) != 0 && ((int32_t) result) < 0) {
            negative = 1;
            result = (uint32_t) -((int32_t) result);
        }
    } else if (sensorID >= IBUS_MEAS_TYPE_SNR && sensorID <= 255) {
        sensorInfo = sensorDescFA[sensorID - IBUS_MEAS_TYPE_SNR];
        if (sensorID == IBUS_MEAS_TYPE_RSSI || sensorID == IBUS_MEAS_TYPE_NOISE) {
            negative = 1;
        }
    }
    if ((sensorInfo & MUL_100) == MUL_100) {
        format = (const char*) formatNumberFractial;
        if(result!= 0) result = udivMod(result, 100, &result2);
    }
    if ((sensorInfo & MUL_010) == MUL_010) {
        format = (const char*) formatNumberFractial;
        if(result!= 0) result = udivMod(result, 10, &result2);
    }
    if ((sensorInfo & CUS_SENSOR) != CUS_SENSOR) {
        if ((sensorInfo & 0xF) != UNIT_NONE) {
            unit = (const char*)(units) +unitsOffsets[(sensorInfo & 0xF)-1];
        }
    } else {
        switch (sensorID) {
            case IBUS_MEAS_TYPE_GPS_STATUS:
                result2 = result >> 8 & 0xFF;
                result &= 0xFF;
                format = (const char*) formatGPS;
                break;
            case IBUS_MEAS_TYPE_ARMED:
                if (!value2Bytes) {
                    target[0] = 'U';
                    target[1] = 'n';
                    target[2] = '\0';
                }
                strcat_(target, (const char *) ARMED);
                return;
            case IBUS_MEAS_TYPE_FLIGHT_MODE:
                if (result <= 9){
                    strcat_(target, (const char *) FLY_MODES + (flyModesOffset[result]));
                    return;
                }
                break;
            case IBUS_MEAS_TYPE_GPS_LON:
            case IBUS_MEAS_TYPE_GPS_LAT:
                format = (const char*) formatCoord;
                result = divMod(result, 10000000, &result2);
                break;
        }
    }

    if (negative) {
        target[0] = '-';
        target++;
    }

    sprintf_(target, format, result, result2);
    //strcat_(target, unit);
}

const char * getSensorName(uint32_t sensor){
	if ( sensor >= IBUS_MEAS_TYPE_INTV && sensor <= IBUS_MEAS_TYPE_UNKNOWN )
	{
		if(sensor <= IBUS_MEAS_TYPE_FLIGHT_MODE) return SENSOR_00 + (sensor * 5);
	    if (sensor == IBUS_MEAS_TYPE_PRES) return SENSOR_41;
	    if ( sensor < IBUS_MEAS_TYPE_ODO1 ) return (const char*)UNKNOWN_SENSOR;

	    if ( sensor <= IBUS_MEAS_TYPE_TX_V ){
	    	sensor = sensor - IBUS_MEAS_TYPE_ODO1;
	    	return SENSORS_7D + (sensor * 5);
	    }
	    if (sensor <= IBUS_MEAS_TYPE_S8a ){
	    	sensor = sensor - IBUS_MEAS_TYPE_GPS_LAT;
	        return SENSORS_80 + (sensor * 5);
	    }
	    if ( sensor >= IBUS_MEAS_TYPE_ALT_FLYSKY)
	    {
	    	sensor = sensor - IBUS_MEAS_TYPE_ALT_FLYSKY;
	    	return SENSORS_F9 + (sensor * 5);
	    }
	 }
	 return (const char*)UNKNOWN_SENSOR;
}
const char * getSensorName2(uint32_t sensor){
    return getSensorName(sensor);
}
