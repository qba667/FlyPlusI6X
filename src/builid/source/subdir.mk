################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../source/main.c \
../source/ibus_telemetry.c \
../source/channelsHack.c \


ASM_SRCS += \
../source/start.asm \
../source/applySwitchesHook1.asm \
../source/applySwitchesHook2.asm \
../source/applySwitchesHook3.asm

OBJS += \
./source/start.o \
./source/main.o  \
./source/ibus_telemetry.o \
./source/channelsHack.o  \
./source/applySwitchesHook1.o \
./source/applySwitchesHook2.o \
./source/applySwitchesHook3.o

C_DEPS += \
./source/main.d \
./source/ibus_telemetry.d \
./source/channelsHack.d \


ASM_DEPS += \
./source/start.d \
./source/applySwitchesHook1.d \
./source/applySwitchesHook2.d \
./source/applySwitchesHook3.d \

# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Os $(PARAMS) -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -g -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -g -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
