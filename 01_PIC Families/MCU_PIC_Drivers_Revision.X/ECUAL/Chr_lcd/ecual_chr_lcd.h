/* 
 * File:   ecual_chr_lcd.h
 * Author: mohammedel-ahmady
 *
 * Created on July 21, 2025, 7:51 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_CHR_LCD_H
#define	ECUAL_CHR_LCD_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecual_chr_lcd_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

// Clear Display
#define lcd_clear_display                       (uint8)0x01
// Return Home
#define lcd_cursor_home                         (uint8)0x02    
// Entry Mode Set
#define lcd_ems_dec_sft_off                     (uint8)0x04
#define lcd_ems_dec_sft_on                      (uint8)0x05
#define lcd_ems_inc_sft_off                     (uint8)0x06
#define lcd_ems_inc_sft_on                      (uint8)0x07
// Display on/off control
#define lcd_dsp_off                             (uint8)0x08
#define lcd_dsp_on_ulc_off_blc_off              (uint8)0x0C
#define lcd_dsp_on_ulc_off_blc_on               (uint8)0x0D
#define lcd_dsp_on_ulc_on_blc_off               (uint8)0x0E
#define lcd_dsp_on_ulc_on_blc_on                (uint8)0x0F
// Move cursor or display shift
#define lcd_mvc_left                            (uint8)0x10
#define lcd_mvc_right                           (uint8)0x14
#define lcd_sfd_left                            (uint8)0x18
#define lcd_sfd_right                           (uint8)0x1C
// Function Set
#define lcd_4bit_onl_f58                        (uint8)0x20
#define lcd_4bit_onl_f511                       (uint8)0x24
#define lcd_4bit_twl_f58                        (uint8)0x28
#define lcd_4bit_twl_f511                       (uint8)0x2C

#define lcd_8bit_onl_f58                        (uint8)0x30
#define lcd_8bit_onl_f511                       (uint8)0x34
#define lcd_8bit_twl_f58                        (uint8)0x38
#define lcd_8bit_twl_f511                       (uint8)0x3C
// Set CGRAM address
#define lcd_cgram_sta                           (uint8)0x40
// Set DDRAM address
#define lcd_ddram_sta                           (uint8)0x80

/*----------------------------------------------------------------------------*/

#define lcd_row1                                (uint8)0x01
#define lcd_row2                                (uint8)0x02
#define lcd_row3                                (uint8)0x03
#define lcd_row4                                (uint8)0x04

#define lcd_row1_add                            (uint8)0x80
#define lcd_row2_add                            (uint8)0xC0
#define lcd_row3_add                            (uint8)0x94
#define lcd_row4_add                            (uint8)0xD4

#define lcd_4bit_mode                           (uint8)0x04
#define lcd_8bit_mode                           (uint8)0x08

#define custom_char_no                          (uint8)0x08

/*----------------------------------------------------------------------------*/


/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef struct{
    gpio_pin_cfg rs_pin;
    gpio_pin_cfg rw_pin;
    gpio_pin_cfg en_pin;
    gpio_pin_cfg data_pins[lcd_4bit_mode];
}chr_lcd_4bit;

typedef struct{
    gpio_pin_cfg rs_pin;
    gpio_pin_cfg rw_pin;
    gpio_pin_cfg en_pin;
    gpio_pin_cfg data_pins[lcd_8bit_mode];
}chr_lcd_8bit;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType gpio_chr_lcd_4bit_init(const chr_lcd_4bit *lcd);
Std_ReturnType gpio_chr_lcd_4bit_send_command(const chr_lcd_4bit *lcd, uint8 command);
Std_ReturnType gpio_chr_lcd_4bit_send_character(const chr_lcd_4bit *lcd, uint8 character);
Std_ReturnType gpio_chr_lcd_4bit_send_character_pos(const chr_lcd_4bit *lcd, uint8 character, uint8 row, uint8 col);
Std_ReturnType gpio_chr_lcd_4bit_send_string(const chr_lcd_4bit *lcd, uint8 *str);
Std_ReturnType gpio_chr_lcd_4bit_send_string_pos(const chr_lcd_4bit *lcd, uint8 *str, uint8 row, uint8 col);
Std_ReturnType gpio_chr_lcd_4bit_send_custom_character(const chr_lcd_4bit *lcd, uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos);

Std_ReturnType gpio_chr_lcd_8bit_init(const chr_lcd_8bit *lcd);
Std_ReturnType gpio_chr_lcd_8bit_send_command(const chr_lcd_8bit *lcd, uint8 command);
Std_ReturnType gpio_chr_lcd_8bit_send_character(const chr_lcd_8bit *lcd, uint8 character);
Std_ReturnType gpio_chr_lcd_8bit_send_character_pos(const chr_lcd_8bit *lcd, uint8 character, uint8 row, uint8 col);
Std_ReturnType gpio_chr_lcd_8bit_send_string(const chr_lcd_8bit *lcd, uint8 *str);
Std_ReturnType gpio_chr_lcd_8bit_send_string_pos(const chr_lcd_8bit *lcd, uint8 *str, uint8 row, uint8 col);
Std_ReturnType gpio_chr_lcd_8bit_send_custom_character(const chr_lcd_8bit *lcd, uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos);

Std_ReturnType convert_byte_to_string(uint8 data, uint8 *str);
Std_ReturnType convert_short_to_string(uint16 data, uint8 *str);
Std_ReturnType convert_integer_to_string(uint32 data, uint8 *str);

#endif	/* ECUAL_CHR_LCD_H */

