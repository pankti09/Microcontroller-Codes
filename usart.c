/*
 * usart.c
 *
 * Created: 22-11-2017 14:48:05
 *  Author: hiteshpatel
 */ 


#include "usart.h"
#include <avr/io.h>
//#include <avr/interrupt.h>

//#define F_CPU 8000000UL
//#define USART_BAUDRATE 9600
//#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void usart_init()
{
	UCSRB |= (1 << RXEN) | (1 << TXEN) ;   	// Turn on the transmission reception ..
	// circuitry and receiver interrupt
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes

	UBRRL = 0x33; 	// Load lower 8-bits of the baud rate value..
	// into the low byte of the UBRR register
	//UBRRH = (BAUD_PRESCALE >> 8); 	// Load upper 8-bits of the baud rate value..
	// into the high byte of the UBRR register
}

void usart_send_char(unsigned char ch)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR=ch;
}

void usart_send_string(unsigned char *str)
{
	while(*str!='\0')
	{
	      while(!(UCSRA & (1<<UDRE)));
	      UDR=*str;
		  str++;	
	}
}

unsigned char usart_receive()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}