/*
 * TIMER0.h
 *
 * Created: 10/24/2023 11:19:00 AM
 *  Author: ahmed radwan
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/*********************************** FN like macro section   ***********************************/

#define TIMER0_DISABLE()				(TCCR0&=0xf8)
#define TIMER0_MODE_SET_NORMAL() do{\
								    CLR_BIT(TCCR0,6);\
									CLR_BIT(TCCR0,3);\
									}while(0)
											
#define TIMER0_MODE_SET_PWM() do{\
									SET_BIT(TCCR0,6);\
									CLR_BIT(TCCR0,3);\
								    }while(0)   
									
#define TIMER0_MODE_SET_CTC() do{\
									SET_BIT(TCCR0,3);\
									CLR_BIT(TCCR0,6);\
								}while(0)

#define TIMER0_MODE_SET_PWM_FAST()							do{\
																SET_BIT(TCCR0,3);\
																SET_BIT(TCCR0,6);\
															}while(0)

#define TIMER0_NORMAL_COMPARE_OUTPUT_PIN_TOGGEL()	    	SET_BIT(TCCR0,4);
#define TIMER0_NORMAL_COMPARE_OUTPUT_PIN_CLEAR()			SET_BIT(TCCR0,5);
#define TIMER0_NORMAL_COMPARE_OUTPUT_PIN_SET()			    (TCCR0|=0x30);
 				
#define PWM_MODE_SET_INVERTING()							do{\
																SET_BIT(TCCR0,4);\
																SET_BIT(TCCR0,5);\
															}while(0)
#define PWM_MODE_SET_NININVERTING()							(SET_BIT(TCCR0,5))

#define PWM_MOD_PHASE_CORRECT_SET_UP_CLEAR_DOWN()				do{\
																SET_BIT(TCCR0,4);\
																SET_BIT(TCCR0,5);\
															}while(0)

#define PWM_MOD_PHASE_CORRECT_CLEAR_UP_SET_DOWN()    		do{\
																CLR_BIT(TCCR0,4);\
																SET_BIT(TCCR0,5);\
															}while(0)

#define SLECT_CLOCK_SOURCE(SOURCE)							(TCCR0|=SOURCE)
#define SET_PRELOAD(PRELOAD)								(TCNT0|=PRELOAD)
#define SET_PRESCALER(PRESCALER)							(TCCR0|=PRESCALER)
#define SET_COMPARE_VALUE(VALUE)							(OCR0=VALUE)

#define TIMER0_COMPARE_MATCH_INT_ENABLE()					(SET_BIT(TIMSK,1))
#define TIMER0_OVERFLOW_INT_ENABLE()						(SET_BIT(TIMSK,0))

#define TIMER0_COMPARE_MATCH_INT_DISABLE()					(CLR_BIT(TIMSK,1))
#define TIMER0_OVERFLOW_INT_DISABLE()						(CLR_BIT(TIMSK,0))

#define TIMER0_CLEAR_COMPARE_MATCH_INT_FLAG()				(CLR_BIT(TIFR,1))
#define TIMER0_CLEAR_OVERFLOW_INT_FLAG()					(CLR_BIT(TIFR,0))

/*********************************** FN like macro section  end ***********************************/


/*********************************** user defined data types section ***********************************/

typedef enum {
	NO_PRE_SCALER=1,
	PRE_SCALER_8,
	PRE_SCALER_64,
	PRE_SCALER_256,
	PRE_SCALER_1024,
	EXTERNAL_CLOCK_FALLING_EDGE,
	EXTERNAL_CLOCK_RISING_EDG
	}timer0_clock_source_t;

typedef enum {
	NORMAL,
	PWM,
	CTC,
	FASTPWM
}timer0_modes_t;
typedef enum {
NIN_INVERTING,
INVERTING
}timer0_pwm_modes_t;
/*********************************** user defined data types section  end ***********************************/

/*****************function prototypes section  *******************************************/

void TIMER0_INT(void);
void TIMER0_SET_OVRRFLOW_CALLBACK(void(*timer0_overflow_isr)(void));
void TIMER0_SET_COMPMATCH_CALLBACK(void(*timer0_compmatch_isr)(void));
void TIMER0_PWM_SET_DUTYCYCLE(u8 duty);

/*****************function prototypes section end *******************************************/



#endif /* TIMER0_H_ */