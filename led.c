/*
 * File:   led.c
 * Author: Vladislav Z.
 *
 * Created on January 25, 2022, 11:15 AM
 */


#include "led.h"

/* Local global constants. */
#define LED_SHORT_DELAY             10U
#define LED_LONG_DELAY              50U
#define LED_ON_DELAY                20U
  

/* Mode is indication mode (ON, BLINK, NUMBER), State is current LED state,
   Number is indication number in NUMBER mode, Count counting number. */
static struct {
    enum e_ledmode mode;
    enum on_off state;
    u8 number;
    u8 count;
} led;

void led_init (void) {
    led.mode = ALWAYS_ON;
    LED_SetHigh();
    led.state = ON;
    led.count = 0;
    led.number = 1;
}

void led_set_mode (enum e_ledmode newmode) 
{
    led.mode = newmode;
}

enum e_ledmode led_get_mode (void) 
{
    return led.mode;
}

void led_set_number (u8 newnumber)
{
    led.number = newnumber;
}

u8 led_get_number (void)
{
    return led.number;
}

enum on_off led_current_state (void) 
{
    return led.state;
}

static void led_on (void) 
{
    LED_SetHigh();
    led.state = ON;
}

static void led_off (void) 
{
    LED_SetLow();
    led.state = OFF;
}

static void led_toggle (void)
{
    LED_Toggle();
    led.state = (led.state + 1) % 2;
}

void led_timer_call (enum on_off state)
{
    if (state == ON) {
        TMR2IF = 0;
        TMR2IE = 1;
        TMR2 = 0;
        TMR2_StartTimer();
        
    } else if (state == OFF) {
        TMR2_StopTimer();
        TMR2IF = 0;
        TMR2IE = 0;
        
    } else {
        puts ("ERROR: WRONG LED TIMER FUNCTION CALL.");
    }      
}

/* @brief: LED WORK function. LED modes:
            ALWAYS_ON: --
            NUMBER: Indicate numbers by led. Blink N times, then long pause.
            BLINK: Indicate SP2 frequency. 
 */
void led_indicate (void)
{  
    static u8 count = 0;
    static u8 delay = 0;
    
    switch (led.mode) {
        case ALWAYS_ON :
            if (led.state == OFF) {
                led_on();
            }
            count = 0;
            delay = 0;
            break;
            
        case NUMBER :
            if ((count == 0) && (led.state == ON)) {
                led_off();
                delay = LED_LONG_DELAY;
            }
            if ((led.state == OFF) && (count >= delay)) {
                led_on();
                delay = LED_ON_DELAY;
            } else if ((led.state == ON) && (count >= delay)) {
                led_off();
                led.count++;
                count = 0;
                if (led.count >= led.number) {
                    led.count = 0;
                    delay = LED_LONG_DELAY;
                } else {
                    delay = LED_SHORT_DELAY;
                }
            } 
            if (count == UINT8_MAX) {
                puts ("ERROR: LED COUNTER OVERFLOW.");
            } else {
                count++;
            }
            break;
            
        case BLINK :
            led_toggle();
            count = 0;
            delay =0;
            break;
            
        default :
            puts("ERROR: WRONG LED MODE.");
            led_set_mode (ALWAYS_ON);
    }
    
}

/***************************** END OF FILE ************************************/