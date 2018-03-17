-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
fs-i6x.bin \

SECONDARY_SIZE += \
fs-i6x.siz \

PARAMS = 

# All Target
all: fs-i6x.elf secondary-outputs 
# Tool invocations

fs-i6x.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -T "../stm32f072.ld" -Xlinker --gc-sections -nodefaultlibs -nostartfiles -fno-builtin -nostdlib -lnosys -Wl,-Map,"fs-i6x.map" --specs=nano.specs -specs=nosys.specs -Xlinker -z -Xlinker muldefs -o "fs-i6x.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
fs-i6x.bin: fs-i6x.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy --update-section .firstSection=org.bin "fs-i6x.elf"
	#arm-none-eabi-objcopy --set-section-flags .firstSection=code,readonly,alloc "fs-i6x.elf"
	arm-none-eabi-objcopy  -j .firstSection -j .mod_* -j .text -j .rodata -O binary "fs-i6x.elf" "fs-i6x.bin"
	#python flysky2.py fs-i6.bin fs-i6
	#python3 flysky3.py fs-i6x.bin fs-i6x
	@echo 'Finished building: $@'
	@echo ' '
	
fs-i6x.siz: fs-i6x.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "fs-i6x.elf"
	arm-none-eabi-size --format=sysv "fs-i6x.elf" -x
	@echo 'Finished building: $@'
	@echo ' '
	
# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(C++_DEPS)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(CC_DEPS)$(SECONDARY_FLASH)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS)$(S_UPPER_DEPS) fs-i6x.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)
.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
