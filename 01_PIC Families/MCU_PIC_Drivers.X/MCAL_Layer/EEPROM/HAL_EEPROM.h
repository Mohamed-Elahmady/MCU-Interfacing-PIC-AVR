/* 
 * File:   HAL_EEPROM.h
 * Author: mohammedel-ahmady
 *
 * Created on August 3, 2025, 11:59 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_EEPROM_CFG.h"
#include "../Interrupt/HAL_INT_INTERRUPT.h"
#include "../mcal_std_types.h"
#include "../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define EECON2_KEY1                                         (uint8)0x55
#define EECON2_KEY2                                         (uint8)0xAA

/******************* Section 3 : Macros Functions Declarations *******************/

#define EEPGD_REGISTER_ACCESS_EEPROM()                      CLEAR_BIT(EECON1, _EECON1_EEPGD_POSITION)
#define EEPGD_REGISTER_ACCESS_PROGRAM_MEMORY()              SET_BIT(EECON1, _EECON1_EEPGD_POSITION)

#define CFGS_REGISTER_ACCESS_EEPROM_PROGRAM_MEMORY()        CLEAR_BIT(EECON1, _EECON1_CFGS_POSITION)
#define CFGS_REGISTER_ACCESS_CONFUGRATION_REGISTERS()       SET_BIT(EECON1, _EECON1_CFGS_POSITION)

#define EEPROM_WRITE_DISABLE()                              CLEAR_BIT(EECON1, _EECON1_WREN_POSITION)
#define EEPROM_WRITE_ENABLE()                               SET_BIT(EECON1, _EECON1_WREN_POSITION)

#define EEPROM_SET_WRITE_CONTROL()                          SET_BIT(EECON1, _EECON1_WR_POSITION) // Clear by Hardware
#define EEPROM_SET_READ_CONTROL()                           SET_BIT(EECON1, _EECON1_RD_POSITION) // Clear by Hardware

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType EEPROM_WRITE_1BYTE(uint16 EE_add, uint8 EE_data);
Std_ReturnType EEPROM_READ_1BYTE(uint16 EE_add, uint8 *EE_data);

#endif	/* HAL_EEPROM_H */

