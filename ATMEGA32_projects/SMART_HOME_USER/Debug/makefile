################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/src/subdir.mk
-include MCAL/TIMERS/TIMER2/src/subdir.mk
-include MCAL/TIMERS/TIMER1/src/subdir.mk
-include MCAL/TIMERS/TIMER0/src/subdir.mk
-include MCAL/SPI/src/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GI/subdir.mk
-include MCAL/EXTI/src/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/src/subdir.mk
-include HAL/SRVM/subdir.mk
-include HAL/SEVEN_SEGMENT/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/DC_MOTOR_H_BRIDGE/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SMART_HOME_USER.lss \

FLASH_IMAGE += \
SMART_HOME_USER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SMART_HOME_USER.elf secondary-outputs

# Tool invocations
SMART_HOME_USER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SMART_HOME_USER.map -mmcu=atmega32 -o "SMART_HOME_USER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SMART_HOME_USER.lss: SMART_HOME_USER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SMART_HOME_USER.elf  >"SMART_HOME_USER.lss"
	@echo 'Finished building: $@'
	@echo ' '

SMART_HOME_USER.hex: SMART_HOME_USER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SMART_HOME_USER.elf  "SMART_HOME_USER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SMART_HOME_USER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SMART_HOME_USER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SMART_HOME_USER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
