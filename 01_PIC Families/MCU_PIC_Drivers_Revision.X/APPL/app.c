/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

chr_lcd_4bit lcd1 = {
    .rs_pin.port = gpio_portB,
    .rs_pin.pin = gpio_pin0,
    .rs_pin.direction = gpio_output,
    .rs_pin.logic = gpio_low,

    .rw_pin.port = gpio_portB,
    .rw_pin.pin = gpio_pin1,
    .rw_pin.direction = gpio_output,
    .rw_pin.logic = gpio_low,

    .en_pin.port = gpio_portB,
    .en_pin.pin = gpio_pin2,
    .en_pin.direction = gpio_output,
    .en_pin.logic = gpio_low,

    .data_pins[0].port = gpio_portC,
    .data_pins[0].pin = gpio_pin0,
    .data_pins[0].direction = gpio_output,
    .data_pins[0].logic = gpio_low,

    .data_pins[1].port = gpio_portC,
    .data_pins[1].pin = gpio_pin1,
    .data_pins[1].direction = gpio_output,
    .data_pins[1].logic = gpio_low,

    .data_pins[2].port = gpio_portC,
    .data_pins[2].pin = gpio_pin2,
    .data_pins[2].direction = gpio_output,
    .data_pins[2].logic = gpio_low,

    .data_pins[3].port = gpio_portC,
    .data_pins[3].pin = gpio_pin3,
    .data_pins[3].direction = gpio_output,
    .data_pins[3].logic = gpio_low
};

chr_lcd_8bit lcd2 = {
    .rs_pin.port = gpio_portB,
    .rs_pin.pin = gpio_pin3,
    .rs_pin.direction = gpio_output,
    .rs_pin.logic = gpio_low,

    .rw_pin.port = gpio_portB,
    .rw_pin.pin = gpio_pin4,
    .rw_pin.direction = gpio_output,
    .rw_pin.logic = gpio_low,

    .en_pin.port = gpio_portB,
    .en_pin.pin = gpio_pin5,
    .en_pin.direction = gpio_output,
    .en_pin.logic = gpio_low,

    .data_pins[0].port = gpio_portD,
    .data_pins[0].pin = gpio_pin0,
    .data_pins[0].direction = gpio_output,
    .data_pins[0].logic = gpio_low,

    .data_pins[1].port = gpio_portD,
    .data_pins[1].pin = gpio_pin1,
    .data_pins[1].direction = gpio_output,
    .data_pins[1].logic = gpio_low,

    .data_pins[2].port = gpio_portD,
    .data_pins[2].pin = gpio_pin2,
    .data_pins[2].direction = gpio_output,
    .data_pins[2].logic = gpio_low,

    .data_pins[3].port = gpio_portD,
    .data_pins[3].pin = gpio_pin3,
    .data_pins[3].direction = gpio_output,
    .data_pins[3].logic = gpio_low,

    .data_pins[4].port = gpio_portD,
    .data_pins[4].pin = gpio_pin4,
    .data_pins[4].direction = gpio_output,
    .data_pins[4].logic = gpio_low,

    .data_pins[5].port = gpio_portD,
    .data_pins[5].pin = gpio_pin5,
    .data_pins[5].direction = gpio_output,
    .data_pins[5].logic = gpio_low,

    .data_pins[6].port = gpio_portD,
    .data_pins[6].pin = gpio_pin6,
    .data_pins[6].direction = gpio_output,
    .data_pins[6].logic = gpio_low,

    .data_pins[7].port = gpio_portD,
    .data_pins[7].pin = gpio_pin7,
    .data_pins[7].direction = gpio_output,
    .data_pins[7].logic = gpio_low
};



int main() {
    Std_ReturnType ret = E_NOT_OK;

    /* Initialize both LCDs */
    ret = gpio_chr_lcd_4bit_init(&lcd1);
    ret = gpio_chr_lcd_8bit_init(&lcd2);

    /* Send Clear Display command */
    ret = gpio_chr_lcd_4bit_send_command(&lcd1, lcd_clear_display);
    ret = gpio_chr_lcd_8bit_send_command(&lcd2, lcd_clear_display);

    __delay_ms(10); // Assuming you have delay function

    /* Send character */
    ret = gpio_chr_lcd_4bit_send_character(&lcd1, 'A');
    ret = gpio_chr_lcd_8bit_send_character(&lcd2, 'B');

    __delay_ms(1000);

    /* Send character at position */
    ret = gpio_chr_lcd_4bit_send_character_pos(&lcd1, 'X', lcd_row1, 5);
    ret = gpio_chr_lcd_8bit_send_character_pos(&lcd2, 'Y', lcd_row2, 7);

    __delay_ms(1000);

    /* Send string */
    ret = gpio_chr_lcd_4bit_send_string(&lcd1, (uint8*)"4-bit LCD");
    ret = gpio_chr_lcd_8bit_send_string(&lcd2, (uint8*)"8-bit LCD");

    __delay_ms(1000);

    /* Send string at position */
    ret = gpio_chr_lcd_4bit_send_string_pos(&lcd1, (uint8*)"Hello", lcd_row2, 1);
    ret = gpio_chr_lcd_8bit_send_string_pos(&lcd2, (uint8*)"World", lcd_row1, 3);

    __delay_ms(1000);

    /* Send custom character */
    uint8 smile_face[8] = {
        0x00,
        0x0A,
        0x00,
        0x00,
        0x11,
        0x0E,
        0x00,
    };
    ret = gpio_chr_lcd_4bit_send_custom_character(&lcd1, smile_face, lcd_row1, 1, 0);
    ret = gpio_chr_lcd_8bit_send_custom_character(&lcd2, smile_face, lcd_row2, 1, 0);

    __delay_ms(1000);

    /* Convert numbers to strings and display them */
    uint8 str1[5];
    uint8 str2[6];
    uint8 str3[12];

    ret = convert_byte_to_string(123, str1);
    ret = gpio_chr_lcd_4bit_send_string_pos(&lcd1, str1, lcd_row2, 6);

    ret = convert_short_to_string(4567, str2);
    ret = gpio_chr_lcd_8bit_send_string_pos(&lcd2, str2, lcd_row1, 10);

    ret = convert_integer_to_string(900, str3);
    ret = gpio_chr_lcd_8bit_send_string_pos(&lcd2, str3, lcd_row2, 5);
    __delay_ms(1000);
    /* Send Clear Display command */
    ret = gpio_chr_lcd_4bit_send_command(&lcd1, lcd_clear_display);
    ret = gpio_chr_lcd_8bit_send_command(&lcd2, lcd_clear_display);

    while (1) {
        // Loop forever
    }

    return (EXIT_SUCCESS);
}