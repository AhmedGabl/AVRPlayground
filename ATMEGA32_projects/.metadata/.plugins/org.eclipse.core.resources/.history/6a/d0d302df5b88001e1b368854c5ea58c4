/*
 * MOTOR_program.c
 * Description: Control functions for two DC motors using L298N motor driver.
 * Created on: Nov 15, 2023
 * Author: AhmedAbogabl
 */

/* UTILES_LIB */
#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
/* MCAL */

#include "../../MCAL/DIO/DIO_interface.h"  // Include Digital Input/Output interface
#include "../../MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "WHM.h"

/* Function to initialize the motor driver */
void MOTOR_voidInit(void) {
	TMR0_voidInit();
    Dio_WriteChannel(SPEEDM_EN, STD_LOW);  // Disable speed motor
    Dio_WriteChannel(STEERINGM_EN, STD_LOW);  // Disable steering motor

    Dio_WriteChannel(SPEEDM_IN1, STD_LOW);  // Set initial direction for speed motor
    Dio_WriteChannel(SPEEDM_IN2, STD_LOW);

    Dio_WriteChannel(STEERINGM_IN1, STD_LOW);  // Set initial direction for steering motor
    Dio_WriteChannel(STEERINGM_IN2, STD_LOW);
}

/* Function to turn on a DC motor */
void MOTOR_voidOn(u8 Copy_u8Motor, u8 Copy_u8Direction) {
    if (Copy_u8Motor == SPEED_MOTOR) {
        Dio_WriteChannel(SPEEDM_IN1, GET_BIT(Copy_u8Direction, 0));
        Dio_WriteChannel(SPEEDM_IN2, GET_BIT(Copy_u8Direction, 1));
        MOTOR_voidControlSpeed(SPEED_MOTOR, INITIAL_SPEED);  // Enable the speed motor

    } else if (Copy_u8Motor == STEERING_MOTOR) {
        Dio_WriteChannel(STEERINGM_EN, STD_HIGH);  // Enable the steering motor
        Dio_WriteChannel(STEERINGM_IN1, GET_BIT(Copy_u8Direction, 0));
        Dio_WriteChannel(STEERINGM_IN2, GET_BIT(Copy_u8Direction, 1));
    }
}

/* Function to control the speed of a DC motor */
void MOTOR_voidControlSpeed(u8 Copy_u8Motor, u8 Copy_u8Speed) {
    if (Copy_u8Motor == SPEED_MOTOR) {
        TMR0_voidSetDutyCycleForPWM(Copy_u8Speed);  // Set PWM Duty Cycle for speed motor
        TMR0_voidStart();  // Start Timer0 for PWM operation
    } else if (Copy_u8Motor == STEERING_MOTOR) {
        // Adjust if steering motor has a different speed control mechanism
        // TMR0_voidSetDutyCycleForPWM(Copy_u8Speed);
        // TMR0_voidStart();
    }
}

/* Function to turn off a DC motor */
void MOTOR_voidOff(u8 Copy_u8Motor) {
    if (Copy_u8Motor == SPEED_MOTOR) {
   //     Dio_WriteChannel(SPEEDM_EN, STD_LOW);  // Disable the speed motor
    	MOTOR_voidControlSpeed(SPEED_MOTOR, 0);  // Enable the speed motor

    //	TMR0_voidStop();  // Stop Timer0
    } else if (Copy_u8Motor == STEERING_MOTOR) {
        Dio_WriteChannel(STEERINGM_EN, STD_LOW);  // Disable the steering motor
        // Stop Timer0 if steering motor uses PWM
        // TMR0_voidStop();
    }
}
