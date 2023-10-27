/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */

//#define F_CPU 16000000UL
#include <avr/io.h>
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"

#include <avr/delay.h>
#include "HAL/LCD/LCD.h"
#include "MCAL/EXTI/includes/EXTI_interface.h"
#include "MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"

#define PWM_CHECK_BY_LED_INTENSITY_OR_MOTOR_SPEED main
//#define CHECK_DELAY_NORMAL_MODE main
//#define CHECK_DELAY_CTC_MODE main

void Action1(void) {
	Dio_FlipChannel(PA_5);
}

int PWM_CHECK_BY_LED_INTENSITY_OR_MOTOR_SPEED() {
	Port_Init(pin_cfg);
	GI_voidEnable();
	TMR0_voidInit();
	TMR0_voidStart();
	u8 local_delay = 1;
	while (1) {
		local_delay++;
		if (local_delay == 100)
			local_delay = 0;
		TMR0_voidSetDutyCycleForPWM(local_delay);
		_delay_ms(50);

	}
	return 0;
}
