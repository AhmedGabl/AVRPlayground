/*
 * PORT_PRIV.h
 *
 * Created: 10/20/2023 9:05:16 PM
 *  Author: ahmed radwan
 */ 


#ifndef PORT_PRIV_H_
#define PORT_PRIV_H_

#define PORTA      (*((volatile ptr_u8)0X3B))
#define DDRA       (*((volatile ptr_u8)0X3A))
#define PINA       (*((volatile ptr_u8)0X39))

#define PORTB      (*((volatile ptr_u8)0X38))
#define DDRB	   (*((volatile ptr_u8)0X37))
#define PINB	   (*((volatile ptr_u8)0X36))

#define PORTC      (*((volatile ptr_u8)0X35))
#define DDRC	   (*((volatile ptr_u8)0X34))
#define PINC	   (*((volatile ptr_u8)0X33))


#define PORTD	   (*((volatile ptr_u8)0X32))
#define DDRD	   (*((volatile ptr_u8)0X31))
#define PIND	   (*((volatile ptr_u8)0X30))


#endif /* PORT_PRIV_H_ */