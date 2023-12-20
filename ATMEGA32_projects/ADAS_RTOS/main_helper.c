#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

#ifndef NULL
#define NULL (void *)0
#endif

/* Define Tasks Priorities */
#define MOTOR_DIR_PRIORITY (1)
#define ButtonOn_PRIORITY (3)

//void MOTOR_ON_Intro_code(void *pvParamter);
void MOTOR_DIR_Intro_code(void *pvParamter);
void ButtonIntro_code(void *pvParamter);

/* Create Task Handles Create */
xTaskHandle Task1Hand = NULL;
xTaskHandle Task2Hand = NULL;

char flag = 0, Onflag = 0;

int main(void)
{
    DDRA = 0x03;

    DDRB = 0x00;
    PORTB |= 0x01;

    xTaskCreate(ButtonIntro_code, (const signed char *)"Task2", 85, NULL, ButtonOn_PRIORITY, &Task2Hand);
    xTaskCreate(MOTOR_DIR_Intro_code, (const signed char *)"Task1", 85, NULL, MOTOR_DIR_PRIORITY, &Task1Hand);

    /* start Scheduler */
    vTaskStartScheduler();

    /* Never Enter Here */
    return 0;
}

/* Task1 Code */
void MOTOR_DIR_Intro_code(void *pvParamter)
{
    // vTaskDelete(&Task3Hand);
    while (1)
    {
        vTaskDelay(1000);
        if (flag == 1)
        {
        	if(Onflag == 0)
        	{
                PORTA = 0x02;
                Onflag =1 ;
        	}else{
            PORTA ^= 0x01;
            /* Send Task in Blocked Queue for 200 Ticks */
            flag = 0;
        	}
        }
    }
}

void ButtonIntro_code(void *pvParamter)
{
    while (1)
    {
        vTaskDelay(100);
        if (((PINB)&0x01) == 0)
        {
            flag = 1;
        }
    }
}
