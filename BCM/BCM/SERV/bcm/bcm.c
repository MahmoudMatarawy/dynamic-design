/*
 * bcm.c
 *
 * Created: 5/25/2023 10:10:11 PM
 *  Author: Mahmoud Sarhan
 */ 
#include "bcm.h"
#include "../../MCAL/uart/uart.h"

#define NOT_INIT		0
#define INIT			1

static uint8_t u8_gs_bcmUartState[INVALID_UART] = {NOT_INIT} ; 



u8_bcmError_t BCM_init(st_bcm_instance_t* st_bcm_instance_t)
{
	uint8_t u8_retVal = BCM_ERROR_OK;
	if (st_bcm_instance_t == NULL)
	{
		u8_retVal = BCM_ERROR_NOT_OK;
	}
	else
	{
		if (st_bcm_instance_t->comm_portocol == UART)
		{
			if (st_bcm_instance_t->comm_channel == UART_0 && u8_gs_bcmUartState[UART_0] == NOT_INIT)
			{
				u8_retVal = UART_init(UART0);
				u8_gs_bcmUartState[UART_0] = INIT;
			}
			else
			{
				u8_retVal = BCM_ERROR_NOT_OK;
			}
		}
		else
		{
			u8_retVal = BCM_ERROR_NOT_OK;
		}
	}
	return u8_retVal;
}
u8_bcmError_t BCM_deinit(st_bcm_instance_t* st_bcm_instance_t)
{
	uint8_t u8_retVal = BCM_ERROR_OK;
	if (st_bcm_instance_t == NULL)
	{
		u8_retVal = BCM_ERROR_NOT_OK;
	}
	else
	{
		if (st_bcm_instance_t->comm_portocol == UART)
		{
			if (st_bcm_instance_t->comm_channel == UART_0 && u8_gs_bcmUartState[UART_0] == INIT)
			{
				u8_retVal = UART_deinit(UART0);
				u8_gs_bcmUartState[UART_0] = NOT_INIT;
			}
			else
			{
				u8_retVal = BCM_ERROR_NOT_OK;
			}
		}
		else
		{
			u8_retVal = BCM_ERROR_NOT_OK;
		}
	}
	return u8_retVal;
}
u8_bcmError_t BCM_send(st_bcm_instance_t* st_bcm_instance_t)
{
	uint8_t u8_retVal = BCM_ERROR_OK;
	if (st_bcm_instance_t == NULL)
	{
		u8_retVal = BCM_ERROR_NOT_OK;
	}
	else
	{
		if (st_bcm_instance_t->comm_portocol == UART)
		{
			if (st_bcm_instance_t->comm_channel == UART_0 && u8_gs_bcmUartState[UART_0] == INIT)
			{
				u8_retVal = UART_tx(*st_bcm_instance_t->u8_message ,UART0);
			}
			else
			{
				u8_retVal = BCM_ERROR_NOT_OK;
			}
		}
		else
		{
			u8_retVal = BCM_ERROR_NOT_OK;
		}
	}
	return u8_retVal;
}
u8_bcmError_t BCM_send_n(st_bcm_instance_t* st_bcm_instance_t)
{
	uint8_t u8_retVal = BCM_ERROR_OK;
	if (st_bcm_instance_t == NULL)
	{
		u8_retVal = BCM_ERROR_NOT_OK;
	}
	else
	{
		if (st_bcm_instance_t->comm_portocol == UART)
		{
			if (st_bcm_instance_t->comm_channel == UART_0 && u8_gs_bcmUartState[UART_0] == INIT)
			{
				u8_retVal = UART_write_string(st_bcm_instance_t->u8_message , UART0);
			}
			else
			{
				u8_retVal = BCM_ERROR_NOT_OK;
			}
		}
		else
		{
			u8_retVal = BCM_ERROR_NOT_OK;
		}
	}
	return u8_retVal;
}
u8_bcmError_t BCM_rec(st_bcm_instance_t* st_bcm_instance_t)
{
	uint8_t u8_retVal = BCM_ERROR_OK;
	if (st_bcm_instance_t == NULL)
	{
		u8_retVal = BCM_ERROR_NOT_OK;
	}
	else
	{
		if (st_bcm_instance_t->comm_portocol == UART)
		{
			if (st_bcm_instance_t->comm_channel == UART_0 && u8_gs_bcmUartState[UART_0] == INIT)
			{
				u8_retVal = UART_rx(st_bcm_instance_t->u8_message ,UART0);
			}
			else
			{
				u8_retVal = BCM_ERROR_NOT_OK;
			}
		}
		else
		{
			u8_retVal = BCM_ERROR_NOT_OK;
		}
	}
	return u8_retVal;
}
u8_bcmError_t BCM_rec_n(st_bcm_instance_t* st_bcm_instance_t)
{
	uint8_t u8_retVal = BCM_ERROR_OK;
	if (st_bcm_instance_t == NULL)
	{
		u8_retVal = BCM_ERROR_NOT_OK;
	}
	else
	{
		if (st_bcm_instance_t->comm_portocol == UART)
		{
			if (st_bcm_instance_t->comm_channel == UART_0 && u8_gs_bcmUartState[UART_0] == INIT)
			{
				u8_retVal = UART_read_string(st_bcm_instance_t->u8_message ,UART0);
			}
			else
			{
				u8_retVal = BCM_ERROR_NOT_OK;
			}
		}
		else
		{
			u8_retVal = BCM_ERROR_NOT_OK;
		}
	}
	return u8_retVal;
}
u8_bcmError_t BCM_dispatcher(st_bcm_instance_t* st_bcm_instance_t)
{
	uint8_t u8_retVal = BCM_ERROR_OK;
	if (st_bcm_instance_t == NULL)
	{
		u8_retVal = BCM_ERROR_NOT_OK;
	}
	else
	{
		switch(st_bcm_instance_t->comm_operation)
		{
			case SEND:
			{
				switch(st_bcm_instance_t->comm_operation_size)
				{
					case BYTE:
					{
						switch(st_bcm_instance_t->comm_portocol)
						{
							case UART:
							{
								u8_retVal = BCM_send(st_bcm_instance_t);
								break;
							}
							default:
							{
								u8_retVal = BCM_ERROR_NOT_OK;
								break;
							}
						}
						break;
					}
					case STRING:
					{
						switch(st_bcm_instance_t->comm_portocol)
						{
							case UART:
							{
								u8_retVal = BCM_send_n(st_bcm_instance_t);
								break;
							}
							default:
							{
								u8_retVal = BCM_ERROR_NOT_OK;
								break;
							}
						}
						break;
					}
					default:
					{
						u8_retVal = BCM_ERROR_NOT_OK;
						break;
					}
					
				}
				break;
			}
			case REC:
			{
				switch(st_bcm_instance_t->comm_operation_size)
				{
					case BYTE:
					{
						switch(st_bcm_instance_t->comm_portocol)
						{
							case UART:
							{
								u8_retVal = BCM_rec(st_bcm_instance_t);
								break;
							}
							default:
							{
								u8_retVal = BCM_ERROR_NOT_OK;
								break;
							}
						}
						break;
					}
					case STRING:
					{
						switch(st_bcm_instance_t->comm_portocol)
						{
							case UART:
							{
								u8_retVal = BCM_rec_n(st_bcm_instance_t);
								break;
							}
							default:
							{
								u8_retVal = BCM_ERROR_NOT_OK;
								break;
							}
						}
						break;
					}
					default:
					{
						u8_retVal = BCM_ERROR_NOT_OK;
						break;
					}
					
				}
				break;
			}
			
			default:
			{
				u8_retVal = BCM_ERROR_NOT_OK;
				break;
			}
			
		}
	}
	return u8_retVal;
}