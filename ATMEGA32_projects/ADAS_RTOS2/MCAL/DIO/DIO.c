/*
 * DIO.c
 *
 * Created: 10/20/2023 10:47:30 PM
 *  Author: ahmed radwan
 */ 
#include "../../SERVICES/Standard_Data_Types.h"
#include "../../SERVICES/Bit_Wise_Operations.h"
#include "../PORT/PORT_PRIV.h"
#include "DIO.h"
#include "DIO_PRIV.h"
#include "DIO_CFG.h"

static volatile u8* PORT_REG_ARR[]={&PORTA,&PORTB,&PORTC,&PORTD};// arr of ptr contain the addresses of ports reg 
static volatile u8* PIN_REG_ARR[]={&PINA,&PINB,&PINC,&PIND};// arr of ptr contain the addresses of pins reg 
	
/**
 * @brief write the input logic on the pin 
 * @param Copy_u8ChannelId:		index for the specific pin 
 * @param DIO_tenuLogicLevel:	logic of the pin
		 @ref DIO_tenuLogicLevel 
 * @return Error_st of the function
 *          E_DIO_OK:  the function done successfully 
 *         	E_DIO_PIN_OUT_OF_RANGE: invalid pin number
 */
Dio_tenuErrorStatus Dio_enuWriteChannel (Dio_tenuPins Copy_u8ChannelId, DIO_tenuLogicLevel Copy_u8Level){
	Dio_tenuErrorStatus DIO_FN_E_ST=E_DIO_OK;
	if (Copy_u8ChannelId>31||Copy_u8ChannelId<0)
	{
		DIO_FN_E_ST=E_DIO_PIN_OUT_OF_RANGE;
	}
	else
	{
		u8 DIO_Local_Port=Copy_u8ChannelId/8; //get the port no
		u8 DIO_Local_Pin=Copy_u8ChannelId%8; //get the pin no in the port
		switch(Copy_u8Level)
		{
			case DIO_PIN_HIGH :
			SET_BIT(*PORT_REG_ARR[DIO_Local_Port],DIO_Local_Pin);
			break;
			case DIO_PIN_LOW:
			CLR_BIT(*PORT_REG_ARR[DIO_Local_Port],DIO_Local_Pin);
			break;
			default:
			DIO_FN_E_ST=E_DIO_WRONG_LOGIC;
			break;
		}
		
	}
	return DIO_FN_E_ST;
	
}
/**
 * @brief read the logic value of the pin 
 * @param Copy_u8ChannelId:		index for the specific pin 
 * @param Add_pu8ChannelLevel: ptr recive the logic of the pin
 * @return Error_st of the function
 *          E_DIO_OK:  the function done successfully 
 *         	E_DIO_PIN_OUT_OF_RANGE: invalid pin number
 *			E_DIO_NULL_PTR: NULL ptr passed to the function 
 */
Dio_tenuErrorStatus Dio_enuReadChannel  (Dio_tenuPins Copy_u8ChannelId, ptr_u8 Add_pu8ChannelLevel){
	Dio_tenuErrorStatus DIO_FN_E_ST=E_DIO_OK;
	if (Copy_u8ChannelId>31||Copy_u8ChannelId<0)
	{
		DIO_FN_E_ST=E_DIO_PIN_OUT_OF_RANGE;
	}
	if(NULL==Add_pu8ChannelLevel)
	{
		DIO_FN_E_ST=E_DIO_NULL_PTR;
	}
	if(DIO_FN_E_ST==E_DIO_OK)
	{
		u8 DIO_Local_Port=Copy_u8ChannelId/8; //get the port no
		u8 DIO_Local_Pin=Copy_u8ChannelId%8; //get the pin no in the port

		*Add_pu8ChannelLevel=GET_BIT(*PIN_REG_ARR[DIO_Local_Port],DIO_Local_Pin);	
	}
	return DIO_FN_E_ST;
}
/**
 * @brief write  logic value on specific port 
 * @param Copy_u8PortId:		index for the specific port 
 * @param Copy_u8Value:			the vlue will write on the port
 * @return Error_st of the function
 *          E_DIO_OK:  the function done successfully 
 *         	E_DIO_PORT_OUT_OF_RANGE: invalid port number
 */
Dio_tenuErrorStatus Dio_enuWritePort    (Dio_tenuPorts Copy_u8PortId, u8 Copy_u8Value)
{
	Dio_tenuErrorStatus DIO_FN_E_ST=E_DIO_OK;
	if (Copy_u8PortId>3||Copy_u8PortId<0)
	{
		DIO_FN_E_ST=E_DIO_PORT_OUT_OF_RANGE;
	}
	else
	{

		ASSIGN_REG(*PORT_REG_ARR[Copy_u8PortId],Copy_u8Value);
	}
	return DIO_FN_E_ST;	
}
/**
 * @brief read the logic value on specific port 
 * @param Copy_u8PortId:			index for the specific port 
 * @param Add_pu8PortValue:			ptr will recive the value of the port
 * @return Error_st of the function
 *          E_DIO_OK:  the function done successfully 
 *         	E_DIO_PORT_OUT_OF_RANGE: invalid port number
 *			E_DIO_NULL_PTR: NULL ptr passed to the function
 */
Dio_tenuErrorStatus Dio_enuReadPort     (Dio_tenuPorts Copy_u8PortId, ptr_u8 Add_pu8PortValue){
	Dio_tenuErrorStatus DIO_FN_E_ST=E_DIO_OK;
	if (Copy_u8PortId>3||Copy_u8PortId<0)
	{
		DIO_FN_E_ST=E_DIO_PORT_OUT_OF_RANGE;
	}
	if(NULL==Add_pu8PortValue)
	{
		DIO_FN_E_ST=E_DIO_NULL_PTR;
	}
	if(DIO_FN_E_ST==E_DIO_OK)
	{
		*Add_pu8PortValue=*PIN_REG_ARR[Copy_u8PortId];
	}
	return DIO_FN_E_ST;
}

/**
 * @brief flip the logic of the pin 
 * @param Copy_u8ChannelId:		index for the specific pin 
 * @return Error_st of the function
 *          E_DIO_OK:  the function done successfully 
 *         	E_DIO_PIN_OUT_OF_RANGE: invalid pin number
 */
Dio_tenuErrorStatus Dio_enuFlipChannel  (Dio_tenuPins Copy_u8ChannelId)
{
	Dio_tenuErrorStatus DIO_FN_E_ST=E_DIO_OK;
	if (Copy_u8ChannelId>31||Copy_u8ChannelId<0)
	{
		DIO_FN_E_ST=E_DIO_PIN_OUT_OF_RANGE;
	}
	else
	{
		u8 DIO_Local_Port=Copy_u8ChannelId/8; //get the port no
		u8 DIO_Local_Pin=Copy_u8ChannelId%8; //get the pin no in the port	
		TGL_BIT(*PORT_REG_ARR[DIO_Local_Port],DIO_Local_Pin);
	}
	return DIO_FN_E_ST;
}


