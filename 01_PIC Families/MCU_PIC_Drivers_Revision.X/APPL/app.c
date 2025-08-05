/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

uint8 counter = 0;
uint8 rest_counter = 0;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    
    while (1) {
        eeprom_write_one_byte(0x3FF, counter++);
        eeprom_read_one_byte(0x3FF, &rest_counter);
        __delay_ms(1000);
    }

    return (EXIT_SUCCESS);
}
