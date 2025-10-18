/* 
 * File:   memory.h
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025, 8:14 PM
 * 
 *  Description:
 *  Memory Driver for PIC18F46K20
 *  Provides low-level access to:
 *      - FLASH Program Memory
 *      - Data EEPROM
 * 
 *  Uses Platform.h types and macros
 */

#ifndef MEMORY_H
#define	MEMORY_H

/******************* Section 1 : Includes *******************/

#include "../Platform.h"
#include <xc.h>

/******************* Section 2 : FLASH Prototypes *******************/

/**
 * @brief Write one byte to FLASH program memory.
 * @param address 16-bit program memory address.
 * @param data 8-bit data to write.
 */
void FLASH_WriteByte(uint16 address, uint8 data);

/**
 * @brief Read one byte from FLASH program memory.
 * @param address 16-bit program memory address.
 * @return 8-bit data read from memory.
 */
uint8 FLASH_ReadByte(uint16 address);

/**
 * @brief Write one 16-bit word to FLASH program memory.
 * @param address Starting address (LSB stored first).
 * @param data 16-bit word to write.
 */
void FLASH_WriteWord(uint16 address, uint16 data);

/**
 * @brief Read one 16-bit word from FLASH program memory.
 * @param address Starting address (LSB stored first).
 * @return 16-bit word read from FLASH.
 */
uint16 FLASH_ReadWord(uint16 address);

/**
 * @brief Erase a page of FLASH memory (typically 64 bytes).
 * @param pageAddress Start address of the page.
 */
void FLASH_ErasePage(uint16 pageAddress);

/******************* Section 3 : EEPROM Prototypes *******************/

/**
 * @brief Write one byte to EEPROM data memory.
 * @param address 8-bit EEPROM address.
 * @param data 8-bit data to write.
 */
void EEPROM_WriteByte(uint16 address, uint8 data);

/**
 * @brief Read one byte from EEPROM data memory.
 * @param address 8-bit EEPROM address.
 * @return 8-bit data read from EEPROM.
 */
uint8 EEPROM_ReadByte(uint16 address);

/**
 * @brief Write one 16-bit word to EEPROM (two consecutive bytes).
 * @param address 8-bit EEPROM base address.
 * @param data 16-bit word to write.
 */
void EEPROM_WriteWord(uint16 address, uint16 data);

/**
 * @brief Read one 16-bit word from EEPROM (two consecutive bytes).
 * @param address 8-bit EEPROM base address.
 * @return 16-bit word read from EEPROM.
 */
uint16 EEPROM_ReadWord(uint16 address);

#endif	/* MEMORY_H */

