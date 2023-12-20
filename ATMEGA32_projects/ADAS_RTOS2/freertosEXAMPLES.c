/*
 * freertosEXAMPLES.c
 *
 * Created: 11/11/2023 9:51:21 PM
 *  Author: ahmed radwan
 */ 
///////////////////////task no 1//////////////////////
///////////////////////task no 2//////////////////////
///////////////////////task no 3//////////////////////
///////////////////////task no 4//////////////////////
/*****************empty task*****************/
/////////////////////////////////////////////////////







///////////////////////task no 5//////////////////////
// 
// #include <avr/io.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "FreeRTOSConfig.h"
// #include "SERVICES/Standard_Data_Types.h"
// 
// #ifndef NULL
// #define NULL (void *)0
// #endif
// 
// 
// void PushButton(void * pvparam);
// #define PushButtonPr (1)
// 
// void Led(void * pvparam);
// #define LedPr (2)
// 
// void init(void);
// 
// /*** Global Variable ****/
// u8 ButtonState = 1;
// 
// int main(void)
// {
// 
// 	/* Creation of the Task*/
// 	xTaskHandle PushHandle  = NULL;
// 	xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);
// 
// 	xTaskHandle LedHandle = NULL ;
// 	xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);
// 
// 	/*Init Function*/
// 	init();
// 
// 	/*start Scheduler */
// 	vTaskStartScheduler();
// 
// 
// 
// 	/*Never Enter Here */
// 	return 0;
// }
// 
// void init(void){
// 	DDRB = 0xFF;
// 
// 	DDRC = 0x00;
// 
// 	PORTC = 0xFF;
// 
// }
// void PushButton(void * pvparam){
// 	portTickType Freq = 50;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if ((PINC & 0x01) == 0){
// 			ButtonState = 0;
// 		}
// 
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// }
// 
// 
// void Led(void * pvparam){
// 	portTickType Freq = 50;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if (ButtonState == 0){
// 			PORTB ^= 0x01;
// 			ButtonState = 1;
// 		}
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// 
// }

/***********************************************************************/




///////////////////////task no 6//////////////////////

// #include <avr/io.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "FreeRTOSConfig.h"
// #include "SERVICES/Standard_Data_Types.h"
// 
// #ifndef NULL
// #define NULL (void *)0
// #endif
// 
// 
// void PushButton(void * pvparam);
// #define PushButtonPr (1)
// 
// void Led(void * pvparam);
// #define LedPr (2)
// 
// void init(void);
// 
// /*** Global Variable ****/
// u8 ButtonState = 1;
// 
// u8 ButtonStateFlag = 0;
// 
// 
// int main(void)
// {
// 
// 	/* Creation of the Task*/
// 	xTaskHandle PushHandle  = NULL;
// 	xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);
// 
// 	xTaskHandle LedHandle = NULL ;
// 	xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);
// 
// 	/*Init Function*/
// 	init();
// 
// 	/*start Scheduler */
// 	vTaskStartScheduler();
// 
// 
// 
// 	/*Never Enter Here */
// 	return 0;
// }
// 
// void init(void){
// 
// 	DDRB = 0xFF;
// 
// 	DDRC = 0x00;
// 
// 	PORTC = 0xFF;
// 
// }
// void PushButton(void * pvparam){
// 	portTickType Freq = 50;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if ((PINC & 0x01) == 0){
// 
// 			/* If the Resource No One is Using so Raise a Flag to Use it **/
// 			if(ButtonStateFlag == 0){
// 				/*Raise the Flag */
// 				ButtonStateFlag = 1;
// 
// 				/*Change the State **/
// 				ButtonState = 0;
// 
// 				/*Release the Flag */
// 				ButtonStateFlag = 0;
// 			}
// 			/*Else Delay 10 Tick till the Resource is Free **/
// 			else {
// 				vTaskDelay(10);
// 			}
// 
// 		}
// 
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// }
// 
// 
// void Led(void * pvparam){
// 	portTickType Freq = 50;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 
// 
// 		/* If the Resource No One is Using so Raise a Flag to Use it **/
// 		if(ButtonStateFlag == 0){
// 
// 			/*Raise the Flag */
// 			ButtonStateFlag = 1;
// 
// 			if (ButtonState == 0){
// 				PORTB ^= 0x01;
// 				ButtonState = 1;
// 			}
// 
// 			/*Release the Flag */
// 			ButtonStateFlag = 0;
// 		}
// 		/*Else Delay 10 Tick till the Resource is Free **/
// 		else {
// 			vTaskDelay(10);
// 		}
// 
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// 
// }

///////////////////////////////task7///////////////////////////

// #include "SERVICES/Standard_Data_Types.h"
// #include <avr/io.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "FreeRTOSConfig.h"
// 
// #ifndef NULL
// #define NULL (void *)0
// #endif
// 
// 
// void PushButton(void * pvparam);
// #define PushButtonPr (1)
// 
// void Led(void * pvparam);
// #define LedPr (2)
// 
// void init(void);
// 
// /*** Global Variable ****/
// u8 ButtonState = 1;
// 
// u8 ButtonStateFlag = 0;
// 
// #define FrogetGlobalInterrupt 1  /* 0  for Nodefect 1 for Defect **/
// 
// int main(void)
// {
// 
// 	/* Creation of the Task*/
// 	xTaskHandle PushHandle  = NULL;
// 	xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);
// 
// 	xTaskHandle LedHandle = NULL ;
// 	xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);
// 
// 	/*Init Function*/
// 	init();
// 
// 	/*start Scheduler */
// 	vTaskStartScheduler();
// 
// 
// 
// 	/*Never Enter Here */
// 	return 0;
// }
// 
// void init(void){
// 
// 	DDRB = 0xFF;
// 
// 	DDRC = 0x00;
// 
// 	PORTC = 0xFF;
// 
// }
// void PushButton(void * pvparam){
// 	portTickType Freq = 250;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if ((PINC & 0x01) == 0){
// 			SREG = 0;
// 			/* If the Resource No One is Using so Stop Scheduling to Use it **/
// 			if(ButtonStateFlag == 0){
// 				/**Disable Global Interrupt*/
// 
// 
// 				/*Raise the Flag */
// 				ButtonStateFlag = 1;
// 
// 				#if (FrogetGlobalInterrupt == 0)
// 				/**Enable Global Interrupt*/
// 				SREG = 128;
// 				#endif
// 
// 				/*Change the State **/
// 				ButtonState = 0;
// 
// 
// 				/**Disable Global Interrupt*/
// 				SREG = 0;
// 
// 				/*Release the Flag */
// 				ButtonStateFlag = 0;
// 				#if (FrogetGlobalInterrupt == 0)
// 				/**Enable Global Interrupt*/
// 				SREG = 128;
// 				#endif
// 			}
// 			/*Else Delay 10 Tick till the Resource is Free **/
// 			else {
// 				vTaskDelay(10);
// 				//SREG = 128;/***************************************/
// 			}
// 
// 		}
// 
// 		/*Make the Task Periodic with Period 250 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// }
// 
// 
// void Led(void * pvparam){
// 	portTickType Freq = 100;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 
// 		SREG = 0 ;
// 		/* If the Resource No One is Using so Raise a Flag to Use it **/
// 		if(ButtonStateFlag == 0){
// 			/**Disable Global Interrupt*/
// 
// 
// 			/*Raise the Flag */
// 			ButtonStateFlag = 1;
// 
// 			#if (FrogetGlobalInterrupt == 0)
// 			/**Enable Global Interrupt*/
// 			SREG = 128;
// 			#endif
// 
// 			if (ButtonState == 0){
// 				PORTB ^= 0x01;
// 				ButtonState = 1;
// 			}
// 
// 			/**Disable Global Interrupt*/
// 			SREG = 0;
// 
// 			/*Release the Flag */
// 			ButtonStateFlag = 0;
// 
// 			#if (FrogetGlobalInterrupt == 0)
// 			/**Disable Global Interrupt*/
// 			SREG = 128;
// 			#endif
// 		}
// 		/*Else Delay 10 Tick till the Resource is Free **/
// 		else {
// 			//vTaskDelay(10);
// 			//SREG = 128;/***************************************/
// 		}
// 
// 		/*Make the Task Periodic with Period 100 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// 
// }

/////////////////////////////////task8///////////////////////////////
// 
// 
// #include "SERVICES/Standard_Data_Types.h"
// 
// 
// #include <avr/io.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "FreeRTOSConfig.h"
// #include "semphr.h"
// 
// #ifndef NULL
// #define NULL (void *)0
// #endif
// 
// 
// void PushButton(void * pvparam);
// #define PushButtonPr (1)
// 
// void Led(void * pvparam);
// #define LedPr (2)
// 
// void init(void);
// 
// /*** Global Variable ****/
// u8 ButtonState = 1;
// 
// #define ForgetGiveSemaphore pdFALSE
// 
// xSemaphoreHandle ButtonSemaphore = NULL;
// 
// #define FrogetGlobalInterrupt 0  /* 0  for Nodefect 1 for Defect **/
// 
// int main(void)
// {
// 
// 	/* Creation of the Task*/
// 	xTaskHandle PushHandle  = NULL;
// 	xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);
// 
// 	xTaskHandle LedHandle = NULL ;
// 	xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);
// 
// 	/*Init Function*/
// 	init();
// 
// 	/*Create Semaphore for the Button */
// 	vSemaphoreCreateBinary(ButtonSemaphore);
// 
// 	/*start Scheduler */
// 	vTaskStartScheduler();
// 
// 
// 
// 	/*Never Enter Here */
// 	return 0;
// }
// 
// void init(void){
// 
// 	DDRB = 0xFF;
// 
// 	DDRC = 0x00;
// 
// 	PORTC = 0xFF;
// 
// }
// void PushButton(void * pvparam){
// 	portTickType Freq = 100;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if ((PINC & 0x01) == 0){
// 
// 			/* If the Resource No One is Using so Take the Semaphore  **/
// 			if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){
// 
// 				/*Change the State **/
// 				ButtonState = 0;
// 
// 				/**Give the Semaphore */
// 				#if ForgetGiveSemaphore == pdFALSE
// 				xSemaphoreGive(ButtonSemaphore);
// 				#endif
// 			}
// 			/*Else Delay 1000 Tick till the Resource is Free **/
// 			else {
// 				vTaskDelay(1000);
// 			}
// 		}
// 
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// }
// 
// 
// void Led(void * pvparam){
// 	portTickType Freq = 100;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){
// 			if (ButtonState == 0){
// 				PORTB ^= 0x01;
// 				ButtonState = 1;
// 			}
// 			/**Give the Semaphore */
// 			xSemaphoreGive(ButtonSemaphore);
// 		}
// 		/*Else Delay 1000 Tick till the Resource is Free **/
// 		else {
// 			vTaskDelay(1000);
// 		}
// 
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// 
// }
////////////////////////////task 9///////////////////////////


// 
// #include "SERVICES/Standard_Data_Types.h"
// 
// 
// #include <avr/io.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "FreeRTOSConfig.h"
// #include "semphr.h"
// 
// #ifndef NULL
// #define NULL (void *)0
// #endif
// 
// 
// void PushButton(void * pvparam);
// #define PushButtonPr (1)
// 
// void PushButton2(void * pvparam);
// #define PushButton2Pr (2)
// 
// 
// void Led(void * pvparam);
// #define LedPr (2)
// 
// void init(void);
// 
// /*** Global Variable ****/
// u8 ButtonState = 1;
// u8 ButtonState2 = 1;
// 
// 
// xSemaphoreHandle ButtonSemaphore = NULL;
// 
// xSemaphoreHandle Button2Semaphore = NULL;
// 
// int main(void)
// {
// 
// 	/* Creation of the Task*/
// 	xTaskHandle PushHandle  = NULL;
// 	xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);
// 
// 	/* Creation of the Task*/
// 	xTaskHandle PushHandle2  = NULL;
// 	xTaskCreate(PushButton2,(const signed char*)"Push Button 2",85,NULL,PushButton2Pr,&PushHandle2);
// 
// 
// 	xTaskHandle LedHandle = NULL ;
// 	xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);
// 
// 	/*Init Function*/
// 	init();
// 
// 	/*Create Semaphore for the Button */
// 	vSemaphoreCreateBinary(ButtonSemaphore);
// 
// 	/*Create Semaphore for the Button */
// 	vSemaphoreCreateBinary(Button2Semaphore);
// 
// 	/*start Scheduler */
// 	vTaskStartScheduler();
// 
// 
// 
// 	/*Never Enter Here */
// 	return 0;
// }
// 
// void init(void){
// 
// 	DDRB = 0xFF;
// 
// 	DDRC = 0x00;
// 
// 	PORTC = 0xFF;
// 
// }
// void PushButton(void * pvparam){
// 
// 	portTickType Freq = 100;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if ((PINC & 0x01) == 0){
// 
// 			/* If the Resource No One is Using so Take the Semaphore  **/
// 			if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){
// 
// 				vTaskDelay(1000);
// 
// 				while(pdFALSE == xSemaphoreTake(Button2Semaphore,100));
// 
// 				/*Change the State **/
// 				ButtonState = 0;
// 
// 				/**Give the Semaphore */
// 
// 				xSemaphoreGive(Button2Semaphore);
// 
// 				xSemaphoreGive(ButtonSemaphore);
// 
// 
// 			}
// 
// 		}
// 
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// }
// 
// 
// void PushButton2(void * pvparam){
// 	portTickType Freq = 100;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 		if ((PINC & 0x02) == 0){
// 
// 			/* If the Resource No One is Using so Take the Semaphore  **/
// 			if(pdTRUE == xSemaphoreTake(Button2Semaphore,100)){
// 
// 				vTaskDelay(1000);
// 
// 				while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100));
// 
// 				/*Change the State **/
// 				ButtonState2 = 0;
// 
// 				/**Give the Semaphore */
// 
// 				xSemaphoreGive(ButtonSemaphore);
// 
// 				xSemaphoreGive(Button2Semaphore);
// 
// 
// 			}
// 
// 			/*Make the Task Periodic with Period 50 Tick */
// 			vTaskDelayUntil(&Start,Freq);
// 		}
// 
// 	}
// }
// 
// 
// void Led(void * pvparam){
// 	portTickType Freq = 100;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 		/* if the Push Button is Pressed */
// 
// 		/* If the Resource No One is Using so Take the Semaphore  **/
// 		if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){
// 
// 			vTaskDelay(1000);
// 
// 			while(pdFALSE == xSemaphoreTake(Button2Semaphore,100));
// 
// 			if (ButtonState == 0 && ButtonState2 == 0){
// 				PORTB ^= 0x01;
// 				ButtonState = 1;
// 				ButtonState2 = 1;
// 			}
// 
// 			/**Give the Semaphore */
// 			xSemaphoreGive(Button2Semaphore);
// 			xSemaphoreGive(ButtonSemaphore);
// 
// 			/*Make the Task Periodic with Period 50 Tick */
// 			vTaskDelayUntil(&Start,Freq);
// 		}
// 
// 
// 	}
// }
///////////////////////////////////////////12///////////////////////////////////

// 
// 
// #include "SERVICES/Standard_Data_Types.h"
// 
// 
// 
// #include <avr/io.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "FreeRTOSConfig.h"
// #include "semphr.h"
// 
// #ifndef NULL
// #define NULL (void *)0
// #endif
// 
// void PushButton2(void * pvparam);
// #define PushButton2Pr (2)
// 
// 
// void Led(void * pvparam);
// #define LedPr (1)
// 
// void init(void);
// 
// xSemaphoreHandle ButtonSemaphore = NULL;
// /* Creation of the Task*/
// 
// 
// xTaskHandle LedHandle = NULL ;
// xTaskHandle PushHandle2  = NULL;
// 
// int main(void)
// {
// 
// 
// 
// 	/* Creation of the Task*/
// 
// 	xTaskCreate(PushButton2,(const signed char*)"Push Button 2",85,NULL,PushButton2Pr,&PushHandle2);
// 
// 
// 	xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);
// 
// 	/*Init Function*/
// 	init();
// 
// 	/*Create Semaphore for the Button */
// 	vSemaphoreCreateBinary(ButtonSemaphore);
// 	xSemaphoreTake(ButtonSemaphore,100);
// 
// 	/*start Scheduler */
// 	vTaskStartScheduler();
// 
// 
// 
// 	/*Never Enter Here */
// 	return 0;
// }
// 
// void init(void){
// 
// 	DDRB = 0xFF;
// 
// 	DDRC = 0x00;
// 
// 	PORTC = 0xFF;
// 
// }
// 
// 
// 
// void PushButton2(void * pvparam){
// 	portTickType Freq = 150;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 
// 		if((PINC & 0x01) == 0){
// 			xSemaphoreGive(ButtonSemaphore);
// 		}
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// }
// 
// 
// 
// void Led(void * pvparam){
// 	portTickType Freq = 150;
// 	portTickType Start = xTaskGetTickCount();
// 	while (1){
// 
// 		/* If the Resource No One is Using so Take the Semaphore  **/
// 		while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100));
// 		PORTB ^= 0x01;
// 		/*Make the Task Periodic with Period 50 Tick */
// 		vTaskDelayUntil(&Start,Freq);
// 	}
// 
// 
// }
// 
// 

// #include "SERVICES/Standard_Data_Types.h"
// #include <util/delay.h>
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/LCD/Inc/LCD_COMANDS.h"
// #include "HAL/LCD/Inc/LCD.h"
// #include "MCAL/GIE/Inc/GIE.h"
// #include "MCAL/USART/Inc/USART.h"
//
//#include <avr/io.h>
//#include "FreeRTOS.h"
//#include "task.h"
//#include "FreeRTOSConfig.h"
//#include "semphr.h"
//
//
//
//void LCD_TASK(void * pvparam);
//#define lcdPr 2
//xTaskHandle LCD_handel = NULL ;
//
//
//
//void recive_ISR_MAIN(void);
//
//QueueHandle_t recive_queue=NULL;
//
//SemaphoreHandle_t xSemaphore_store;
//
//
//
//u8 data_LCD=0;
//u8 data_isr=0;
// 
// LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
//	 .lcd_pins[1] = PIN_B1_ID_9,
//	 .lcd_pins[2] = PIN_B2_ID_10,
//	 .lcd_pins[3] = PIN_B3_ID_11,
//	 .lcd_pin_rs = PIN_A3_ID_3,
//	 .lcd_pin_e = PIN_A2_ID_2};
//
//
// stUSART_CFG_T usart={
//	 .BaudRate=9600,
//	 .datalegnth=USART_8_bit_legn,
//	 .stopbits=USART_Two_stopBit_CFG,
//	 .parity=USART_ParityDISABLE_CFG,
//	 .EUSART_INT_When_Recive=USART_INT_ENABLE_CFG,
//	 .EUSART_INT_When_Transmit=USART_INT_DISABLE_CFG,
//	 .EUSART_INT_When_DataRegEmpty=USART_INT_DISABLE_CFG,
//	 .Recive_ISR=recive_ISR_MAIN
// };
// 
// 
//
//int main(void)
//{
//
// 	Port_vidInit();
// 	GIE_INIT();
//	LCD_vidInit_4bit(&lcd);
// 	USART_INT_FULL(&usart);
//	 
//	 /* Create a counting semaphore that has a maximum count of 10 and an
//    initial count of 0. */
//    xSemaphore_store = xSemaphoreCreateCounting( 10, 1 );
//	/* Creation of the Task*/
//	
//	recive_queue= xQueueCreate(10,sizeof(u8));
//	xTaskCreate(LCD_TASK,(const signed char*)"lcd ",85,NULL,lcdPr,&LCD_handel);
//	
//	/*start Scheduler */
//	vTaskStartScheduler();
//
//	/*Never Enter Here */
//	return 0;
//}
//void LCD_TASK(void * pvparam)
//{
//	
//	portTickType Freq = 150;
//	portTickType Start = xTaskGetTickCount();
//	
//	
//	while (1){
//		if(pdTRUE ==xQueueReceive(recive_queue,&data_LCD,10))
//		{
//			LCD_vidDisplayChar_4bit(&lcd,data_LCD);
//			/*Make the Task Periodic with Period 50 Tick */
//			vTaskDelayUntil(&Start,Freq);
//		}
//
//	}
//}
//
// void recive_ISR_MAIN(void)
// {  
//	 
//	USART_vidReadData_Non_Bloking(&usart,&data_isr);
//	        /* See if we can obtain the semaphore.  If the semaphore is not
//        available wait 10 ticks to see if it becomes free. */
//        if( xSemaphoreTakeFromISR( xSemaphore_store, NULL ) == pdTRUE )
//        {
//            /* We were able to obtain the semaphore and can now access the
//            shared resource. */
//
//            xQueueSendFromISR(recive_queue,(void*)&data_isr,0);
//
//            /* We have finished accessing the shared resource.  Release the
//            semaphore. */
//            xSemaphoreGiveFromISR( xSemaphore_store,NULL );
//        }
//		else
//		{	
//		}
// }
 






























