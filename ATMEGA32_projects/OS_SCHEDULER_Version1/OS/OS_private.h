/*
 * OS_private.h
 *
 *  Created on: Nov 17, 2023
 *      Author: AhmedAbogabl
 *
 */

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

typedef struct{
	u16 Periodicity;
	u8 TaskID;
	void (*Fptr)(void);
}Task;

void Scheduler(void);


#endif /* OS_PRIVATE_H_ */
