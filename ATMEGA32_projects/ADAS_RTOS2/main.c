#include "SERVICES/Standard_Data_Types.h"

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "queue.h"
#include "event_groups.h"

#include <util/delay.h>
#include "SERVICES/Bit_Wise_Operations.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/Inc/LCD_COMANDS.h"
#include "HAL/LCD/Inc/LCD.h"
#include "HAL/KEY_PAD/Inc/KEY_PAD.h"

#include "MCAL/GIE/Inc/GIE.h"
#include "MCAL/ADC/Inc/ADC.h"
#include "MCAL/USART/Inc/USART.h"






void LCD_TASK(void * pvparam);
#define lcdPr 7
xTaskHandle LCD_handel = NULL ;

void KEYPAD_TASK(void * pvparam);
#define keypaddPr 8
xTaskHandle keypad_handel = NULL ;

void intCOMPONENt_TSTASK(void * pvparam);
#define  intPr 10
xTaskHandle int_handel=NULL;

void PASSword_TASK (void * pvparam);
#define  passPr 9
xTaskHandle PASSwordhandel=NULL;

void adc_task(void * pvparam);
#define adcpr 5
xTaskHandle adchandel=NULL;


//void recive_ISR_MAIN(void);

QueueHandle_t recive_queue=NULL;
QueueHandle_t keypad_queue=NULL;
EventGroupHandle_t  event_handeler=NULL;

SemaphoreHandle_t xSemaphore_LCD;

//u8 data_LCD=0;
u8 data_isr=0;
u8 keypadvlue='$';

KEY_PAD_ST keypad = {
    .key_pad_rows_pins[0] = DIO_C5_ID_21,
    .key_pad_rows_pins[1] = DIO_C4_ID_20,
    .key_pad_rows_pins[2] = DIO_C3_ID_19,
    .key_pad_rows_pins[3] = DIO_C2_ID_18,
    .key_pad_col_pins[0] = DIO_D7_ID_31,
    .key_pad_col_pins[1] = DIO_D6_ID_30,
    .key_pad_col_pins[2] = DIO_D5_ID_29,
    .key_pad_col_pins[3] = DIO_D3_ID_27,
};

LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
	 .lcd_pins[1] = PIN_B1_ID_9,
	 .lcd_pins[2] = PIN_B2_ID_10,
	 .lcd_pins[3] = PIN_B4_ID_12,
	 .lcd_pin_rs = PIN_A3_ID_3,
	 .lcd_pin_e = PIN_A2_ID_2};

stUSART_CFG_T usart={
	 .BaudRate=9600,
	 .datalegnth=USART_8_bit_legn,
	 .stopbits=USART_Two_stopBit_CFG,
	 .parity=USART_ParityDISABLE_CFG,
	 .EUSART_INT_When_Recive=USART_INT_ENABLE_CFG,
	 .EUSART_INT_When_Transmit=USART_INT_DISABLE_CFG,
	 .EUSART_INT_When_DataRegEmpty=USART_INT_DISABLE_CFG,
	 //.Recive_ISR=recive_ISR_MAIN
};


const u16 static_pass=1234;
u8 pass_state=0;
u16 loc_passcheck=0;

stADC_cfg_t adc={.Interrupt=ADC_INT_DISABLE,
				 .ADCprescaler=ADC_PRESCALER_DIV_ON_128,
				 .ADCvolt_refrance=AVCC
				 };
u16 ADC_READ=0;
int main(void)
{

   /* intialization part*/
	Port_vidInit();
	GIE_INIT();
	ADC_INIT(&adc);
	key_pad_Init(&keypad);
	USART_INT_FULL(&usart);
	


	 /* Create a counting semaphore that has a maximum count of 10 and an
     initial count of 0. */
     xSemaphore_LCD= xSemaphoreCreateBinary();
	
	
	/*creation of event group*/
	event_handeler=xEventGroupCreate();
	
	/* Creation of Queue*/
	recive_queue= xQueueCreate(10,sizeof(u8));
	keypad_queue=xQueueCreate(4,sizeof(u8));
	
	/* Creation of the Task*/
	xTaskCreate(intCOMPONENt_TSTASK,(const signed char*)"int",85,NULL,intPr,&int_handel);
	xTaskCreate(LCD_TASK,(const signed char*)"lcd ",85,NULL,lcdPr,&LCD_handel);
	xTaskCreate(KEYPAD_TASK,(const signed char*)"key ",85,NULL,keypaddPr,&keypad_handel);
	xTaskCreate(PASSword_TASK,(const signed char*)"pass ",85,NULL,passPr,&PASSwordhandel);
	xTaskCreate(adc_task,(const signed char*)"adc ",85,NULL,adcpr,&adchandel);
	

	/*start Scheduler */
	vTaskStartScheduler();

	/*Never Enter Here */
	return 0;
}
void LCD_TASK(void * pvparam)
{

	portTickType Freq = 150;
	portTickType Start = xTaskGetTickCount();


	while (1){
		//if(pdTRUE ==xQueueReceive(keypad_queue,&data_LCD,10))
		//{
		//	LCD_OS_vidDisplayChar_4bit(&lcd,data_LCD);
		//	/*Make the Task Periodic with Period 50 Tick */
			vTaskDelayUntil(&Start,Freq);
		//}
	}
}
void KEYPAD_TASK(void * pvparam)
{

	portTickType Freq = 250;
	portTickType Start = xTaskGetTickCount();
	static u8 counter=0;
	xSemaphoreTake(xSemaphore_LCD,portMAX_DELAY);
	LCD_OS_vidDisplayString_4bit(&lcd,"enter the pass:");
	xSemaphoreGive(xSemaphore_LCD);

	while (1)
	{
		if(counter<4)
		{
			key_OS_pad_Get_value(&keypad,&keypadvlue);
			if (keypadvlue!='$')
			{
				//storepass in keypad_queue
				xSemaphoreTake(xSemaphore_LCD,portMAX_DELAY);
				LCD_OS_vidDisplayChar_4bit(&lcd,keypadvlue);
				xSemaphoreGive(xSemaphore_LCD);
				xQueueSend(keypad_queue,(void*)&keypadvlue,10);		
				keypadvlue='$';
				counter++;
			}
			vTaskDelayUntil(&Start,Freq);
		}
		else
		{
			// inform pass check fn to start work
			xEventGroupSetBits(event_handeler,0x01);
	         // wait event gived from th pass check task
			xEventGroupWaitBits(event_handeler,0x02,pdTRUE,pdTRUE,portMAX_DELAY);
			if(pass_state==1)
		   {
			   LCD_OS_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
			   LCD_OS_vidDisplayString_4bit(&lcd,"      welcome ");
			   xEventGroupSetBits(event_handeler,0x04);
			   vTaskDelay(1000);
			   //if pass wright delete task else repeat
			   vTaskDelete(NULL);
		   }
		   else
		   {
			   //repeat
			   counter=0;
			   
			   
		   }	
		}
	}
}
void PASSword_TASK(void * pvparam)
{
	
	u8 temp=0;
	
	while (1)
	{
		
		xEventGroupWaitBits(event_handeler,0x01,pdTRUE ,pdTRUE,portMAX_DELAY);
		for(u8 i=0;i<4;i++)
		{
			if(pdTRUE ==xQueueReceive(keypad_queue,&temp,portMAX_DELAY))
			{
				loc_passcheck=loc_passcheck*10+(temp-48);
			}
		}
		if(loc_passcheck==static_pass)
		{
			pass_state=1;
		}
		if(pass_state==1)
		{
			xEventGroupSetBits(event_handeler,0x02);
			vTaskDelete(NULL);
		}
		else
		{
			loc_passcheck=0;
			LCD_OS_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
			LCD_OS_vidDisplayString_4bit(&lcd,"      wrong pass ");
			vTaskDelay(500);
			LCD_OS_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
			LCD_OS_vidDisplayString_4bit(&lcd," enter the pass:");
			xEventGroupSetBits(event_handeler,0x02);
			
		}
		
	}
}
void intCOMPONENt_TSTASK(void * pvparam)
{
	while(1)
	{
		xSemaphoreGive(xSemaphore_LCD);
		xSemaphoreTake(xSemaphore_LCD,portMAX_DELAY);
		LCD_OS_vidInit_4bit(&lcd);
		LCD_OS_vidDisplayString_4bit(&lcd,"     int done ");
		vTaskDelay(250);
		LCD_OS_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
		xSemaphoreGive(xSemaphore_LCD);
		vTaskDelete( NULL );
	}
	
}
void adc_task(void * pvparam)
{
	while(1)
	{
		xEventGroupWaitBits(event_handeler,0x04,pdFALSE,pdTRUE,portMAX_DELAY);
		ADC_GET_CONV_BOOLING(0,&ADC_READ);
		LCD_OS_vidDisplayNumber_4bit(&lcd,ADC_READ);
		vTaskDelay(500);
		LCD_OS_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);		
	}

	
}

//void recive_ISR_MAIN(void)
//{
//
//	USART_vidReadData_Non_Bloking(&usart,&data_isr);
//	        /* See if we can obtain the semaphore.  If the semaphore is not
//       available wait 10 ticks to see if it becomes free. */
//       if( xSemaphoreTakeFromISR( xSemaphore_store, NULL ) == pdTRUE )
//       {
//           /* We were able to obtain the semaphore and can now access the
//           shared resource. */
//
//           xQueueSendFromISR(recive_queue,(void*)&data_isr,0);
//
//           /* We have finished accessing the shared resource.  Release the
//           semaphore. */
//           xSemaphoreGiveFromISR( xSemaphore_store,NULL );
//       }
//		else
//		{
//		}
//}
