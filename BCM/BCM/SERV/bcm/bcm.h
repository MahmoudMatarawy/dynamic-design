/*
 * bcm.h
 *
 * Created: 5/25/2023 10:10:26 PM
 *  Author: Mahmoud Sarhan
 */ 


#ifndef BCM_H_
#define BCM_H_

#include "../../STD_LIB/std_types.h"


typedef uint8_t u8_bcmError_t;

#define BCM_ERROR_OK			((u8_bcmError_t)0x00)
#define BCM_ERROR_NOT_OK		((u8_bcmError_t)0x06)

typedef enum
{
	UART = 0,
	INVALID_PROTOCOL
}en_comm_portocol_t;



typedef enum
{
	UART_0 = 0,
	INVALID_CHANNEL
}en_comm_channel_t;

typedef enum
{
	SEND = 0,
	REC,
	INVALID_OPERATION
}en_comm_operation_t;

typedef enum
{
	BYTE = 0,
	STRING,
	INVALID_OPERATION_SIZE
}en_comm_operation_size_t;



typedef struct
{
	en_comm_portocol_t comm_portocol;
	en_comm_channel_t comm_channel;
	en_comm_operation_t comm_operation;
	en_comm_operation_size_t comm_operation_size;
	 uint8_t* u8_message;
}st_bcm_instance_t;


u8_bcmError_t BCM_init(st_bcm_instance_t* st_bcm_instance_t);
u8_bcmError_t BCM_deinit(st_bcm_instance_t* st_bcm_instance_t);
u8_bcmError_t BCM_send(st_bcm_instance_t* st_bcm_instance_t);
u8_bcmError_t BCM_send_n(st_bcm_instance_t* st_bcm_instance_t);
u8_bcmError_t BCM_rec(st_bcm_instance_t* st_bcm_instance_t);
u8_bcmError_t BCM_rec_n(st_bcm_instance_t* st_bcm_instance_t);
u8_bcmError_t BCM_dispatcher(st_bcm_instance_t* st_bcm_instance_t);



#endif /* BCM_H_ */