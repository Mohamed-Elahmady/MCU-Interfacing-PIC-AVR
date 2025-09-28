///* 
// * File:   Main.h
// * Author: mohammedel-ahmady
// *
// * Created on June 21, 2025, 4:22 AM
// */
//
//#include "Main.h"
//
//SPI_CFG spi1 = {
//    .SPI_INTERRUPT = NULL,
//    .priority = INTERRUPT_LOW_PRIORITY,
//    
//    .spi_cfg.mode = SPI_MASTER_MODE,
//    .spi_cfg.mode_cfg = SPI_MASTER_CLOCK_FOSC_DIV_16,
//    
//    .spi_cfg.clk_polarity = SPI_IDLE_STATE_LOW_LEVEL,
//    .spi_cfg.clk_phase = SPI_TRANSMISSION_IDLE_ACTIVE,
//    .spi_cfg.clk_sample = SPI_MASTER_SLAVE_RECEIVING_MIDDLE_SAMPLING,
//    
//    .ss_pin.PORT = GPIO_PORTD,
//    .ss_pin.PIN = GPIO_PIN0,
//    .ss_pin.DIRECTION = GPIO_OUTPUT,
//    .ss_pin.LOGIC = GPIO_LOW
//};
//
//uint8 data = 0;
//int main(void) {
//    application_init();
//
//    while(1){
//        SPI_WRITE_STRING_BLOCKING(&spi1, "Mohammed\r");
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void){
//    ECUAL_LAYER_INIT();
//    SPI_INIT(&spi1);
//    SPI_WRITE_BYTE_BLOCKING(&spi1, 0xAA);
//}