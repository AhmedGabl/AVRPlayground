/*
 * GIE.h
 *
 * Created: 10/22/2023 3:21:00 PM
 *  Author: ahmed radwan
 */ 


#ifndef EXTI_H_
#define EXTI_H_
#include "EXTI_PRIV.h"
/*************************macros section***********************************/


/***************************INT0*********************************/

#define EXTI_INT0_Interrupt_Disable() (CLR_BIT(GICR,6))// clear the iterrupt enable for the external interrupt INT0
#define EXTI_INT0_Interrupt_Enable()  (SET_BIT(GICR,6))// set the iterrupt enable for the external interrupt INT0

#define EXTI_INT0_Interrupt_Flag_clear() (CLR_BIT(GIFR,6))// clear the iterrupt flag for the external interrupt INT0


/***************************INT1*********************************/

#define EXTI_INT1_Interrupt_Disable() (CLR_BIT(GICR,7))// clear the iterrupt enable for the external interrupt INT1
#define EXTI_INT1_Interrupt_Enable()  (SET_BIT(GICR,7))// set the iterrupt enable for the external interrupt INT1

#define EXTI_INT1_Interrupt_Flag_clear() (CLR_BIT(GIFR,7))// clear the iterrupt flag for the external interrupt INT1

/***************************INT2*********************************/
#define EXTI_INT2_Interrupt_Disable() (CLR_BIT(GICR,5))// clear the iterrupt enable for the external interrupt INT2
#define EXTI_INT2_Interrupt_Enable()  (SET_BIT(GICR,5))// set the iterrupt enable for the external interrupt INT2

#define EXTI_INT2_Interrupt_Flag_clear() (CLR_BIT(GIFR,5))// clear the iterrupt flag for the external interrupt INT2

/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/
typedef enum{
	EXTI_INT0=0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_tenuSource;

typedef enum{
	EXTI_MODE_LOW_LEVEL=0,
	EXTI_MODE_LOGICAL_CHANGE,
	EXTI_MODE_FALING_EDGE,
	EXTI_MODE_RISING_EDGE
}EXTI_tenuMode;
typedef enum{
	EXINT_WRONG_SOURCE,
	EXINT_EOK,
	EXINT_NULL_PTR,
	EXINT_WRONG_MODE
}EXTI_tenuError_Staus;

/*********************************** user defined data types section end ***********************************/

EXTI_tenuError_Staus EXI_INT(EXTI_tenuSource INT,EXTI_tenuMode mode,void (*call_back)(void) );

/*****************function prototypes section*******************************************/


/*****************function prototypes section end*******************************************/



#endif /* EXTI_H_ */