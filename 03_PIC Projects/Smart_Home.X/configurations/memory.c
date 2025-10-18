/* 
 * File:   memory.c
 * Author: mohammedel-ahmady
 * 
 * Created on October 17, 2025, 9:10 PM
 * 
 * Description:
 *  Implementation of low-level memory access functions
 *  for PIC18F46K20 (FLASH + EEPROM)
 * 
 *  All functions are blocking and use register-level access.
 */

#include "memory.h"

/***********************************************************/
/********************** FLASH SECTION **********************/
/***********************************************************/

/**
 * @brief Write a single byte to FLASH program memory.
 */
void FLASH_WriteByte(uint16 address, uint8 data)
{
    // Load address into Table Pointer
    TBLPTRU = 0x00;                                // Upper 8 bits always 0 in 64KB space
    TBLPTRH = (uint8)(address >> 8);
    TBLPTRL = (uint8)(address & 0xFF);

    // Load data into latch
    TABLAT = data;

    // Configure access to FLASH
    EECON1bits.EEPGD = 1; // Access program memory
    EECON1bits.CFGS  = 0; // Access Flash, not config
    EECON1bits.WREN  = 1; // Enable write

    // Disable interrupts during unlock
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;

    // Begin write
    EECON1bits.WR = 1;

    // Wait until write completes
    while (EECON1bits.WR);

    // Restore state
    INTCONbits.GIE = 1;
    EECON1bits.WREN = 0;
}

/**
 * @brief Read a single byte from FLASH program memory.
 */
uint8 FLASH_ReadByte(uint16 address)
{
    // Load address
    TBLPTRU = 0x00;
    TBLPTRH = (uint8)(address >> 8);
    TBLPTRL = (uint8)(address & 0xFF);

    // Perform table read
    asm("TBLRD*");
    return TABLAT;
}

/**
 * @brief Write 16-bit word to FLASH memory (2 bytes).
 */
void FLASH_WriteWord(uint16 address, uint16 data)
{
    FLASH_WriteByte(address, (uint8)(data & 0xFF));        // LSB
    FLASH_WriteByte(address + 1, (uint8)((data >> 8)));    // MSB
}

/**
 * @brief Read 16-bit word from FLASH memory (2 bytes).
 */
uint16 FLASH_ReadWord(uint16 address)
{
    uint8 low  = FLASH_ReadByte(address);
    uint8 high = FLASH_ReadByte(address + 1);
    return ((uint16)high << 8) | low;
}

/**
 * @brief Erase 1 page (64 bytes) by overwriting with 0xFF.
 */
void FLASH_ErasePage(uint16 pageAddress)
{
    for (uint16 i = 0; i < 64; i++)
    {
        FLASH_WriteByte(pageAddress + i, 0xFF);
    }
}

/***********************************************************/
/********************** EEPROM SECTION *********************/
/***********************************************************/

/**
 * @brief Write a single byte to EEPROM.
 */
void EEPROM_WriteByte(uint16 address, uint8 data)
{
    while (EECON1bits.WR);   // Wait if previous write still active

    EEADR = address;         // Load EEPROM address
    EEDATA = data;           // Load data

    EECON1bits.EEPGD = 0;    // Select data EEPROM
    EECON1bits.CFGS  = 0;    // Access memory, not config
    EECON1bits.WREN  = 1;    // Enable write

    INTCONbits.GIE = 0;      // Disable global interrupts
    EECON2 = 0x55;           // Required unlock sequence
    EECON2 = 0xAA;
    EECON1bits.WR = 1;       // Begin write

    while (EECON1bits.WR);   // Wait until done

    INTCONbits.GIE = 1;      // Re-enable interrupts
    EECON1bits.WREN = 0;     // Disable write
}

/**
 * @brief Read a single byte from EEPROM.
 */
uint8 EEPROM_ReadByte(uint16 address)
{
    EEADR = address;
    EECON1bits.EEPGD = 0; // Select data EEPROM
    EECON1bits.CFGS  = 0; // Access EEPROM
    EECON1bits.RD = 1;    // Trigger read
    return EEDATA;
}

/**
 * @brief Write 16-bit word to EEPROM (2 consecutive bytes).
 */
void EEPROM_WriteWord(uint16 address, uint16 data)
{
    EEPROM_WriteByte(address, (uint8)(data & 0xFF));       // LSB
    EEPROM_WriteByte(address + 1, (uint8)((data >> 8)));   // MSB
}

/**
 * @brief Read 16-bit word from EEPROM (2 consecutive bytes).
 */
uint16 EEPROM_ReadWord(uint16 address)
{
    uint8 low  = EEPROM_ReadByte(address);
    uint8 high = EEPROM_ReadByte(address + 1);
    return ((uint16)high << 8) | low;
}