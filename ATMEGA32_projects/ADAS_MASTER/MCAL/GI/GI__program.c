/*
 * GI__program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: AhmedAbogabl
 */

#include "GI_interface.h"
#include "GI_register.h"
#include "../../utils/BIT_MATH.h"
#include "../../utils/STD_TYPES.h"

void GI_voidEnable(void)
{
	SET_BIT(SREG,GLE);
}

void GI_voidDisable(void)
{
	CLR_BIT(SREG,GLE);
}
