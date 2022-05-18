/* 
 * File:   button.h
 * Author: Vladislav Z.
 * Comments:
 * Revision history: 
 */

#ifndef BUTTON_H
#define	BUTTON_H

/* NOTE: BUTTON PULL UP MUST BE ON. */

#include "main.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
    
enum e_buttonstate {
    NO_PRESSED,
    SHORT_PRESSED,
    LONG_PRESSED
};

/* struct button_t{
    enum on_off value;
    enum e_buttonstate state; 
    u8 count;
};
*/

void button_init (void);

bool button_is_pressed (void);

enum e_buttonstate button_check (void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* BUTTON_H */

/***************************** END OF FILE ************************************/