/*
 * ADC_PRIV.h
 *
 * Created: 10/23/2023 11:21:50 AM
 *  Author: ahmed radwan
 */ 


#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define ADMUX			(*((volatile u8*) 0x27))
#define ADCSRA			(*((volatile u8*) 0x26))
#define ADCH			(*((volatile u8*) 0x25))
#define ADCL			(*((volatile u8*) 0x24))
#define ADC_DATA		(*((volatile u16*) 0x24))



#endif /*ADC_PRIV_H_ */