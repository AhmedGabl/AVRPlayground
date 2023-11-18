/*
 * DCM_program.c
 * Description: Control functions for a DC motor using H-Bridge and Timer0 PWM mode.
 * Created on: Oct 27, 2023
 * Author: AhmedAbogabl
 */


/* UTILES_LIB */
#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
/* MCAL */
#include "../../MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"
#include "DCM_interface.h"


/* Function to turn on the DC motor */
void DCM_voidOn(u8 Copy_u8Direction) {
    /* Turns on the DC motor, sets direction, enables PWM, and starts motor control. */
    Dio_WriteChannel(DCM_EN, STD_HIGH);  // Enable the DC motor
    Dio_WriteChannel(DCM_DIR, Copy_u8Direction);  // Set motor direction
    DCM_voidControlSpeed(INITIAL_SPEED);  // Control motor speed
}

/* Function to control the speed of the DC motor */
void DCM_voidControlSpeed(u8 Copy_u8Speed) {
    /* Controls the DC motor speed using PWM mode from Timer0. */
    TMR0_voidSetDutyCycleForPWM(Copy_u8Speed);  // Set PWM Duty Cycle
    TMR0_voidStart();  // Start Timer0 for PWM operation
}

/* Function to turn off the DC motor */
void DCM_voidOff(void) {
    /* Turns off the DC motor and stops Timer0 PWM. */
    Dio_WriteChannel(DCM_EN, STD_LOW);  // Disable the DC motor
    TMR0_voidStop();  // Stop Timer0
}
