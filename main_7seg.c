/*
 * Seven_segment.c
 *
 * Author : Sagar
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	unsigned char dig[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    while (1) 
    {
		for (unsigned char i=0;i<10;i++)
		{
			PORTD = dig[i];
			_delay_ms(1000);
		}
    }
}

