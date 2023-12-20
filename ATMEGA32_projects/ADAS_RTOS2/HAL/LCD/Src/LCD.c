/*
 * LCD.c
 *
 * Created: 10/21/2023 10:48:37 AM
 *  Author: ahmed radwan
 */
#include "../../../SERVICES/Standard_Data_Types.h" 

#include <util/delay.h>

#include "../../../MCAL/PORT/PORT.h"
#include "../../../MCAL/DIO/DIO.h"
#include "../Inc/LCD_COMANDS.h"
#include "../Inc/LCD.h"
static void LCD_vid_Send_8bit_bus(LCD_8BIT_ST*lcd,u8 comand);
static void LCD_vid_Generate_faling(LCD_8BIT_ST*lcd);
static void LCD_vid_8Pin_Dir_cfg(LCD_8BIT_ST*lcd);

LCD_tenuErrorStatus LCD_vidInit_8bit(LCD_8BIT_ST*lcd)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		LCD_vid_8Pin_Dir_cfg(lcd);
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_LOW);//send commands
		_delay_ms(35);
		LCD_vid_Send_8bit_bus(lcd,LCD_8BIT_MODE_2LINE_5_8);
		_delay_ms(45);
		LCD_vid_Send_8bit_bus(lcd,LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_ON);
		_delay_ms(45);
		LCD_vid_Send_8bit_bus(lcd,LCD_CLEAR_DISPLAY);
		_delay_ms(10);
		LCD_vid_Send_8bit_bus(lcd,LCD_ENTRY_MODE_INCREMENT_SHIFT_OFF);
		_delay_ms(10);
		LCD_vid_Send_8bit_bus(lcd,LCD_DDRAM_START_ADDRESS);
	}
	
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidSendcommand_8bit(LCD_8BIT_ST*lcd,u8 Copyu8Comaand)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_LOW);
		LCD_vid_Send_8bit_bus(lcd,Copyu8Comaand);
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidDisplayChar_8bit(LCD_8BIT_ST*lcd,u8 Copyu8Char)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_HIGH);
		LCD_vid_Send_8bit_bus(lcd,Copyu8Char);
	}
	return LCD_Error_state;

}
LCD_tenuErrorStatus LCD_vidCraetCustomChar_8bit(LCD_8BIT_ST*lcd,ptr_u8 add_pu8CustomChar, u8 index){
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd||NULL==add_pu8CustomChar)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else if(index>7)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		LCD_vidSendcommand_8bit(lcd,LCD_CGRAM_START_ADDRESS+index*8);
		for(u8 lcd_bytecounter=0;lcd_bytecounter<8;lcd_bytecounter++ )
		{
			LCD_vidDisplayChar_8bit(lcd,*(add_pu8CustomChar+lcd_bytecounter));
		}
		
		LCD_vidSendcommand_8bit(lcd,LCD_DDRAM_START_ADDRESS);
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidGotoXY_8bit(LCD_8BIT_ST*lcd,u8 copy_rows,u8 copy_colums )
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else if(copy_rows>4)
	{
		LCD_Error_state=LCD_ROW_OUT_OF_RANGE;
	}
	else if(copy_rows>20)
	{
		LCD_Error_state=LCD_COL_OUT_OF_RANGE;
	}
	else
	{
		switch (copy_rows)
		{
			case ROW1:
				LCD_vidSendcommand_8bit(lcd,(LCD_4ROWS_FIRST_ROW_ADDREESS+copy_colums));
				break;
			case ROW2:
				LCD_vidSendcommand_8bit(lcd,(LCD_4ROWS_SECOND_ROW_ADDREESS+copy_colums));
			break;
			case ROW3:
				LCD_vidSendcommand_8bit(lcd,(LCD_4ROWS_THIRD_ROW_ADDREESS+copy_colums));
				break;
			case ROW4:
				LCD_vidSendcommand_8bit(lcd,(LCD_4ROWS_FOURTH_ROW_ADDREESS+copy_colums));
				break;
		}
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidDisplayString_8bit(LCD_8BIT_ST*lcd,ptr_u8 add_pu8String)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd||NULL==add_pu8String)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else{
		while(*add_pu8String)
		{
			LCD_vidDisplayChar_8bit(lcd,*add_pu8String);
			add_pu8String++;
		}
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidDisplayNumber_8bit(LCD_8BIT_ST*lcd,u32 Copynum)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		if(Copynum==1)
		{
			LCD_vidDisplayChar_8bit(lcd,'1');
		}
		else
		{
			u8 numbers[10]={'0','1','2','3','4','5','6','7','8','9'};
			u32 temp=1;
			while(Copynum)
			{
				temp=temp*10+Copynum%10;
				Copynum/=10;
			}
			while(temp>1)
			{
				LCD_vidDisplayChar_8bit(lcd,numbers[temp%10]);
				temp/=10;
			}
		}
			
	}
		
	return LCD_Error_state;		
}



static void LCD_vid_8Pin_Dir_cfg(LCD_8BIT_ST*lcd)
{
	for(int i=0;i<8;i++)
	{
		
		Port_enuSetpinDirection(lcd->lcd_pins[i],PIN_MODE_OUTPUT);
	}
	Port_enuSetpinDirection(lcd->lcd_pin_e,PIN_MODE_OUTPUT);
	Port_enuSetpinDirection(lcd->lcd_pin_rs,PIN_MODE_OUTPUT);

}
static void LCD_vid_Send_8bit_bus(LCD_8BIT_ST*lcd,u8 data)
{
	
	for(int i=0;i<8;i++)
	{
		Dio_enuWriteChannel(lcd->lcd_pins[i],(data>>i)&(u8)0x01);
	}
	LCD_vid_Generate_faling(lcd);
}
static void LCD_vid_Generate_faling(LCD_8BIT_ST*lcd)
{
	Dio_enuWriteChannel(lcd->lcd_pin_e,DIO_PIN_HIGH);
	_delay_ms(5);
	Dio_enuWriteChannel(lcd->lcd_pin_e,DIO_PIN_LOW);
}


/************************************** lcd 4 bit section ****************************************************/


static void LCD_vid_Send_4bit_bus(LCD_4BIT_ST*lcd,u8 comand);
static void LCD_vid_Generate_faling_4bit(LCD_4BIT_ST*lcd);
static void LCD_vid_4Pin_Dir_cfg(LCD_4BIT_ST*lcd);

LCD_tenuErrorStatus LCD_vidInit_4bit(LCD_4BIT_ST*lcd)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		LCD_vid_4Pin_Dir_cfg(lcd);
		_delay_ms(40);
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_LOW);//send commands
		LCD_vid_Send_4bit_bus(lcd,LCD_8BIT_MODE_2LINE_5_8);
		_delay_ms(5);
		LCD_vid_Send_4bit_bus(lcd,LCD_8BIT_MODE_2LINE_5_8);
		_delay_ms(150);
		LCD_vid_Send_4bit_bus(lcd,LCD_8BIT_MODE_2LINE_5_8);
		
		LCD_vid_Send_4bit_bus(lcd,LCD_CLEAR_DISPLAY);
		
		LCD_vid_Send_4bit_bus(lcd,LCD_CURSOR_HOME);
		LCD_vid_Send_4bit_bus(lcd,LCD_ENTRY_MODE_INCREMENT_SHIFT_OFF);
		LCD_vid_Send_4bit_bus(lcd,LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_OFF);
		LCD_vid_Send_4bit_bus(lcd,LCD_4BIT_MODE_2LINE_5_8);
		LCD_vid_Send_4bit_bus(lcd,LCD_DDRAM_START_ADDRESS);
	}
	
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidSendcommand_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Comaand)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_LOW);
		LCD_vid_Send_4bit_bus(lcd,Copyu8Comaand);
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidDisplayChar_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Char)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_HIGH);
		LCD_vid_Send_4bit_bus(lcd,Copyu8Char);
	}
	return LCD_Error_state;

}
LCD_tenuErrorStatus LCD_vidCraetCustomChar_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8CustomChar, u8 index){
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd||NULL==add_pu8CustomChar)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else if(index>7)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		LCD_vidSendcommand_4bit(lcd,LCD_CGRAM_START_ADDRESS+index*8);
		for(u8 lcd_bytecounter=0;lcd_bytecounter<8;lcd_bytecounter++ )
		{
			LCD_vidDisplayChar_4bit(lcd,*(add_pu8CustomChar+lcd_bytecounter));
		}
		
		LCD_vidSendcommand_4bit(lcd,LCD_DDRAM_START_ADDRESS);
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidGotoXY_4bit(LCD_4BIT_ST*lcd,u8 copy_rows,u8 copy_colums )
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else if(copy_rows>4)
	{
		LCD_Error_state=LCD_ROW_OUT_OF_RANGE;
	}
	else if(copy_rows>20)
	{
		LCD_Error_state=LCD_COL_OUT_OF_RANGE;
	}
	else
	{
		switch (copy_rows)
		{
			case ROW1:
			LCD_vidSendcommand_4bit(lcd,(LCD_4ROWS_FIRST_ROW_ADDREESS+copy_colums));
			break;
			case ROW2:
			LCD_vidSendcommand_4bit(lcd,(LCD_4ROWS_SECOND_ROW_ADDREESS+copy_colums));
			break;
			case ROW3:
			LCD_vidSendcommand_4bit(lcd,(LCD_4ROWS_THIRD_ROW_ADDREESS+copy_colums));
			break;
			case ROW4:
			LCD_vidSendcommand_4bit(lcd,(LCD_4ROWS_FOURTH_ROW_ADDREESS+copy_colums));
			break;
		}
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidDisplayString_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8String)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd||NULL==add_pu8String)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else{
		while(*add_pu8String)
		{
			LCD_vidDisplayChar_4bit(lcd,*add_pu8String);
			add_pu8String++;
		}
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_vidDisplayNumber_4bit(LCD_4BIT_ST*lcd,u32 Copynum)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		if(Copynum==0)
		{
			LCD_vidDisplayChar_4bit(lcd,'0');
		}
		else
		{
			u8 numbers[10]={'0','1','2','3','4','5','6','7','8','9'};
			u32 temp=1;
			while(Copynum)
			{
				temp=temp*10+Copynum%10;
				Copynum/=10;
			}
			while(temp>1)
			{
				LCD_vidDisplayChar_4bit(lcd,numbers[temp%10]);
				temp/=10;
			}
		}
		
	}
	
	return LCD_Error_state;
}

LCD_tenuErrorStatus LCD_vidDisplayFloatNumber_4bit(LCD_4BIT_ST*lcd,f32 Copynum){
	s32 temp=(s32) Copynum;
	LCD_vidDisplayNumber_4bit(lcd,temp);
	temp=(s32)((Copynum-temp)*100);
	LCD_vidDisplayChar_4bit(lcd,'.');
	LCD_vidDisplayNumber_4bit(lcd,temp);
}

static void LCD_vid_4Pin_Dir_cfg(LCD_4BIT_ST*lcd)
{
	for(u8 i=0;i<4;i++)
	{
		Port_enuSetpinDirection(lcd->lcd_pins[i],PIN_MODE_OUTPUT);
	}
	Port_enuSetpinDirection(lcd->lcd_pin_e,PIN_MODE_OUTPUT);
	Port_enuSetpinDirection(lcd->lcd_pin_rs,PIN_MODE_OUTPUT);

}
static void LCD_vid_Send_4bit_bus(LCD_4BIT_ST*lcd,u8 data)
{
	for(u8 i=0;i<4;i++)
	{
		Dio_enuWriteChannel(lcd->lcd_pins[i],(data>>(i+4))&(u8)0x01);
	}
	LCD_vid_Generate_faling_4bit(lcd);
	for(u8 i=0;i<4;i++)
	{
		Dio_enuWriteChannel(lcd->lcd_pins[i],(data>>i)&(u8)0x01);
	}
	LCD_vid_Generate_faling_4bit(lcd);
}
static void LCD_vid_Generate_faling_4bit(LCD_4BIT_ST*lcd)
{
	Dio_enuWriteChannel(lcd->lcd_pin_e,DIO_PIN_HIGH);
	_delay_ms(5);
	Dio_enuWriteChannel(lcd->lcd_pin_e,DIO_PIN_LOW);
}
/*******************LCD FN compatable with free RTOS***************/

static void LCD_OS_vid_Send_4bit_bus(LCD_4BIT_ST*lcd,u8 data);
static void LCD_OS_vid_Generate_faling_4bit(LCD_4BIT_ST*lcd);

LCD_tenuErrorStatus LCD_OS_vidInit_4bit(LCD_4BIT_ST*lcd)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		LCD_vid_4Pin_Dir_cfg(lcd);
		vTaskDelay(40);
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_LOW);//send commands
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_8BIT_MODE_2LINE_5_8);
		vTaskDelay(5);
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_8BIT_MODE_2LINE_5_8);
		vTaskDelay(40);
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_8BIT_MODE_2LINE_5_8);
		
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_CLEAR_DISPLAY);
		
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_CURSOR_HOME);
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_ENTRY_MODE_INCREMENT_SHIFT_OFF);
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_OFF);
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_4BIT_MODE_2LINE_5_8);
		LCD_OS_vid_Send_4bit_bus(lcd,LCD_DDRAM_START_ADDRESS);
	}
	
	return LCD_Error_state;	
}

LCD_tenuErrorStatus LCD_OS_vidSendcommand_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Comaand)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_LOW);
		LCD_OS_vid_Send_4bit_bus(lcd,Copyu8Comaand);
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_OS_vidDisplayChar_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Char)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		Dio_enuWriteChannel(lcd->lcd_pin_rs,DIO_PIN_HIGH);
		LCD_OS_vid_Send_4bit_bus(lcd,Copyu8Char);
	}
	return LCD_Error_state;

}
LCD_tenuErrorStatus LCD_OS_vidCraetCustomChar_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8CustomChar, u8 index){
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd||NULL==add_pu8CustomChar)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else if(index>7)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		LCD_OS_vidSendcommand_4bit(lcd,LCD_CGRAM_START_ADDRESS+index*8);
		for(u8 lcd_bytecounter=0;lcd_bytecounter<8;lcd_bytecounter++ )
		{
			LCD_OS_vidDisplayChar_4bit(lcd,*(add_pu8CustomChar+lcd_bytecounter));
		}
		
		LCD_OS_vidSendcommand_4bit(lcd,LCD_DDRAM_START_ADDRESS);
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_OS_vidGotoXY_4bit(LCD_4BIT_ST*lcd,u8 copy_rows,u8 copy_colums )
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else if(copy_rows>4)
	{
		LCD_Error_state=LCD_ROW_OUT_OF_RANGE;
	}
	else if(copy_rows>20)
	{
		LCD_Error_state=LCD_COL_OUT_OF_RANGE;
	}
	else
	{
		switch (copy_rows)
		{
			case ROW1:
			LCD_OS_vidSendcommand_4bit(lcd,(LCD_4ROWS_FIRST_ROW_ADDREESS+copy_colums));
			break;
			case ROW2:
			LCD_OS_vidSendcommand_4bit(lcd,(LCD_4ROWS_SECOND_ROW_ADDREESS+copy_colums));
			break;
			case ROW3:
			LCD_OS_vidSendcommand_4bit(lcd,(LCD_4ROWS_THIRD_ROW_ADDREESS+copy_colums));
			break;
			case ROW4:
			LCD_OS_vidSendcommand_4bit(lcd,(LCD_4ROWS_FOURTH_ROW_ADDREESS+copy_colums));
			break;
		}
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_OS_vidDisplayString_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8String)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd||NULL==add_pu8String)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else{
		while(*add_pu8String)
		{
			LCD_OS_vidDisplayChar_4bit(lcd,*add_pu8String);
			add_pu8String++;
		}
	}
	return LCD_Error_state;
}
LCD_tenuErrorStatus LCD_OS_vidDisplayNumber_4bit(LCD_4BIT_ST*lcd,u32 Copynum)
{
	LCD_tenuErrorStatus LCD_Error_state=LCD_E_OK;
	if(NULL==lcd)
	{
		LCD_Error_state=LCD_ERROR_NULL_PTR;
	}
	else
	{
		if(Copynum==0)
		{
			LCD_OS_vidDisplayChar_4bit(lcd,'0');
		}
		else
		{
			u8 numbers[10]={'0','1','2','3','4','5','6','7','8','9'};
			u32 temp=1;
			while(Copynum)
			{
				temp=temp*10+Copynum%10;
				Copynum/=10;
			}
			while(temp>1)
			{
				LCD_OS_vidDisplayChar_4bit(lcd,numbers[temp%10]);
				temp/=10;
			}
		}
		
	}
	
	return LCD_Error_state;
}

LCD_tenuErrorStatus LCD_OS_vidDisplayFloatNumber_4bit(LCD_4BIT_ST*lcd,f32 Copynum){
	s32 temp=(s32) Copynum;
	LCD_OS_vidDisplayNumber_4bit(lcd,temp);
	temp=(s32)((Copynum-temp)*100);
	LCD_OS_vidDisplayChar_4bit(lcd,'.');
	LCD_OS_vidDisplayNumber_4bit(lcd,temp);
}
static void LCD_OS_vid_Send_4bit_bus(LCD_4BIT_ST*lcd,u8 data)
{
	for(u8 i=0;i<4;i++)
	{
		Dio_enuWriteChannel(lcd->lcd_pins[i],(data>>(i+4))&(u8)0x01);
	}
	LCD_OS_vid_Generate_faling_4bit(lcd);
	for(u8 i=0;i<4;i++)
	{
		Dio_enuWriteChannel(lcd->lcd_pins[i],(data>>i)&(u8)0x01);
	}
	LCD_OS_vid_Generate_faling_4bit(lcd);
}
static void LCD_OS_vid_Generate_faling_4bit(LCD_4BIT_ST*lcd)
{
	Dio_enuWriteChannel(lcd->lcd_pin_e,DIO_PIN_HIGH);
	vTaskDelay(5);
	Dio_enuWriteChannel(lcd->lcd_pin_e,DIO_PIN_LOW);
}