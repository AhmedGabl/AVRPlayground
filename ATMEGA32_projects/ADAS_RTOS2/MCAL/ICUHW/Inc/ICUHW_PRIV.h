/*
 * ICUHW_PRIV.h
 *
 * Created: 10/28/2023 3:40:28 AM
 *  Author: ahmed radwan
 */ 


#ifndef ICUHW_PRIV_H_
#define ICUHW_PRIV_H_


#define TCCR1A   (*((volatile ptr_u8)0X4F))
#define TCNT1H   (*((volatile ptr_u8)0X4D))
#define TCNT1L   (*((volatile ptr_u8)0X4C))
#define TIFR     (*((volatile ptr_u8)0X58))




#endif /* ICUHW_PRIV_H_ */