/*
 * File:   button.c
 * Author: Vladislav Z.
 *
 * Created on January 25, 2022, 2:58 PM
 */


#include "button.h"


/* Local global constants. */
#define BUTTON_LONG_PRESS_DELAY      30U
#define BUTTON_SHORT_PRESS_DELAY     10U

/* Value is current button value (getting by button_is_pressed() function).
   State current button state. Change when button get unpressed. 
   Count button press counter. */
static struct {
    enum on_off value;
    enum e_buttonstate state; 
    u8 count;
} button;

void button_init (void)
{
    button.value = button_is_pressed();
    button.state = NO_PRESSED;
    button.count = 0;
}

bool button_is_pressed (void) {
    return BUTTON_GetValue() ? true : false;
}

/* @brief: Main button function. It's check button, and return state value:
                NO_PRESSED, SHORT_PRESSED or LONG_PRESSED. */
enum e_buttonstate button_check (void)
{
    button.value = button_is_pressed();
    if (button.value == ON) {
#ifdef DEBUG
        puts("INFO: BUTTON IS PRESSED.");
#endif
        if (button.count == UINT8_MAX) {
            puts ("WARNING: BUTTON COUNTER OVERFLOW.");      
        }
        
        if (button.count >= BUTTON_LONG_PRESS_DELAY) {
            button.state = LONG_PRESSED;
        } else {
            button.count++;
        }
        
    } else if (button.value == OFF) {
        if(button.count >= BUTTON_SHORT_PRESS_DELAY) {
            button.state = SHORT_PRESSED;
        } else if (button.count == 0) {
            button.state = NO_PRESSED;
        }
        
#ifdef DEBUG
        printf ("INFO: BUTTON COUNTER IS %d\n.", button.count); 
#endif
        button.count = 0;
    
    } else {
        puts ("ERROR: BUTTON UNDIFINED VALUE.");
    }
    return button.state;
}

/***************************** END OF FILE ************************************/