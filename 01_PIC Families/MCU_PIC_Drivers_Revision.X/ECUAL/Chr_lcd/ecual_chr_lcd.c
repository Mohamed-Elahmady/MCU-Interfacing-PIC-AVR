/* 
 * File:   ecual_chr_lcd.c
 * Author: mohammedel-ahmady
 *
 * Created on July 21, 2025, 7:51 PM
 */


/******************* Section 0 : Includes *******************/

#include "ecual_chr_lcd.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

static Std_ReturnType lcd_4bit_send_4bit(const chr_lcd_4bit *lcd, uint8 data);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit *lcd, uint8 row, uint8 col);
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit *lcd);

static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit *lcd, uint8 row, uint8 col);
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit *lcd);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((gpio_chr_lcd_4bit_cfg_enable) == (gpio_chr_lcd_4bit_cfg))

Std_ReturnType gpio_chr_lcd_4bit_init(const chr_lcd_4bit *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        // control pins init
        Retval = gpio_pin_init(&(lcd->rs_pin));
        Retval = gpio_pin_init(&(lcd->rw_pin));
        Retval = gpio_pin_init(&(lcd->en_pin));
        
        // data pins init
        for(uint8 i = 0; i < lcd_4bit_mode; i++){
            Retval = gpio_pin_init(&(lcd->data_pins[i]));
        }
        
        __delay_ms(20);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_8bit_twl_f58);
        __delay_ms(5);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_8bit_twl_f58);
        __delay_us(150);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_8bit_twl_f58);
        
        
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_clear_display);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_cursor_home);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_ems_inc_sft_off);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_dsp_on_ulc_off_blc_off);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_4bit_twl_f58);
        Retval = gpio_chr_lcd_4bit_send_command(lcd, lcd_ddram_sta);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_4bit_send_command(const chr_lcd_4bit *lcd, uint8 command){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_write_logic(&(lcd->rs_pin), gpio_low);
        Retval = gpio_pin_write_logic(&(lcd->rw_pin), gpio_low);
        
        Retval = lcd_4bit_send_4bit(lcd, command >> 4);
        Retval = lcd_4bit_send_enable_signal(lcd);
        Retval = lcd_4bit_send_4bit(lcd, command);
        Retval = lcd_4bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_4bit_send_character(const chr_lcd_4bit *lcd, uint8 character){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_write_logic(&(lcd->rs_pin), gpio_high);
        Retval = gpio_pin_write_logic(&(lcd->rw_pin), gpio_low);
        
        Retval = lcd_4bit_send_4bit(lcd, character >> 4);
        Retval = lcd_4bit_send_enable_signal(lcd);
        Retval = lcd_4bit_send_4bit(lcd, character);
        Retval = lcd_4bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_4bit_send_character_pos(const chr_lcd_4bit *lcd, uint8 character, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_4bit_set_cursor(lcd, row, col);
        Retval = gpio_chr_lcd_4bit_send_character(lcd, character);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_4bit_send_string(const chr_lcd_4bit *lcd, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            gpio_chr_lcd_4bit_send_character(lcd, *str);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_4bit_send_string_pos(const chr_lcd_4bit *lcd, uint8 *str, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_4bit_set_cursor(lcd, row, col);
        Retval = gpio_chr_lcd_4bit_send_string(lcd, str);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_4bit_send_custom_character(const chr_lcd_4bit *lcd, uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_chr_lcd_4bit_send_command(lcd, (lcd_cgram_sta + (ram_pos * 8)));
        
        for(uint8 i = 0; i < custom_char_no; i++){
            Retval = gpio_chr_lcd_4bit_send_character(lcd, c_character[i]);
        }
        
        Retval = gpio_chr_lcd_4bit_send_character_pos(lcd, ram_pos, row, col);
    }
    return Retval;
}


#endif

#if ((gpio_chr_lcd_8bit_cfg_enable) == (gpio_chr_lcd_8bit_cfg))

Std_ReturnType gpio_chr_lcd_8bit_init(const chr_lcd_8bit *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        // control pins init
        Retval = gpio_pin_init(&(lcd->rs_pin));
        Retval = gpio_pin_init(&(lcd->rw_pin));
        Retval = gpio_pin_init(&(lcd->en_pin));
        
        // data pins init
        for(uint8 i = 0; i < lcd_8bit_mode; i++){
            Retval = gpio_pin_init(&(lcd->data_pins[i]));
        }
        
        // lcd_configurations
        __delay_ms(20);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_8bit_twl_f58);
        __delay_ms(5);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_8bit_twl_f58);
        __delay_us(150);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_8bit_twl_f58);
        
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_clear_display);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_cursor_home);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_ems_inc_sft_off);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_dsp_on_ulc_off_blc_off);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_8bit_twl_f58);
        Retval = gpio_chr_lcd_8bit_send_command(lcd, lcd_ddram_sta);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_8bit_send_command(const chr_lcd_8bit *lcd, uint8 command){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_write_logic(&(lcd->rs_pin), gpio_low);
        Retval = gpio_pin_write_logic(&(lcd->rw_pin), gpio_low);
        
        for(uint8 i = 0; i < lcd_8bit_mode; i++){
            Retval = gpio_pin_write_logic(&(lcd->data_pins[i]), ((gpio_logic)((command >> i) & 0x01)));
        }
        
        Retval =lcd_8bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_8bit_send_character(const chr_lcd_8bit *lcd, uint8 character){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_write_logic(&(lcd->rs_pin), gpio_high);
        Retval = gpio_pin_write_logic(&(lcd->rw_pin), gpio_low);
        
        for(uint8 i = 0; i < lcd_8bit_mode; i++){
            Retval = gpio_pin_write_logic(&(lcd->data_pins[i]), ((gpio_logic)((character >> i) & 0x01)));
        }
        
        Retval =lcd_8bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_8bit_send_character_pos(const chr_lcd_8bit *lcd, uint8 character, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_8bit_set_cursor(lcd, row, col);
        Retval = gpio_chr_lcd_8bit_send_character(lcd, character);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_8bit_send_string(const chr_lcd_8bit *lcd, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            Retval = gpio_chr_lcd_8bit_send_character(lcd, *str);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_8bit_send_string_pos(const chr_lcd_8bit *lcd, uint8 *str, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_8bit_set_cursor(lcd, row, col);
        gpio_chr_lcd_8bit_send_string(lcd, str);
    }
    return Retval;
}

Std_ReturnType gpio_chr_lcd_8bit_send_custom_character(const chr_lcd_8bit *lcd, uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == c_character || ram_pos >= custom_char_no){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_chr_lcd_8bit_send_command(lcd, (lcd_cgram_sta + (ram_pos * 8)));
        
        for(uint8 i = 0; i < custom_char_no; i++){
            Retval = gpio_chr_lcd_8bit_send_character(lcd, c_character[i]);
        }
        
        Retval = gpio_chr_lcd_8bit_send_character_pos(lcd, ram_pos, row, col);
    }
    return Retval;
}


#endif

Std_ReturnType convert_byte_to_string(uint8 data, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        memset(str, '\0', 4);
        sprintf(str, "%i", data);
    }
    return Retval;
}
Std_ReturnType convert_short_to_string(uint16 data, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        memset(str, '\0', 6);
        sprintf(str, "%i", data);
    }
    return Retval;
}
Std_ReturnType convert_integer_to_string(uint32 data, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        memset(str, '\0', 11);
        sprintf(str, "%i", data);
    }
    return Retval;
}

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType lcd_4bit_send_4bit(const chr_lcd_4bit *lcd, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = 0; i < lcd_4bit_mode; i++){
            Retval = gpio_pin_write_logic(&(lcd->data_pins[i]), ((gpio_logic)((data >> i) & 0x01)));
        }
    }
    return Retval;
}
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit *lcd, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        col--;
        switch(row){
            case lcd_row1:
                Retval = gpio_chr_lcd_4bit_send_command(lcd, (lcd_row1_add + col));
                break;
            case lcd_row2:
                Retval = gpio_chr_lcd_4bit_send_command(lcd, (lcd_row2_add + col));
                break;
            case lcd_row3:
                Retval = gpio_chr_lcd_4bit_send_command(lcd, (lcd_row3_add + col));
                break;
            case lcd_row4:
                Retval = gpio_chr_lcd_4bit_send_command(lcd, (lcd_row4_add + col));
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_write_logic(&(lcd->en_pin), gpio_high);
        __delay_us(5);
        Retval = gpio_pin_write_logic(&(lcd->en_pin), gpio_low);
    }
    return Retval;
}

static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit *lcd, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        col--;
        switch(row){
            case lcd_row1:
                Retval = gpio_chr_lcd_8bit_send_command(lcd, (lcd_row1_add + col));
                break;
            case lcd_row2:
                Retval = gpio_chr_lcd_8bit_send_command(lcd, (lcd_row2_add + col));
                break;
            case lcd_row3:
                Retval = gpio_chr_lcd_8bit_send_command(lcd, (lcd_row3_add + col));
                break;
            case lcd_row4:
                Retval = gpio_chr_lcd_8bit_send_command(lcd, (lcd_row4_add + col));
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_write_logic(&(lcd->en_pin), gpio_high);
        __delay_us(5);
        Retval = gpio_pin_write_logic(&(lcd->en_pin), gpio_low);
    }
    return Retval;
}
