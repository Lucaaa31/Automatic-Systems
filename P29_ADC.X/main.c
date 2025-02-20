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
P29_ADC.X
Realizzare un progetto che preveda la conversione in digitale di un segnale analogico solo mantenendo premuto il pulsante S1 della demoPIC,
e che il risultato della conversione venga visualizzato su PORTB.
Modifiche righe:
 * 31;
 * da 58 a 65.
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
    ADC_Initialize();
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

    while (1)
    {
        while(IO_RA2_PORT==1){
            ADC_StartConversion();
            while(ADCON0bits.GO_nDONE == 1){
            
            }
            PORTB=ADRESH;
        }
        PORTB=0;
    }
}
/**
 End of File
*/