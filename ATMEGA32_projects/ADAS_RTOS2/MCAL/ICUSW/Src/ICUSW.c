/*
 * ICUSW.c
 *
 * Created: 10/27/2023 12:45:04 PM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../SERVICES/Bit_Wise_Operations.h"
#include "../../EXTI/EXTI_PRIV.h"
#include "../../EXTI/EXTI_CFG.h"
#include "../../EXTI/EXTI.h"
#include "../../TIMER0/Inc/TIMER0_PRIV.h"
#include "../../TIMER0/Inc/TIMER0_CFG.h"
#include "../../TIMER0/Inc/TIMER0.h"
#include "../Inc/ICUSW.h"

static u32 Global_EXINT_flag=0;
static u32 Global_on_time_value=0;
static u32 Global_period_time_value=0;
static u32 Global_duty_value=0;
static u32 Global_over_flow_counter=0;


static void ICUSW_EXTI_ISR (void);
static void ICUSW_timer0_ISR (void);

static void EXTI_SET_RISING(void);
static void EXTI_SET_FALING(void);

void ICUSW_voidEnable(void)
{
	TIMER0_INT();	
	TIMER0_SET_OVRRFLOW_CALLBACK(ICUSW_timer0_ISR);
	EXI_INT(EXTI_INT0,EXTI_MODE_RISING_EDGE,ICUSW_EXTI_ISR);
}
void ICUSW_voidDisable(void)
{
	EXTI_INT0_Interrupt_Disable();
	TIMER0_DISABLE();
}

void ICUSW_u8Get_period(f32* totalperiod)
{
	*totalperiod=(f32)Global_period_time_value*TIMER0_PRESCALER_CFG/F_CPU*100000;
}
void ICUSW_u8Get_dutycycle(f32* duty)
{
	*duty=(f32)Global_on_time_value/Global_period_time_value;
}
void ICUSW_u8Get_On_period(f32* onperiod)
{
	*onperiod=(f32)Global_on_time_value*TIMER0_PRESCALER_CFG/F_CPU*100000;
}

static void ICUSW_EXTI_ISR (void){
	static u32 LOC_garbdge_ticks=0;
	static u32 LOC_third_ticks=0;
	static u32 LOC_on_time=0;
	static u32 LOC_period_time=0;
	if(Global_EXINT_flag==0)
	{   
		//first rising
		Global_over_flow_counter=0;
		LOC_garbdge_ticks=TCNT0;// garbadge ticks
		Global_EXINT_flag=1;
		EXTI_SET_FALING();
	}
	else if(Global_EXINT_flag==1)
	{
		//second edge 
		LOC_on_time=TCNT0+(Global_over_flow_counter*255)-LOC_garbdge_ticks;
		Global_EXINT_flag=2;
		EXTI_SET_RISING();
	}
	else if(Global_EXINT_flag==2)
	{
		//third edge 
		LOC_third_ticks=TCNT0;
		LOC_period_time=LOC_third_ticks+(Global_over_flow_counter*255)-LOC_garbdge_ticks;
		Global_EXINT_flag=1;
		EXTI_SET_FALING();
		Global_on_time_value=LOC_on_time;//results
		Global_period_time_value=LOC_period_time;//results
		Global_over_flow_counter=0;
		LOC_garbdge_ticks=LOC_third_ticks;
	}

}
static void ICUSW_timer0_ISR (void){
	Global_over_flow_counter++;

}
static void EXTI_SET_FALING(void)
{
	MCUCR|=0x02;
}
static void EXTI_SET_RISING(void)
{

	MCUCR|=0x03;			
}