/*
 * KEY_PAD.h
 *
 * Created: 10/22/2023 12:19:56 PM
 *  Author: ahmed radwan
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_

/*************************macros section***********************************/
#define  NO_OF_ROWS    4
#define  NO_OF_COLUMS  4
 
/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/
typedef struct{
	Dio_tenuPins key_pad_rows_pins[NO_OF_ROWS];
	Dio_tenuPins key_pad_col_pins[NO_OF_COLUMS];
	}KEY_PAD_ST;
	
	typedef enum{
		KEY_PAD_E_OK,
		KEY_PAD_NULL_PTR,
		KEY_PRESSED,
		KEY_NOT_PRESSED
		}KEY_PAD_tenuErrorStatus;

/*********************************** user defined data types section end ***********************************/



/*****************function prototypes section*******************************************/
KEY_PAD_tenuErrorStatus key_pad_Init(KEY_PAD_ST*key_bad);
KEY_PAD_tenuErrorStatus key_pad_Get_value(KEY_PAD_ST*key_pad,ptr_u8 value);

KEY_PAD_tenuErrorStatus key_OS_pad_Get_value(KEY_PAD_ST*key_pad,ptr_u8 value);

/*****************function prototypes section end*******************************************/




#endif /* KEY_PAD_H_ */