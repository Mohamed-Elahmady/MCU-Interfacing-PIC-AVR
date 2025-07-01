/* 
 * File:   hal_gpio_cfg.h
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:36 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_GPIO_CFG_H
#define	HAL_GPIO_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define gpio_pin_cfg_disable                            0x00
#define gpio_pin_cfg_enable                             0x01
#define gpio_port_cfg_disable                           0x00
#define gpio_port_cfg_enable                            0x01

#define gpio_pin_cfg_t                                 (gpio_pin_cfg_enable)
#define gpio_port_cfg_t                                (gpio_port_cfg_enable)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

#endif	/* HAL_GPIO_CFG_H */

