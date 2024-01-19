/*
 * SPI.h
 *
 * Created: 10/29/2023 9:22:14 AM
 *  Author: ahmed radwan
 */ 


#ifndef SPI_H_
#define SPI_H_

#define SPI_INT_ENABLE()							SET_BIT(SPCR,7)
#define SPI_INT_DISABLE()							CLR_BIT(SPCR,7)

#define SPI_ENABLE()								SET_BIT(SPCR,6)
#define SPI_DISABLE()								CLR_BIT(SPCR,6)

#define SPI_MSB_FIRST()							CLR_BIT(SPCR,5)
#define SPI_LSB_FIRST()							SET_BIT(SPCR,5)

#define SPI_MASTER_MODE_SLECT()					SET_BIT(SPCR,4)
#define SPI_SLAVE_MODE_SLECT()					CLR_BIT(SPCR,4)

#define SPI_CLOCK_IDLE_HIGH()				SET_BIT(SPCR,3)
#define SPI_CLOCK_IDLE_LOW()				CLR_BIT(SPCR,3)

#define SPI_CLOCK_LEADING_SAMPLE()				CLR_BIT(SPCR,2)
#define SPI_CLOCK_TRAILING_SAMPLE()				SET_BIT(SPCR,2)

#define SPI_FREQ(freq)							do{SPCR|=(freq&0x03);\
												   SPSR|=(freq&0x04);\
													}while(0)



#define SPI_INT_FLAG_STATUS()                    GET_BIT(SPSR,7)

#define WRITE_COLLISION_FLAG()                    GET_BIT(SPSR,6)

typedef enum{
	SPI_MSB_FIRST_CFG,
	SPI_LSB_FIRST_CFG
}SPI_enuData_Order_T;

typedef enum{
	SPI_FOSC_DIV_4,
	SPI_FOSC_DIV_16,
	SPI_FOSC_DIV_64,
	SPI_FOSC_DIV_128,
	SPI_FOSC_DIV_2,
	SPI_FOSC_DIV_8,
	SPI_FOSC_DIV_32,
	}SPI_enuFREQ_T;
	
typedef enum{
	SPI_SLAVE_MODE,
	SPI_MASTER_MODE
	}SPI_enuMode_T;
	
typedef enum{
	SPI_CLOCK_SAMPLE_LEADING,
	SPI_CLOCK_SAMPLE_TRAILING
}SPI_enuCLOCK_PHASE_T;

typedef enum{
	SPI_CLOCK_IDEL_LOW,
	SPI_CLOCK_IDEL_HIGH
}SPI_enuCLOCK_POLATITY_T;
typedef enum{
	SPI_INT_EN_CFG,
	SPI_INT_DIS_CFG
}SPI_enuINT_T;
	
typedef struct{
	SPI_enuMode_T mode_s;
	SPI_enuCLOCK_POLATITY_T CLK_polarity;
	SPI_enuCLOCK_PHASE_T CLK_phase;
	SPI_enuFREQ_T freq_cfg;
	SPI_enuData_Order_T dataorder;
	CALL_BACK_FN_TYPE SPI_CALL_BACK;
	SPI_enuINT_T SPI_interrupt_cfg;
	}SPI_st_T;
	

typedef enum{
	SPI_ENOK,
	SPI_EOK,
	SPI_NULLPTR
}SPI_enuError_T;

SPI_enuError_T spi_INT(SPI_st_T*SPI);
SPI_enuError_T spi_transmit(SPI_st_T*SPI,u8 data);
SPI_enuError_T spi_Recive_bolling(SPI_st_T*SPI,u8*rdata);
SPI_enuError_T spi_SendRecive(u8 data,u8* recived);
SPI_enuError_T spi_SendRecive_ASYNC(u8 data,u8* recived);
SPI_enuError_T spi_Recive_ASYNC(u8* recived);
SPI_enuError_T spi_Update_Recive(u8 data,u8* recived);





#endif /* SPI_H_ */