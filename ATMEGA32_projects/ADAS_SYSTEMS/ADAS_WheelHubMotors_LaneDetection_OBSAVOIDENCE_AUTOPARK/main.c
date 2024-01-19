/*
 * main.c
 * Description: automotive ecu resposible for whm bluetooth control and some auculery functions
 * Author: AhmedAbogabl
 * Created on: Oct 17, 2023
 */

#include "utils/BIT_MATH.h"
#include "utils/STD_TYPES.h"
#include "APP/ADAS_APP.h"

int main(void) {
	HW_init();
	while (1){
        WHM();
    }
    return 0;
}