/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18326
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*                         Main application
 * @brief:      Timer0 - SPD counter
 *              Timer1 - Calculate SPD frequency 
 *              Timer2 - LED timer
 *              Timer3 - ADC auto-trigger timer
 *              Timer4 - PWM5 timer FUEL_OUTPUT
 *              Timer6 - PWM6 timer SPD_OUTPUT
 *              
 *  upd. 21.04.22   Далее будут коментарии на русском языке.
 */

/* @TODO:    В конце оптимизорвать максимально работу, закомментировать
 *           неиспользуемые функции*/
#include "main.h"
#include "led.h"
#include "button.h"
#include "eeprom.h"
#include "fuel.h"
#include "spd.h"

/* Global constants. */
#define IDLE            10000UL

/* Function prototypes. */
void menu_change (void);

/* Global variables.*/
enum menu_t {
    WORK_TASK,
    SPD_MUL_CORRECTION_TASK,
    FUEL_CORRECTION_TASK,
    SPD_ADD_CORRECTION_TASK
};
static enum menu_t menu = WORK_TASK;

void main(void)
{
    /* Device initialization*/
    SYSTEM_Initialize();
    
    float tmp;
    u16 s_tmp;
    
#ifdef DEBUG
    FLASH_ReadWord(0x0005);
    printf ("INFO: RevID %d\nDeviceID %d\n", NVMDATH, NVMDATL);
#endif
   
    led_init ();
    button_init ();
    spd_init ();  
    fuel_init ();
    
    TMR1_SetInterruptHandler (frequency_calculation);
    TMR2_SetInterruptHandler (led_indicate);   
  
    while (1)
    {
        enum e_buttonstate button;
        button = button_check();
        
        switch (menu) {
/*  @FIXME: Разобраться с вызовом fuel_get() перенастроить его на автотригерр
            по 3 таймеру. 
    @TODO:
 *      СДЕЛАТЬ BUTTON по прерыванию, и счетчик в нем же. так же прерывание
 *      обработать так, чтобы при нажатии  обрабатывались прерывания по Таймеру1
 *      т.е. обработчик спидометра чтобы работал, на случай залипания или 
 *      замыкания клавиши.
 *      Переделать алгоритм работы menu в частности WORK_TASK и добавить новые
 *      режимы для первоначальной калибровки коэффициентов:
 *          -
 * 
 *      ДОПЛНИТЕЛЬНО сделать алгоритм для калибровки коэффициентов FUEL, а так же
 *      на новой схеме сделать алгоритм выбора источника с возможностью переключения.
        */
            case WORK_TASK : 
                if (is_moving()) {
                    led_set_mode (BLINK);
                } else {
                    led_set_mode (NUMBER);
                }
                
                fuel_get();
                
                if (button == LONG_PRESSED) {
                    led_set_mode (ALWAYS_ON);
                    PIE1bits.TMR1IE = 0;
                    while (button != SHORT_PRESSED) {
                        spd_test_pwm();                 
                        button = button_check();
                    }
                    PIE1bits.TMR1IE = 1;
                } 
                
                for (u32 i = 0; i < IDLE; i++);
                break;
                
            case SPD_MUL_CORRECTION_TASK : {
                float stored_spd_k;
                stored_spd_k = spd_get_k_corr();
                spd_k_calibration ();
                
                if (button == LONG_PRESSED) {
                    tmp = spd_get_k_corr();
                    write_correction (SPD_MUL_CORR, (void*)&tmp);
                    led_set_mode (ALWAYS_ON);
                } else if (button == SHORT_PRESSED) {
                    spd_set_k_corr (stored_spd_k);
                } else {
                    led_set_mode (NUMBER);
                 }
                break;
            }
            case FUEL_CORRECTION_TASK : {
                float stored_fuel;
                stored_fuel = fuel_get_corr();
                fuel_calibration ();
                
                if (button == LONG_PRESSED) {
                    tmp = fuel_get_corr();
                    write_correction (FUEL_CORR, (void*)&tmp);
                    led_set_mode (ALWAYS_ON);
                } else if (button == SHORT_PRESSED) {
                    fuel_set_corr (stored_fuel);
                } else {
                    led_set_mode (NUMBER);
                }
                break;
            }
            case SPD_ADD_CORRECTION_TASK : {
                u8 stored_spd_a;
                stored_spd_a = spd_get_a_corr ();
                spd_a_calibration ();
                
                if (button == LONG_PRESSED) {
                    s_tmp = spd_get_a_corr();
                    write_correction (SPD_ADD_CORR, (void*)&tmp);
                    led_set_mode (ALWAYS_ON);
                } else if (button == SHORT_PRESSED) {
                    spd_set_a_corr (stored_spd_a);
                } else {
                    led_set_mode (NUMBER);
                }
                break;
            }
            
            default : {
                puts ("ERROR: MENU UNKNOWN STATE.");
            }
        }
                       
        if (button == SHORT_PRESSED) {
            menu_change();
        }
    }
}


/* @brief: Switch to next menu level. */
void menu_change (void)
{
    menu = (menu + 1) % 4;
    
}



/***************************** END OF FILE ************************************/