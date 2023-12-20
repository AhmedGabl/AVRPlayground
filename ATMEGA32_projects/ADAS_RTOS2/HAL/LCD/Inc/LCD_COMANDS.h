/*
 * LCD_COMANDS.h
 *
 * Created: 10/21/2023 10:49:22 AM
 *  Author: ahmed radwan
 */ 


#ifndef LCD_COMANDS_H_
#define LCD_COMANDS_H_

#define LCD_CLEAR_DISPLAY                           0X01
#define LCD_CURSOR_HOME                             0X02
#define LCD_ENTRY_MODE_DECREMENT_SHIFT_OFF          0X04
#define LCD_ENTRY_MODE_DECREMENT_SHIFT_ON           0X05
#define LCD_ENTRY_MODE_INCREMENT_SHIFT_OFF          0X06
#define LCD_ENTRY_MODE_INCREMENT_SHIFT_ON           0X07

#define LCD_DISPLAY_OFF                             0X08
#define LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_OFF     0X0C
#define LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_ON      0X0D
#define LCD_DISPLAY_ON_UNDR_LINE_ON_CURSOR_OFF      0X0E
#define LCD_DISPLAY_ON_UNDR_LINE_ON_CURSOR_ON       0X0F

#define LCD_CURSOR_MOVE_SHIFT_LEFT                  0X10
#define LCD_CURSOR_MOVE_SHIFT_RIGHT                 0X14
#define LCD_DISPLAY_SHIFT_LEFT                      0X18
#define LCD_DISPLAY_SHIFT_RIGHT                     0X1C

#define LCD_8BIT_MODE_2LINE_5_8                     0X38
#define LCD_4BIT_MODE_2LINE_5_8                     0X28


#define LCD_CGRAM_START_ADDRESS                     0X40
#define LCD_DDRAM_START_ADDRESS                     0X80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4

#define LCD_2ROWS_FIRST_ROW_ADDREESS                0x80
#define LCD_2ROWS_SECOND_ROW_ADDREESS               0xC0

#define LCD_4ROWS_FIRST_ROW_ADDREESS                0x80
#define LCD_4ROWS_SECOND_ROW_ADDREESS               0xC0
#define LCD_4ROWS_THIRD_ROW_ADDREESS                0x94
#define LCD_4ROWS_FOURTH_ROW_ADDREESS               0xD4

#define LCD_STABLE_DELAY_MS                          20




#endif /* LCD_COMANDS_H_ */