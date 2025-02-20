/**
P24_IOC_bis.X
il progetto prevede la realizzazione di un gioco luci che si attivi al rilascio 
del pulsante S1 collegato al PIN RB0 attraverso il meccanismo dell'Interrupt 
On Change (IOC), nessuna riga di codice deve essere inserita manualmente nel main.c.
N.B. collegamento fisico tra RA2  a RB0
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