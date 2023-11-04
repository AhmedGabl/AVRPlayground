/*
 * LCD.c
 *
 *  Created on: Oct 21, 2023
 *      Author:AhmedAbogabl
 */

#include "LCD.h"
#include "avr/delay.h"

static u8 current_pos = 0;


void LCD_SendData(u8 data)
{
	Dio_WriteChannel(RS,STD_HIGH);

	Dio_WriteChannel(D4,GET_BIT(data,4));
	Dio_WriteChannel(D5,GET_BIT(data,5));
	Dio_WriteChannel(D6,GET_BIT(data,6));
	Dio_WriteChannel(D7,GET_BIT(data,7));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);

	Dio_WriteChannel(D4,GET_BIT(data,0));
	Dio_WriteChannel(D5,GET_BIT(data,1));
	Dio_WriteChannel(D6,GET_BIT(data,2));
	Dio_WriteChannel(D7,GET_BIT(data,3));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);
}

void LCD_SendCMD(u8 command)
{
	Dio_WriteChannel(RS,STD_LOW);

	Dio_WriteChannel(D4,GET_BIT(command,4));
	Dio_WriteChannel(D5,GET_BIT(command,5));
	Dio_WriteChannel(D6,GET_BIT(command,6));
	Dio_WriteChannel(D7,GET_BIT(command,7));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);

	Dio_WriteChannel(D4,GET_BIT(command,0));
	Dio_WriteChannel(D5,GET_BIT(command,1));
	Dio_WriteChannel(D6,GET_BIT(command,2));
	Dio_WriteChannel(D7,GET_BIT(command,3));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);
}
/**
 * LCD_Init - Initializes the LCD module
 * Initializes the LCD by sending a series of commands to set the display mode, entry mode, and clear the screen.
 */
void LCD_Init(void) {
    _delay_ms(50);  // Wait for the LCD to power up

    LCD_SendCMD(LCD_CURSOR_HOME);  // Set the cursor to the home position
    LCD_SendCMD(LCD_FUNCTION_SET_4_BIT_2_LINE_8_DOTS);  // Set the display to 4-bit mode, 2 lines, and 5x8 dots
    _delay_ms(1);

    // Turn on the display and set cursor settings
    LCD_SendCMD(LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_ON);  // Display on, underline cursor on, block cursor on
    _delay_ms(1);

    LCD_SendCMD(LCD_CLEAR_COMMAND);  // Clear the display
    _delay_ms(2);

    LCD_SendCMD(LCD_ENTRY_MODE_INC_SHIFT_OFF);  // Set the entry mode - increment without display shift
    _delay_ms(1);

    LCD_SendCMD(LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF);  // Display on, underline cursor off, block cursor off

    // Set the cursor to the start of the Display Data RAM (DDRAM)
    LCD_SendCMD(LCD_DDRAM_START);
}
/**
 * LCD_CLR : This function Clears the LCD 4bit
 * @param	void
 * @return	void
 */
void LCD_CLR(void)
{
	LCD_SendCMD(0x01);
	current_pos=0;
}

/**
 * LCD_PutChar : This function displays a character on the LCD 4bit
 * @param	data which is the character to display Ex: 'A'
 * @return	void
 */

void LCD_PutChar (const u8 character)
{
	if(current_pos == 20 )
	{
		LCD_GoTo(2, 1);
	}
	else if(current_pos == 40 )
	{
		LCD_GoTo(3, 1);
	}
	else if(current_pos == 60 )
	{
		LCD_GoTo(4, 1);
	}
	else if(current_pos == 80 )
	{
		LCD_GoTo(1, 1);
		current_pos =0;
	}
	LCD_SendData(character);
	current_pos ++;
}
void LCD_PutTextAnimated(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        LCD_PutChar(text[i]);
        _delay_ms(20); // Adjust the delay as needed
    }
}
/**
 * LCD_PutString : This function displays whole string on the LCD 4bit
 * @param	data which is the string to display Ex: "Mahmoud El Arabi"
 * @return	void
 */
void LCD_PutString (const u8* str)
{
	 while (*str){
		LCD_PutChar(*str);
		str++;
		}
}

/**
 * LCD_PutChar_at_X_Y : This function displays a character on the LCD 4bit at specific position
 * @param	1- data which is the character to display
 * 			2- row : the Row position of the character
 * 			3- col : the Column position of the character
 * 			Ex ('A', 2, 3) -> will display A @ [2,3]
 * @return	void
 */
void LCD_PutChar_at_X_Y (u8 data, u8 row, u8 col)
{
	LCD_GoTo(row, col);
	LCD_SendData(data);
}

void LCD_PutString_at_X_Y(u8* data, u8 row, u8 col)
{
	LCD_GoTo(row, col);
	LCD_PutString(data);
}

//void LCD_PutInt(u32 Number)
//{
//	if(Number == 0 )
//		return ;
//	else
//		LCD_PutInt(Number/10);
//	///if(Number<255)
//	 LCD_PutChar((Number%10)+0x30);
//}


void LCD_PutInt(u16 num)
{
	 char num_str[7];  // Assuming a 7-character buffer is sufficient
	    snprintf(num_str, sizeof(num_str), "%d", num);

	    // Display the string on the LCD character by character
	    for (int i = 0; num_str[i] != '\0'; i++) {
	        LCD_PutChar(num_str[i]);
	    }
}


//{ u32 notu16
//    u8 current_pos_backup = current_pos; // Backup the current_pos
//    current_pos = 0; // Reset the current_pos to 0
//
//    if (Number == 0)
//    {
//        return ;//LCD_PutChar('0'); // Display '0' if the number is 0
//    }
//    else
//    {
//        LCD_PutInt(Number / 10);
//        LCD_PutChar((Number % 10) + '0'); // Convert the digit to a character
//    }
//
//    current_pos = current_pos_backup; // Restore the original current_pos value
//}
//

void LCD_PutCustomChar(u8 row, u8 col, u8* CustomCharacter, u8 MemPos)
{
	LCD_SendCMD(LCD_CGRAM_START + (MemPos * 8));
	for(int i = 0 ; i < 8 ; i++)
	{
		LCD_SendData(CustomCharacter[i]);
	}
	LCD_PutChar_at_X_Y(MemPos, row, col);
}

void LCD_GoTo(u8 row, u8 coul){
    coul--;
    switch (row){
        case ROW1:
            LCD_SendCMD(0x80+coul);
        break;
        case ROW2:
            LCD_SendCMD(0xC0+coul);
        break;
        case ROW3:
            LCD_SendCMD(0x94+coul);
        break;
        case ROW4:
            LCD_SendCMD(0xD4+coul);
        break;
        default:
        	break;
    }
}

