/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18326
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA4
#define LED_LAT                  LATAbits.LATA4
#define LED_PORT                 PORTAbits.RA4
#define LED_WPU                  WPUAbits.WPUA4
#define LED_OD                   ODCONAbits.ODCA4
#define LED_ANS                  ANSELAbits.ANSA4
#define LED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_GetValue()           PORTAbits.RA4
#define LED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set FUEL_LOW aliases
#define FUEL_LOW_TRIS                 TRISCbits.TRISC0
#define FUEL_LOW_LAT                  LATCbits.LATC0
#define FUEL_LOW_PORT                 PORTCbits.RC0
#define FUEL_LOW_WPU                  WPUCbits.WPUC0
#define FUEL_LOW_OD                   ODCONCbits.ODCC0
#define FUEL_LOW_ANS                  ANSELCbits.ANSC0
#define FUEL_LOW_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define FUEL_LOW_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define FUEL_LOW_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define FUEL_LOW_GetValue()           PORTCbits.RC0
#define FUEL_LOW_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define FUEL_LOW_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define FUEL_LOW_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define FUEL_LOW_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define FUEL_LOW_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define FUEL_LOW_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define FUEL_LOW_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define FUEL_LOW_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set FUEL aliases
#define FUEL_TRIS                 TRISCbits.TRISC2
#define FUEL_LAT                  LATCbits.LATC2
#define FUEL_PORT                 PORTCbits.RC2
#define FUEL_WPU                  WPUCbits.WPUC2
#define FUEL_OD                   ODCONCbits.ODCC2
#define FUEL_ANS                  ANSELCbits.ANSC2
#define FUEL_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define FUEL_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define FUEL_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define FUEL_GetValue()           PORTCbits.RC2
#define FUEL_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define FUEL_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define FUEL_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define FUEL_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define FUEL_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define FUEL_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define FUEL_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define FUEL_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISCbits.TRISC3
#define BUTTON_LAT                  LATCbits.LATC3
#define BUTTON_PORT                 PORTCbits.RC3
#define BUTTON_WPU                  WPUCbits.WPUC3
#define BUTTON_OD                   ODCONCbits.ODCC3
#define BUTTON_ANS                  ANSELCbits.ANSC3
#define BUTTON_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define BUTTON_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define BUTTON_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define BUTTON_GetValue()           PORTCbits.RC3
#define BUTTON_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set VARIABLE_R aliases
#define VARIABLE_R_TRIS                 TRISCbits.TRISC5
#define VARIABLE_R_LAT                  LATCbits.LATC5
#define VARIABLE_R_PORT                 PORTCbits.RC5
#define VARIABLE_R_WPU                  WPUCbits.WPUC5
#define VARIABLE_R_OD                   ODCONCbits.ODCC5
#define VARIABLE_R_ANS                  ANSELCbits.ANSC5
#define VARIABLE_R_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define VARIABLE_R_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define VARIABLE_R_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define VARIABLE_R_GetValue()           PORTCbits.RC5
#define VARIABLE_R_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define VARIABLE_R_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define VARIABLE_R_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define VARIABLE_R_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define VARIABLE_R_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define VARIABLE_R_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define VARIABLE_R_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define VARIABLE_R_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/