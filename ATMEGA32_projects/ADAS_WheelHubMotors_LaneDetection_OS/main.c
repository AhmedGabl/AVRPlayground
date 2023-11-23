/*
 * main.c
 * Description: Door access control system using AVR microcontroller
 * Author: AhmedAbogabl
 * Created on: Oct 17, 2023
 */

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/GI/GI_interface.h"
#include "MCAL/ADC/includes/ADC_interface.h"
//car
#include "HAL/SRVM/SRVM_interface.h"
#include "HAL/MOTOR/WHM.h"
#include "HAL/BLUETOOTH/BT.h"
#include "OS/OS_interface.h"

#define L_S PC_0
#define R_S PC_1

/*
 * *****************************************************************************************
 */

// Constants for obstacle detection sensors
#define FRONT_SENSOR PC0
#define BACK_SENSOR PC1
#define LEFT_SENSOR PC2
#define RIGHT_SENSOR PC3

void AutoPark(void);
void Delay_ms(u32 Copy_u32Time);

/*
 * *********************************************************************************************
 */
void BT(void);		//BLUETOOTH FUNCTON
void WHM(void);		//MOTOR CONTROL FUNCTION

#define WHMPr (2)	//MOTOR CONTROL FUNCTION PRIORITY

void init(void);

void LED5(void) {
	Dio_FlipChannel(PA_5);
}

void LED4(void) {
	Dio_FlipChannel(PA_4);
}

void LED6(void) {
	Dio_FlipChannel(PA_6);
}

/*** Global Variable ****/
u8 ButtonState = 1;

u8 BT_read_vlaue = 0;
int main(void) {
	init();
	OS_voidCreateTask(0, 2, 0, BT);
	OS_voidCreateTask(1, 4, 1, WHM);

	OS_voidStartScheduler();
	while (1) {
//		BT();
//		WHM();
	}
	return 0;
}

void init(void) {
	Port_Init(pin_cfg);
	ADC_Init();		//pin 0 and 1
	BT_Init();
	GI_voidEnable();
	MOTOR_voidInit();

	Dio_WriteChannel(PC_0, STD_HIGH);
	Dio_WriteChannel(PC_1, STD_HIGH);

	Dio_WriteChannel(PA_4, STD_LOW);
	Dio_WriteChannel(PA_5, STD_LOW);
	Dio_WriteChannel(PA_6, STD_LOW);
}

void BT(void) {
	if (ButtonState == 1) {
		/*Change the State **/
		BT_read_vlaue = BT_Receive();
		ButtonState = 0;
	}
}

//static void PASS_semaphore(void)
//{
//	ButtonState = 0;
//}

void WHM(void) {
//OS_voidSuspendTask(0,5000);
//if()
	/* if the Push Button is Pressed */
	if (ButtonState == 0) {
	//	BT_read_vlaue = BT_read_vlaue + '0' ;
		switch (BT_read_vlaue) {
		case 'W':
			LED4();
			MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
			UART_TransmitString("inside W \r\n");

//			//steps movement
//			Delay_ms(100);
//			MOTOR_voidOff(SPEED_MOTOR);

			ButtonState = 1;
			break;
		case 'S':
			LED5();
			MOTOR_voidOn(SPEED_MOTOR, MOTOR_CCW);
			UART_TransmitString("inside S \r\n");

//			//steps movement
//			Delay_ms(100);
//			MOTOR_voidOff(SPEED_MOTOR);

			ButtonState = 1;
			break;
		case 'P':
			//
			MOTOR_voidOff(SPEED_MOTOR);
			UART_TransmitString("inside p \r\n");
			ButtonState = 1;
			break;
		case 'K':
			//
			MOTOR_voidOff(STEERING_MOTOR);
			UART_TransmitString("inside k \r\n");
			ButtonState = 1;
			break;

		case 'D':			UART_TransmitString("inside D \r\n");
			LED6();
			MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);

			//steps movement
			Delay_ms(1000);
			MOTOR_voidOff(STEERING_MOTOR);


			ButtonState = 1;
			break;
		case 'A':UART_TransmitString("inside A \r\n");

			LED6();
			MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);

			//steps movement
			Delay_ms(1000);
			MOTOR_voidOff(STEERING_MOTOR);

			ButtonState = 1;
			break;
		case '1':
			ButtonState = '1';
			LaneAssist(10);
			//		OS_voidSuspendTask(0, 10000);
			ButtonState = 1;
			UART_TransmitString("inside 1 \r\n");

			break;

		default:		//LED6();
			if ('0' <= BT_read_vlaue <= '9')
				MOTOR_voidControlSpeed(SPEED_MOTOR, (BT_read_vlaue - '0') * 10);

			//case 'P':
			//	MOTOR_voidOff(STEERING_MOTOR);
			ButtonState = 1;
			UART_TransmitString("inside default \r\n");

			break;
		}

		//	ButtonState = 1;
	}
}

//u16 L_S = 0 ;
//u16 R_S = 0;   ///pin PC0   PC1

void LaneAssist(u8 Copy_u8NormalSpeed) {
	//set default speed
	UART_TransmitString("inside Lane assistant \r\n");
//	OS_voidSuspendTask(0, 10000);

	while (1) {
		//if Right Sensor and Left Sensor are at White color then it will call forword function
		if ((Dio_ReadChannel(R_S) == 0) && (Dio_ReadChannel(L_S) == 0)) {//forward
			UART_TransmitString("inside motor 1  \r\n");

			MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
			MOTOR_voidOff(STEERING_MOTOR);
			MOTOR_voidControlSpeed(SPEED_MOTOR, Copy_u8NormalSpeed);

		}

		//if Right Sensor is Black and Left Sensor is White then it will call turn Right function
		if ((Dio_ReadChannel(R_S) == 1) && (Dio_ReadChannel(L_S) == 0)) {//turnRight
			UART_TransmitString("inside motor 2  \r\n");
			MOTOR_voidControlSpeed(SPEED_MOTOR, 10);
			MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
		}
		//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
		if ((Dio_ReadChannel(R_S) == 0) && (Dio_ReadChannel(L_S) == 1)) {
			//turnLeft
			UART_TransmitString("inside motor 3  \r\n");

			MOTOR_voidControlSpeed(SPEED_MOTOR, 10);
			MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
		}
		//if Right Sensor and Left Sensor are at Black color then it will call Stop function
		if ((Dio_ReadChannel(R_S) == 1) && (Dio_ReadChannel(L_S) == 1)) {
			//Stop
			UART_TransmitString("inside motor 4  \r\n");
			MOTOR_voidOff(STEERING_MOTOR);
			MOTOR_voidOff(SPEED_MOTOR);
		}
	}
}

void AutoPark(void) {
	// Set default speed
	MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
	MOTOR_voidControlSpeed(SPEED_MOTOR, 10);

	// Move forward until obstacle is detected in front
	while (ADC_ReadChannel(FRONT_SENSOR) < 100) {
		// Continue moving forward until obstacle is detected
		MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
	}

	// Stop and delay for a while
	MOTOR_voidOff(STEERING_MOTOR);
	MOTOR_voidOff(SPEED_MOTOR);
	Delay_ms(2000);

	// Turn right until it's clear
	MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
	Delay_ms(1000);

	// Move backward until obstacle is detected at the back
	MOTOR_voidOn(SPEED_MOTOR, MOTOR_CCW);
	while (ADC_ReadChannel(BACK_SENSOR) < 100) {
		// Continue moving backward until obstacle is detected
		MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
	}

	// Stop and delay for a while
	MOTOR_voidOff(STEERING_MOTOR);
	MOTOR_voidOff(SPEED_MOTOR);
	Delay_ms(2000);

	// Turn left until it's clear
	MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
	Delay_ms(1000);

	// Stop and drop steering
	MOTOR_voidOff(STEERING_MOTOR);
	MOTOR_voidOff(SPEED_MOTOR);
}

void Delay_ms(u32 Copy_u32Time) {
	for (u32 i = 0; i < Copy_u32Time; i++) {
		for (u16 j = 0; j < 1200; j++) {
			// Adjust this loop for the desired delay
		}
	}
}