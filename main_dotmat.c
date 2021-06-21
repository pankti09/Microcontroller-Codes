/*
 * Dot_matrix.c
 *
 * Author : Sagar
 */ 

#include <avr/io.h>
#include <util/delay.h>

unsigned char row[]={0xB0,0xB6,0xB6,0xB6,0x86};
unsigned char col[]={0x01,0x02,0x04,0x08,0x10};
int main(void)
{
	DDRD |= 0x7F;
	DDRB |= 0x1F;
    while (1) 
    {
		for(int j=0;j<100;j++)
		{
			for(int i=0;i<5;i++)
			{
			
			PORTD |= 0x7F;
			PORTB |= 0x1F;
			PORTD = row[i];	
			PORTB = col[i];
			_delay_ms(1);
			}
		}
    }
}

