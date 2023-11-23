/*
 * LCD.h
 *
 *  Created on: Oct 21, 2023
 *      Author: AhmedAbogabl
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include <avr/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"

//LCD commands
#define CLEAR       0x01    // Clear display
#define HOME        0x02    // Return cursor to home position
#define MODE        0x06    // Entry mode set
#define DISPLAY_ON  0x0C    // Display on, cursor off
#define DISPLAY_OFF 0x08    // Display off
#define CURSER_ON   0x0F
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF                           0x0C

// Shift the display or move the cursor
#define SHIFT_LEFT  0x18    // Shift display left
#define SHIFT_RIGHT 0x1C    // Shift display right

// Function set - data length and number of display lines
#define FOUR_BIT    0x28    // 4-bit data, 2 display lines
#define EIGHT_BIT   0x38    // 8-bit data, 2 display lines

// Set CG RAM address (for custom characters)
#define SET_CGRAM_ADDR  0x40  // Add the custom character address (0-7) to set

// Set DDRAM address (for positioning the cursor)
#define SET_DDRAM_ADDR  0x80  // Add the DDRAM address (0x00 to 0x13) to set

//void LCD_SendCMD(u8 cmd);
//void LCD_SendCMD(u8 cmd);

// Define the control pins and data pins connected to the LCD
#define LCD_RS      PA_3   // Register select pin
#define LCD_EN      PA_2   // Enable pin
#define LCD_DATA4   PB_0   // Data bit 4
#define LCD_DATA5   PB_1   // Data bit 5
#define LCD_DATA6   PB_2   // Data bit 6
#define LCD_DATA7   PB_4   // Data bit 7

//
//// Define bit masks and shift values for data pins and command nibbles
//#define DATA_MASK       0x0F  // Bits 0 and 1 of PORTB  0011
//#define HIGH_NIBBLE     0xF0  // Upper 4 bits of the command  11
//#define HIGH_NIBBLE_SHIFT 4   // Shift value for the high nibble
////#define LOW_NIBBLE_SHIFT  4   // Shift value for the low nibble
//

#define LCD_ROW_NUMBERS			4
#define LCD_COL_NUMBERS			20

#define ROW1    ((u8)1)
#define ROW2    ((u8)2)
#define ROW3    ((u8)3)
#define ROW4    ((u8)4)

#define COL1	((u8)1)
#define COL2	((u8)2)
#define COL3	((u8)3)
#define COL4	((u8)4)
#define COL5	((u8)5)
#define COL6	((u8)6)
#define COL7	((u8)7)
#define COL8	((u8)8)
#define COL9	((u8)9)
#define COL10	((u8)10)
#define COL11	((u8)11)
#define COL12	((u8)12)
#define COL13	((u8)13)
#define COL14	((u8)14)
#define COL15	((u8)15)
#define COL16	((u8)16)
#define COL17	((u8)17)
#define COL18	((u8)18)
#define COL19	((u8)19)
#define COL20	((u8)20)


void Lcd_Init();

void Lcd_SendData(u8 Data);
void Lcd_SendCMD(u8 cmd);

void Lcd_GoTo(u8 row,u8 col);

void Lcd_PutChar (u8 character);
void Lcd_Clear(void);

void Lcd_PutString (u8* str);
void lcd4_disply_char_at_X_Y (u8 data, u8 row, u8 col);
void Lcd_PutString_x_Y(u8* data, u8 row, u8 col);
void Lcd_PutInt (u32 Number);


#endif /* HAL_LCD_LCD_H_ */
