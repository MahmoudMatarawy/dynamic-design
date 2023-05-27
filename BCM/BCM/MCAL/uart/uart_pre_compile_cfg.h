/*
 * uart_pre_compile_cfg.h
 *
 * Created: 5/26/2023 3:55:50 AM
 *  Author: Mahmoud Sarhan
 */ 


#ifndef UART_PRE_COMPILE_CFG_H_
#define UART_PRE_COMPILE_CFG_H_
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

#define  baudrate ((F_CPU)/(st_uart0Config.baud*16UL)-1)


#define  PARITY			NONE
#define  STOP_BITS		ONE_STOP_BIT
#define  DATA_FRAME		Data_8_bit
#define  Mode_Select	Asynchronous

#endif /* UART_PRE_COMPILE_CFG_H_ */