/*
 * BUTTON.h
 *
 * Created: 10/21/2023 1:42:53 AM
 *  Author: ahmed radwan
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


/*************************macros section***********************************/


/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/
typedef enum {
	BUTTON_NOT_PRESSED,
	BUTTON_PRESSED
	}Button_tenuState;
	
typedef enum {
	BUTTON_PULL_DOWN,
	BUTTON_PULL_UP
	}Button_tenuCFG;

typedef enum {
	BUTTON_ERROR_PIN_ID,
	BUTTON_E_OK,
	BUTTON_ERROR_NULL_PTR
}Button_tenuErrorStatus;
typedef struct {
	Dio_tenuPins button_pin_id;
	Button_tenuCFG conection;
}Button_tst;


/*********************************** user defined data types section end ***********************************/



/*****************function prototypes section*******************************************/
Button_tenuErrorStatus Button_enuInit(const Button_tst* button);
Button_tenuErrorStatus Button_enuRead(const Button_tst* button,Button_tenuState* status);


/*****************function prototypes section end*******************************************/


#endif /* BUTTON_H_ */