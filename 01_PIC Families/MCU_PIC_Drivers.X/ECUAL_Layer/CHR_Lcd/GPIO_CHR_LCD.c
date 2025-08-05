/* 
 * File:   GPIO_CHR_LCD.c
 * Author: mohammedel-ahmady
 *
 * Created on July 18, 2025, 2:22 PM
 */

/******************* Section 0 : Includes *******************/

#include "GPIO_CHR_LCD.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

static Std_ReturnType chr_lcd_4bit_send_4bit(const CHR_LCD_4BIT *lcd, uint8 data);
static Std_ReturnType chr_lcd_4bit_set_cursor_pos(const CHR_LCD_4BIT *lcd, uint8 row, uint8 col);
static Std_ReturnType chr_lcd_4bit_send_enable_signal(const CHR_LCD_4BIT *lcd);

static Std_ReturnType chr_lcd_8bit_set_cursor_pos(const CHR_LCD_8BIT *lcd, uint8 row, uint8 col);
static Std_ReturnType chr_lcd_8bit_send_enable_signal(const CHR_LCD_8BIT *lcd);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((GPIO_CHR_LCD_4BIT_CFG_ENABLE) == (GPIO_CHR_LCD_4BIT_CFG))

Std_ReturnType GPIO_LCD_4BIT_INIT(const CHR_LCD_4BIT *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        // Control Pins INIT
        Retval = GPIO_PIN_INIT(&(lcd->rs_pin));
        Retval = GPIO_PIN_INIT(&(lcd->rw_pin));
        Retval = GPIO_PIN_INIT(&(lcd->en_pin));
        
        // Data Pins INIT
        for(uint8 i = ZERO_INIT; i < LCD_4BIT_MODE; i++){
            Retval = GPIO_PIN_INIT(&(lcd->data_pins[i]));
        }
        
        // LCD Configurations INIT
        __delay_ms(20);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, LCD_8BIT_TWL_F58);
        __delay_ms(5);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, LCD_8BIT_TWL_F58);
        __delay_us(150);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, LCD_8BIT_TWL_F58);
        
        
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, CHR_LCD_CLEAR_SCREEN);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, CHR_LCD_CURSOR_HOME);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, LCD_EMS_INC_SFT_OFF);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, LCD_DSP_ON_ULC_OFF_BLC_OFF);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, LCD_4BIT_TWL_F58);
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, LCD_DDRAM_STA);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_4BIT_CFG_ENABLE) == (GPIO_CHR_LCD_4BIT_CFG))

Std_ReturnType GPIO_LCD_4BIT_SEND_COMMAND(const CHR_LCD_4BIT *lcd,uint8 command){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rs_pin), GPIO_LOW);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rw_pin), GPIO_LOW);
        
        Retval = chr_lcd_4bit_send_4bit(lcd, (command >> 4));
        Retval = chr_lcd_4bit_send_enable_signal(lcd);
        Retval = chr_lcd_4bit_send_4bit(lcd, (command));
        Retval = chr_lcd_4bit_send_enable_signal(lcd);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_4BIT_CFG_ENABLE) == (GPIO_CHR_LCD_4BIT_CFG))

Std_ReturnType GPIO_LCD_4BIT_SEND_CHARACTER(const CHR_LCD_4BIT *lcd, uint8 character){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rs_pin), GPIO_HIGH);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rw_pin), GPIO_LOW);
        
        Retval = chr_lcd_4bit_send_4bit(lcd, (character >> 4));
        Retval = chr_lcd_4bit_send_enable_signal(lcd);
        Retval = chr_lcd_4bit_send_4bit(lcd, (character));
        Retval = chr_lcd_4bit_send_enable_signal(lcd);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_4BIT_CFG_ENABLE) == (GPIO_CHR_LCD_4BIT_CFG))

Std_ReturnType GPIO_LCD_4BIT_SEND_CHARACTER_POS(const CHR_LCD_4BIT *lcd, uint8 character, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = chr_lcd_4bit_set_cursor_pos(lcd, row, col);
        Retval = GPIO_LCD_4BIT_SEND_CHARACTER(lcd, character);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_4BIT_CFG_ENABLE) == (GPIO_CHR_LCD_4BIT_CFG))

Std_ReturnType GPIO_LCD_4BIT_SEND_STRING(const CHR_LCD_4BIT *lcd, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            GPIO_LCD_4BIT_SEND_CHARACTER(lcd, *str);
            str++;
        }
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_4BIT_CFG_ENABLE) == (GPIO_CHR_LCD_4BIT_CFG))

Std_ReturnType GPIO_LCD_4BIT_SEND_STRING_POS(const CHR_LCD_4BIT *lcd, uint8 *str, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        Retval = chr_lcd_4bit_set_cursor_pos(lcd, row, col);
        Retval = GPIO_LCD_4BIT_SEND_STRING(lcd, str);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_4BIT_CFG_ENABLE) == (GPIO_CHR_LCD_4BIT_CFG))

Std_ReturnType GPIO_LCD_4BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_4BIT *lcd, const uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, (LCD_CGRAM_STA + (ram_pos * 8)));
        for(uint8 i = 0; i < CUSTOM_CHAR_NO; i++){
            Retval = GPIO_LCD_4BIT_SEND_CHARACTER(lcd, c_character[i]);
        }
        Retval = GPIO_LCD_4BIT_SEND_CHARACTER_POS(lcd, ram_pos, row, col);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_8BIT_CFG_ENABLE) == (GPIO_CHR_LCD_8BIT_CFG))

Std_ReturnType GPIO_LCD_8BIT_INIT(const CHR_LCD_8BIT *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        // Control Pins INIT
        Retval = GPIO_PIN_INIT(&(lcd->rs_pin));
        Retval = GPIO_PIN_INIT(&(lcd->rw_pin));
        Retval = GPIO_PIN_INIT(&(lcd->en_pin));
        
        // Data Pins INIT
        for(uint8 i = ZERO_INIT; i < LCD_8BIT_MODE; i++){
            Retval = GPIO_PIN_INIT(&(lcd->data_pins[i]));
        }
        
        // LCD Configurations INIT
        __delay_ms(20);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, LCD_8BIT_TWL_F58);
        __delay_ms(5);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, LCD_8BIT_TWL_F58);
        __delay_us(150);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, LCD_8BIT_TWL_F58);
        
        
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, CHR_LCD_CLEAR_SCREEN);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, CHR_LCD_CURSOR_HOME);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, LCD_EMS_INC_SFT_OFF);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, LCD_DSP_ON_ULC_OFF_BLC_OFF);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, LCD_8BIT_TWL_F58);
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, LCD_DDRAM_STA);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_8BIT_CFG_ENABLE) == (GPIO_CHR_LCD_8BIT_CFG))

Std_ReturnType GPIO_LCD_8BIT_SEND_COMMAND(const CHR_LCD_8BIT *lcd,uint8 command){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rs_pin), GPIO_LOW);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rw_pin), GPIO_LOW);
        
        for(uint8 i = ZERO_INIT; i < LCD_8BIT_MODE; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->data_pins[i]), (GPIO_LOGIC)READ_BIT(command, i));
        }
        Retval = chr_lcd_8bit_send_enable_signal(lcd);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_8BIT_CFG_ENABLE) == (GPIO_CHR_LCD_8BIT_CFG))

Std_ReturnType GPIO_LCD_8BIT_SEND_CHARACTER(const CHR_LCD_8BIT *lcd, uint8 character){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rs_pin), GPIO_HIGH);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->rw_pin), GPIO_LOW);
        
        for(uint8 i = ZERO_INIT; i < LCD_8BIT_MODE; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->data_pins[i]), (GPIO_LOGIC)READ_BIT(character, i));
        }
        Retval = chr_lcd_8bit_send_enable_signal(lcd);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_8BIT_CFG_ENABLE) == (GPIO_CHR_LCD_8BIT_CFG))

Std_ReturnType GPIO_LCD_8BIT_SEND_CHARACTER_POS(const CHR_LCD_8BIT *lcd, uint8 character, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = chr_lcd_8bit_set_cursor_pos(lcd, row, col);
        Retval = GPIO_LCD_8BIT_SEND_CHARACTER(lcd, character);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_8BIT_CFG_ENABLE) == (GPIO_CHR_LCD_8BIT_CFG))

Std_ReturnType GPIO_LCD_8BIT_SEND_STRING(const CHR_LCD_8BIT *lcd, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            GPIO_LCD_8BIT_SEND_CHARACTER(lcd, *(str));
            str++;
        }
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_8BIT_CFG_ENABLE) == (GPIO_CHR_LCD_8BIT_CFG))

Std_ReturnType GPIO_LCD_8BIT_SEND_STRING_POS(const CHR_LCD_8BIT *lcd, uint8 *str, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        Retval = chr_lcd_8bit_set_cursor_pos(lcd, row, col);
        GPIO_LCD_8BIT_SEND_STRING(lcd, str);
    }
    return Retval;
}

#endif

#if ((GPIO_CHR_LCD_8BIT_CFG_ENABLE) == (GPIO_CHR_LCD_8BIT_CFG))

Std_ReturnType GPIO_LCD_8BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_8BIT *lcd, const uint8 c_character[], uint8 row, uint8 col, uint8 ram_pos){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == c_character || ram_pos >= CUSTOM_CHAR_NO){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, (LCD_CGRAM_STA + (ram_pos * 8)));
        for(uint8 i = 0; i < CUSTOM_CHAR_NO; i++){
            Retval = GPIO_LCD_8BIT_SEND_CHARACTER(lcd, c_character[i]);
        }
        Retval = GPIO_LCD_8BIT_SEND_CHARACTER_POS(lcd, ram_pos, row, col);
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

static Std_ReturnType chr_lcd_4bit_send_4bit(const CHR_LCD_4BIT *lcd, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = ZERO_INIT; i < LCD_4BIT_MODE; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->data_pins[i]), (GPIO_LOGIC)READ_BIT(data, i));
        }
    }
    return Retval;
}

static Std_ReturnType chr_lcd_4bit_set_cursor_pos(const CHR_LCD_4BIT *lcd, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        col--;
        switch(row){
            case LCD_ROW1:
                Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW1_ADD + col));
                break;
            case LCD_ROW2:
                Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW2_ADD + col));
                break;
            case LCD_ROW3:
                Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW3_ADD + col));
                break;
            case LCD_ROW4:
                Retval = GPIO_LCD_4BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW4_ADD + col));
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType chr_lcd_4bit_send_enable_signal(const CHR_LCD_4BIT *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->en_pin), GPIO_HIGH);
        __delay_us(5);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->en_pin), GPIO_LOW);
    }
    return Retval;
}


static Std_ReturnType chr_lcd_8bit_set_cursor_pos(const CHR_LCD_8BIT *lcd, uint8 row, uint8 col){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        col--;
        switch(row){
            case LCD_ROW1:
                Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW1_ADD + col));
                break;
            case LCD_ROW2:
                Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW2_ADD + col));
                break;
            case LCD_ROW3:
                Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW3_ADD + col));
                break;
            case LCD_ROW4:
                Retval = GPIO_LCD_8BIT_SEND_COMMAND(lcd, (uint8)(LCD_ROW4_ADD + col));
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType chr_lcd_8bit_send_enable_signal(const CHR_LCD_8BIT *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->en_pin), GPIO_HIGH);
        __delay_us(5);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->en_pin), GPIO_LOW);
    }
    return Retval;
}