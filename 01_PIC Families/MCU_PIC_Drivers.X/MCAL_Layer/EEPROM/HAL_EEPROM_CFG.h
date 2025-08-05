/* 
 * File:   HAL_EEPROM_CFG.h
 * Author: mohammedel-ahmady
 *
 * Created on August 3, 2025, 11:59 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EEPROM_CFG_H
#define	HAL_EEPROM_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define EEPROM_WRITE_CFG_DISABLE                  0x00
#define EEPROM_WRITE_CFG_ENABLE                   0x01
#define EEPROM_READ_CFG_DISABLE                   0x00
#define EEPROM_READ_CFG_ENABLE                    0x01

#define EEPROM_WRITE_CFG                          (EEPROM_WRITE_CFG_ENABLE)
#define EEPROM_READ_CFG                           (EEPROM_READ_CFG_ENABLE)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

#endif	/* HAL_EEPROM_CFG_H */

