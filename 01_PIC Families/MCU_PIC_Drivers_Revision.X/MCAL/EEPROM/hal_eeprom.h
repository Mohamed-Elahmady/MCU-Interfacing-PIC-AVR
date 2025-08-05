/* 
 * File:   hal_eeprom.h
 * Author: mohammedel-ahmady
 *
 * Created on August 4, 2025, 4:26 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/******************* Section 1 : Includes *******************/

#include "../mcu_cfg.h"
#include "hal_eeprom_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define eepcon_key1                                          (uint8)0x55
#define eepcon_key2                                          (uint8)0xAA

/******************* Section 3 : Macros Functions Declarations *******************/

#define eepgd_access_eeprom_memory()                         (EECON1bits.EEPGD = (uint8)0x00)
#define eepgd_access_program_memory()                        (EECON1bits.EEPGD = (uint8)0x01)

#define cfgs_access_eeprom_program_memory()                  (EECON1bits.CFGS = (uint8)0x00)
#define cfgs_access_configuration_register()                 (EECON1bits.CFGS = (uint8)0x01)

#define eeprom_write_disable()                               (EECON1bits.WREN = (uint8)0x00)
#define eeprom_write_enable()                                (EECON1bits.WREN = (uint8)0x01)

// write/read control cleared by microcontroller after operation
#define eeprom_set_write_control()                           (EECON1bits.WR = (uint8)0x01)
#define eeprom_set_read_control()                            (EECON1bits.RD = (uint8)0x01)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType eeprom_write_one_byte(uint16 ee_add, uint8 ee_data);
Std_ReturnType eeprom_read_one_byte(uint16 ee_add, uint8 *ee_data);


#endif	/* HAL_EEPROM_H */

