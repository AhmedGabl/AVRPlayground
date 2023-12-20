/*
 * KEY_PAD.c
 *
 * Created: 10/22/2023 12:19:24 PM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include <util/delay.h>
#include "../../../MCAL/PORT/PORT.h"
#include "../../../MCAL/DIO/DIO.h"
#include "../Inc/KEY_PAD.h"
u8 Keypad[NO_OF_ROWS][NO_OF_COLUMS]={{'7','8','9','/'},
									 {'4','5','6','*'},
									 {'1','2','3','-'},
									 {'c','0','=','+'}};
KEY_PAD_tenuErrorStatus key_pad_Init(KEY_PAD_ST*key_pad)
{
	KEY_PAD_tenuErrorStatus key_pad_status=KEY_PAD_E_OK;
	if(NULL==key_pad)
	{
		key_pad_status=KEY_PAD_NULL_PTR;
	}
	else
	{
		for(u8 row_counter=0; row_counter<NO_OF_ROWS;row_counter++)
		{
			Port_enuSetpinMode(key_pad->key_pad_rows_pins[row_counter],PIN_MODE_OUTPUT_HIGH);
		}	
		for(u8 col_counter=0; col_counter<NO_OF_COLUMS;col_counter++ )
		{
			Port_enuSetpinMode(key_pad->key_pad_col_pins[col_counter],PIN_CFG_MODE_INPUT_PULLUP);
		}	
	}
	return key_pad_status;
}
KEY_PAD_tenuErrorStatus key_pad_Get_value(KEY_PAD_ST*key_pad,ptr_u8 value)
{
	KEY_PAD_tenuErrorStatus key_pad_status=KEY_PAD_E_OK;
	u8 locla_value=1;
	if(NULL==key_pad)
	{
		key_pad_status=KEY_PAD_NULL_PTR;
	}
	else
	{
		for(u8 row_counter=0;row_counter<NO_OF_ROWS;row_counter++)
		{
			Dio_enuWriteChannel(key_pad->key_pad_rows_pins[row_counter],DIO_PIN_HIGH);//make sure that all rows high in the first
		}
		_delay_ms(10);
		for(u8 row_counter=0;row_counter<NO_OF_ROWS;row_counter++)
		{
			Dio_enuWriteChannel(key_pad->key_pad_rows_pins[row_counter],DIO_PIN_LOW);
			
			for(u8 col_counter=0;col_counter<NO_OF_COLUMS;col_counter++)
			{
				//_delay_ms(500);
				Dio_enuReadChannel(key_pad->key_pad_col_pins[col_counter],&locla_value);
				if(locla_value==0)
				{
					*value=Keypad[row_counter][col_counter];
					key_pad_status=KEY_PRESSED;
				}
			}
			Dio_enuWriteChannel(key_pad->key_pad_rows_pins[row_counter],DIO_PIN_HIGH);
		}
	}
	return key_pad_status;
}
KEY_PAD_tenuErrorStatus key_OS_pad_Get_value(KEY_PAD_ST*key_pad,ptr_u8 value)
{
	KEY_PAD_tenuErrorStatus key_pad_status=KEY_PAD_E_OK;
	u8 locla_value=1;
	if(NULL==key_pad)
	{
		key_pad_status=KEY_PAD_NULL_PTR;
	}
	else
	{
		for(u8 row_counter=0;row_counter<NO_OF_ROWS;row_counter++)
		{
			Dio_enuWriteChannel(key_pad->key_pad_rows_pins[row_counter],DIO_PIN_HIGH);//make sure that all rows high in the first
		}
		vTaskDelay(10);
		for(u8 row_counter=0;row_counter<NO_OF_ROWS;row_counter++)
		{
			Dio_enuWriteChannel(key_pad->key_pad_rows_pins[row_counter],DIO_PIN_LOW);
			
			for(u8 col_counter=0;col_counter<NO_OF_COLUMS;col_counter++)
			{
				//_delay_ms(500);
				Dio_enuReadChannel(key_pad->key_pad_col_pins[col_counter],&locla_value);
				if(locla_value==0)
				{
					*value=Keypad[row_counter][col_counter];
					key_pad_status=KEY_PRESSED;
				}
			}
			Dio_enuWriteChannel(key_pad->key_pad_rows_pins[row_counter],DIO_PIN_HIGH);
		}
	}
	return key_pad_status;
}
