/*
 * PORT.c
 *
 * Created: 10/20/2023 9:06:13 PM
 *  Author: ahmed radwan
 */ 
#include "../../SERVICES/Standard_Data_Types.h"
#include "../../SERVICES/Bit_Wise_Operations.h"
#include "PORT.h"
#include "PORT_PRIV.h"
#include "PORT_CFG.h"

static volatile u8* DDRR_REG_ARR[]={&DDRA,&DDRB,&DDRC,&DDRD};
static volatile u8* PORT_REG_ARR[]={&PORTA,&PORTB,&PORTC,&PORTD};
	
/**
 * @brief initialize the direction to all pins (INPUT OR OUTPUT)
 */
void Port_vidInit(void){

	/*undefine macros for redefinition with sitable value (0 or 1) will be writen in the DDR register*/
	#undef PIN_CFG_MODE_OUTPUT_LOW
	#undef PIN_CFG_MODE_OUTPUT_HIGH
	#undef PIN_CFG_MODE_INPUT_FLOATING
	#undef PIN_CFG_MODE_INPUT_PULLUP
	#define PIN_CFG_MODE_OUTPUT_LOW         1
	#define PIN_CFG_MODE_OUTPUT_HIGH        1
	#define PIN_CFG_MODE_INPUT_FLOATING     0
	#define PIN_CFG_MODE_INPUT_PULLUP       0

	/*assign values to the DDR register*/
	DDRA=CONC(PIN_A7_ID_7_CFG,PIN_A6_ID_6_CFG,PIN_A5_ID_5_CFG,PIN_A4_ID_4_CFG,PIN_A3_ID_3_CFG,PIN_A2_ID_2_CFG,PIN_A1_ID_1_CFG,PIN_A0_ID_0_CFG);
	
	DDRB=CONC(PIN_B7_ID_15_CFG,PIN_B6_ID_14_CFG,PIN_B5_ID_13_CFG,PIN_B4_ID_12_CFG,PIN_B3_ID_11_CFG,PIN_B2_ID_10_CFG,PIN_B1_ID_9_CFG,PIN_B0_ID_8_CFG);
	DDRC=CONC(PIN_C7_ID_23_CFG,PIN_C6_ID_22_CFG,PIN_C5_ID_21_CFG,PIN_C4_ID_20_CFG,PIN_C3_ID_19_CFG,PIN_C2_ID_18_CFG,PIN_C1_ID_17_CFG,PIN_C0_ID_16_CFG);
	DDRD=CONC(PIN_D7_ID_31_CFG,PIN_D6_ID_30_CFG,PIN_D5_ID_29_CFG,PIN_D4_ID_28_CFG,PIN_D3_ID_27_CFG,PIN_D2_ID_26_CFG,PIN_D1_ID_25_CFG,PIN_D0_ID_24_CFG);

	/*undefine macros for redefinition with sitable value (0 or 1) will be writen in the DDR register*/
	#undef PIN_CFG_MODE_OUTPUT_LOW
	#undef PIN_CFG_MODE_OUTPUT_HIGH
	#undef PIN_CFG_MODE_INPUT_FLOATING
	#undef PIN_CFG_MODE_INPUT_PULLUP
	#define PIN_CFG_MODE_OUTPUT_LOW         0
	#define PIN_CFG_MODE_OUTPUT_HIGH        1
	#define PIN_CFG_MODE_INPUT_FLOATING     2
	#define PIN_CFG_MODE_INPUT_PULLUP       3
}
/**
 * @brief initialize the direction to specific pin (INPUT OR OUTPUT) 
 * @param Copy_pin_no index for the specific pin 
 * @param Copy_pin_direction value of the direction @ref PIN_tenuDirection 
 * @return Error_st of the function
 *         (E_OK) : the function done successfully
 *         (E_PIN_OUT_OF_RANGE): the function has issue in input pin id out of range 
 *         (E_WRONG_DIRECTION): the function has issue in the given value of the direction 
 */
Port_tenuErrorStatus Port_enuSetpinDirection(u8 Copy_pin_no,PIN_tenuDirection Copy_pin_direction ){
	Port_tenuErrorStatus Error_st=E_OK;
	if (Copy_pin_no>31||Copy_pin_no<0)
	{
		Error_st=E_PIN_OUT_OF_RANGE;
	}
	else
	{
		u8 Local_Port_vlue=Copy_pin_no/8; //get the port no
		u8 Local_Port_pin=Copy_pin_no%8; //get the pin no in the port

		if (Copy_pin_direction==PIN_MODE_OUTPUT)//check if the pin output
		{
			//SET THE PIN TO BE OUTPUT
			SET_BIT(*DDRR_REG_ARR[Local_Port_vlue],Local_Port_pin);
		}
		else if(Copy_pin_direction==PIN_MODE_INPUT)//check if the pin input
		{
			//SET THE PIN TO BE INPUT
			CLR_BIT(*DDRR_REG_ARR[Local_Port_vlue],Local_Port_pin);
		}
		else{
			//undefined status
			Error_st=E_WRONG_DIRECTION;

		}
	}

	return Error_st;

}

/**
 * @brief configure the pin mode 
 * @param Copy_pin_no index for the specific pin 
 * @param Copy_pin_mode value of the direction @ref PIN_tenuMode 
 * @return Error_st of the function
 *         (E_OK) : the function done successfully
 *         (E_PIN_OUT_OF_RANGE): the function has issue in input pin id out of range 
 *         (E_WRONG_MODE): the function has issue in the given value of the mode 
 */
Port_tenuErrorStatus Port_enuSetpinMode(u8 Copy_pin_no,PIN_tenuMode Copy_pin_mode ){
	Port_tenuErrorStatus Error_st=E_OK;
	if (Copy_pin_no>31||Copy_pin_no<0)
	{
		Error_st=E_PIN_OUT_OF_RANGE;
	}
	else
	{
		u8 Local_Port_vlue=Copy_pin_no/8; //get the port no
		u8 Local_Port_pin=Copy_pin_no%8; //get the pin no in the port
		switch (Copy_pin_mode)
		{
			case PIN_MODE_OUTPUT_LOW:
			// SET THE PIN OUTPUT LOW
			SET_BIT(*DDRR_REG_ARR[Local_Port_vlue],Local_Port_pin);
			CLR_BIT(*PORT_REG_ARR[Local_Port_vlue],Local_Port_pin);
			break;
			case PIN_MODE_OUTPUT_HIGH:
			// SET THE PIN OUTPUT HIGH
			SET_BIT(*DDRR_REG_ARR[Local_Port_vlue],Local_Port_pin);
			SET_BIT(*PORT_REG_ARR[Local_Port_vlue],Local_Port_pin);
			break;
			case PIN_MODE_INPUT_FLOATING:
			CLR_BIT(*DDRR_REG_ARR[Local_Port_vlue],Local_Port_pin);// MAKE THE PIN INPUT FLOATING
			CLR_BIT(*PORT_REG_ARR[Local_Port_vlue],Local_Port_pin);
			break;
			case PIN_MODE_INPUT_PULLUP:
			CLR_BIT(*DDRR_REG_ARR[Local_Port_vlue],Local_Port_pin);// MAKE THE PIN INPUT
			SET_BIT(*PORT_REG_ARR[Local_Port_vlue],Local_Port_pin);//CONFIGUARE IT AS PULLUP
			break;
			default:
			Error_st=E_WRONG_MODE;
			break;
		}

	}
	return Error_st;
}


