/*
 * BCM.c
 *
 * Created: 5/25/2023 10:04:02 PM
 * Author : Mahmoud Sarhan
 */ 
#include "MCAL/uart/uart.h"
int main(void)
{
	UART_init(UART0);
	UART_write_string((uint8_t *)" Enter .",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 1 For : Adding user . ",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 2 For : Deleting user . ",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 3 For : Opening the gate . ",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 4 For : Closing the gate . ",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 5 For : Users information . ",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 6 For : changing user's password .",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 7 For : Stopping the Buzzer .",UART0);
	UART_tx(13,UART0);
	UART_write_string((uint8_t *)" 8 For : Setting time and date .",UART0);
	UART_tx(13,UART0);
    /* Replace with your application code */
    while (1) 
    {
    }
}

