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
#define MOD_EEPROM_START = 8192;

typedef void (*loadSettingsFun)();
const loadSettingsFun loadSettingsOrg = (loadSettingsFun)0x08006F78+1;

typedef int32_t (*eepromFun)(uint32_t eepromAddress, void* target, uint32_t length);
const eepromFun readEEPROM = (eepromFun)0x0800F378+1;
const eepromFun writeEEPROM = (eepromFun)0x080192C4+1;

typedef int32_t (*crcFun)(uint32_t null, void* target, uint32_t length);
const crcFun crc = (eepromFun)0x08005728+1;

void loadSettingsHook();





#endif
