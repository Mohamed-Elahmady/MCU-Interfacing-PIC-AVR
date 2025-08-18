#include "app.h"

void adc_app_interrupt(void);

adc_cfg adc1 = {
    .adc_interrupt = adc_app_interrupt,
    .priority = interrupt_high_priority,
    .channel = adc_channel_an0,
    .clk = adc_conversion_clock_fosc_div_4,
    .acq = adc_acq_12tad,
    .ref = adc_internal_voltage_reference,
    .format = adc_format_right
};

volatile uint16 res[4] = {0, 0, 0, 0};

volatile uint8 ir_req = 0;

int main(void) {
    Std_ReturnType ret = E_NOT_OK;

    ret = adc_init(&adc1);
    if(ret != E_OK){
    }

    ret = adc_start_conversion_interrupt(&adc1, adc_channel_an0);
    if(ret != E_OK){
    }

    while(1){
    }

    return (EXIT_SUCCESS);
}

void adc_app_interrupt(void){
    Std_ReturnType ret = E_NOT_OK;

    ret = adc_get_conversion_result(&adc1, &res[ir_req]);

    ir_req++;
    if(ir_req > 3) ir_req = 0;

    ret = adc_set_channel(&adc1, (adc_channel)ir_req);

    ret = adc_start_conversion(&adc1);

    intenral_interrupt_adc_clear_flag();
}