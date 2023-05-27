/*
 * uart_private_reg.h
 *
 * Created: 5/26/2023 2:43:58 AM
 *  Author: Mahmoud Sarhan
 */ 


#ifndef UART_PRIVATE_REG_H_
#define UART_PRIVATE_REG_H_


#define UBRRL0		(*((volatile uint8_t *) 0x29))
#define UBRRH0		(*((volatile uint8_t *) 0x40))
#define UCSRA0		(*((volatile uint8_t *) 0x2B))
#define UCSRB0		(*((volatile uint8_t *) 0x2A))
#define UCSRC0		(*((volatile uint8_t *) 0x40))
#define UDR0			(*((volatile uint8_t *) 0x2C))




/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0

/* SPCR */
#define SPIE0    7
#define SPE0     6
#define DORD0    5
#define MSTR0    4
#define CPOL0    3
#define CPHA0    2
#define SPR10    1
#define SPR00    0

/* UCSRA */
#define RXC0    7
#define TXC0    6
#define UDRE0   5
#define FE0     4
#define DOR0     3
#define PE0      2
#define U2X0     1
#define MPCM0    0

/* UCSRB */
#define RXCIE0   7
#define TXCIE0   6
#define UDRIE0   5
#define RXEN0    4
#define TXEN0    3
#define UCSZ20   2
#define RXB80    1
#define TXB80    0

/* UCSRC */
#define URSEL0   7
#define UMSEL0   6
#define UPM10    5
#define UPM00    4
#define USBS0    3
#define UCSZ10   2
#define UCSZ00   1
#define UCPOL0   0


#endif /* UART_PRIVATE_REG_H_ */