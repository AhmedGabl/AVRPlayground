/*
 * OS_interface.h
 **  Created on: Nov 17, 2023
 *      Author: AhmedAbogabl
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_


/*
 * OS_voidCreateTask
 */
void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Periodicity, void (*ptr)(void));

/*
 * OS_voidStartScheduler
 */
void OS_voidStartScheduler(void);

#endif /* OS_INTERFACE_H_ */
