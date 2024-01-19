/*
 * WHM_config.h
 *
 *  Created on: Nov 27, 2023
 *      Author: AhmedAbogabl
 */

#ifndef HAL_MOTOR_WHM_CONFIG_H_
#define HAL_MOTOR_WHM_CONFIG_H_

// Initial speed for PWM
#define INITIAL_SPEED 20

// Pin configurations for the speed motor
#define SPEEDM_EN  PB_3  // Enable pin for speed motor  //PWM
#define SPEEDM_IN1 PB_2  // Input 1 for speed motor
#define SPEEDM_IN2 PB_1  // Input 2 for speed motor

// Pin configurations for the steering motor
#define STEERINGM_EN  PD_3  // Enable pin for steering motor
#define STEERINGM_IN1 PD_4  // Input 1 for steering motor
#define STEERINGM_IN2 PD_5  // Input 2 for steering motor


#endif /* HAL_MOTOR_WHM_CONFIG_H_ */
