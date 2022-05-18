/* 
 * File:   spd.h
 * Author: Vladislav Z.
 * Comments:
 * Revision history: 
 */

#ifndef SPD_H
#define	SPD_H

#include "main.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

void frequency_calculation (void);

bool is_moving (void);

u16 spd_get_speed (void);

void spd_init (void);

void spd_test_pwm (void);

void spd_k_calibration (void);

void spd_a_calibration (void);

float spd_get_k_corr (void);

void spd_set_k_corr (float value);

u8 spd_get_a_corr (void);

void spd_set_a_corr (u8 value);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

/***************************** END OF FILE ************************************/