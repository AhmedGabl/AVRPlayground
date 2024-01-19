/*
 * USART_PRIV.h
 *
 * Created: 10/28/2023 11:15:24 AM
 *  Author: ahmed radwan
 */ 


#ifndef USART_PRIV_H_
#define USART_PRIV_H_

 
#define UDR			(*((volatile ptr_u8)0x2C))
#define UCSRA		(*((volatile ptr_u8)0x2B))
#define UCSRB		(*((volatile ptr_u8)0x2A))
#define UCSRC		(*((volatile ptr_u8)0x40))////
#define UBRRH		(*((volatile ptr_u8)0x40))////
#define UBRRL		(*((volatile ptr_u8)0x29))






#endif /* USART_PRIV_H_ */