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
P31_ADC.X
Realizzare un progetto che preveda la conversione in digitale di un segnale analogico (partitore di tensione tramite trimmer)
solo mantenendo premuto il pulsante S1 della demoPIC. Se il valore del segnale analogico è superiore a 3,4V eseguire un lampeggio
di tutti i LED con frequenza di lampeggio di 2Hz.

(Per la risoluzione dell'esercizio, si consiglia la giustificazione destra per calcolare il valore del risultato in decimale da convertire in volt dopo il calcolo del quanto Q) 
Modifiche righe:
 * 34;
 * da 61 a 75.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
/*
                         Main application
 */
float risultato;
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
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
        if(IO_RA2_PORT == 1){
                ADC_StartConversion();
        
                while(ADCON0bits.GO_nDONE == 1){
                    
                }
                risultato = 0.0046 * (ADRESL + (256 * ADRESH));
                if(risultato >= 3.4){
                        PORTB=0b11111111;
                        __delay_ms(250);
                        PORTB=0b00000000;
                        __delay_ms(250);
                    }
                PORTB=ADRESL;
        }
    }
}
/**
 End of File
*/