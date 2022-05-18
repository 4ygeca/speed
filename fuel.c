/*
 * File:   fuel.c
 * Author: Vladislav Z.
 *
 * Created on January 26, 2022, 4:55 PM
 */


#include "fuel.h"

#define FUEL_LOW                    10U
#define DEFAULT_FUEL_CORR           1.0F
#define LOW_COUNT_LIMIT             100U
#define PERCENT_COEFFICIENT         0.5F
#define ADC_LIMIT                   1023

static struct {
    adc_result_t adc_value;
    u16 pwm_value;
    float corr;
    u8  percent;
    bool low;
}fuel;

static void fuel_set_low (bool var) {
    fuel.low = var;
    if (fuel.low) {
        FUEL_LOW_SetHigh();
    } else {
        FUEL_LOW_SetLow();
    }
}

static u16 fuel_pwm_calculate (void)
{
    fuel.pwm_value = (u16)(fuel.corr * (float)fuel.adc_value);
    return fuel.pwm_value;
}

static u8 fuel_percent_calculate (void) 
{
    fuel.percent = (u8)(PERCENT_COEFFICIENT * (float)fuel.adc_value);
    return fuel.percent;
}

static float fuel_uint_to_float (u16 value) 
{
    return ((2.0f/ADC_RESULT_MAX) * value);
}

static void fuel_low_check (void) 
{
    static u8 low_count = 0;
    /* Low fuel error checking and set. */
    if (fuel.percent < FUEL_LOW) {
        if (!is_fuel_low()) {
            if (low_count > LOW_COUNT_LIMIT) {
                fuel_set_low (true);
            } else {
                low_count++;
            }
        } else {
            low_count = 0;
        }
    } else {
        if (is_fuel_low()) {
            if (low_count > LOW_COUNT_LIMIT) {
                fuel_set_low (false);
            } else {
                low_count++;
            }
        } else {
            low_count = 0;
        }
    }
}

void fuel_init (void)
{
    fuel.adc_value = ADC_GetConversion (FUEL);
    fuel.pwm_value = fuel_pwm_calculate ();
    fuel.percent = fuel_percent_calculate ();
    fuel.low = true;
}

/* @brief: Main fuel function.*/
void fuel_get (void)
{
    adc_result_t tmp;
    
    /* Check if auto-conversion is on than take result from ADC registers.*/
    if ((ADACT == 0x10) && (ADCON0bits.CHS == FUEL)){
        tmp = (adc_result_t)((ADRESH << 8) + ADRESL);
    } else {
        tmp = ADC_GetConversion (FUEL);
    }
    if (fuel.adc_value != tmp) {
        fuel.adc_value = tmp;
        fuel_pwm_calculate ();
        fuel_percent_calculate ();
    }
    PWM5_LoadDutyValue (fuel.pwm_value);
    fuel_low_check();
}

 /* @brief: Start and stop auto-trigger conversation by Timer3 overflow.*/
void fuel_auto_conversion (enum on_off state)
{
    if (state == ON) {
        ADACT = 0x10;
    } else if (state == OFF) {           
        ADACT = 0x00;
    } else {
        puts ("ERROR: AUTO_CONVERSION UNDIFINED PARAMETR. ");
    }
}

void fuel_calibration (void)
{
    adc_result_t tmp;
    
    tmp = ADC_GetConversion (VARIABLE_R);
    fuel.corr = fuel_uint_to_float (tmp);
    
    tmp = ADC_GetConversion (FUEL);
    if (fuel.adc_value != tmp) {
        fuel.adc_value = tmp;
    }
    
    fuel_pwm_calculate ();
    PWM5_LoadDutyValue (fuel.pwm_value);
    
    fuel_percent_calculate ();
    fuel_low_check();
        
}

bool is_fuel_low (void){
    return fuel.low;
}

float fuel_get_corr (void) 
{
    return fuel.corr;
}

void fuel_set_corr (float value)
{
    fuel.corr = value;
}


/***************************** END OF FILE ************************************/