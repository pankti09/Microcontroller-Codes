
#ifndef _EEPROM_H
#define _EEPROM_H

#include <avr\io.h>

#define C_MaxEepromSize_U16 1024

typedef unsigned char   uint8_t;
typedef unsigned int    uint16_t;

void EEPROM_WriteByte(uint16_t eepromAddress_u16, uint8_t eepromData_u8);
uint8_t EEPROM_ReadByte(uint16_t eepromAddress_u16);
void EEROM_WriteString(uint16_t eepromAddress_u16, uint8_t *ptr_stringPointer_u8);
void EEPROM_ReadString(uint16_t eepromAddress_u16, uint8_t *ptrdestStringAddress_u8)

#endif







