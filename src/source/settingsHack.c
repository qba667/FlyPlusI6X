#include "settingsHack.h"

void loadSettingsHook(){
    loadSettingsOrg();
    readEEPROM(MOD_EEPROM_START, (void*) &modModelConfig, sizeof(configStruct));
}
