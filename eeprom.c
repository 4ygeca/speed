/*
 * File:   eeprom.c
 * Author: Vladislav Z.
 *
 * Created on January 26, 2022, 1:57 PM
 */


#include "eeprom.h"

/* Local global constants. */
#define EEPROM_DEFAULT_VALUE        0x00
#define DEFAULT_ADDRESS             0x7010
#define SPD_MUL_OFFSET              0x00
#define SPD_ADD_OFFSET              0x10
#define FUEL_OFFSET                 0x20
#define ERROR_OFFSET                0xE0

static void eeprom_read_error_handler (void) {
    puts ("WARNING! UNCORRECT CORRECTION DATA IN EEPROM.");
}
/* @brief: Read correction from eeprom at defined addresses. And return void pointer.
    
 * @NOTE: For use void pointer need *(some_type_t*) void_pinter; */
void* read_correction (enum corr_t type)
{
    union {
        float f_num;
        u16 s_num;
        u8 byte[sizeof(float)];
    } buffer;
    
    u16 address;
    void* return_ptr = NULL;
    float tmp;
    u16 s_tmp;
    
    switch (type) {
        case SPD_MUL_CORR :
            address = DEFAULT_ADDRESS + SPD_MUL_OFFSET;
            
            for (u8 i = 0; i < sizeof(buffer); i++) {
                buffer.byte[i] = DATAEE_ReadByte (address + i);
            }
            tmp = buffer.f_num;
            for (u8 i = 0; i < sizeof(buffer); i++) {
                buffer.byte[i] = DATAEE_ReadByte (address + i + ERROR_OFFSET);
            }
            if (buffer.f_num != tmp) {
                eeprom_read_error_handler();
            } else {
#ifdef DEBUG
            puts ("INFO: SPD_MUL_CORR READ SUCCESS.");
#endif
                return_ptr = &buffer.f_num;
            }
            break;
            
        case SPD_ADD_CORR :
            address = DEFAULT_ADDRESS + SPD_ADD_OFFSET;

            for (u8 i = 0; i < sizeof(buffer.s_num); i++) {
                buffer.byte[i] = DATAEE_ReadByte (address + i);
            }
            s_tmp = buffer.s_num;
            for (u8 i = 0; i < sizeof(buffer.s_num); i++) {
                buffer.byte[i] = DATAEE_ReadByte (address + i + ERROR_OFFSET);
            }
            if (buffer.s_num != s_tmp) {
                eeprom_read_error_handler();
            } else {
#ifdef DEBUG
            puts ("INFO: SPD_ADD_CORR READ SUCCESS.");
#endif
                return_ptr = &buffer.s_num;
            }
            break;
            
        case FUEL_CORR :
            address = DEFAULT_ADDRESS + FUEL_OFFSET;
            
            for (u8 i = 0; i < sizeof(buffer); i++) {
                buffer.byte[i] = DATAEE_ReadByte (address + i);
            }
            tmp = buffer.f_num;
            for (u8 i = 0; i < sizeof(buffer); i++) {
                buffer.byte[i] = DATAEE_ReadByte (address + i + ERROR_OFFSET);
            }
            if (buffer.f_num != tmp) {
                eeprom_read_error_handler();
            } else {
#ifdef DEBUG
            puts ("INFO: FUEL_CORR READ SUCCESS.");
#endif
                return_ptr = &buffer.f_num;
            }
            break;
            
        default :
            puts ("ERROR: READ_CORRECTION UNKNOWN TYPE IDENTIFIER "); 
    }

    return return_ptr;
}

/* @brief: Function write correction values at defined addresses. */
void write_correction (enum corr_t type, void* value)
{
    union {
        float f_num;
        u16 s_num;
        u8 byte[sizeof(float)];
    } buffer;
    
    u16 address;
    
    switch (type) {
        case SPD_MUL_CORR :
            address = DEFAULT_ADDRESS + SPD_MUL_OFFSET;
            buffer.f_num = *(float*) value;
            for (u8 i = 0; i < sizeof(buffer); i++) {
                DATAEE_WriteByte (address + i, buffer.byte[i]);
                DATAEE_WriteByte (address + i + ERROR_OFFSET, buffer.byte[i]);
            }
#ifdef DEBUG
            puts ("INFO: SPD_MUL_CORR SAVED AT EEPROM.");
#endif
            break;
            
        case SPD_ADD_CORR :
            address = DEFAULT_ADDRESS + SPD_ADD_OFFSET;
            buffer.s_num = *(u16*) value;
            for (u8 i = 0; i < sizeof(buffer.s_num); i++) {
                DATAEE_WriteByte (address + i, buffer.byte[i]);
                DATAEE_WriteByte (address + i + ERROR_OFFSET, buffer.byte[i]);
            }
#ifdef DEBUG
            puts ("INFO: SPD_ADD_CORR READED FROM EEPROM.");
#endif
            break;
            
        case FUEL_CORR :
            address = DEFAULT_ADDRESS + FUEL_OFFSET;
            buffer.f_num = *(float*) value;
            for (u8 i = 0; i < sizeof(buffer); i++) {
                DATAEE_WriteByte (address + i, buffer.byte[i]);
                DATAEE_WriteByte (address + i + ERROR_OFFSET, buffer.byte[i]);
            }
#ifdef DEBUG
            puts ("INFO: FUEL_CORR SAVED AT EEPROM.");
#endif
            break;
            
        default :
            puts ("ERROR: READ_CORRECTION UNKNOWN TYPE IDENTIFIER "); 
    }

}


/***************************** END OF FILE ************************************/