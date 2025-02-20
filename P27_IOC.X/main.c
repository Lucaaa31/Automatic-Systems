
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
P27_IOC.X
Il progetto prevede la realizzazione di tre giochi di luci infiniti, che si attivino ciascuno alla seguente sequenza:
GIOCO1: pressione di S1 (non mantenuta) per 5 secondi e successiva premuta di S2 (non mantenuta) per tre secondi 
GIOCO2: pressione contemporanea di S1 e S2 per 6 secondi (non mantenuta)
GIOCO3: pressione di S1 per 8 secondi (non mantenuta) e successiva premuta simultanea di S2 e S3 (non mantenuta)  per tre secondi 

il meccanismo dell'Interrupt On Change (IOC), nessuna riga di codice deve essere inserita manualmente nel main.c.

N.B. nel/nei giochi luce non includere il/i LED utilizzato/i per la lettura dell'IOC
 * Attivo Interrupt globale e periferiale
 * Programma scritto su pin_manager.c
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