/*
 * DCM_interface.h
 * Description: Interface for controlling a DC motor using an H-Bridge and Timer0 PWM mode.
 * Created on: Oct 27, 2023
 * Author: AhmedAbogabl
 */

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"  // Include Digital Input/Output interface

// Constants for DC motor control

// Initial speed for PWM
#define INITIAL_SPEED 25

// Pin configurations for the motor
#define DCM_EN  PB_6  // Enable pin
#define DCM_DIR PB_5  // Direction pin
#define DCM_PWM PB_3  // PWM pin

// Constants for motor direction
#define DCM_CW    1  // Clockwise direction
#define DCM_CCW   0  // Counterclockwise direction


// Function Prototypes

// Function to turn the DC motor on in a specified direction
void DCM_voidOn(u8 Copy_u8Direction);

// Function to control the speed of the DC motor
void DCM_voidControlSpeed(u8 Copy_u8Speed);

// Function to turn the DC motor off
void DCM_voidOff(void);

#endif /* DCM_INTERFACE_H_ */
