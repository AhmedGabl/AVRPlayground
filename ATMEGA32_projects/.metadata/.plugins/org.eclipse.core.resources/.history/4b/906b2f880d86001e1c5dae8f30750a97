

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"



/* Define Tasks Priorities */
#define  LedOn_PRIORITY (2)

/*tasks codes prototypes */
 void LedIntro_code( void* pvParamter);


 /*Create Task Handles Create */
 xTaskHandle Task1Hand = NULL;


 int main(void)
{
	/*initialize DIO*/
	DDRB |= 0x01;
	/*Create tasks*/
	xTaskCreate(LedIntro_code,(const signed char *)"Task1",85,NULL,LedOn_PRIORITY,&Task1Hand);

	/*start Scheduler */
	vTaskStartScheduler();

	/*Never Enter Here */
	return 0;
}

/*Task1 Code */
 void LedIntro_code(void*pvParamter)
{
	for (;;)
	{

		/*Toggle Led */
		PORTB |= 0x01;

		/*Send Task in Blocked Queue for 2000 Ticks */
		vTaskDelay(2000);

		/*Toggle Led */
		PORTB &= 0xFE;

		/*Send Task in Blocked Queue for 2000 Ticks */
		vTaskDelay(2000);
	}
}
