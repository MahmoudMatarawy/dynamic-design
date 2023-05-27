/*
 * app.c
 *
 * Created: 5/25/2023 10:07:15 PM
 *  Author: Mahmoud Sarhan
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "../HAL/led/led.h"
#include "../SERV/bcm/bcm.h"




const uint8_t u8_gc_single_message = 9;
const uint8_t u8_arr_gc_multi_message[] = "I am Mahmoud";
static uint8_t u8_gs_single_message_rx = 0;
static uint8_t u8_arr_gs_multi_message_rec[13];


static uint8_t u8_gs_send_string_result = 1;
static uint8_t u8_gs_send_byte_result = 1;
static uint8_t u8_gs_rec_string_result = 1;
static uint8_t u8_gs_rec_byte_result = 1;


st_bcm_instance_t st_bcm_instance_send_string = {
	.comm_portocol = UART,
	.comm_channel = UART_0,
	.comm_operation = SEND,
	.comm_operation_size = STRING,
	.u8_message = (uint8_t*)u8_arr_gc_multi_message
	} ;

st_bcm_instance_t st_bcm_instance_send_byte = {
	.comm_portocol = UART,
	.comm_channel = UART_0,
	.comm_operation = SEND,
	.comm_operation_size = BYTE,
	.u8_message = (uint8_t*) &u8_gc_single_message
} ;

st_bcm_instance_t st_bcm_instance_rec_byte = {
	.comm_portocol = UART,
	.comm_channel = UART_0,
	.comm_operation = REC,
	.comm_operation_size = BYTE,
	.u8_message = (uint8_t*) &u8_gs_single_message_rx
} ;


st_bcm_instance_t st_bcm_instance_rec_string = {
	.comm_portocol = UART,
	.comm_channel = UART_0,
	.comm_operation = REC,
	.comm_operation_size = STRING,
	.u8_message = (uint8_t*)u8_arr_gs_multi_message_rec
} ;


void APP_init(void);

void APP_start(void)
{
	APP_init();
	while(1)
	{
		
		
		_delay_ms(1000);
		u8_gs_send_string_result = BCM_dispatcher(&st_bcm_instance_send_string);
		if (u8_gs_send_string_result == 0)
		{
			LED_toggle(LED_0);
			u8_gs_send_string_result = 1;
			//_delay_ms(2000);
		}
		//PORTB = u8_gs_rec_string_result;
		//_delay_ms(1000);
		u8_gs_rec_string_result = BCM_dispatcher(&st_bcm_instance_rec_string);
		//PORTB = u8_gs_rec_string_result;
		if (u8_gs_rec_string_result == 0)
		{
			LED_toggle(LED_1);
			u8_gs_rec_string_result = 1;
		}
		
		
		
		/*
		u8_gs_send_string_result = BCM_dispatcher(&st_bcm_instance_send_string);
		if (u8_gs_send_string_result == 0)
		{
			LED_toggle(LED_0);
			u8_gs_send_string_result = 1;
		}
		
		u8_gs_rec_byte_result = BCM_dispatcher(&st_bcm_instance_rec_byte);
		if (u8_gs_rec_byte_result == 0)
		{
			LED_toggle(LED_1);
			u8_gs_rec_byte_result = 1;
		}
		
		u8_gs_send_byte_result = BCM_dispatcher(&st_bcm_instance_send_byte);
		if (u8_gs_send_byte_result == 0)
		{
			LED_toggle(LED_0);
			u8_gs_send_byte_result = 1;
		}
		
		*/
	}
}



void APP_init(void)
{
	//DDRB = 0xff;
	BCM_init(&st_bcm_instance_send_string);
	LED_init(LED_0);
	//LED_on(LED_0);
	LED_init(LED_1);
}