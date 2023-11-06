/*
 * LCD.c
 *
 *  Created on: Oct 21, 2023
 *      Author: AhmedAbogabl
 */

#include "LCD.h"

void Lcd_SendCMD(u8 cmd) {
	// Set RS to command mode
	Dio_WriteChannel(LCD_RS, STD_LOW);

	// Send the high nibble
	Dio_WriteChannel(PB_0, GET_BIT(cmd, 4));
	Dio_WriteChannel(PB_1, GET_BIT(cmd, 5));
	Dio_WriteChannel(PB_2, GET_BIT(cmd, 6));
	Dio_WriteChannel(PB_4, GET_BIT(cmd, 7));

	Dio_WriteChannel(LCD_EN, STD_HIGH);
	_delay_us(1);
	Dio_WriteChannel(LCD_EN, STD_LOW);
	_delay_us(1);

	// Send the low nibble
	Dio_WriteChannel(PB_0, GET_BIT(cmd, 0));
	Dio_WriteChannel(PB_1, GET_BIT(cmd, 1));
	Dio_WriteChannel(PB_2, GET_BIT(cmd, 2));
	Dio_WriteChannel(PB_4, GET_BIT(cmd, 3));

	Dio_WriteChannel(LCD_EN, STD_HIGH);
	_delay_us(1);
	Dio_WriteChannel(LCD_EN, STD_LOW);
	_delay_us(1);  // Wait for the command to execute
}

void Lcd_SendData(u8 data) {

	// Set RS to data mode
//	SET_BIT(PORTA, LCD_RS);
	Dio_WriteChannel(LCD_RS, STD_HIGH);
	// Send the high nibble

	Dio_WriteChannel(PB_0, GET_BIT(data, 4));
	Dio_WriteChannel(PB_1, GET_BIT(data, 5));
	Dio_WriteChannel(PB_2, GET_BIT(data, 6));
	Dio_WriteChannel(PB_4, GET_BIT(data, 7));
	Dio_WriteChannel(LCD_EN, STD_HIGH);
	_delay_us(1);
	Dio_WriteChannel(LCD_EN, STD_LOW);
	_delay_us(1);
	// Send the low nibble
	Dio_WriteChannel(PB_0, GET_BIT(data, 0));
	Dio_WriteChannel(PB_1, GET_BIT(data, 1));
	Dio_WriteChannel(PB_2, GET_BIT(data, 2));
	Dio_WriteChannel(PB_4, GET_BIT(data, 3));

	Dio_WriteChannel(LCD_EN, STD_HIGH);
	_delay_us(1);
	Dio_WriteChannel(LCD_EN, STD_LOW);
	_delay_us(10);  // Wait for the data to be displayed
}

void Lcd_GoTo(u8 row,u8 col){
	col--;
	switch (row){
	        case ROW1:
	        	Lcd_SendCMD(0x80+col);
	        break;
	        case ROW2:
	        	Lcd_SendCMD(0xC0+col);
	        break;
	        case ROW3:
	        	Lcd_SendCMD(0x94+col);
	        break;
	        case ROW4:
	        	Lcd_SendCMD(0xD4+col);
	        break;
	        default:break;

	    }
}

void Lcd_PutChar (u8 character)
{
	Lcd_SendData(character);
}

void Lcd_PutInt(u32 Number)
{

	if(Number == 0 )
		return ;
	else
		Lcd_PutInt(Number/10);
	///if(Number<255)
	 Lcd_SendData((Number%10)+0x30);
}

void Lcd_Init(void) {
	_delay_ms(50);
	Lcd_SendCMD(HOME);
	Lcd_SendCMD(FOUR_BIT);
	_delay_ms(1);
	Lcd_SendCMD(CURSER_ON);
	_delay_ms(1);
	Lcd_SendCMD(CLEAR);
	_delay_ms(1);
	Lcd_SendCMD(MODE);
	_delay_ms(1);
	Lcd_SendCMD(LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF);
	Lcd_SendCMD(SET_DDRAM_ADDR);
}
void Lcd_Clear(void){
Lcd_SendCMD(CLEAR);
}


void Lcd_PutString (u8* str)
{
	 while (*str !='\0'){
		Lcd_PutChar(*str);
		str++;
		}
}

void lcd4_disply_char_at_X_Y (u8 data, u8 row, u8 col)
{
	Lcd_GoTo(row, col);
	Lcd_SendData(data);
}


void Lcd_PutString_x_Y(u8* data, u8 row, u8 col)
{
	Lcd_GoTo(row, col);
	Lcd_PutString(data);
}
