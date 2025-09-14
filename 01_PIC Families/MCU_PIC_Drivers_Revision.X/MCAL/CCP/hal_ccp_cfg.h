/* 
 * File:   hal_ccp_cfg.h
 * Author: mohammedel-ahmady
 *
 * Created on September 11, 2025, 10:58 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_CCP_CFG_H
#define	HAL_CCP_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define ccp_cfg_capture_mode_selected                          0x00
#define ccp_cfg_compare_mode_selected                          0x01
#define ccp_cfg_pwm_mode_selected                              0x02

#define ccp1_cfg_mode_selected                                 (ccp_cfg_compare_mode_selected)
#define ccp2_cfg_mode_selected                                 (ccp_cfg_pwm_mode_selected)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

#endif	/* HAL_CCP_CFG_H */

