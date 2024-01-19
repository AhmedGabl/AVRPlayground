/*
 * GIE.c
 *
 * Created: 10/22/2023 3:29:07 PM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../SERVICES/Bit_Wise_Operations.h"
#include "../Inc/GIE_PRIV.h"
#include "../Inc/GIE_CFG.h"
#include "../Inc/GIE.h"
/**
 * @brief initialize the GIE BIT in the SREG register depending on the configuration in the GIE_CFG.h file
 */
void GIE_INIT(void)
{
 	switch(GIE_STATE)
	 {
		 case ENABLE_GIE:
		 SET_BIT(SREG,7);
		 break;
		 case DISABLE_GIE:
		 CLR_BIT(SREG,7);
		 break;
	 }
	 
}
/**
 * @brief Enable the GIE BIT int he SREG register 
 */
void GIE_Enable(void)
{
	SET_BIT(SREG,7);
}
/**
 * @brief Disable the GIE BIT int he SREG register 
 */
void GIE_Disable(void)
{
	CLR_BIT(SREG,7);
}
/**
 * @brief get the value of the GIE BIT int he SREG register
 * @return value of the bit
 */
u8 GIE_Get_Status(void)
{
	return GET_BIT(SREG,7);
}