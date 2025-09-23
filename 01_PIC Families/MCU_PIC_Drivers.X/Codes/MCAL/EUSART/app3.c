///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//#include "../MCAL_Layer/EUSART/HAL_EUSART.h"
//
//Std_ReturnType Ret = E_OK;
//
//EUSART_CFG usart_object = {
//    .eusart_tx_mode.interrupt_state = EUSART_ASYNC_TX_INTERRUPT_DISABLE_STATE,
//    .eusart_tx_mode.tx_interrupt = NULL,
//    .eusart_tx_mode.tx_priority = INTERRUPT_HIGH_PRIORITY,
//    
//    .eusart_tx_mode.state = EUSART_ASYNC_TX_ENABLE_STATE,
//    .eusart_tx_mode.tx_size = EUSART_ASYNC_TX_9BIT_SIZE_DISABLE,
//    
//    .eusart_rx_mode.interrupt_state = EUSART_ASYNC_RX_INTERRUPT_DISABLE_STATE,
//    .eusart_rx_mode.rx_interrupt = NULL,
//    .eusart_rx_mode.rx_priority = INTERRUPT_HIGH_PRIORITY,
//    .eusart_rx_mode.farming_interrupt = NULL,
//    .eusart_rx_mode.farming_priority = INTERRUPT_LOW_PRIORITY,
//    .eusart_rx_mode.overrun_interrupt = NULL,
//    .eusart_rx_mode.overrun_priority = INTERRUPT_LOW_PRIORITY,
//    
//    .eusart_rx_mode.state = EUSART_ASYNC_RX_ENABLE_STATE,
//    .eusart_rx_mode.rx_size = EUSART_ASYNC_RX_9BIT_SIZE_DISABLE,
//    
//    .baud_rate = 9600,
//    .br_cfg = EUSART_BR_ASYNC_8BIT_LOW_SPEED,
//    
//    .error_states.status = 0x00
//};
//
//int main() {
//    application_init();
//    while (1) {
//        Ret = EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(&usart_object, 'A');
//        __delay_ms(200);
//        Ret = EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(&usart_object, 'B');
//        __delay_ms(200);
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = EUSART_ASYNC_INIT(&usart_object);
//}

///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//#include "../MCAL_Layer/EUSART/HAL_EUSART.h"
//
//Std_ReturnType Ret = E_OK;
//
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//EUSART_CFG usart_object = {
//    .eusart_tx_mode.interrupt_state = EUSART_ASYNC_TX_INTERRUPT_DISABLE_STATE,
//    .eusart_tx_mode.tx_interrupt = NULL,
//    .eusart_tx_mode.tx_priority = INTERRUPT_HIGH_PRIORITY,
//    
//    .eusart_tx_mode.state = EUSART_ASYNC_TX_ENABLE_STATE,
//    .eusart_tx_mode.tx_size = EUSART_ASYNC_TX_9BIT_SIZE_DISABLE,
//    
//    .eusart_rx_mode.interrupt_state = EUSART_ASYNC_RX_INTERRUPT_DISABLE_STATE,
//    .eusart_rx_mode.rx_interrupt = NULL,
//    .eusart_rx_mode.rx_priority = INTERRUPT_HIGH_PRIORITY,
//    .eusart_rx_mode.farming_interrupt = NULL,
//    .eusart_rx_mode.farming_priority = INTERRUPT_LOW_PRIORITY,
//    .eusart_rx_mode.overrun_interrupt = NULL,
//    .eusart_rx_mode.overrun_priority = INTERRUPT_LOW_PRIORITY,
//    
//    .eusart_rx_mode.state = EUSART_ASYNC_RX_ENABLE_STATE,
//    .eusart_rx_mode.rx_size = EUSART_ASYNC_RX_9BIT_SIZE_DISABLE,
//    
//    .baud_rate = 9600,
//    .br_cfg = EUSART_BR_ASYNC_8BIT_LOW_SPEED,
//    
//    .error_states.status = 0x00
//};
//
//uint8 data = 0x00;
//
//int main() {
//    application_init();
//    while (1) {
//        Ret = EUSART_ASYNC_RX_READ_BYTE_NON_BLOCKING(&usart_object, &data);
//        if(data == 'A'){
//            GPIO_LED_TURN_ON(&led1);
//            Ret = EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(&usart_object, "Led Turned On\r");
//            data = 0;
//        }
//        else if(data == 'B'){
//            GPIO_LED_TURN_OFF(&led1);
//            Ret = EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(&usart_object, "Led Turned Off\r");
//            data = 0;
//        }
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = EUSART_ASYNC_INIT(&usart_object);
//    GPIO_LED_INIT(&led1);
//}