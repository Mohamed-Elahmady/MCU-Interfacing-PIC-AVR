/* 
 * File:   hal_eeprom_cfg.h
 * Author: mohammedel-ahmady
 *
 * Created on August 4, 2025, 4:27 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EEPROM_CFG_H
#define	HAL_EEPROM_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define eeprom_write_cfg_disable                            0x00
#define eeprom_write_cfg_enable                             0x01
#define eeprom_read_cfg_disable                             0x00
#define eeprom_read_cfg_enable                              0x01

#define eeprom_write_cfg                                    (eeprom_write_cfg_enable)
#define eeprom_read_cfg                                     (eeprom_read_cfg_enable)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/


#endif	/* HAL_EEPROM_CFG_H */

