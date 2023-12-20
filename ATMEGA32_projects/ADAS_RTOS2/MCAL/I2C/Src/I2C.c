/*
 * I2C.c
 *
 * Created: 10/30/2023 10:38:49 AM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../SERVICES/Bit_Wise_Operations.h"
#include <util/delay.h>
#include "../../PORT/PORT.h"
#include "../../DIO/DIO.h"
#include "../Inc/I2C_PRIV.h"
#include "../Inc/I2C_CFG.h"
#include "../Inc/I2C.h"
static CALL_BACK_FN_TYPE I2C_CALL_BACK_FN_ISR=NULL;





I2C_ERROR_ST I2C_Init(I2C_stCFG_t*I2c)
{
   I2C_ERROR_ST I2S_ERROR_STATE=I2C_EOK;
  if(NULL==I2c)
  {
	  I2S_ERROR_STATE=I2C_NULL_PTR;
  }
  else
  {
	  I2C_DISABLE();
	 if(I2c->I2C_Mode==I2C_MASTER)
	 {
		
		TWAR=((I2c->I2C_Slave_Adress)<<1);
		I2C_SET_PRESCALER(I2c->I2C_PRESCALR_CFG);
		TWBR=I2c->I2C_clock_FREQ_TWBR_value;

	 }
	 else if (I2c->I2C_Mode==I2C_SLAVE)
	 {
		 TWAR=((I2c->I2C_Slave_Adress)<<1);
		 I2C_ENABLE_ACK();
	 }
	if(I2c->I2C_INTERRUPT_cfg==I2C_INTERUPT_ENABLE)
	{
		I2C_INT_ENABLE();
		I2C_CALL_BACK_FN_ISR=I2C_CALL_BACK_FN_ISR;	
	}
	I2C_ENABLE();
  }
  	return I2S_ERROR_STATE;

}
I2C_ERROR_ST I2C_DeInit(I2C_stCFG_t*I2c)
{
  I2C_ERROR_ST I2S_ERROR_STATE=I2C_EOK;
  if(NULL==I2c)
  {
	  I2S_ERROR_STATE=I2C_NULL_PTR;
  }
  else
  {
	
	I2C_DISABLE();
	
	if(I2c->I2C_INTERRUPT_cfg==I2C_INTERUPT_ENABLE)
	{
		I2C_INT_DIABLE();
		I2C_CALL_BACK_FN_ISR=I2C_CALL_BACK_FN_ISR;	
	}
  }
}
void I2C_SendStart(void)
{
	I2C_SEND_START();
	I2C_WAIT_THEFLAG();
	_delay_ms(10);
}
void I2C_SendRepetedStart(void)
{
		I2C_SEND_START();
		I2C_WAIT_THEFLAG();
		_delay_ms(10);
}
void I2C_SendStop(void)
{
	I2C_SEND_STOP();
	_delay_ms(10);
}
void I2C_SEND_Adress_WRITE(u8 address)
{
	TWDR=address<<1;
	I2C_START_ACTION();
	I2C_WAIT_THEFLAG();
	_delay_ms(10);
}
void I2C_SEND_Adress_READ(u8 address)
{
	I2C_ENABLE_ACK();
	TWDR=((address<<1)|0x01);
	I2C_START_ACTION();
	I2C_WAIT_THEFLAG();
	_delay_ms(10);
}
void I2C_SEND_DATA(u8 data){
	TWDR=data;
	I2C_START_ACTION();
	I2C_WAIT_THEFLAG();
	_delay_ms(10);
}
void I2C_SEND_FULL_FRAME_WRITE(u8 aderss,u8 data)
{
	I2C_SendStart();
	I2C_SEND_Adress_WRITE(aderss);
	I2C_SEND_DATA(data);
	I2C_SendStop();
}
void I2C_SEND_FULL_FRAME_READ(u8 aderss,u8* data)
{
	I2C_SendStart();
	I2C_SEND_Adress_READ(aderss);
	I2C_ENABLE_ACK();
	I2C_START_ACTION();
	I2C_WAIT_THEFLAG();
	*data=TWDR;
	I2C_SendStop();
}
void I2C_SEND_FULL_FRAME_READ_NACK(u8 aderss,u8* data)
{
	I2C_SendStart();
	I2C_SEND_Adress_READ(aderss);
	
	I2C_START_ACTION();
	I2C_WAIT_THEFLAG();
	*data=TWDR;
	I2C_SendStop();
}



void __vector_19(void) __attribute__((signal));
void __vector_19(void)
{
	I2C_CALL_BACK_FN_ISR();
}