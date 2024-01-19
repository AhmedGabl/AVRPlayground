/*
 * PORT_CFG.h
 *
 * Created: 10/20/2023 9:06:01 PM
 *  Author: ahmed radwan
 */ 


#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/*
* ****************OPTION AVILABEL***************
* PIN_CFG_MODE_OUTPUT_LOW       
* PIN_CFG_MODE_OUTPUT_HIGH      
* PIN_CFG_MODE_INPUT_FLOATING   
* PIN_CFG_MODE_INPUT_PULLUP     
*
*
*/


/*******************PORTA******************/
#define PIN_A0_ID_0_CFG               PIN_CFG_MODE_INPUT_FLOATING
#define PIN_A1_ID_1_CFG               PIN_CFG_MODE_INPUT_FLOATING
#define PIN_A2_ID_2_CFG               PIN_CFG_MODE_INPUT_FLOATING
#define PIN_A3_ID_3_CFG               PIN_CFG_MODE_INPUT_FLOATING
#define PIN_A4_ID_4_CFG               PIN_CFG_MODE_OUTPUT_HIGH
#define PIN_A5_ID_5_CFG               PIN_CFG_MODE_OUTPUT_HIGH
#define PIN_A6_ID_6_CFG               PIN_CFG_MODE_OUTPUT_HIGH
#define PIN_A7_ID_7_CFG               PIN_CFG_MODE_INPUT_FLOATING

/*******************PORTB******************/

#define PIN_B0_ID_8_CFG               PIN_CFG_MODE_OUTPUT_HIGH
#define PIN_B1_ID_9_CFG               PIN_CFG_MODE_INPUT_FLOATING
#define PIN_B2_ID_10_CFG              PIN_CFG_MODE_INPUT_PULLUP//int2
#define PIN_B3_ID_11_CFG              PIN_CFG_MODE_INPUT_FLOATING
#define PIN_B4_ID_12_CFG              PIN_CFG_MODE_INPUT_FLOATING
#define PIN_B5_ID_13_CFG              PIN_CFG_MODE_INPUT_FLOATING
#define PIN_B6_ID_14_CFG              PIN_CFG_MODE_INPUT_FLOATING//
#define PIN_B7_ID_15_CFG              PIN_CFG_MODE_OUTPUT_HIGH//red led

/*******************PORTC******************/

#define PIN_C0_ID_16_CFG             PIN_CFG_MODE_INPUT_FLOATING
#define PIN_C1_ID_17_CFG             PIN_CFG_MODE_INPUT_FLOATING
#define PIN_C2_ID_18_CFG             PIN_CFG_MODE_OUTPUT_LOW//ROW4
#define PIN_C3_ID_19_CFG             PIN_CFG_MODE_OUTPUT_LOW//ROW3
#define PIN_C4_ID_20_CFG             PIN_CFG_MODE_OUTPUT_LOW//ROW2
#define PIN_C5_ID_21_CFG             PIN_CFG_MODE_OUTPUT_LOW//ROW 1
#define PIN_C6_ID_22_CFG             PIN_CFG_MODE_OUTPUT_LOW
#define PIN_C7_ID_23_CFG             PIN_CFG_MODE_OUTPUT_LOW

/*******************PORTD******************/

#define PIN_D0_ID_24_CFG              PIN_CFG_MODE_INPUT_FLOATING
#define PIN_D1_ID_25_CFG              PIN_CFG_MODE_INPUT_FLOATING
#define PIN_D2_ID_26_CFG              PIN_CFG_MODE_INPUT_PULLUP //int0
#define PIN_D3_ID_27_CFG              PIN_CFG_MODE_INPUT_PULLUP//int1 // COL4
#define PIN_D4_ID_28_CFG              PIN_CFG_MODE_INPUT_FLOATING
#define PIN_D5_ID_29_CFG              PIN_CFG_MODE_OUTPUT_LOW//COL3
#define PIN_D6_ID_30_CFG              PIN_CFG_MODE_OUTPUT_LOW//COL2
#define PIN_D7_ID_31_CFG              PIN_CFG_MODE_INPUT_PULLUP//COL1



#endif /* PORT_CFG_H_ */