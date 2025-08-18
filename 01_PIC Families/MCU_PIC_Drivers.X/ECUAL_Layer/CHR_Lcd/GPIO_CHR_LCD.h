/* 
 * File:   GPIO_CHR_LCD.h
 * Author: mohammedel-ahmady
 *
 * Created on July 18, 2025, 2:22 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef GPIO_CHR_LCD_H
#define	GPIO_CHR_LCD_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "GPIO_CHR_LCD_CFG.h"

/******************* Section 2 : Macros Declarations *******************/

//----------------------------------------------------------------------------//

// Clear Display
#define CHR_LCD_CLEAR_SCREEN                    (uint8)0x01
// Return Home
#define CHR_LCD_CURSOR_HOME                     (uint8)0x02
// Entry Mode Set
#define LCD_EMS_DEC_SFT_OFF                     (uint8)0x04
#define LCD_EMS_DEC_SFT_ON                      (uint8)0x05
#define LCD_EMS_INC_SFT_OFF                     (uint8)0x06
#define LCD_EMS_INC_SFT_ON                      (uint8)0x07
// Display on/off control
#define LCD_DSP_OFF                             (uint8)0x08
#define LCD_DSP_ON_ULC_OFF_BLC_OFF              (uint8)0x0C
#define LCD_DSP_ON_ULC_OFF_BLC_ON               (uint8)0x0D
#define LCD_DSP_ON_ULC_ON_BLC_OFF               (uint8)0x0E
#define LCD_DSP_ON_ULC_ON_BLC_ON                (uint8)0x0F
// Move cursor or display shift
#define LCD_MVC_LEFT                            (uint8)0x10
#define LCD_MVC_RIGHT                           (uint8)0x14
#define LCD_SFD_LEFT                            (uint8)0x18
#define LCD_SFD_RIGHT                           (uint8)0x1C
// Function Set
#define LCD_4BIT_ONL_F58                        (uint8)0x20
#define LCD_4BIT_ONL_F511                       (uint8)0x24
#define LCD_4BIT_TWL_F58                        (uint8)0x28
#define LCD_4BIT_TWL_F511                       (uint8)0x2C

#define LCD_8BIT_ONL_F58                        (uint8)0x30
#define LCD_8BIT_ONL_F511                       (uint8)0x34
#define LCD_8BIT_TWL_F58                        (uint8)0x38
#define LCD_8BIT_TWL_F511                       (uint8)0x3C
// Set CGRAM address
#define LCD_CGRAM_STA                           (uint8)0x40
// Set DDRAM address
#define LCD_DDRAM_STA                           (uint8)0x80

//----------------------------------------------------------------------------//

#define LCD_4BIT_MODE                           (uint8)0x04
#define LCD_8BIT_MODE                           (uint8)0x08

#define LCD_ROW1                                (uint8)0x01
#define LCD_ROW2                                (uint8)0x02
#define LCD_ROW3                                (uint8)0x03
#define LCD_ROW4                                (uint8)0x04

#define LCD_ROW1_ADD                            (uint8)0x80
#define LCD_ROW2_ADD                            (uint8)0xC0
#define LCD_ROW3_ADD                            (uint8)0x94
#define LCD_ROW4_ADD                            (uint8)0xD4

#define CUSTOM_CHAR_NO                          (uint8)0x08

//----------------------------------------------------------------------------//

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef struct {
    GPIO_PIN_CFG rs_pin;
    GPIO_PIN_CFG rw_pin;
    GPIO_PIN_CFG en_pin;
    GPIO_PIN_CFG data_pins[LCD_4BIT_MODE];
}CHR_LCD_4BIT;

typedef struct {
    GPIO_PIN_CFG rs_pin;
    GPIO_PIN_CFG rw_pin;
    GPIO_PIN_CFG en_pin;
    GPIO_PIN_CFG data_pins[LCD_8BIT_MODE];
}CHR_LCD_8BIT;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType GPIO_LCD_4BIT_INIT(const CHR_LCD_4BIT *lcd);
Std_ReturnType GPIO_LCD_4BIT_SEND_COMMAND(const CHR_LCD_4BIT *lcd,uint8 command);
Std_ReturnType GPIO_LCD_4BIT_SEND_CHARACTER(const CHR_LCD_4BIT *lcd, uint8 character);
Std_ReturnType GPIO_LCD_4BIT_SEND_CHARACTER_POS(const CHR_LCD_4BIT *lcd, uint8 character, uint8 row, uint8 col);
Std_ReturnType GPIO_LCD_4BIT_SEND_STRING(const CHR_LCD_4BIT *lcd, uint8 *str);
Std_ReturnType GPIO_LCD_4BIT_SEND_STRING_POS(const CHR_LCD_4BIT *lcd, uint8 *str, uint8 row, uint8 col);
Std_ReturnType GPIO_LCD_4BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_4BIT *lcd, const uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos);

Std_ReturnType GPIO_LCD_8BIT_INIT(const CHR_LCD_8BIT *lcd);
Std_ReturnType GPIO_LCD_8BIT_SEND_COMMAND(const CHR_LCD_8BIT *lcd,uint8 command);
Std_ReturnType GPIO_LCD_8BIT_SEND_CHARACTER(const CHR_LCD_8BIT *lcd, uint8 character);
Std_ReturnType GPIO_LCD_8BIT_SEND_CHARACTER_POS(const CHR_LCD_8BIT *lcd, uint8 character, uint8 row, uint8 col);
Std_ReturnType GPIO_LCD_8BIT_SEND_STRING(const CHR_LCD_8BIT *lcd, uint8 *str);
Std_ReturnType GPIO_LCD_8BIT_SEND_STRING_POS(const CHR_LCD_8BIT *lcd, uint8 *str, uint8 row, uint8 col);
Std_ReturnType GPIO_LCD_8BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_8BIT *lcd, const uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos);

Std_ReturnType convert_uint8_to_string(uint8 data, uint8 *str);
Std_ReturnType convert_uint16_to_string(uint16 data, uint8 *str);
Std_ReturnType convert_uint32_to_string(uint32 data, uint8 *str);

#endif	/* GPIO_CHR_LCD_H */

