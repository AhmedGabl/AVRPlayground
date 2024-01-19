/*
 * DCM_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedAbogabl
 */



/* UTILES_LIB */
#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"


void DCM_voidOn(u8 Copy_u8Direction)
{
	/* Turn DC motor on using H-Bridge
	 By Setting PWM, Dir and Enable pins with high
	 or Dir Low depend on Copy_u8Direction*/
}


void DCM_voidControlSpeed(u8 Copy_u8Speed)
{
	/* Controlling DC motor speed using PWM
	mode from TMR0 by setting Duty Cycle*/
}


void DCM_voidOff(void)
{
	/* Turn DC motor off using H-Bridge
	   By Setting Enable pin with low */
}
