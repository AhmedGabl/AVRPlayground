/*
 * KP_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedAbogabl
 */

#include "KP_interface.h"
#include "KP_config.h"
#include "avr/delay.h"

u8 Keys[][4] = { { '7', '8', '9', '/' }, { '4', '5', '6', '*' }, { '1', '2',
				'3', '-' }, { '.', '0', '=', '+' } };

u8 KP_GetKey() {
	u8 i, j = 0;

	for (i = 0; i < 4; i++) {
		Dio_WriteChannel(col1, !(i == 0));
		Dio_WriteChannel(col2, !(i == 1));
		Dio_WriteChannel(col3, !(i == 2));
		Dio_WriteChannel(col4, !(i == 3));

		if (!Dio_ReadChannel(row1)) {
			//_delay_ms(10); // Introduce a short delay for debouncing
			j = 1;
			while (!Dio_ReadChannel(row1));break;

		}
		if (!Dio_ReadChannel(row2)) {
			//_delay_ms(10); // Introduce a short delay for debouncing
			j = 2;
			while (!Dio_ReadChannel(row2));break;


		}
		if (!Dio_ReadChannel(row3)) {
			//_delay_ms(10); // Introduce a short delay for debouncing
			j = 3;
			while (!Dio_ReadChannel(row3));break;

		}
		if (!Dio_ReadChannel(row4)) {
			//_delay_ms(10); // Introduce a short delay for debouncing
			j = 4;
			while (!Dio_ReadChannel(row4));break;

		}
	}
	Dio_WriteChannel(col1, STD_HIGH);
	Dio_WriteChannel(col2, STD_HIGH);
	Dio_WriteChannel(col3, STD_HIGH);
	Dio_WriteChannel(col4, STD_HIGH);


	if (j == 0)
		return 0;
	else
		return (Keys[j-1][i]);
}
