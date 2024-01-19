/*
 * GIE_PRIV.h
 *
 * Created: 10/22/2023 3:34:21 PM
 *  Author: ahmed radwan
 */ 


#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define ENABLE_GIE   1
#define DISABLE_GIE  0

#define GIFR    (*((volatile ptr_u8)0X5A))
#define GICR    (*((volatile ptr_u8)0X5B))
#define MCUCR   (*((volatile ptr_u8)0X55))
#define MCUCSR  (*((volatile ptr_u8)0X54))


//#define EXTI_WRITE_MODE(REG,source,mode)           (REG=((((REG>>(2*source))&mode)|mode)<<(2*source))|REG)
//#define MODIFY_BITS(byte, source, mode)			 ((byte & ~(3 << source)) | ((mode & 3) << source))



#endif /* EXTI_PRIV_H_ */