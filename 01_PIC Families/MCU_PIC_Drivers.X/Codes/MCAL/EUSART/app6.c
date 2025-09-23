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
//void eusart_tx_isr(void);
//void eusart_rx_isr(void);
//void eusart_frame_isr(void);
//void eusart_overrun_isr(void);
//
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//GPIO_LED led2 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN1, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//EUSART_CFG usart_object = {
//    .eusart_tx_mode.interrupt_state = EUSART_ASYNC_TX_INTERRUPT_ENABLE_STATE,
//    .eusart_tx_mode.tx_interrupt = eusart_tx_isr,
//    .eusart_tx_mode.tx_priority = INTERRUPT_HIGH_PRIORITY,
//    
//    .eusart_tx_mode.state = EUSART_ASYNC_TX_ENABLE_STATE,
//    .eusart_tx_mode.tx_size = EUSART_ASYNC_TX_9BIT_SIZE_DISABLE,
//    
//    .eusart_rx_mode.interrupt_state = EUSART_ASYNC_RX_INTERRUPT_ENABLE_STATE,
//    .eusart_rx_mode.rx_priority = INTERRUPT_HIGH_PRIORITY,
//    .eusart_rx_mode.rx_interrupt = eusart_rx_isr,
//    .eusart_rx_mode.farming_interrupt = eusart_frame_isr,
//    .eusart_rx_mode.overrun_interrupt = eusart_overrun_isr,
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
//volatile uint32 tx_flag = 0, rx_flag = 0;
//uint8 data = 0, data_flag = 0;
//
//int main() {
//    application_init();
//    while (1) {
//        if(data_flag == 1){
//            data_flag = 0;
//            if(data == 'a'){
//                GPIO_LED_TURN_ON(&led1);
//                EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(&usart_object, "L1 ON\r");
//            }
//            else if(data == 'b'){
//                GPIO_LED_TURN_ON(&led2);
//                EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(&usart_object, "L2 ON\r");
//            }
//            else if(data == 'c'){
//                GPIO_LED_TURN_OFF(&led1);
//                EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(&usart_object, "L1 OFF\r");
//            }
//            else if(data == 'd'){
//                GPIO_LED_TURN_OFF(&led2);
//                EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(&usart_object, "L2 OFF\r");
//            }
//            else{
//                GPIO_LED_TURN_OFF(&led1);
//                GPIO_LED_TURN_OFF(&led2);
//                EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(&usart_object, "L1 & L2 OFF\r");
//            }
//        }
//
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = EUSART_ASYNC_INIT(&usart_object);
//    GPIO_LED_INIT(&led1);
//    GPIO_LED_INIT(&led2);
//}
//
//void eusart_tx_isr(void){
//    tx_flag++;
//}
//
//void eusart_rx_isr(void){
//    rx_flag++;
//    Ret = EUSART_ASYNC_RX_READ_BYTE_NON_BLOCKING(&usart_object, &data);
//    data_flag = 1;
//}
//
//void eusart_frame_isr(void){
//    Ret = EUSART_ASYNC_RX_READ_BYTE_NON_BLOCKING(&usart_object, &data);
//}
//void eusart_overrun_isr(void){
//    EUSART_ASYNC_RX_RESTART(&usart_object);
//}