/*
 * watch_dog.c
 *
 * Created: 10/27/2023 11:14:38 AM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../SERVICES/Bit_Wise_Operations.h"
#include "../Inc/watch_dog_priv.h"
#include "../Inc/watch_dog.h"
#include "../Inc/watch_dod_cfg.h"
void watch_dog_init(void){

	WATCH_DOG_SET_PRESCALER();
	WDTCR|=(1<<4)|(1<<3);
}
void watch_dog_enable(void){
	WATCH_DOG_ENABLE();
}
void watch_dog_disable(void){
	WDTCR|=(1<<4)|(1<<3);
	WATCH_DOG_DISABLE();
	
	
}
void watch_dog_reset(void){
	WATCH_DOG_DISABLE_enable();
}