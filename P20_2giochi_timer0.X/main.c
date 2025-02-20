/**
P20_2giochi_timer0.X
il progetto prevede la realizzazione di due giochi luci infiniti,
che si attivano alla pressione dei pulsanti S1 (primo gioco) o pulsante S2 (secondo gioco),
che impegni tutto il PORTB del PIC16F1827 utilizzando esclusivamente il TMR0,
 nessuna riga di codice deve essere inserita manualmente nel main.c.
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