/*
 * EXTI_program.c
 *
 * Created on: Oct 22, 2023
 * Author: AhmedAbogabl
 */

//utlils
#include "../../../utils/BIT_MATH.h"
#include "../../../utils/STD_TYPES.h"
//MCAL
#include "../includes/EXTI_register.h"
#include "../includes/EXTI_interface.h"


// Function pointer for callback functions
static void (*private_pCallBackINT0)(void) = NULL;
static void (*private_pCallBackINT1)(void) = NULL;
static void (*private_pCallBackINT2)(void) = NULL;

// Initialize external interrupt settings
void EXTI_voidInit(u8 copy_u8InterruptSource, u8 copy_u8SenseControl) {
    switch (copy_u8InterruptSource) {
    case EXTI_INT0:
        switch (copy_u8SenseControl) {
        default:
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
        case EXTI_ANY_LOGICAL_CHANGE:
            SET_BIT(MCUCR, ISC00);
            CLR_BIT(MCUCR, ISC01);
            break;
        case EXTI_LOW_LEVEL:
            CLR_BIT(MCUCR, ISC00);
            CLR_BIT(MCUCR, ISC01);
            break;
        }
        break;

    case EXTI_INT1:
        switch (copy_u8SenseControl) {
        default:
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
        case EXTI_ANY_LOGICAL_CHANGE:
            SET_BIT(MCUCR, ISC10);
            CLR_BIT(MCUCR, ISC11);
            break;
        case EXTI_LOW_LEVEL:
            CLR_BIT(MCUCR, ISC10);
            CLR_BIT(MCUCR, ISC11);
            break;
        }
        break;

    case EXTI_INT2:
        switch (copy_u8SenseControl) {
        default:
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCSR, ISC2);
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCSR, ISC2);
            break;
        }
        break;
    }
}

// Enable the specified external interrupt
void EXTI_voidEnable(u8 copy_u8InterruptSource) {
    switch (copy_u8InterruptSource) {
    case EXTI_INT0:
        SET_BIT(GICR, INT0);
        break;
    case EXTI_INT1:
        SET_BIT(GICR, INT1);
        break;
    case EXTI_INT2:
        SET_BIT(GICR, INT2);
        break;
    }
}

// Disable the specified external interrupt
void EXTI_voidDisable(u8 copy_u8InterruptSource) {
    switch (copy_u8InterruptSource) {
    case EXTI_INT0:
        CLR_BIT(GICR, INT0);
        break;
    case EXTI_INT1:
        CLR_BIT(GICR, INT1);
        break;
    case EXTI_INT2:
        CLR_BIT(GICR, INT2);
        break;
    }
}

// Set a callback function for the specified external interrupt
void EXTRI_voidSetCallBackINT(u8 EXTI_Int, void (*ptrToFunction)(void)) {
    if (ptrToFunction != NULL) {
        switch (EXTI_Int) {
        case EXTI_INT0:
            private_pCallBackINT0 = ptrToFunction;
            break;
        case EXTI_INT1:
            private_pCallBackINT1 = ptrToFunction;
            break;
        case EXTI_INT2:
            private_pCallBackINT2 = ptrToFunction;
            break;
        default:
            break;
        }
    }
}

/**********************************************************************************************************
 * ISR for external interrupts (0, 1, 2)
 ********************************************************************************************************/

// ISR for External Interrupt 0
void __vector_1(void) __attribute__((signal));
void __vector_1(void) {
    // Execute INT0 callback function
    if (private_pCallBackINT0 != NULL) {
        private_pCallBackINT0();
    }
}

// ISR for External Interrupt 1
void __vector_2(void) __attribute__((signal));
void __vector_2(void) {
    // Execute INT1 callback function
    if (private_pCallBackINT1 != NULL) {
        private_pCallBackINT1();
    }
}

// ISR for External Interrupt 2
void __vector_3(void) __attribute__((signal));
void __vector_3(void) {
    // Execute INT2 callback function
    if (private_pCallBackINT2 != NULL) {
        private_pCallBackINT2();
    }
}
