/*
 * TIMER0_PRIV.h
 *
 * Created: 10/24/2023 11:20:31 AM
 *  Author: ahmed radwan
 */ 


#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

#define TCCR0	(*((volatile ptr_u8)0x53))
#define TCNT0	(*((volatile ptr_u8)0x52))
#define OCR0	(*((volatile ptr_u8)0x5c))
#define TIMSK	(*((volatile ptr_u8)0x59))
#define TIFR	(*((volatile ptr_u8)0x58))

#endif /* TIMER0_PRIV_H_ */