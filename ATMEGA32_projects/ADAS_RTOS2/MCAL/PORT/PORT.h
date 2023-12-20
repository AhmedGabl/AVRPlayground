/*
 * PORT.h
 *
 * Created: 10/20/2023 9:05:41 PM
 *  Author: ahmed radwan
 */ 


#ifndef PORT_H_
#define PORT_H_


/*************************macros section***********************************/
#define PIN_CFG_MODE_OUTPUT_LOW         0
#define PIN_CFG_MODE_OUTPUT_HIGH        1
#define PIN_CFG_MODE_INPUT_FLOATING     2
#define PIN_CFG_MODE_INPUT_PULLUP       3
/******************* port A *********************/
#define PIN_A0_ID_0 0
#define PIN_A1_ID_1 1
#define PIN_A2_ID_2 2
#define PIN_A3_ID_3 3
#define PIN_A4_ID_4 4
#define PIN_A5_ID_5 5
#define PIN_A6_ID_6 6
#define PIN_A7_ID_7 7

/******************* port B *********************/

#define PIN_B0_ID_8 8
#define PIN_B1_ID_9 9
#define PIN_B2_ID_10 10
#define PIN_B3_ID_11 11
#define PIN_B4_ID_12 12
#define PIN_B5_ID_13 13
#define PIN_B6_ID_14 14
#define PIN_B7_ID_15 15

/******************* port C *********************/

#define PIN_C0_ID_16 16
#define PIN_C1_ID_17 17
#define PIN_C2_ID_18 18
#define PIN_C3_ID_19 19
#define PIN_C4_ID_20 20
#define PIN_C5_ID_21 21
#define PIN_C6_ID_22 22
#define PIN_C7_ID_23 23

/******************* port D *********************/

#define PIN_D0_ID_24 24
#define PIN_D1_ID_25 25
#define PIN_D2_ID_26 26
#define PIN_D3_ID_27 27
#define PIN_D4_ID_28 28
#define PIN_D5_ID_29 29
#define PIN_D6_ID_30 30
#define PIN_D7_ID_31 31

/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/

typedef enum {
	E_PIN_OUT_OF_RANGE,
	E_OK,
	E_WRONG_DIRECTION,
	E_WRONG_MODE
} Port_tenuErrorStatus;
typedef enum {
	PIN_MODE_INPUT,
	PIN_MODE_OUTPUT
	
} PIN_tenuDirection;
typedef enum {
	PIN_MODE_OUTPUT_LOW ,
	PIN_MODE_OUTPUT_HIGH ,
	PIN_MODE_INPUT_FLOATING ,
	PIN_MODE_INPUT_PULLUP ,
PIN_MODE_INPUT_PULLDOWN }PIN_tenuMode;
/*********************************** user defined data types section end ***********************************/



/*****************function prototypes section*******************************************/
void Port_vidInit(void);
Port_tenuErrorStatus Port_enuSetpinDirection(u8 Copy_pin_no,PIN_tenuDirection Copy_pin_direction);
Port_tenuErrorStatus Port_enuSetpinMode(u8 Copy_pin_no, PIN_tenuMode Copy_pin_mode);
/*****************function prototypes section end*******************************************/




#endif /* PORT_H_ */