################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SEVEN_SEGMENT/SEVEN_SEGMENT.c 

OBJS += \
./HAL/SEVEN_SEGMENT/SEVEN_SEGMENT.o 

C_DEPS += \
./HAL/SEVEN_SEGMENT/SEVEN_SEGMENT.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SEVEN_SEGMENT/%.o: ../HAL/SEVEN_SEGMENT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


