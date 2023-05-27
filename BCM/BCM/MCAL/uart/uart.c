/*
 * uart.c
 *
 * Created: 5/25/2023 10:09:54 PM
 *  Author: Mahmoud Sarhan
 */ 

#include "uart_pre_link_cfg.h"
#include "uart.h"
#include "uart_private_reg.h"

#define INIT		1
#define NOT_INIT	0


extern const st_uartConfig_t st_gc_uartConfig[1];

//extern const uint8_t STOP_BITS;
/*extern const uint8_t Mode_Select;
extern const uint8_t DATA_FRAME;
extern const uint8_t PARITY;*/




static uint8_t u8_uart_state[INVALID_UART] = {NOT_INIT};


u8_uartErrorType UART_init(en_uartNum_t uartNum)
{
	uint8_t u8_retVal = UART_ERROR_OK;
	switch(uartNum)
	{
		case UART0 :
		{
			UBRRH0  = (baudrate>>8);
			UBRRL0  = baudrate ;
			UCSRB0 |= (1<<TXEN0)|(1<<RXEN0);
			UCSRC0 |= (1<<URSEL0)|(st_gc_uartConfig[UART0].DATA_FRAME<<1) | (st_gc_uartConfig[UART0].PARITY<<4) | (st_gc_uartConfig[UART0].STOP_BITS<<3) | (st_gc_uartConfig[UART0].Mode_Select<<6);
			u8_uart_state[UART0] = INIT;
			break;
		}
		default:
		{
			u8_retVal = UART_ERROR_NOT_OK;
			break;
		}
	}
	return u8_retVal;
}


u8_uartErrorType UART_deinit(en_uartNum_t uartNum)
{
	uint8_t u8_retVal = UART_ERROR_OK;
	switch(uartNum)
	{
		case UART0 :
		{
			UBRRH0  = NOT_INIT;
			UBRRL0  = NOT_INIT ;
			UCSRB0  = NOT_INIT;
			UCSRC0  = NOT_INIT;
			u8_uart_state[UART0] = NOT_INIT;
			break;
		}
		default:
		{
			u8_retVal = UART_ERROR_NOT_OK;
			break;
		}
	}
	return u8_retVal;
}





u8_uartErrorType UART_tx(uint8_t data , en_uartNum_t uartNum)
{
	uint8_t u8_retVal = UART_ERROR_OK;
	switch(uartNum)
	{
		case UART0:
		{
			if (u8_uart_state[UART0] == INIT)
			{
				while(!( UCSRA0 & (1<<UDRE0)));		/* Wait for empty transmit buffer */
				UDR0 = data;						/* Put data into buffer, sends the data */
			}
			else{
				u8_retVal = UART_ERROR_NOT_OK;
			}
			break;
		}
		default:
		{
			u8_retVal = UART_ERROR_NOT_OK;
			break;
		}
	}
	
	return u8_retVal;					
}

u8_uartErrorType UART_rx(uint8_t* data , en_uartNum_t uartNum)
{
	uint8_t u8_retVal = UART_ERROR_OK;
	switch(uartNum)
	{
		case UART0:
		{
			if (u8_uart_state[UART0] == INIT)
			{
				while (! ((UCSRA0) & (1<<RXC0)));
				* data = UDR0;
			}
			else{
				u8_retVal = UART_ERROR_NOT_OK;
			}
			break;
		}
		default:
		{
			u8_retVal = UART_ERROR_NOT_OK;
			break;
		}
	}
	
	return u8_retVal ;
}


u8_uartErrorType UART_read_string( uint8_t *n , en_uartNum_t uartNum )
{
	uint8_t u8_retVal = UART_ERROR_OK;
	switch(uartNum)
	{
		case UART0:
		{
			if (u8_uart_state[UART0] == INIT)
			{
				uint8_t x=0 ;
				n[0] = 48;
				do 
				{
					u8_retVal = UART_rx(&n[x],uartNum);
					x++;
				} while (n[x-1]!='\0');
			}
			else{
				u8_retVal = UART_ERROR_NOT_OK;
			}
			break;
		}
		default:
		{
			u8_retVal = UART_ERROR_NOT_OK;
			break;
		}
	}
	
	return u8_retVal ;
}




u8_uartErrorType UART_write_string( uint8_t *n , en_uartNum_t uartNum)
{
	uint8_t u8_retVal = UART_ERROR_OK;
	switch(uartNum)
	{
		case UART0:
		{
			if (u8_uart_state[UART0] == INIT)
			{
				for (uint8_t x=0 ; n[x]!='\0' ; x++)
				{
					u8_retVal = UART_tx(n[x],uartNum);
				}
				u8_retVal = UART_tx('\0',uartNum);
			}
			else{
				u8_retVal = UART_ERROR_NOT_OK;
			}
			break;
		}
		default:
		{
			u8_retVal = UART_ERROR_NOT_OK;
			break;
		}
	}
	
	return u8_retVal ;
}