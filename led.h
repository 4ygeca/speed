/* 
 * File:   led.h    
 * Author: Vladislav Z.
 * Comments:
 * Revision history: 
 */

#ifndef LED_H
#define	LED_H

#include <xc.h> 
#include "main.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
  

/* Mode is indication mode (ON, BLINK, NUMBER), State is current LED state,
   Number is indication number in NUMBER mode, Count counting number. 
static struct {
    enum e_ledmode mode;
    enum e_ledstate state;
    u8 number;
    u8 count;
} led; */
    
enum e_ledmode{
    BLINK,
    NUMBER,
    ALWAYS_ON
};

/* API functions as is.*/

void led_init (void);

void led_set_mode (enum e_ledmode newmode);

enum e_ledmode led_get_mode (void);

void led_set_number (u8 newnumber);

u8 led_get_number (void);

enum on_off led_current_state (void);

void led_timer_call (enum on_off state);

/* Main LED control function. Need call it by timer or something else.*/
void led_indicate (void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* LED_H */

/***************************** END OF FILE ************************************/