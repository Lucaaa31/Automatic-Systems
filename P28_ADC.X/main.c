/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1827
        Driver Version    :  2.00
*/

/*
P28_ADC.X
Realizzare un progetto che preveda la conversione in digitale di un segnale analogico,
e che il risultato della conversione venga visualizzato su PORTB.
Modifiche righe:
 * 31;
 * da 57 a 61.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    ADC_Initialize();               //potrebbe non servire in quanto istruzione già eseguita in quella precedente
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1){
        ADC_StartConversion();
        while(ADCON0bits.GO_nDONE == 1){
            
        }
        PORTB=ADRESH;
    }
}
/**
 End of File
*/