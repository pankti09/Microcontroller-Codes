/*
 * Internal_EEPROM.c
 *
 * Created: 24-09-2018 05:12:20
 * Author : Miral
 */ 

#include <avr/io.h>
#include <avr/eeprom.h>
#include "usart.h"
#include "eeprom.h"


int main(void)
{
    /* Replace with your application code */
	unsigned int eeprom_address=0x00;
	unsigned char write_char='A';
	unsigned char read_char;
	unsigned char str1[]={"What you want to write on EEPROM?"};
	
	usart_init();
	
	usart_send_string(str1);
	
	for(write_char='A';write_char<='Z';write_char++)
	{
		EEPROM_WriteByte(eeprom_address,write_char);
		read_char=EEPROM_ReadByte(eeprom_address);
		usart_send_char(read_char);
		eeprom_address++;
	}
}

