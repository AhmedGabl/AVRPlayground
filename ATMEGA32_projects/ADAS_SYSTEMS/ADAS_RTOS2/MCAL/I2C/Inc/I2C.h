/*
 * I2C.h
 *
 * Created: 10/30/2023 10:42:50 AM
 *  Author: ahmed radwan
 */ 


#ifndef I2C_H_
#define I2C_H_



/*********************************** user defined FN like macro ***********************************/

#define I2C_ENABLE()						 (SET_BIT(TWCR,2))
#define I2C_DISABLE()						 (SET_BIT(TWCR,2))


#define I2C_INT_FLAG_CLEAR()				 (SET_BIT(TWCR,TWINT))// clear the interrupt flag 

#define I2C_ENABLE_ACK()					 (SET_BIT(TWCR,TWEA))// ENABLE ACK BIT after match address ,recive data ,genaral call 
#define I2C_DIABLE_ACK()					 (CLR_BIT(TWCR,TWEA))// DISABLE ACK BIT 

#define I2C_INT_ENABLE()					 (SET_BIT(TWCR,TWIE))
#define I2C_INT_DIABLE()					 (CLR_BIT(TWCR,TWIE))


#define I2C_SEND_START()					TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN)
#define I2C_SEND_STOP()						TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO)

#define I2C_WAIT_THEFLAG()					while (!(TWCR & (1<<TWINT)))
#define I2C_START_ACTION()					TWCR = (1<<TWINT) | (1<<TWEN)

#define I2C_SET_PRESCALER(PRESCALER)		(TWCR|=PRESCALER)
/*********************************** user defined FN like macro END ***********************************/



/*********************************** user defined data types section  ***********************************/
typedef enum{
	I2C_EOK,
	I2C_ENOK,
	I2C_NULL_PTR
	}I2C_ERROR_ST;
	
typedef enum{
	I2C_MASTER,
    I2C_SLAVE
	}I2C_enMode_cfg_t;
	
typedef enum{
	I2C_INTERUPT_ENABLE,
	I2C_INTERUPT_DISABLE
	}I2C_enuIterrupt_cfg_t;
	
typedef enum{
	I2C_Prescaler_1,
	I2C_Prescaler_4,
	I2C_Prescaler_16,
	I2C_Prescaler_64
	}I2C_enuPrescaler_cfg_t;
	
 typedef struct { 
	 I2C_enMode_cfg_t I2C_Mode;
	 u8 I2C_Slave_Adress;
	 I2C_enuIterrupt_cfg_t I2C_INTERRUPT_cfg ;
	 I2C_enuPrescaler_cfg_t I2C_PRESCALR_CFG;
	 u8 I2C_clock_FREQ_TWBR_value;
	 CALL_BACK_FN_TYPE I2C_ISR;
 }I2C_stCFG_t;
/*********************************** user defined data types section end ***********************************/


/*
*          use this formula to get the values of TWBR & TWPS:
*          SCL_frequency = F_CPU/(16+2*TWBR*4^TWPS)
*/

/*****************function prototypes section*******************************************/

I2C_ERROR_ST I2C_Init(I2C_stCFG_t*I2c);
I2C_ERROR_ST I2C_DeInit(I2C_stCFG_t*I2c);
void I2C_SendStart(void);
void I2C_SendRepetedStart(void);
void I2C_SendStop(void);
void I2C_SEND_Adress_WRITE(u8 aderss);
void I2C_SEND_Adress_READ(u8 aderss);
void I2C_SEND_DATA(u8 data);
void I2C_SEND_FULL_FRAME_WRITE(u8 aderss,u8 data);
void I2C_SEND_FULL_FRAME_READ_NACK(u8 aderss,u8* data);
/*****************function prototypes section end *******************************************/





#endif /* I2C_H_ */