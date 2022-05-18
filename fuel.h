/* 
 * File:   fuel.h
 * Author: Vladislav Z.
 * Comments:
 * Revision history: 
 */


#ifndef FUEL_H
#define	FUEL_H

#include "main.h" 

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

void fuel_init (void);

void fuel_get (void);

void fuel_calibration (void);

void fuel_auto_conversion (enum on_off state);

bool is_fuel_low (void);

float fuel_get_corr (void);

void fuel_set_corr (float value);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* FUEL_H */

/***************************** END OF FILE ************************************/