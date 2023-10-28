################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMERS/TIMER0/src/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/DIO/subdir.mk
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
DCMOTOR_H_BRIDGE.lss \

FLASH_IMAGE += \
DCMOTOR_H_BRIDGE.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DCMOTOR_H_BRIDGE.elf secondary-outputs

# Tool invocations
DCMOTOR_H_BRIDGE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DCMOTOR_H_BRIDGE.map -mmcu=atmega32 -o "DCMOTOR_H_BRIDGE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DCMOTOR_H_BRIDGE.lss: DCMOTOR_H_BRIDGE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DCMOTOR_H_BRIDGE.elf  >"DCMOTOR_H_BRIDGE.lss"
	@echo 'Finished building: $@'
	@echo ' '

DCMOTOR_H_BRIDGE.hex: DCMOTOR_H_BRIDGE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DCMOTOR_H_BRIDGE.elf  "DCMOTOR_H_BRIDGE.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DCMOTOR_H_BRIDGE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DCMOTOR_H_BRIDGE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DCMOTOR_H_BRIDGE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
