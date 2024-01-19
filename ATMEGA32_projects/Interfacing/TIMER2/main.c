/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include <avr/delay.h>
#include "MCAL/TIMERS/TIMER2/includes/TMR2_interface.h"



/*
 * options:
 * PWM_TEST
 * CTC_OVF_TEST
 */
#define PWM_TEST main


void Action1(void)
{
	Dio_FlipChannel(PA_5);
}


int PWM_TEST() {

	Port_Init(pin_cfg);

Dio_WriteChannel(PA_5,STD_HIGH);
	//enable interrupts in project
GI_voidEnable();
	TMR2_voidInit();
	TMR2_voidStart();

//	_delay_ms(10000);

	u8 local_delay =0;
	while (1){

		local_delay++;
		if(local_delay==101) local_delay=0;
		TMR2_voidSetDutyCycleForPWM(local_delay);
		_delay_ms(50);

	}
	return 0;
}

int CTC_OVF_TEST() {

	Port_Init(pin_cfg);
	Dio_WriteChannel(PA_5,STD_LOW);
	//enable interrupts in project
	GI_voidEnable();
	TMR2_voidInit();

	//to test ctc
	TMR2_voidSetDelay_ms_usingCTC(1000);
	TMR2_voidSetCallBackCTC(Action1);
	//to test overflow
	//	TMR2_voidSetCallBackOVF(Action1);
	TMR2_voidStart();
	while (1){

	}
	return 0;
}
