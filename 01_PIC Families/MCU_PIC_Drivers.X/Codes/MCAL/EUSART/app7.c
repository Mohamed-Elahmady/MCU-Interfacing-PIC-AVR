/////* 
//// * File:   Main.c
//// * Author: Mohammed.El-Ahmady
//// *
//// * Created on June 21, 2025, 4:00 AM
//// */
////
////#include "Main.h"
////
////Std_ReturnType Ret = E_OK;
////
////void eusart_rx_isr(void);
////
//////GPIO_LED led00 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
////GPIO_LED led01 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
////
////EUSART_CFG usart_object = {
////    .eusart_tx_mode.interrupt_state = EUSART_ASYNC_TX_INTERRUPT_DISABLE_STATE,
////    .eusart_tx_mode.tx_interrupt = NULL,
////    .eusart_tx_mode.tx_priority = INTERRUPT_HIGH_PRIORITY,
////    
////    .eusart_tx_mode.state = EUSART_ASYNC_TX_ENABLE_STATE,
////    .eusart_tx_mode.tx_size = EUSART_ASYNC_TX_9BIT_SIZE_DISABLE,
////    
////    .eusart_rx_mode.interrupt_state = EUSART_ASYNC_RX_INTERRUPT_ENABLE_STATE,
////    .eusart_rx_mode.rx_priority = INTERRUPT_HIGH_PRIORITY,
////    .eusart_rx_mode.rx_interrupt = eusart_rx_isr,
////    .eusart_rx_mode.farming_interrupt = NULL,
////    .eusart_rx_mode.overrun_interrupt = NULL,
////    
////    .eusart_rx_mode.state = EUSART_ASYNC_RX_ENABLE_STATE,
////    .eusart_rx_mode.rx_size = EUSART_ASYNC_RX_9BIT_SIZE_DISABLE,
////    
////    .baud_rate = 9600,
////    .br_cfg = EUSART_BR_ASYNC_8BIT_LOW_SPEED,
////    
////    .error_states.status = 0x00
////};
////
////uint8 data = 0, data_flag = 0;
////
////int main() {
////    application_init();
////    EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(&usart_object, 'a');
////    while (1) {
////    }
////    return (EXIT_SUCCESS);
////}
////
////void application_init(void) {
////    ECUAL_LAYER_INIT();
////    Ret = EUSART_ASYNC_INIT(&usart_object);
//////    GPIO_LED_INIT(&led00);
////    GPIO_LED_INIT(&led01);
////}
////
////void eusart_rx_isr(void){
////    Ret = EUSART_ASYNC_RX_READ_BYTE_NON_BLOCKING(&usart_object, &data);
////    data_flag = 1;
////    if(data == 'c'){
////        GPIO_LED_TURN_ON(&led01);
////        EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(&usart_object, 'a');
////    }
////    if(data == 'd'){
////        GPIO_LED_TURN_OFF(&led01);
////        EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(&usart_object, 'b');
////    }
////}
//
//
///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//Std_ReturnType Ret = E_OK;
//
//void eusart_rx_isr(void);
//
//GPIO_LED led00 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
////GPIO_LED led01 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//EUSART_CFG usart_object = {
//    .eusart_tx_mode.interrupt_state = EUSART_ASYNC_TX_INTERRUPT_DISABLE_STATE,
//    .eusart_tx_mode.tx_interrupt = NULL,
//    .eusart_tx_mode.tx_priority = INTERRUPT_HIGH_PRIORITY,
//    
//    .eusart_tx_mode.state = EUSART_ASYNC_TX_ENABLE_STATE,
//    .eusart_tx_mode.tx_size = EUSART_ASYNC_TX_9BIT_SIZE_DISABLE,
//    
//    .eusart_rx_mode.interrupt_state = EUSART_ASYNC_RX_INTERRUPT_ENABLE_STATE,
//    .eusart_rx_mode.rx_priority = INTERRUPT_HIGH_PRIORITY,
//    .eusart_rx_mode.rx_interrupt = eusart_rx_isr,
//    .eusart_rx_mode.farming_interrupt = NULL,
//    .eusart_rx_mode.overrun_interrupt = NULL,
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
//uint8 data = 0, data_flag = 0;
//
//int main() {
//    application_init();
//    while (1) {
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = EUSART_ASYNC_INIT(&usart_object);
//    GPIO_LED_INIT(&led00);
////    GPIO_LED_INIT(&led01);
//}
//
//void eusart_rx_isr(void){
//    Ret = EUSART_ASYNC_RX_READ_BYTE_NON_BLOCKING(&usart_object, &data);
//    data_flag = 1;
//    if(data == 'a'){
//        GPIO_LED_TURN_ON(&led00);
//        EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(&usart_object, 'd');
//        __delay_ms(250);
//    }
//    if(data == 'b'){
//        GPIO_LED_TURN_OFF(&led00);
//        EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(&usart_object, 'c');
//        __delay_ms(250);
//    }
//}