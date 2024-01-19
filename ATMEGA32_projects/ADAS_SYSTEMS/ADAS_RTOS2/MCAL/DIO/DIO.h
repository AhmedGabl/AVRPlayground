/*
* DIO.h
*
* Created: 10/20/2023 10:48:02 PM
*  Author: ahmed radwan
*/


#ifndef DIO_H_
#define DIO_H_

/*************************macros section***********************************/


/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/


/*********************************** user defined data types section end ***********************************/
typedef enum{
	DIO_PIN_LOW,
	DIO_PIN_HIGH
}DIO_tenuLogicLevel;

typedef enum{
	E_DIO_PIN_OUT_OF_RANGE,
	E_DIO_PORT_OUT_OF_RANGE,
	E_DIO_OK,
	E_DIO_WRONG_LOGIC,
	E_DIO_NULL_PTR
}Dio_tenuErrorStatus;

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}Dio_tenuPorts;

typedef enum{
	DIO_A0_ID_0,
	DIO_A1_ID_1,
	DIO_A2_ID_2,
	DIO_A3_ID_3,
	DIO_A4_ID_4,
	DIO_A5_ID_5,
	DIO_A6_ID_6,
	DIO_A7_ID_7,
	DIO_B0_ID_8,
	DIO_B1_ID_9,
	DIO_B2_ID_10,
	DIO_B3_ID_11,
	DIO_B4_ID_12,
	DIO_B5_ID_13,
	DIO_B6_ID_14,
	DIO_B7_ID_15,
	DIO_C0_ID_16,
	DIO_C1_ID_17,
	DIO_C2_ID_18,
	DIO_C3_ID_19,
	DIO_C4_ID_20,
	DIO_C5_ID_21,
	DIO_C6_ID_22,
	DIO_C7_ID_23,
	DIO_D0_ID_24,
	DIO_D1_ID_25,
	DIO_D2_ID_26,
	DIO_D3_ID_27,
	DIO_D4_ID_28,
	DIO_D5_ID_29,
	DIO_D6_ID_30,
	DIO_D7_ID_31
}Dio_tenuPins;


/*****************function prototypes section*******************************************/
Dio_tenuErrorStatus Dio_enuWriteChannel (Dio_tenuPins Copy_u8ChannelId, DIO_tenuLogicLevel Copy_u8Level);
Dio_tenuErrorStatus Dio_enuReadChannel  (Dio_tenuPins Copy_u8ChannelId, ptr_u8 Add_pu8ChannelLevel);
Dio_tenuErrorStatus Dio_enuWritePort    (Dio_tenuPorts Copy_u8PortId, u8 Copy_u8Value);
Dio_tenuErrorStatus Dio_enuReadPort     (Dio_tenuPorts Copy_u8PortId, ptr_u8 Add_pu8PortValue);
Dio_tenuErrorStatus Dio_enuFlipChannel  (Dio_tenuPins Copy_u8ChannelId);
/*****************function prototypes section end*******************************************/





#endif /* DIO_H_ */