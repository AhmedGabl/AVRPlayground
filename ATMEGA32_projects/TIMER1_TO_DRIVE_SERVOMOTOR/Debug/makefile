################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMERS/TIMER2/src/subdir.mk
-include MCAL/TIMERS/TIMER1/src/subdir.mk
-include MCAL/TIMERS/TIMER0/src/subdir.mk
-include MCAL/SPI/src/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GI/subdir.mk
-include MCAL/EXTI/src/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/SRVM/subdir.mk
-include HAL/SEVEN_SEGMENT/subdir.mk
-include HAL/LCD/subdir.mk
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
TIMER1_TO_DRIVE_SERVOMOTOR.lss \

FLASH_IMAGE += \
TIMER1_TO_DRIVE_SERVOMOTOR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TIMER1_TO_DRIVE_SERVOMOTOR.elf secondary-outputs

# Tool invocations
TIMER1_TO_DRIVE_SERVOMOTOR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TIMER1_TO_DRIVE_SERVOMOTOR.map -mmcu=atmega32 -o "TIMER1_TO_DRIVE_SERVOMOTOR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TIMER1_TO_DRIVE_SERVOMOTOR.lss: TIMER1_TO_DRIVE_SERVOMOTOR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TIMER1_TO_DRIVE_SERVOMOTOR.elf  >"TIMER1_TO_DRIVE_SERVOMOTOR.lss"
	@echo 'Finished building: $@'
	@echo ' '

TIMER1_TO_DRIVE_SERVOMOTOR.hex: TIMER1_TO_DRIVE_SERVOMOTOR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TIMER1_TO_DRIVE_SERVOMOTOR.elf  "TIMER1_TO_DRIVE_SERVOMOTOR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TIMER1_TO_DRIVE_SERVOMOTOR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TIMER1_TO_DRIVE_SERVOMOTOR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TIMER1_TO_DRIVE_SERVOMOTOR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
