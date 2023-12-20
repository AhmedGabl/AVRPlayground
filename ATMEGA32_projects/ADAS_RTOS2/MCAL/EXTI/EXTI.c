/*
 * GIE.c
 *
 * Created: 10/22/2023 3:29:07 PM
 *  Author: ahmed radwan
 */ 
#include "../../SERVICES/Standard_Data_Types.h"
#include "../../SERVICES/Bit_Wise_Operations.h"
#include "../PORT/PORT.h"
#include "EXTI_PRIV.h"
#include "EXTI_CFG.h"
#include "EXTI.h"
static void (*EXTI_APP_FN[3])(void);
EXTI_tenuError_Staus EXI_INT(EXTI_tenuSource Exti,EXTI_tenuMode mode,void (*call_back)(void) )
{
	EXTI_tenuError_Staus EXINT_Status=EXINT_EOK;
	switch (Exti)
	{
		case EXTI_INT0:
			Port_enuSetpinMode(PIN_D2_ID_26,PIN_CFG_MODE_INPUT_PULLUP);
			EXTI_INT0_Interrupt_Disable();
			EXTI_INT0_Interrupt_Flag_clear();
			if(mode==EXTI_MODE_LOW_LEVEL)
			{
				CLR_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
			}
			else if(mode==EXTI_MODE_LOGICAL_CHANGE)
			{
				
				SET_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
			}
			else if(mode==EXTI_MODE_FALING_EDGE)
			{
				CLR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
			}
			else
			{
				//rising
				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
			}
			EXTI_APP_FN[0]=call_back;
			EXTI_INT0_Interrupt_Enable();
			break;
		case EXTI_INT1:
			Port_enuSetpinMode(PIN_D3_ID_27,PIN_CFG_MODE_INPUT_PULLUP);
			EXTI_INT1_Interrupt_Disable();
			EXTI_INT1_Interrupt_Flag_clear();
			if(mode==EXTI_MODE_LOW_LEVEL)
			{
				CLR_BIT(MCUCR,2);
				CLR_BIT(MCUCR,3);
			}
			else if(mode==EXTI_MODE_LOGICAL_CHANGE)
			{
				SET_BIT(MCUCR,2);
				CLR_BIT(MCUCR,3);
				
			}
			else if(mode==EXTI_MODE_FALING_EDGE)
			{
				CLR_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
			}
			else
			{
				SET_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
			}
			EXTI_APP_FN[1]=call_back;
			EXTI_INT1_Interrupt_Enable();
			break;			
		case EXTI_INT2:
			Port_enuSetpinMode(PIN_B2_ID_10,PIN_CFG_MODE_INPUT_PULLUP);
			EXTI_INT2_Interrupt_Disable();
			EXTI_INT2_Interrupt_Flag_clear();
			if(mode==EXTI_MODE_FALING_EDGE)
			{
				CLR_BIT(MCUCSR,6);
			}
			else
			{
				SET_BIT(MCUCSR,6);
			}
			EXTI_APP_FN[2]=call_back;
		    EXTI_INT2_Interrupt_Enable();
			break;
		}
		return EXINT_Status;
}


/**********************ISR for the EXTI in the vector table*************/
void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	EXTI_APP_FN[0]();
}

void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	EXTI_APP_FN[1]();
}

void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	EXTI_APP_FN[2]();
}