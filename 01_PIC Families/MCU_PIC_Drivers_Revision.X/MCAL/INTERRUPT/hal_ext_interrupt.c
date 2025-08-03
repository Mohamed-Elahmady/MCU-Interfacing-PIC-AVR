/* 
 * File:   hal_ext_interrupt.c
 * Author: mohammedel-ahmady
 *
 * Created on July 31, 2025, 6:14 PM
 */

/******************* Section 0 : Includes *******************/

#include "hal_ext_interrupt.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

// Helper Functions for INTX PINs

static interrupt_handler int0_interrupt_isr = NULL;
static interrupt_handler int1_interrupt_isr = NULL;
static interrupt_handler int2_interrupt_isr = NULL;

static Std_ReturnType external_interrupt_intx_pin_init(const interrupt_intx *inter);
static Std_ReturnType external_interrupt_intx_set_edge(const interrupt_intx *inter);
static Std_ReturnType external_interrupt_intx_set_priority(const interrupt_intx *inter);
static Std_ReturnType external_interrupt_intx_clear_flag(const interrupt_intx *inter);
static Std_ReturnType external_interrupt_intx_set_disable(const interrupt_intx *inter);
static Std_ReturnType external_interrupt_intx_set_enable(const interrupt_intx *inter);

static Std_ReturnType external_interrupt_intx_set_interrupt_handler(const interrupt_intx *inter);
static Std_ReturnType external_interrupt_int0_set_interrupt_handler(const interrupt_handler interrupt_isr);
static Std_ReturnType external_interrupt_int1_set_interrupt_handler(const interrupt_handler interrupt_isr);
static Std_ReturnType external_interrupt_int2_set_interrupt_handler(const interrupt_handler interrupt_isr);

// Helper Functions for RBX PINs

static interrupt_handler rb4_interrupt_isr_high = NULL;
static interrupt_handler rb4_interrupt_isr_low = NULL;
static interrupt_handler rb5_interrupt_isr_high = NULL;
static interrupt_handler rb5_interrupt_isr_low = NULL;
static interrupt_handler rb6_interrupt_isr_high = NULL;
static interrupt_handler rb6_interrupt_isr_low = NULL;
static interrupt_handler rb7_interrupt_isr_high = NULL;
static interrupt_handler rb7_interrupt_isr_low = NULL;

static Std_ReturnType external_interrupt_OC_rbx_pin_init(const interrupt_rbx *inter);
static Std_ReturnType external_interrupt_OC_rbx_set_priority(const interrupt_rbx *inter);
static Std_ReturnType external_interrupt_OC_rbx_clear_flag(const interrupt_rbx *inter);
static Std_ReturnType external_interrupt_OC_rbx_set_disable(const interrupt_rbx *inter);
static Std_ReturnType external_interrupt_OC_rbx_set_enable(const interrupt_rbx *inter);

static Std_ReturnType external_interrupt_rbx_set_interrupt_handler(const interrupt_rbx *inter);
static Std_ReturnType external_interrupt_rb4_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low);
static Std_ReturnType external_interrupt_rb5_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low);
static Std_ReturnType external_interrupt_rb6_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low);
static Std_ReturnType external_interrupt_rb7_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType external_interrupt_intx_init(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable INTX
        Retval = external_interrupt_intx_set_disable(inter);
        // 2. Clear Flag
        Retval = external_interrupt_intx_clear_flag(inter);
        // 3. Set Edge
        Retval = external_interrupt_intx_set_edge(inter);
        // 4. Set Priority if needed
#if ((interrupt_feature_enable) == (interrupt_priority_levels))        
        Retval = external_interrupt_intx_set_priority(inter);
#endif
        // 5. Pin Init
        Retval = external_interrupt_intx_pin_init(inter);
        // 6. set call back function
        Retval = external_interrupt_intx_set_interrupt_handler(inter);
        // 7. Enable INTX
        Retval = external_interrupt_intx_set_enable(inter);
    }
    return Retval;
}

Std_ReturnType external_interrupt_intx_deinit(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Clear  Flag
        Retval = external_interrupt_intx_clear_flag(inter);
        // 2. Disable INTX
        Retval = external_interrupt_intx_set_disable(inter);
    }
    return Retval;
}

void int0_isr(void){
    // Clear Flag
    external_interrupt_int0_clear_flag();
    // Code
    
    // Call Back Function
    if(int0_interrupt_isr){
        int0_interrupt_isr();
    }
}

void int1_isr(void){
    // Clear Flag
    external_interrupt_int1_clear_flag();
    // Code
    
    // Call Back Function
    if(int1_interrupt_isr){
        int1_interrupt_isr();
    }
}

void int2_isr(void){
    // Clear Flag
    external_interrupt_int2_clear_flag();
    // Code
    
    // Call Back Function
    if(int2_interrupt_isr){
        int2_interrupt_isr();
    }
}

Std_ReturnType external_interrupt_rbx_init(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable INTX
        Retval = external_interrupt_OC_rbx_set_disable(inter);
        // 2. Clear Flag
        Retval = external_interrupt_OC_rbx_clear_flag(inter);
        // 3. Set Priority if needed
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
        Retval = external_interrupt_OC_rbx_set_priority(inter);
#endif
        // 4. Pin Init
        Retval = external_interrupt_OC_rbx_pin_init(inter);
        // 5. set call back function
        Retval = external_interrupt_rbx_set_interrupt_handler(inter);
        // 6. Enable INTX
        Retval = external_interrupt_OC_rbx_set_enable(inter);
    }
    return Retval;
}

Std_ReturnType external_interrupt_rbx_deinit(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Clear  Flag
        Retval = external_interrupt_OC_rbx_clear_flag(inter);
        // 2. Disable INTX
        Retval = external_interrupt_OC_rbx_set_disable(inter);
    }
    return Retval;
}

void rb4_isr(uint8 change){
    // Clear Flag
    external_interrupt_rbx_clear_flag();
    // Code
    
    // Call Back Function
    if(change == change_high){
        if(rb4_interrupt_isr_high){
            rb4_interrupt_isr_high();
        }
        else{ /* Nothing */ }
    }
    else if(change == change_low){
        if(rb4_interrupt_isr_low){
            rb4_interrupt_isr_low();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }
}

void rb5_isr(uint8 change){
    // Clear Flag
    external_interrupt_rbx_clear_flag();
    // Code
    
    // Call Back Function
    if(change == change_high){
        if(rb5_interrupt_isr_high){
            rb5_interrupt_isr_high();
        }
        else{ /* Nothing */ }
    }
    else if(change == change_low){
        if(rb5_interrupt_isr_low){
            rb5_interrupt_isr_low();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }
}

void rb6_isr(uint8 change){
    // Clear Flag
    external_interrupt_rbx_clear_flag();
    // Code
    
    // Call Back Function
    if(change == change_high){
        if(rb6_interrupt_isr_high){
            rb6_interrupt_isr_high();
        }
        else{ /* Nothing */ }
    }
    else if(change == change_low){
        if(rb6_interrupt_isr_low){
            rb6_interrupt_isr_low();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }
}

void rb7_isr(uint8 change){
    // Clear Flag
    external_interrupt_rbx_clear_flag();
    // Code
    
    // Call Back Function
    if(change == change_high){
        if(rb7_interrupt_isr_high){
            rb7_interrupt_isr_high();
        }
        else{ /* Nothing */ }
    }
    else if(change == change_low){
        if(rb7_interrupt_isr_low){
            rb7_interrupt_isr_low();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }
}

/******************* Section 4:  Helper Functions Definitions *******************/

// Helper Functions for INTX PINs

static Std_ReturnType  external_interrupt_intx_pin_init(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_direction_init(&(inter->pin));
    }
    return Retval;
}

static Std_ReturnType  external_interrupt_intx_set_edge(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_int0:
                if(interrupt_rising_edge == inter->edg){
                    external_interrupt_int0_rising_edge();
                }
                else if(interrupt_falling_edge == inter->edg){
                    external_interrupt_int0_falling_edge();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case interrupt_int1:
                if(interrupt_rising_edge == inter->edg){
                    external_interrupt_int1_rising_edge();
                }
                else if(interrupt_falling_edge == inter->edg){
                    external_interrupt_int1_falling_edge();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case interrupt_int2:
                if(interrupt_rising_edge == inter->edg){
                    external_interrupt_int2_rising_edge();
                }
                else if(interrupt_falling_edge == inter->edg){
                    external_interrupt_int2_falling_edge();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

static Std_ReturnType  external_interrupt_intx_set_priority(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_int0:
                if(interrupt_high_priority != inter->priority){
                    Retval = E_NOT_OK;
                }
                break;
            case interrupt_int1:
                if(interrupt_high_priority == inter->priority){
                    external_interrupt_int1_high_priority();
                }
                else if(interrupt_low_priority == inter->priority){
                    external_interrupt_int1_low_priority();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case interrupt_int2:
                if(interrupt_high_priority == inter->priority){
                    external_interrupt_int2_high_priority();
                }
                else if(interrupt_low_priority == inter->priority){
                    external_interrupt_int2_low_priority();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#endif

static Std_ReturnType  external_interrupt_intx_clear_flag(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_int0:
                external_interrupt_int0_clear_flag();
                break;
            case interrupt_int1:
                external_interrupt_int1_clear_flag();
                break;
            case interrupt_int2:
                external_interrupt_int2_clear_flag();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType  external_interrupt_intx_set_disable(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_int0:
                external_interrupt_int0_disable();
                break;
            case interrupt_int1:
                external_interrupt_int1_disable();
                break;
            case interrupt_int2:
                external_interrupt_int2_disable();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType  external_interrupt_intx_set_enable(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_int0:
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                external_interrupt_int0_enable();
                break;
            case interrupt_int1:
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                external_interrupt_int1_enable();
                break;
            case interrupt_int2:
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                external_interrupt_int2_enable();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType external_interrupt_intx_set_interrupt_handler(const interrupt_intx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_int0:
                Retval = external_interrupt_int0_set_interrupt_handler(inter->intx_isr);
                break;
            case interrupt_int1:
                Retval = external_interrupt_int1_set_interrupt_handler(inter->intx_isr);
                break;
            case interrupt_int2:
                Retval = external_interrupt_int2_set_interrupt_handler(inter->intx_isr);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType external_interrupt_int0_set_interrupt_handler(const interrupt_handler interrupt_isr){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_isr){
        Retval = E_NOT_OK;
    }
    else{
        int0_interrupt_isr = interrupt_isr;
    }
    return Retval;
}

static Std_ReturnType external_interrupt_int1_set_interrupt_handler(const interrupt_handler interrupt_isr){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_isr){
        Retval = E_NOT_OK;
    }
    else{
        int1_interrupt_isr = interrupt_isr;
    }
    return Retval;
}

static Std_ReturnType external_interrupt_int2_set_interrupt_handler(const interrupt_handler interrupt_isr){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_isr){
        Retval = E_NOT_OK;
    }
    else{
        int2_interrupt_isr = interrupt_isr;
    }
    return Retval;
}

// Helper Functions for RBX PINs

static Std_ReturnType external_interrupt_OC_rbx_pin_init(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_direction_init(&(inter->pin));
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

static Std_ReturnType external_interrupt_OC_rbx_set_priority(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->priority){
            case interrupt_high_priority:
                external_interrupt_rbx_high_priority();
                break;
            case interrupt_low_priority:
                external_interrupt_rbx_low_priority();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#endif

static Std_ReturnType external_interrupt_OC_rbx_clear_flag(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        external_interrupt_rbx_clear_flag();
    }
    return Retval;
}

static Std_ReturnType external_interrupt_OC_rbx_set_disable(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_rb4:
                external_interrupt_rb4_disable();
                break;
            case interrupt_rb5:
                external_interrupt_rb5_disable();
                break;
            case interrupt_rb6:
                external_interrupt_rb6_disable();
                break;
            case interrupt_rb7:
                external_interrupt_rb7_disable();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
        
        if(IOCBbits.IOCB4 == 0x00 && IOCBbits.IOCB5 == 0x00 && IOCBbits.IOCB6 == 0x00 && IOCBbits.IOCB7 == 0x00){
            external_interrupt_rbx_disable();
        }
    }
    return Retval;
}

static Std_ReturnType external_interrupt_OC_rbx_set_enable(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_rb4:
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                external_interrupt_rbx_enable();
                external_interrupt_rb4_enable();
                break;
            case interrupt_rb5:
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                external_interrupt_rbx_enable();
                external_interrupt_rb5_enable();
                break;
            case interrupt_rb6:
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                external_interrupt_rbx_enable();
                external_interrupt_rb6_enable();
                break;
            case interrupt_rb7:
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                external_interrupt_rbx_enable();
                external_interrupt_rb7_enable();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType external_interrupt_rbx_set_interrupt_handler(const interrupt_rbx *inter){
    Std_ReturnType Retval = E_OK;
    if(NULL == inter){
        Retval = E_NOT_OK;
    }
    else{
        switch(inter->src){
            case interrupt_rb4:
                Retval = external_interrupt_rb4_set_interrupt_handler(inter->rbx_isr_high, inter->rbx_isr_low);
                break;
            case interrupt_rb5:
                Retval = external_interrupt_rb5_set_interrupt_handler(inter->rbx_isr_high, inter->rbx_isr_low);
                break;
            case interrupt_rb6:
                Retval = external_interrupt_rb6_set_interrupt_handler(inter->rbx_isr_high, inter->rbx_isr_low);
                break;
            case interrupt_rb7:
                Retval = external_interrupt_rb7_set_interrupt_handler(inter->rbx_isr_high, inter->rbx_isr_low);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType external_interrupt_rb4_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_isr_high || NULL == interrupt_isr_low){
        Retval = E_NOT_OK;
    }
    else{
        rb4_interrupt_isr_high = interrupt_isr_high;
        rb4_interrupt_isr_low = interrupt_isr_low;
    }
    return Retval;
}

static Std_ReturnType external_interrupt_rb5_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_isr_high || NULL == interrupt_isr_low){
        Retval = E_NOT_OK;
    }
    else{
        rb5_interrupt_isr_high = interrupt_isr_high;
        rb5_interrupt_isr_low = interrupt_isr_low;
    }
    return Retval;
}

static Std_ReturnType external_interrupt_rb6_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_isr_high || NULL == interrupt_isr_low){
        Retval = E_NOT_OK;
    }
    else{
        rb6_interrupt_isr_high = interrupt_isr_high;
        rb6_interrupt_isr_low = interrupt_isr_low;
    }
    return Retval;
}

static Std_ReturnType external_interrupt_rb7_set_interrupt_handler(const interrupt_handler interrupt_isr_high, const interrupt_handler interrupt_isr_low){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_isr_high || NULL == interrupt_isr_low){
        Retval = E_NOT_OK;
    }
    else{
        rb7_interrupt_isr_high = interrupt_isr_high;
        rb7_interrupt_isr_low = interrupt_isr_low;
    }
    return Retval;
}
