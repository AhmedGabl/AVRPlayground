/*
 * TIMER0_CFG.h
 *
 * Created: 10/24/2023 11:20:08 AM
 *  Author: ahmed radwan
 */ 


#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_
/*
	****options*****
	NORMAL
	PWM
	CTC
	FASTPWM
*/
#define TIMER0_MODE_CFG       NORMAL


/*
	****options*****
	NO_PRE_SCALER=1
	PRE_SCALER_8
	PRE_SCALER_64
	PRE_SCALER_256
	PRE_SCALER_1024
	EXTERNAL_CLOCK_FALLING_EDGE
	EXTERNAL_CLOCK_RISING_EDG
	*/
#define TIMER0_PRESCALER_CFG  PRE_SCALER_1024

/************enter u8 value ******/
#define TIMER0_PRELOAD_CFG    (u8)240

/************enter u8 value ******/
#define TIMER0_COMPARE_VALUE_CFG (u8)(0)

/************PWM compare match PIN Action ******/
/*
	NON_INVERTING
	INVERTING
*/
#define TIMER0_PWM_MODE                 NIN_INVERTING


#define ENABLE 1
#define DISABLE 0

#define TIMER0_OVERFLOW_INT_CFG             ENABLE
#define TIMER0_COMPARE_MODE_INT_CFG         DISABLE   






#endif /* TIMER0_CFG_H_ */