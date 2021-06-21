#include "eeprom.h"
#include <avr\io.h>

void EEPROM_WriteByte(uint16_t eepromAddress_u16, uint8_t eepromData_u8)
{
	while((EECR & (1<<EEWE))!=0); // Wait for completion of previous write.
	                                 // EEWE will be cleared by hardware once Eeprom write is completed.

	EEAR = eepromAddress_u16;  //Load the eeprom address and data
	EEDR = eepromData_u8;

	EECR |= (1<<EEMWE);    // Eeprom Master Write Enable
	EECR |= (1<<EEWE);     // Start eeprom write by setting EEWE
}

uint8_t EEPROM_ReadByte(uint16_t eepromAddress_u16)
{
	while((EECR & (1<<EEWE))!=0);    //Wait for completion of previous write if any.

	EEAR = eepromAddress_u16;    //Load the address from where the data needs to be read.
	EECR |= (1<<EERE);          // start eeprom read by setting EERE

	return EEDR;             // Return data from data register
}

void EEROM_WriteString(uint16_t eepromAddress_u16, uint8_t *ptr_stringPointer_u8)
{
	do
	{
		EEPROM_WriteByte(eepromAddress_u16,*ptr_stringPointer_u8);
		ptr_stringPointer_u8++;
		eepromAddress_u16++;
	}while(*(ptr_stringPointer_u8)!='\0');
}

void EEPROM_ReadString(uint16_t eepromAddress_u16, uint8_t *ptrdestStringAddress_u8)
{
	char eeprom_data;
	
	do 
	{
		eeprom_data=EEPROM_ReadByte(eepromAddress_u16);
		*ptrdestStringAddress_u8=eeprom_data;
		ptrdestStringAddress_u8++;
		eepromAddress_u16++;
	} while (eeprom_data!=0);
}
