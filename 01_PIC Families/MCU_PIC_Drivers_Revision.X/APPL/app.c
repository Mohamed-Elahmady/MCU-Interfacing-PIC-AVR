/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:26 AM
 */

#include "app.h"

gpio_led led1 = {
    .pin.port = gpio_portD,
    .pin.pin = gpio_pin0,
    .pin.direction = gpio_output,
    .pin.logic = gpio_low,
    .con = led_source,
    .state = led_off
};

eusart_cfg eusart1 = {
    .tx_transmitter = {
        .tx_state = eusart_tx_enable_state,
        .tx_9bit_state = eusart_tx_9bit_disable_state,
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
        .tx_int_state = eusart_tx_interrupt_disable_state, 
        .tx_interrupt = NULL, 
        .tx_priority = interrupt_low_priority,
#endif
    },
    .rx_reciver = {
        .rx_state = eusart_rx_enable_state,
        .rx_9bit_state = eusart_rx_9bit_disable_state,
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
        .rx_int_state = eusart_rx_interrupt_disable_state,
        .rx_interrupt = NULL,
        .framing_interrupt = NULL,
        .ovverun_interrupt = NULL,
        .rx_priority = interrupt_low_priority,
#endif
    },
    .baud_rate = 9600,
    .baud_rate_cfg = eusart_async_16bit_low_speed
};

uint8 rx_data = 0;

int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    

    /* Initialize EUSART */
    ret = eusart_init(&eusart1);
    eusart_async_tx_write_string_blocking(&eusart1, (uint8*)"Loading 0.5 sec .....\r");
    __delay_ms(500);
    eusart_async_tx_write_string_blocking(&eusart1, (uint8*)"EUSART Echo Test Started...\r");
    while(1){
        ret = eusart_async_rx_read_byte_non_blocking(&eusart1, &rx_data);
        eusart_async_tx_write_byte_blocking(&eusart1, rx_data);
        rx_data = 0;
    }

    return (EXIT_SUCCESS);
}
