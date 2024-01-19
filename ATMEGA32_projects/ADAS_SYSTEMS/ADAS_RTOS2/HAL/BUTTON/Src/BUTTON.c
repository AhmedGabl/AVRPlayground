/*
 * BUTTON.c
 *
 * Created: 10/21/2023 1:42:36 AM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../MCAL/PORT/PORT.h"
#include "../../../MCAL/DIO/DIO.h"
#include "../Inc/BUTTON.h"
Button_tenuErrorStatus Button_enuInit(const Button_tst* button){
	Button_tenuErrorStatus BUTTON_FN_E_ST=BUTTON_E_OK;
	if(NULL==button)
	{
		BUTTON_FN_E_ST=BUTTON_ERROR_NULL_PTR;
	}	
	else if ((button->button_pin_id >31)||(button->button_pin_id <0))
	{
		BUTTON_FN_E_ST=BUTTON_ERROR_PIN_ID;
	}
	if(BUTTON_FN_E_ST==BUTTON_E_OK)
	{
	Port_enuSetpinDirection(button->button_pin_id,PIN_MODE_INPUT);
	}
	return BUTTON_FN_E_ST;
}
Button_tenuErrorStatus Button_enuRead(const Button_tst* button,Button_tenuState* status)
{
	Button_tenuErrorStatus BUTTON_FN_E_ST=BUTTON_E_OK;
	Button_tenuState Local_Status;
	if(NULL==button||NULL==status)
	{
		BUTTON_FN_E_ST=BUTTON_ERROR_NULL_PTR;
	}
	else if ((button->button_pin_id >31)||(button->button_pin_id <0))
	{
		BUTTON_FN_E_ST=BUTTON_ERROR_PIN_ID;
	}
	if(BUTTON_FN_E_ST==BUTTON_E_OK)
	{
		//to solve denouncing problem
		for(u8 denouncing_counter=0;denouncing_counter<10;denouncing_counter++)
		{
			Dio_enuReadChannel(button->button_pin_id,(ptr_u8)&Local_Status);
		}
		if(button->conection==BUTTON_PULL_DOWN)
		{
			switch (Local_Status)
			{
				case 1:
				*status=BUTTON_PRESSED;
				break;
				case 0:
				*status=BUTTON_NOT_PRESSED;
				break;
				default:
				break;
			}
		}
		else if(button->conection==BUTTON_PULL_UP)
		{
			switch (Local_Status)
			{
				case 1:
				*status=BUTTON_NOT_PRESSED;
				break;
				case 0:
				*status=BUTTON_PRESSED;
				break;
				default:
				break;
			}
		}		
	}
	return BUTTON_FN_E_ST;
}
