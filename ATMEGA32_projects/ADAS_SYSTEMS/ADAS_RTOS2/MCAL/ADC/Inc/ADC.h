/*
 * ADC.h
 *
 * Created: 10/23/2023 11:21:02 AM
 *  Author: ahmed radwan
 */ 


#ifndef ADC_H_
#define ADC_H_

/*************************macros section***********************************/
#define ADC_SET_INTERNAL_v_Refrance()           SET_BIT(ADMUX,6)
#define ADC_SET_V_Refrance(refrance)            ADMUX|=(refrance<<6)

#define ADC_DATA_LEFT_SHIFT()		    SET_BIT(ADMUX,5)
#define ADC_DATA_RIFHT_SHIFT()		    CLR_BIT(ADMUX,5)

#define ADC_SELECT_CHANNEL(channel)    ASSIGN_L_NIB(ADMUX,channel)

#define ADC_ENABLE()					SET_BIT(ADCSRA,7)
#define ADC_DISABLE()					CLR_BIT(ADCSRA,7)

//#define ADC_PRESCALER_128()                   ADCSRA|=0x07
#define ADC_SET_PRESCALER(prescaler)            ADCSRA|=prescaler

#define ADC_START_CONV()					SET_BIT(ADCSRA,6)
#define ADC_STOP_CONV()						CLR_BIT(ADCSRA,6)

#define ADC_CLEAR_FLAG()						CLR_BIT(ADCSRA,4)
#define ADC_CONV_DONE()						    GET_BIT(ADCSRA,4)

#define ADC_ENABLE_INT()                        SET_BIT(ADCSRA,3)
#define ADC_DISABLE_INT()                        CLR_BIT(ADCSRA,3)


/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/
 typedef enum {
	 ADC0,
	 ADC1,
	 ADC2,
	 ADC3,
	 ADC4,
	 ADC5,
	 ADC6,
	 ADC7
 }ADC_enuTChanel;
 typedef enum {
	 AREF,
	 AVCC,
	 Internal=3
 }ADC_enuTvoltage_referance;
  typedef enum {
	  LEFT_ASSIGN,
	  RIGHT_ASSIGN
  }ADC_enuTDatadirection;
  
typedef enum {
	ADC_PRESCALER_DIV_ON_2=1,
	ADC_PRESCALER_DIV_ON_4,
	ADC_PRESCALER_DIV_ON_8,
	ADC_PRESCALER_DIV_ON_16,
	ADC_PRESCALER_DIV_ON_32,
	ADC_PRESCALER_DIV_ON_64,
	ADC_PRESCALER_DIV_ON_128
}ADC_enuTPrescaler;
	
 typedef enum {
   ADC_INT_ENABLE,
   ADC_INT_DISABLE
}ADC_enuTINT_CFG;
 
 typedef struct {
	 ADC_enuTvoltage_referance ADCvolt_refrance;
	 ADC_enuTPrescaler  ADCprescaler;
	 ADC_enuTDatadirection ADC_result_dir;
	 ADC_enuTINT_CFG Interrupt;
	 CALL_BACK_FN_TYPE ADC_isr;
 }stADC_cfg_t;
 

/*********************************** user defined data types section end ***********************************/



/*****************function prototypes section*******************************************/

//void ADC_INIT(void);
void ADC_INIT(stADC_cfg_t*ADCown);
void ADC_DEINIT(void);
void ADC_SET_Callback(void (*ADC_CALLBack_ISR)(void));
void ADC_GET_CONV_ISR(ADC_enuTChanel channel,u16* result);
void ADC_GET_CONV_BOOLING(ADC_enuTChanel,ptr_u16 result);


/*****************function prototypes section end*******************************************/






#endif /* ADC_H_ */