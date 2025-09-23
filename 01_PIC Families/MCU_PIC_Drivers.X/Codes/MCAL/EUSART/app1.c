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
////    Ret = EUSART_ASYNC_WRITE_STRING_BLOCKING(&usart_object, "Mohamed");
//    while (1) {
//        Ret = EUSART_ASYNC_WRITE_STRING_BLOCKING(&usart_object, "Mohamed\r");
//        __delay_ms(250);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, 'M');
////        __delay_ms(500);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, 'o');
////        __delay_ms(500);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, 'h');
////        __delay_ms(500);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, 'a');
////        __delay_ms(500);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, 'm');
////        __delay_ms(500);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, 'e');
////        __delay_ms(500);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, 'd');
////        __delay_ms(500);
////        Ret = EUSART_ASYNC_WRITE_BYTE_BLOCKING(&usart_object, '-');
////        __delay_ms(500);
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = EUSART_ASYNC_INIT(&usart_object);
//}