/////* 
//// * File:   Main.h
//// * Author: mohammedel-ahmady
//// *
//// * Created on June 21, 2025, 4:22 AM
//// */
////
////#include "Main.h"
////
////// Master
////
////Std_ReturnType Ret = E_OK;
////
////// 0x60=> 0110 0000     => add = 0011 0000 "0x30" | (0)Write Operation     
////#define SLAVE1_ADD      0x60
////
////Std_ReturnType I2C_SEND_FRAME(const I2C_CFG *i2c, uint16 add, uint8 data);
////
////I2C_CFG i2c1 = {
////    .I2C_INTERRUPT = NULL,
////    .I2C_OVF_INTERRUPT = NULL,
////    .I2C_COL_INTERRUPT = NULL,
////    .i2c_priority = INTERRUPT_HIGH_PRIORITY,
////    
////    .i2c_frame.mode = I2C_MASTER_MODE,
////    .i2c_frame.mode_cfg = I2C_MASTER_MODE_CLK,
////    .i2c_clock = 100000,
////    
////    .i2c_frame.receive_mode = I2C_RECEIVE_ENABLE,
////    .i2c_frame.slew_rate = I2C_SLEW_RATE_100KHZ_DISABLE,
////    .i2c_frame.smbus = I2C_SMBUS_DISABLE,
////    .i2c_frame.general_call = I2C_GENERAL_CALL_DISABLE,
////};
////
////uint8 data = 0;
////
////int main(void) {
////    application_init();
////        
////    while(1){
////        Ret = I2C_SEND_FRAME(&i2c1, (SLAVE1_ADD), 'A');
////        __delay_ms(300);
////        Ret = I2C_SEND_FRAME(&i2c1, (SLAVE1_ADD), 'C');
////        __delay_ms(300);
////    }
////    return (EXIT_SUCCESS);
////}
////
////void application_init(void){
////    ECUAL_LAYER_INIT();
////    Ret = I2C_INIT(&i2c1);
////}
////
////Std_ReturnType I2C_SEND_FRAME(const I2C_CFG *i2c, uint16 add, uint8 data){
////    Std_ReturnType Retval = E_OK;
////    if(NULL == i2c){
////        Retval = E_NOT_OK;
////    }
////    else{
////        uint8 slave_ack = 0;
////        Retval = I2C_MASTER_SEND_START_CONDITION(i2c);
////        Retval = I2C_MASTER_WRITE_BYTE_BLOCKING(i2c, add, &slave_ack);
////        Retval = I2C_MASTER_WRITE_BYTE_BLOCKING(i2c, data, &slave_ack);
////        Retval = I2C_MASTER_SEND_STOP_CONDITION(i2c);
////    }
////    return Retval;
////}
//
//
//
//
//
///* 
// * File:   Main.h
// * Author: mohammedel-ahmady
// *
// * Created on June 21, 2025, 4:22 AM
// */
//
//#include "Main.h"
//
//// Slave 1
//
//Std_ReturnType Ret = E_OK;
//
//void i2c_isr(void);
//
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTD, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//I2C_CFG i2c1 = {
//    .I2C_INTERRUPT = i2c_isr,
//    .I2C_OVF_INTERRUPT = NULL,
//    .I2C_COL_INTERRUPT = NULL,
//    .i2c_priority = INTERRUPT_HIGH_PRIORITY,
//    
//    .i2c_frame.mode = I2C_SLAVE_MODE,
//    .i2c_frame.mode_cfg = I2C_SLAVE_MODE_7BIT_ADD,
//    .i2c_frame.i2c_slave_add = 0x30,
//    
//    .i2c_frame.receive_mode = I2C_RECEIVE_ENABLE,
//    .i2c_frame.slew_rate = I2C_SLEW_RATE_100KHZ_DISABLE,
//    .i2c_frame.smbus = I2C_SMBUS_DISABLE,
//    .i2c_frame.general_call = I2C_GENERAL_CALL_DISABLE,
//};
//
//volatile uint8 counter = 0;
//
//int main(void) {
//    application_init();
//        
//    while(1){
//        I2C_SLAVE_RELEASE_CLOCK_STRETCHING();
//        
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void){
//    ECUAL_LAYER_INIT();
//    Ret = I2C_INIT(&i2c1);
//    Ret = GPIO_LED_INIT(&led1);
////    GPIO_LED_TURN_TOGGLE(&led1);
////    __delay_ms(300);
////    GPIO_LED_TURN_TOGGLE(&led1);
//}
//
//volatile uint8 received_data = 0;
//
//void i2c_isr(void){
//    uint8 dummy = 0;
//
//    if (I2C_SLAVE_RECEIVED_DATA_TYPE()) {
//        received_data = SSPBUF;
//        GPIO_LED_TURN_TOGGLE(&led1);
//    } else {
//        dummy = SSPBUF;
//    }
//
//    if (I2C_MASTER_SLAVE_READ_OVERFLOW_STATUS()) I2C_MASTER_SLAVE_CLEAR_OVERFLOW();
//    if (I2C_MASTER_SLAVE_READ_COLLISION_STATUS()) I2C_MASTER_SLAVE_CLEAR_COLLISION();
//
//    I2C_SLAVE_RELEASE_CLOCK_STRETCHING();
//}