/* 
 * File:   EE24C2C.h
 * Author: mohammedel-ahmady
 *
 * Created on October 18, 2025, 4:38 PM
 */

#ifndef EE24C02C_H
#define	EE24C02C_H

#include "../configurations/i2c.h"

void EEPROM_24C02C_Write_Byte(uint8 slave_add, uint8 byte_add, uint8 data); 
uint8  EEPROM_24C02C_Read_Byte(uint8 slave_add, uint8 byte_add); 

#endif	/* EE24C02C_H */

