/*
 * DC_motor.c
 *
 * Author : Sagar
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD |= 0x03;
    while (1) 
    {
		PORTD |= 0x01;
		PORTD &= 0xFD;
		_delay_ms(500);
		PORTD |= 0x02;
		PORTD &= 0xFE;
		_delay_ms(500);
    }
}

