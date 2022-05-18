/* 
 * File:   main.h
 * Author: Vladislav Z.
 * Comments:
 * Revision history: 
 */

#ifndef MAIN_H
#define	MAIN_H

#include "mcc_generated_files/mcc.h"

/*
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable(); 
 */

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    
#define DEBUG
    
#define ADC_RESULT_MAX          1023

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;

enum on_off {
    OFF,
    ON
};

enum corr_t {
    SPD_MUL_CORR,
    SPD_ADD_CORR,
    FUEL_CORR
};



#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MAIN_H */

/***************************** END OF FILE ************************************/