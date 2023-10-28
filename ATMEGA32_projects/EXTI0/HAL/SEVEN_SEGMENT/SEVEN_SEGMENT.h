/*
 * SEVEN_SEGMENT.h
 *
 *  Created on: Oct 21, 2023
 *      Author: AhmedAbogabl
 */

#ifndef HAL_SEVEN_SEGMENT_H_
#define HAL_SEVEN_SEGMENT_H_

#include "../../MCAL/DIO/DIO_interface.h"

#define SevSegA PB_0
#define SevSegB PB_1
#define SevSegC PB_2
#define SevSegD PB_4

#define SevSeg1_Enable PA_3

#define SevSeg2_Enable PA_2
//#define C_Anode 0
//
//#define C_Cathode 1

typedef enum {
	C_Anode_7Seg,
	C_Cathode_7Seg
}SevenSeg_Type;


typedef enum{
	SEG_1 = PA_3,
	SEG_2 = PA_2,
	SEG_3 = PB_5,
	SEG_4 = PB_6
}SegNumber;


void SevenSeg_Send(u8 num1,u8 num2,u8 num3 , u8 num4);//SevenSeg_Type type ,

void SevenSeg_SendOneSeg(u8 number); //SevenSeg_Type type ,

void SevenSeg_SegEnable(SegNumber seg);

void SevenSeg_SegDisable(SegNumber seg);

void SevenSeg_Init(void);
#endif /* HAL_SEVEN_SEGMENT_H_ */
