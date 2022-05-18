/* 
 * File:   eeprom.h
 * Author: Vladislav Z.
 * Comments:
 * Revision history: 
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include "main.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    


void* read_correction (enum corr_t type);

void write_correction (enum corr_t type, void* value);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* EEPROM_H */

/***************************** END OF FILE ************************************/