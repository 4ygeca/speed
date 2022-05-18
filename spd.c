/*
 * File:   spd.c
 * Author: ch_do
 *
 * Created on January 25, 2022, 5:54 PM
 */

/* @FIXME:  Уйти от использования типа float. */

#include "spd.h"
#include "eeprom.h"

/* Local global constants. */
#define DEFAULT_SPD_MUL_CORR        1.0F
#define DEFAULT_SPD_ADD_CORR        0U
#define FREQ_DELAY                  100U

static struct {
    float k;
    u8 a;
    u16 count;
    u16 duty;
    u8 pr_value;
    u16 speed;
}spd;

bool is_moving (void) {
    return spd.count == 0 ? false : true;
}

void spd_init (void) 
{
    void* tmp;
    tmp = read_correction (SPD_MUL_CORR);
    spd.k = *(float*)tmp;
    if (spd.k != 0) {
        spd.k = DEFAULT_SPD_MUL_CORR;
        *(float*) tmp = DEFAULT_SPD_MUL_CORR;
        write_correction (SPD_MUL_CORR, tmp);
    }
    
    tmp = read_correction (SPD_ADD_CORR);
    spd.a = *(u8*)tmp;
    if (spd.a != 0) {
        spd.a = DEFAULT_SPD_ADD_CORR;
        *(u16*)tmp = DEFAULT_SPD_ADD_CORR;
        write_correction (SPD_ADD_CORR, tmp);
    }
    
    spd.count = 0;
    spd.duty = 0;
    spd.pr_value = 0;
    spd.speed = 0;
}

u16 spd_get_speed (void)
{
    return spd.speed;
}

float spd_get_k_corr (void)
{
    return spd.k;
}

void spd_set_k_corr (float value)
{
    spd.k = value;
}

u8 spd_get_a_corr (void)
{
    return spd.a;
}

void spd_set_a_corr (u8 value)
{
    spd.a = value;
}

static float spd_uint_to_float (u16 value)
{
    return ((2.0f/ADC_RESULT_MAX) * value);
}

static u8 spd_adc_to_u8 (adc_result_t value)
{
    return (u8)(ADC_RESULT_MAX / UINT8_MAX * value);
}

/* @brief:  Function calculate input signal frequency. And configurate output
 *          modulated signal on PWM6 */
void frequency_calculation (void) 
{
    /* Storage Timer 0 counter and reset hardware counter for he continue count. */
    spd.count = (u16)((TMR0H << 8) | TMR0L);
    TMR0_Reload();
    
    /* Action when in move. SPD calculation and toggling LED. */
    if (is_moving()) {
        /* SPEED FORMULA. */
        spd.speed = (u16)(spd.k * spd.count) + spd.a;
        
        /* Load Timer Period Register and calculate 50% duty. */
        spd.pr_value = (u8)(spd.speed / sizeof(spd.speed));
        TMR6_LoadPeriodRegister (spd.pr_value);
        spd.duty = (4 * (u16)spd.pr_value + 1) / 2;
        PWM6_LoadDutyValue (spd.duty);
    
#ifdef DEBUG
        printf("SPD %d PR %d", spd.speed, spd.pr_value);
        printf("SPD_DUTY %d", spd.duty);
#endif
        
/*TODO: something with led. Use led API.*/        
    /* If we don't move then, load NULL in SPD output PWM, and activate LED for
       menu indication.*/
    } else if (spd.speed != 0) {
        spd.duty = 0;
        spd.speed = 0;
        spd.pr_value = 0;
        TMR6_LoadPeriodRegister (spd.pr_value);
        PWM6_LoadDutyValue (spd.duty);
    }
    
}

/* @brief: Generate PWM impulses of all frequency limit on SPD output.*/
void spd_test_pwm (void)
{
    static u8 spd_count = 0;
    static u8 func_count = 0;
    static u8 rising = 1;
    
    if(func_count > FREQ_DELAY) {
        if(rising) {
            spd_count++;
        } else {
            spd_count--;
        }
        if (spd_count == UINT8_MAX) {
            rising = 0;
        } else if (spd_count == 0) {
            rising = 1;
        }
        func_count = 0;
        TMR6_LoadPeriodRegister (spd_count);
        PWM6_LoadDutyValue ((4 * (u16)spd_count + 1) / 2);
    } else {
        func_count++;
    }
    
    
}


/* @brief: Speed multiple correction calibration function. */
void spd_k_calibration (void)
{
    adc_result_t tmp;   
    adc_channel_t stored_ch = ADCON0bits.CHS;
    
    tmp = ADC_GetConversion (VARIABLE_R);
    ADCON0bits.CHS = stored_ch;
    
    spd.k = spd_uint_to_float (tmp);
    
    
}

/* @brief: Speed addition correction calibration function. */
void spd_a_calibration (void)
{  
    adc_result_t tmp;
    adc_channel_t stored_ch = ADCON0bits.CHS;
    
    tmp = ADC_GetConversion (VARIABLE_R);
    ADCON0bits.CHS = stored_ch;
        
    spd.a = spd_adc_to_u8 (tmp);
    
    
}

/***************************** END OF FILE ************************************/