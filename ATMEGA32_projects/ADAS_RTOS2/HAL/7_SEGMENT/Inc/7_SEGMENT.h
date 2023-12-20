/*
 * _7_SEGMENT.h
 *
 * Created: 10/21/2023 1:45:37 AM
 *  Author: ahmed radwan
 */ 


#ifndef _7_SEGMENT_H_
#define _7_SEGMENT_H_


/*************************macros section***********************************/


/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/
typedef enum {
	SevenSegment_ERROR_PIN_ID,
	SevenSegment_E_OK,
	SevenSegment_ERROR_NULL_PTR,
	SevenSegment_ERROR_VALUE
	
}SevenSegment_tenuErrorStatus;
typedef struct{
	Dio_tenuPins Segment_PIN1;
	Dio_tenuPins Segment_PIN2;
	Dio_tenuPins Segment_PIN3;
	Dio_tenuPins Segment_PIN4;
	}SevenSegment_tst;
	typedef struct{
		Dio_tenuPins Segment1_active;
		Dio_tenuPins Segment2_active;
		Dio_tenuPins Segment3_active;
		Dio_tenuPins Segment4_active;
	}SevenSegment4pins_tst;

/*********************************** user defined data types section end ***********************************/

SevenSegment_tenuErrorStatus SevenSegment_INIT(SevenSegment_tst* sevensegment);
SevenSegment_tenuErrorStatus SevenSegment_write(SevenSegment_tst* sevensegment,u8 Copy_u8value);
//SevenSegment_tenuErrorStatus SevenSegment_Swaper(SevenSegment4_tst* active_pins);

/*****************function prototypes section*******************************************/


/*****************function prototypes section end*******************************************/





#endif /* _7_SEGMENT_H_ */