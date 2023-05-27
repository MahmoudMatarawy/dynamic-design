/*
 * uart.h
 *
 * Created: 5/25/2023 10:08:48 PM
 *  Author: Mahmoud Sarhan
 */ 


#ifndef UART_H_
#define UART_H_

#include "../../STD_LIB/std_types.h"

typedef uint8_t u8_uartErrorType;

#define UART_ERROR_OK				((u8_uartErrorType)0x00)
#define UART_ERROR_NOT_OK			((u8_uartErrorType)0x03)


typedef enum
{
	UART0 = 0,
	INVALID_UART
}en_uartNum_t;


u8_uartErrorType UART_init(en_uartNum_t uartNum);
u8_uartErrorType UART_deinit(en_uartNum_t uartNum);
u8_uartErrorType UART_tx(uint8_t data , en_uartNum_t uartNum);
u8_uartErrorType UART_rx(uint8_t* data , en_uartNum_t uartNum);
u8_uartErrorType UART_write_string( uint8_t *n , en_uartNum_t uartNum );
u8_uartErrorType UART_read_string( uint8_t *n , en_uartNum_t uartNum );


#endif /* UART_H_ */