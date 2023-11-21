/*
 * OS_program.c
 *
 *  Created on: Nov 17, 2023
 *      Author: AhmedAbogabl
 */

#include "../utils/BIT_MATH.h"
#include "../utils/BIT_MATH.h"
#include "../MCAL/TIMERS/TIMER2/includes/TMR2_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"

Task OS_Tasks[OS_NUMBER_OF_TASKS];
static TasksCount =0 ;


u32 TickCount = 0;

void Scheduler(void) {
	u8 flag=0;

    for (u8 i = 0; i < OS_NUMBER_OF_TASKS; i++) {

        if ((OS_Tasks[i].State == OS_TASK_READY )) {
            if (OS_Tasks[i].InitialDelay == 0) {
                OS_Tasks[i].InitialDelay = OS_Tasks[i].Periodicity - 1;
                OS_Tasks[i].Fptr();
            } else {
                OS_Tasks[i].InitialDelay--;
            }
        }
    }
    TickCount++;
}

/*
 * OS_voidCreateTask
 */
void OS_voidCreateTask(u8 Copy_u8ID,u8 Copy_u8Priority, u16 Copy_u8Periodicity, u16 Copy_u8InitialDelay, void (*ptr)(void)) {
if(TasksCount < OS_NUMBER_OF_TASKS){
	OS_Tasks[TasksCount].Priority = Copy_u8Priority;
	OS_Tasks[TasksCount].Fptr = ptr;
    OS_Tasks[TasksCount].InitialDelay = Copy_u8InitialDelay;
    OS_Tasks[TasksCount].Periodicity = Copy_u8Periodicity;
    OS_Tasks[TasksCount].State = OS_TASK_READY;
    OS_Tasks[TasksCount].TaskID = Copy_u8ID;
    TasksCount++;
}
}

/*
 * OS_voidDeleteTask
 */
void OS_voidDeleteTask(u8 Copy_u8ID) {
	u8 i;
	for( i=0; i<TasksCount ;i++){
		if(OS_Tasks[i].TaskID ==Copy_u8ID )
    OS_Tasks[i].State = OS_TASK_DELETED;
}
}
/*
 * OS_voidSuspendTask
 */
void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime) {
	u8 i;
		for( i=0; i < TasksCount ;i++){
			if(OS_Tasks[i].TaskID ==Copy_u8ID ){
    OS_Tasks[i].State = OS_TASK_SUSPENDED;
    OS_Tasks[i].SuspendTime = Copy_u8SuspendTime + TickCount;
			}
}
}
/*
 * OS_voidStartScheduler
 */
void OS_voidStartScheduler(void) {
    // Initialize Timer/Counter 2
    TMR2_voidInit();

    // Start Timer/Counter 2
    TMR2_voidStart();

    // Set a callback function to be called on Timer/Counter 2 overflow
    TMR2_voidSetCallBackOVF(Scheduler);
}

/*
 * OS_voidResumeTask
 */
void OS_voidResumeTask(u8 Copy_u8ID) {
	u8 i;
		for( i=0; i<TasksCount ;i++){
			if(OS_Tasks[i].TaskID ==Copy_u8ID )
    OS_Tasks[i].State = OS_TASK_READY;
}
}

/*
 * OS_u8GetTaskState
 */

u8 OS_u8GetTaskState(u8 Copy_u8ID) {
	u8 i;
		for( i=0; i<TasksCount ;i++){
			if(OS_Tasks[i].TaskID ==Copy_u8ID )
				return OS_Tasks[i].State;
		}
}
