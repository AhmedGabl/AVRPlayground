/*
 * main.c
 * Description: Door access control system using AVR microcontroller
 * Author: AhmedAbogabl
 * Created on: Oct 17, 2023
 */


#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/GI/GI_interface.h"


//car
#include "HAL/SRVM/SRVM_interface.h"
#include "HAL/MOTOR/WHM.h"
#include "HAL/BLUETOOTH/BT.h"

//////////////RTOS
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "std_types.h"
#include "semphr.h"
#include "projdefs.h"

#ifndef NULL
#define NULL (void *)0
#endif


void BT(void * pvparam);
#define BTPr (1)

void WHM(void * pvparam);
#define WHMPr (2)

void init(void);

/*** Global Variable ****/
u8 ButtonState = 1;

#define ForgetGiveSemaphore pdFALSE

xSemaphoreHandle ButtonSemaphore = NULL;

#define FrogetGlobalInterrupt 0  /* 0  for Nodefect 1 for Defect **/

 int main(void)
{

	 /* Creation of the Task*/
	 xTaskHandle BTHandle  = NULL;
	 xTaskCreate(BT,(const signed char*)"BT",85,NULL,BTPr,&BTHandle);

	 xTaskHandle WHMHandle = NULL ;
	 xTaskCreate(WHM,(const signed char*)"WHM ",85,NULL,WHMPr,&WHMHandle);

	 /*Init Function*/
	 init();

	 /*Create Semaphore for the Button */
	 vSemaphoreCreateBinary(ButtonSemaphore);

	/*start Scheduler */
	vTaskStartScheduler();



	/*Never Enter Here */
	return 0;
}

void init(void){
	Port_Init(pin_cfg);
BT_Init();
MOTOR_voidInit();
}

 void BT(void * pvparam){
	 portTickType Freq = 100;
	 portTickType Start = xTaskGetTickCount();

	 while (1){
		 /* if the Push Button is Pressed */
		// if ((PINC & 0x01) == 0){

			 /* If the Resource No One is Using so Take the Semaphore  **/
			 if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){

				 /*Change the State **/
				 ButtonState = BT_Receive();

				 /**Give the Semaphore */
				 ////////////////////////////////////////////////////////////////////////////
				if( ForgetGiveSemaphore == pdFALSE)
				 xSemaphoreGive(ButtonSemaphore);
				 ///////////////////////////////////////////////////////////////////////////////
				//#endif
			 }
			 /*Else Delay 1000 Tick till the Resource is Free **/
			 else {
				 vTaskDelay(100);
			 }
		 //}

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }

 }


 void WHM(void * pvparam){
	 portTickType Freq = 100;
	 portTickType Start = xTaskGetTickCount();

	 while (1){
		 MOTOR_voidOff(SPEED_MOTOR);
		 MOTOR_voidOff(STEERING_MOTOR);
		 /* if the Push Button is Pressed */
		 if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){
			switch (ButtonState) {
				case 'W':
					MOTOR_voidOn(SPEED_MOTOR,MOTOR_CW);
					break;
				case 'P':
					MOTOR_voidOff(SPEED_MOTOR);
					break;
				case 'S':
					MOTOR_voidOn(SPEED_MOTOR,MOTOR_CCW);
					break;

				case 'D':
					MOTOR_voidOn(STEERING_MOTOR,MOTOR_CW);
					break;
				case 'A':
					MOTOR_voidOn(STEERING_MOTOR,MOTOR_CCW);
					break;
				default:
					break;
			}

			 if (ButtonState == 0){
				 PORTB ^= 0x01;
				 ButtonState = 1;
			 }
			 /**Give the Semaphore */
			 xSemaphoreGive(ButtonSemaphore);
		 }
		 /*Else Delay 1000 Tick till the Resource is Free **/
		 else {
			 vTaskDelay(1000);
		 }
		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }


 }

 /*
  * fun prototypes
  */
 void WHM_SpeedOff(void);
 void WHM_SteeringOff(void);

 #define ForgetGiveSemaphore		 pdFALSE
 #define FrogetGlobalInterrupt 		0  /* 0  for Nodefect 1 for Defect **/

 void BT(void );
 void WHM(void);

 #define WHMPr (2)

 void init(void);

 /*** Global Variable ****/
 u8 ButtonState = 1;

 u8 BT_read_vlaue = 0;
 int main(void) {
 	init();

 //	while (1) {

 //		BT();
 //
 //		WHM();
 //	}


 	OS_voidCreateTask(0,100,0,BT);
 	OS_voidCreateTask(1,200,1,WHM);

 	/*Never Enter Here */
 	OS_voidStartScheduler();
 	while(1)
 	{

 	}
 	return 0;
 }

 void init(void) {
 	Port_Init(pin_cfg);
 	BT_Init();
 	GI_voidEnable();

 	MOTOR_voidInit();
 }

 void BT(void) {
 	if (ButtonState == 1) {
 		/*Change the State **/
 		BT_read_vlaue = BT_Receive();
 		ButtonState = 0;
 	}
 }

 void WHM(void ) {

 	/* if the Push Button is Pressed */
 	if (ButtonState == 0) {

 		switch (BT_read_vlaue) {
 		case 'W':
 			MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
 			ButtonState = 1;
 			break;
 		case 'P':
 			MOTOR_voidOff(SPEED_MOTOR);
 			ButtonState = 1;
 			break;
 		case 'S':
 			MOTOR_voidOn(SPEED_MOTOR, MOTOR_CCW);
 			ButtonState = 1;
 			break;
 		case 'D':
 			MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
 			ButtonState = 1;
 			break;
 		case 'A':
 			MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
 			ButtonState = 1;
 			break;
 		default:
 			break;
 		}

 		ButtonState = 1;
 	}
 }
