/*
 * USART.h
 *
 * Created: 10/28/2023 11:15:04 AM
 *  Author: ahmed radwan
 */ 


#ifndef USART_H_
#define USART_H_

/************************* fn like macros section***********************************/


#define  USART_Receive_Complete()		GET_BIT(UCSRA,7)
#define  USART_Transmit_Complete()		GET_BIT(UCSRA,6)
#define  USART_Data_Register_Empty()	GET_BIT(UCSRA,5)

#define  RX_INT_ENABLE()				SET_BIT(UCSRB,7)
#define  TX_INT_ENABLE()				SET_BIT(UCSRB,6)
#define  EMPTY_INT_ENABLE()				SET_BIT(UCSRB,5)


#define  RX_MODE_ENABLE()				   SET_BIT(UCSRB,4)
#define  TX_MODE_ENABLE()				   SET_BIT(UCSRB,3)


#define  UCSRC_ACCCES()                    SET_BIT(UCSRC,7)
#define  UBRRH_ACCCES()                    CLR_BIT(UCSRC,7)


#define  USART_ASYN_SLECT()                CLR_BIT(UCSRC,6)


#define SET_BAUD_RATE()					     (UBRRL|=0x67)
#define Stop_Bit_Selec()				     SET_BIT(UCSRC,3)

#define Stop_1Bit_Select()                   CLR_BIT(UCSRC,3)
#define Stop_2Bit_Select()                   SET_BIT(UCSRC,3)

#define slect_8bit()                           (UCSRC|=0x03)
#define slect_bit_no(no)                       do{\
												  (UCSRC&=0xf9);\
												  (UCSRC|=(no<<1));\
												  }while(0)



/************************* fn like macros section END ***********************************/


/*********************************** user defined data types section ***********************************/

typedef enum {
	USART_INT_DISABLE_CFG,
	USART_INT_ENABLE_CFG
}enuUSART_INT_CFG_T;

typedef enum {
	USART_5_bit_legn,
	USART_6_bit_legn,
	USART_7_bit_legn,
	USART_8_bit_legn,
	USART_9_bit_legn=7,
}enuUSART_DataLegnth_CFG_T;

typedef enum {
	USART_ParityDISABLE_CFG,
	USART_Even_Parity_CFG=2,
	USART_Odd_Parity_CFG
}enuUSART_Parity_CFG_T;

typedef enum {
	USART_one_stopBit_CFG,
	USART_Two_stopBit_CFG
}enuUSART_noStopBits_CFG_T;

typedef enum {
	USART_ENOK,
	USART_EOK,
	USART_NULLPTR
}enuUSART_ERRORSTATUS_T;

typedef struct {
	u32 BaudRate;
	enuUSART_Parity_CFG_T parity;
	enuUSART_noStopBits_CFG_T stopbits;
	enuUSART_DataLegnth_CFG_T datalegnth;
	enuUSART_INT_CFG_T EUSART_INT_When_Recive;
	enuUSART_INT_CFG_T EUSART_INT_When_Transmit;
	enuUSART_INT_CFG_T EUSART_INT_When_DataRegEmpty;
	CALL_BACK_FN_TYPE  Recive_ISR;
	CALL_BACK_FN_TYPE  Transmit_ISR;
	CALL_BACK_FN_TYPE  DataRegEmpty_ISR;
}stUSART_CFG_T;

/*********************************** user defined data types section end ***********************************/


/*****************function prototypes section*******************************************/
enuUSART_ERRORSTATUS_T USART_INT_FULL(stUSART_CFG_T*usart);
enuUSART_ERRORSTATUS_T USART_vidRECIVE_Bloking(stUSART_CFG_T*usart,u16 *data);
enuUSART_ERRORSTATUS_T USART_vidTRANSMIT_Blokind(stUSART_CFG_T*usart,u16 data);
enuUSART_ERRORSTATUS_T USART_vidReadData_Non_Bloking(stUSART_CFG_T*usart,u16 *data);
//enuUSART_ERRORSTATUS_T USART_INT(void);
/*****************function prototypes section end*******************************************/











#endif /* USART_H_ */