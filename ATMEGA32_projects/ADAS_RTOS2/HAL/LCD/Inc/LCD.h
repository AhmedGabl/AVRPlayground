/*
 * LCD.h
 *
 * Created: 10/21/2023 10:48:52 AM
 *  Author: ahmed radwan
 */ 


#ifndef LCD_H_
#define LCD_H_


/*************************macros section***********************************/


/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/
typedef enum {
	LCD_CGRAM_ERR_INDEX,
	LCD_E_OK,
	LCD_ERROR_NULL_PTR,
	LCD_ROW_OUT_OF_RANGE,
	LCD_COL_OUT_OF_RANGE
}LCD_tenuErrorStatus;
typedef struct  
{
	Dio_tenuPins lcd_pins[8];
	Dio_tenuPins lcd_pin_rs;
	Dio_tenuPins lcd_pin_e;
	
}LCD_8BIT_ST;
typedef struct
{
	Dio_tenuPins lcd_pins[4];
	Dio_tenuPins lcd_pin_rs;
	Dio_tenuPins lcd_pin_e;
}LCD_4BIT_ST;

/*********************************** user defined data types section end ***********************************/




/*****************function prototypes section*******************************************/
LCD_tenuErrorStatus LCD_vidInit_8bit(LCD_8BIT_ST*lcd);
LCD_tenuErrorStatus LCD_vidSendcommand_8bit(LCD_8BIT_ST*lcd,u8 Copyu8Comaand);
LCD_tenuErrorStatus LCD_vidDisplayChar_8bit(LCD_8BIT_ST*lcd,u8 Copyu8Char);
LCD_tenuErrorStatus LCD_vidCraetCustomChar_8bit(LCD_8BIT_ST*lcd,ptr_u8 add_pu8CustomChar, u8 index);
LCD_tenuErrorStatus LCD_vidGotoXY_8bit(LCD_8BIT_ST*lcd,u8 copy_rows,u8 copy_colums );
LCD_tenuErrorStatus LCD_vidDisplayString_8bit(LCD_8BIT_ST*lcd,ptr_u8 add_pu8String);
LCD_tenuErrorStatus LCD_vidDisplayNumber_8bit(LCD_8BIT_ST*lcd,u32 Copynum);
 /******************************************************************************************/
 
 LCD_tenuErrorStatus LCD_vidInit_4bit(LCD_4BIT_ST*lcd);
 LCD_tenuErrorStatus LCD_vidSendcommand_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Comaand);
 LCD_tenuErrorStatus LCD_vidDisplayChar_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Char);
 LCD_tenuErrorStatus LCD_vidCraetCustomChar_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8CustomChar, u8 index);
 LCD_tenuErrorStatus LCD_vidGotoXY_4bit(LCD_4BIT_ST*lcd,u8 copy_rows,u8 copy_colums );
 LCD_tenuErrorStatus LCD_vidDisplayString_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8String);
 LCD_tenuErrorStatus LCD_vidDisplayNumber_4bit(LCD_4BIT_ST*lcd,u32 Copynum);
 LCD_tenuErrorStatus LCD_vidDisplayFloatNumber_4bit(LCD_4BIT_ST*lcd,f32 Copynum);

 /******************************************************************************************/
 LCD_tenuErrorStatus LCD_OS_vidInit_4bit(LCD_4BIT_ST*lcd);
 LCD_tenuErrorStatus LCD_OS_vidSendcommand_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Comaand);
 LCD_tenuErrorStatus LCD_OS_vidDisplayChar_4bit(LCD_4BIT_ST*lcd,u8 Copyu8Char);
 LCD_tenuErrorStatus LCD_OS_vidCraetCustomChar_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8CustomChar, u8 index);
 LCD_tenuErrorStatus LCD_OS_vidGotoXY_4bit(LCD_4BIT_ST*lcd,u8 copy_rows,u8 copy_colums );
 LCD_tenuErrorStatus LCD_OS_vidDisplayString_4bit(LCD_4BIT_ST*lcd,ptr_u8 add_pu8String);
 LCD_tenuErrorStatus LCD_OS_vidDisplayNumber_4bit(LCD_4BIT_ST*lcd,u32 Copynum);
 LCD_tenuErrorStatus LCD_OS_vidDisplayFloatNumber_4bit(LCD_4BIT_ST*lcd,f32 Copynum);
 
/*****************function prototypes section end*******************************************/


#endif /* LCD_H_ */