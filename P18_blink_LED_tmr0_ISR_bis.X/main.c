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
    P18_timer0_blinkLED_ISR_bis.X
Creare un nuovo progetto per il lampeggio di un LED della demoPIC ogni 5 secondi (5 secondi ON, 5 secondi OFF) con tempo scandito dal timer0, impostato da MCC.
La lettura dell'overflow del timer0 deve essere gestita in modalità interrupt, con relativa scrittura delle istruzione nella Interrupt Service Routine.
Modificare in maniera opportuna l'ISR per ottenere il tempo richiesto.
 * Attivo Interrupt globale e periferiale
 * Programma scritto su TMR0.c
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/