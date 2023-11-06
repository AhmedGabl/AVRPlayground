/*
 * DCM_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedAbogabl
 */

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_
#include "../../MCAL/DIO/DIO_interface.h"


//pin configurations

#define DCM_EN PB_6
#define DCM_DIR PB_5
#define DCM_PWM PB_3

// Define constants for motor direction
#define DCM_CW    0
#define DCM_CCW   1

// Function to turn the DC motor on in a specified direction
void DCM_voidOn(u8 Copy_u8Direction);

// Function to control the speed of the DC motor
void DCM_voidControlSpeed(u8 Copy_u8Speed);

// Function to turn the DC motor off
void DCM_voidOff(void);

#endif /* DCM_INTERFACE_H_ */
