/*
 * MOTOR_INTERFACE.h
 * Description: Interface for controlling two DC motors using L298N motor driver.
 * Created on: Nov 15, 2023
 * Author: AhmedAbogabl
 */

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

// Constants for DC motor control

// Initial speed for PWM
#define INITIAL_SPEED 50

// Pin configurations for the speed motor
#define SPEEDM_EN  PB_3  // Enable pin for speed motor
#define SPEEDM_IN1 PB_4  // Input 1 for speed motor
#define SPEEDM_IN2 PB_5  // Input 2 for speed motor

// Pin configurations for the steering motor
#define STEERINGM_EN  PD_3  // Enable pin for steering motor
#define STEERINGM_IN1 PD_4  // Input 1 for steering motor
#define STEERINGM_IN2 PD_5  // Input 2 for steering motor

// Constants for motor direction
#define MOTOR_CW    1  // Clockwise direction
#define MOTOR_CCW   2  // Counterclockwise direction

// Motor identifiers
#define SPEED_MOTOR     0
#define STEERING_MOTOR  1

// Function Prototypes

// Function to initialize the motor driver
void MOTOR_voidInit(void);

// Function to turn on a DC motor
void MOTOR_voidOn(u8 Copy_u8Motor, u8 Copy_u8Direction);

// Function to control the speed of a DC motor
void MOTOR_voidControlSpeed(u8 Copy_u8Motor, u8 Copy_u8Speed);

// Function to turn off a DC motor
void MOTOR_voidOff(u8 Copy_u8Motor);

#endif /* MOTOR_INTERFACE_H_ */
