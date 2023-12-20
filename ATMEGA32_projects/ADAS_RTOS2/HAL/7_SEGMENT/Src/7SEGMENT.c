/*
 * _7SEGMENT.c
 *
 * Created: 10/21/2023 1:46:08 AM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../MCAL/PORT/PORT.h"
#include "../../../MCAL/DIO/DIO.h"
#include "../Inc/7_SEGMENT.h"
SevenSegment_tenuErrorStatus SevenSegment_INIT(SevenSegment_tst* sevensegment)
{
	SevenSegment_tenuErrorStatus segment_FN_E_ST=SevenSegment_E_OK;
	if(NULL==sevensegment)
	{
		segment_FN_E_ST=SevenSegment_ERROR_NULL_PTR;
	}
	else
	{
		Port_enuSetpinDirection(sevensegment->Segment_PIN1,PIN_MODE_OUTPUT);
		Port_enuSetpinDirection(sevensegment->Segment_PIN2,PIN_MODE_OUTPUT);
		Port_enuSetpinDirection(sevensegment->Segment_PIN3,PIN_MODE_OUTPUT);
		Port_enuSetpinDirection(sevensegment->Segment_PIN4,PIN_MODE_OUTPUT);
	}
	return segment_FN_E_ST;
}
SevenSegment_tenuErrorStatus SevenSegment_write(SevenSegment_tst* sevensegment,u8 Copy_u8value)
{
	SevenSegment_tenuErrorStatus segment_FN_E_ST=SevenSegment_E_OK;
	if(NULL==sevensegment)
	{
		segment_FN_E_ST=SevenSegment_ERROR_NULL_PTR;
	}
	else if (Copy_u8value>9)
	{
		segment_FN_E_ST=SevenSegment_ERROR_VALUE;
	}
	else
	{
		Dio_enuWriteChannel(sevensegment->Segment_PIN1,(Copy_u8value&0x01));
		Dio_enuWriteChannel(sevensegment->Segment_PIN2,((Copy_u8value>>1)&0x01));
		Dio_enuWriteChannel(sevensegment->Segment_PIN3,((Copy_u8value>>2)&0x01));
		Dio_enuWriteChannel(sevensegment->Segment_PIN4,((Copy_u8value>>3)&0x01));
	}
	return segment_FN_E_ST;
}
// used in using four 7 segment  together
// SevenSegment_tenuErrorStatus SevenSegment_Swaper(SevenSegment4_tst* active_pins){
//  	SevenSegment_tenuErrorStatus segment_FN_E_ST=SevenSegment_E_OK;
// 	if(NULL==active_pins)
// 	{
// 		segment_FN_E_ST=SevenSegment_ERROR_NULL_PTR;
// 	}
// 	else
// 	{
// 		Dio_enuWriteChannel(active_pins->Segment1_active,1);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		_delay_ms(20);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,1);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		_delay_ms(20);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,1);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		_delay_ms(20);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,1);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		Dio_enuWriteChannel(active_pins->Segment1_active,0);
// 		_delay_ms(20);
// 
// 	}
// 	return segment_FN_E_ST;
// 	
// }