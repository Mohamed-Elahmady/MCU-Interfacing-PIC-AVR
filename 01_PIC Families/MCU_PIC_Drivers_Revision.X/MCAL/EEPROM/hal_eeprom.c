/* 
 * File:   hal_eeprom.c
 * Author: mohammedel-ahmady
 *
 * Created on August 4, 2025, 4:26 PM
 */

/******************* Section 0 : Includes *******************/

#include "hal_eeprom.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType eeprom_write_one_byte(uint16 ee_add, uint8 ee_data){
    Std_ReturnType Retval = E_OK;
    
    // 0. save global interrupt state
    uint8 global_interrupt_state = INTCONbits.GIE;
    // 1. Address the eeprom loaction
    EEADRH = (uint8)((ee_add >> 8) & 0x03);
    EEADR = (uint8)(ee_add & 0xFF);
    // 2. Assign Data in eeprom
    EEDATA = (uint8)ee_data;
    // 3. clear EEPGD 
    eepgd_access_eeprom_memory();
    // 4. clear CFGS
    cfgs_access_eeprom_program_memory();
    // 9. set EEPROM Write Enable
    eeprom_write_enable();
    // 6. disable global interrupt
    INTCONbits.GIE = (uint8)0x00;
    // 7. Set EECON2 Keys
    EECON2 = eepcon_key1;
    EECON2 = eepcon_key2;
    // 8. Set Write control "cleared by mcu"
    eeprom_set_write_control();
    // 9. Wait until the data write
    while(EECON1bits.WR);
    // 10. Clear EEPROM Write Enable
    eeprom_write_disable();
    // 11. Set global interrupt_status
    INTCONbits.GIE = global_interrupt_state;
}
Std_ReturnType eeprom_read_one_byte(uint16 ee_add, uint8 *ee_data){
    Std_ReturnType Retval = E_OK;
    if(NULL == ee_data){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Address the eeprom loaction
        EEADRH = (uint8)((ee_add >> 8) & 0x03);
        EEADR = (uint8)(ee_add & 0xFF);
        // 2. clear EEPGD 
        eepgd_access_eeprom_memory();
        // 3. clear CFGS
        cfgs_access_eeprom_program_memory();
        // 4. Set read control "cleared by mcu"
        eeprom_set_read_control();
        // 5. Wait to 2 No instruction Operation
        NOP();
        NOP();
        // 6. return data
        *ee_data = EEDATA;
    }
}

/******************* Section 4:  Helper Functions Definitions *******************/


