/*
 * EXTI_interface.h
 *
 * Created on: Oct 22, 2023
 * Author: AhmedAbogabl
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* Macros For Interrupt Source */
#define EXTI_INT0   0
#define EXTI_INT1   1
#define EXTI_INT2   2


/* Macros For Interrupt Trigger Edge */
#define EXTI_LOW_LEVEL          0
#define EXTI_ANY_LOGICAL_CHANGE 1
#define EXTI_FALLING_EDGE       2
#define EXTI_RISING_EDGE        3


/******************************************************
 * Function: EXTI_voidInit
 * Brief: Initialize external interrupt settings.
 * Options:
 * - copy_u8InterruptSource: Specifies the external interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * - copy_u8SenseControl: Specifies the sense control type (EXTI_RISING_EDGE, EXTI_FALLING_EDGE, EXTI_ANY_LOGICAL_CHANGE, LOW_LEVEL).
 *
 * This function sets the sense control for the specified external interrupt source.
 * The options control when the external interrupt will be triggered based on the voltage level.
 ******************************************************/
void EXTI_voidInit(u8 copy_u8InterruptSource, u8 copy_u8SenseControl);

/******************************************************
 * Function: EXTI_voidEnable
 * Brief: Enable the specified external interrupt.
 * Options:
 * - copy_u8InterruptSource: Specifies the external interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 *
 * This function enables the specified external interrupt to allow it to trigger when the conditions are met.
 ******************************************************/
void EXTI_voidEnable(u8 copy_u8InterruptSource);

/******************************************************
 * Function: EXTI_voidDisable
 * Brief: Disable the specified external interrupt.
 * Options:
 * - copy_u8InterruptSource: Specifies the external interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 *
 * This function disables the specified external interrupt to prevent it from triggering.
 ******************************************************/
void EXTI_voidDisable(u8 copy_u8InterruptSource);

/******************************************************
 * Function: EXTRI_voidSetCallBackINT
 * Brief: Set a callback function for the specified external interrupt.
 * Options:
 * - EXTI_Int: Specifies the external interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * - ptrToFunction: A pointer to the callback function to be executed when the interrupt is triggered.
 *
 * This function allows you to register a custom callback function that will be executed when the specified
 * external interrupt occurs.
 ******************************************************/
void EXTRI_voidSetCallBackINT(u8 EXTI_Int, void (*ptrToFunction)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
