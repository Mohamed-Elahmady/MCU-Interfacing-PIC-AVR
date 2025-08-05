/* 
 * File:   HAL_EEPROM.c
 * Author: mohammedel-ahmady
 *
 * Created on August 3, 2025, 11:59 PM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_EEPROM.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((EEPROM_WRITE_CFG_ENABLE) == (EEPROM_WRITE_CFG))

/**
 * @brief           : This function writes one byte into the internal EEPROM memory
 * @param EE_add    : The address in EEPROM memory to write the byte to
 * @param EE_data   : The data byte to be written
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 */

Std_ReturnType EEPROM_WRITE_1BYTE(uint16 EE_add, uint8 EE_data){
    Std_ReturnType Retval = E_OK;
    
    // 0. Save Global interrupt Enable bit status 
    uint8 Global_Interrupt_Status = INTCONbits.GIE;
    // 1. Address the location u need to write
    EEADRH = (uint8)((EE_add >> 8) & 0x03);
    EEADR  = (uint8)(EE_add & 0xFF);
    // 2. Write Data in data register
    EEDATA = EE_data;
    // 3. Clear EEPGD
    EEPGD_REGISTER_ACCESS_EEPROM();
    // 4. Clear CFGS
    CFGS_REGISTER_ACCESS_EEPROM_PROGRAM_MEMORY();
    // 5. Enable Write in EEPROM WREN
    EEPROM_WRITE_ENABLE();
    // 6. Disable Global Interrupt
    INTCONbits.GIE = (uint8)0x00;
    // 7. Set EECON2 Keys
    EECON2 = EECON2_KEY1;
    EECON2 = EECON2_KEY2;
    // 8. Enable EEPROM Write Control "CLeared by MCU"
    EEPROM_SET_WRITE_CONTROL();
    // 9. Wait until the WR is Cleared by MCU
    while(EECON1bits.WR);
    // 10. Disable Write in EEPROM WREN
    EEPROM_WRITE_DISABLE();
    // 11. Assign Global interrupt status again
    INTCONbits.GIE = Global_Interrupt_Status;
    
    return Retval;
}

#endif 

#if ((EEPROM_READ_CFG_ENABLE) == (EEPROM_READ_CFG))

/**
 * @brief           : This function reads one byte from the internal EEPROM memory
 * @param EE_add    : The address in EEPROM memory to read the byte from
 * @param EE_data   : Pointer to a variable to store the read data
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function failed due to null pointer input
 */

Std_ReturnType EEPROM_READ_1BYTE(uint16 EE_add, uint8 *EE_data){
    Std_ReturnType Retval = E_OK;
    if(NULL == EE_data){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Assign Address to EEADR
        EEADRH = (uint8)((EE_add >> 8) & 0x03);
        EEADR = (uint8)(EE_add& 0xFF);
        // 2. Clear EEPGD
        EEPGD_REGISTER_ACCESS_EEPROM();
        // 3. Clear CFGS
        CFGS_REGISTER_ACCESS_EEPROM_PROGRAM_MEMORY();
        // 4. Enable EEPROM Write Control "CLeared by MCU"
        EEPROM_SET_READ_CONTROL();
        // 5. Wait for 2 no instruction operation
        NOP();
        NOP();
        // 6. return data
        *EE_data = EEDATA; 
    }
    return Retval;
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/
