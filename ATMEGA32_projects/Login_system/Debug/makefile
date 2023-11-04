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
-include MCAL/PORT/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/SRVM/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
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
Login_system.lss \

FLASH_IMAGE += \
Login_system.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Login_system.elf secondary-outputs

# Tool invocations
Login_system.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Login_system.map -mmcu=atmega32 -o "Login_system.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Login_system.lss: Login_system.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Login_system.elf  >"Login_system.lss"
	@echo 'Finished building: $@'
	@echo ' '

Login_system.hex: Login_system.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Login_system.elf  "Login_system.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Login_system.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Login_system.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Login_system.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
