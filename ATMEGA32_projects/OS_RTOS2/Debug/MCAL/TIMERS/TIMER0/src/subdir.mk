################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMERS/TIMER0/src/TMR0_program.c 

OBJS += \
./MCAL/TIMERS/TIMER0/src/TMR0_program.o 

C_DEPS += \
./MCAL/TIMERS/TIMER0/src/TMR0_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMERS/TIMER0/src/%.o: ../MCAL/TIMERS/TIMER0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\GitHub\AVRPlayground\ATMEGA32_projects\OS_RTOS\FreeRTOS" -I"D:\GitHub\AVRPlayground\ATMEGA32_projects\OS_RTOS\FreeRTOS\Source\include" -I"D:\GitHub\AVRPlayground\ATMEGA32_projects\OS_RTOS\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


