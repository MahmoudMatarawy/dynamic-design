/*
 * uart_cfg.h
 *
 * Created: 5/25/2023 10:09:02 PM
 *  Author: Mahmoud Sarhan
 */ 


#ifndef UART_PRE_LINK_CFG_H_
#define UART_PRE_LINK_CFG_H_
#include "../../STD_LIB/std_types.h"
//#include <avr/io.h>
#define  F_CPU 8000000UL

typedef enum
{
	NONE = 0,
	EVEN = 2,
	ODD = 3
	}en_parity_t;


typedef enum 
{
	Asynchronous = 0,
	Synchronous
}en_synchronism_t;


typedef enum 
{
	Data_5_bit = 0,
	Data_6_bit = 1,
	Data_7_bit = 2,
	Data_8_bit = 3,
	Data_9_bit = 7
}en_dataWidth_t;

typedef enum
{
	ONE_STOP_BIT = 0,
	TWO_STOP_BIT
}en_stopBits_t;



//const uint8_t STOP_BITS	= 0;				// 0 = 1 bit			1 = 2 bit



typedef struct
{
	uint16_t baud ;
	en_parity_t PARITY;
	en_synchronism_t Mode_Select;
	en_dataWidth_t DATA_FRAME;
	en_stopBits_t STOP_BITS;
}st_uartConfig_t;

const st_uartConfig_t st_gc_uartConfig[1] = {
	{.baud = 9600,
	.DATA_FRAME = Data_8_bit,
	.Mode_Select = Asynchronous,
	.PARITY = NONE,
	.STOP_BITS = ONE_STOP_BIT}
	}; 
	
	
	
#define  baudrate ((F_CPU)/(st_gc_uartConfig[UART0].baud*16UL)-1)

#endif /* UART_PRE_LINK_CFG_H_ */