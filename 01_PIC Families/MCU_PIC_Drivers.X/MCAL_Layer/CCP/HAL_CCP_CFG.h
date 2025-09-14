 /* 
 * File:   HAL_CCP_CFG.h
 * Author: mohammedel-ahmady
 *
 * Created on September 3, 2025, 3:23 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_CCP_CFG_H
#define	HAL_CCP_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define CCP_CFG_CAPTURE_MODE_SELECTED              0x00
#define CCP_CFG_COMPARE_MODE_SELECTED              0x01
#define CCP_CFG_PWM_MODE_SELECTED                  0x02

#define CCP1_CFG_SELECTED_MODE                     (CCP_CFG_COMPARE_MODE_SELECTED)
#define CCP2_CFG_SELECTED_MODE                     (CCP_CFG_PWM_MODE_SELECTED)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

#endif	/* HAL_CCP_CFG_H */

