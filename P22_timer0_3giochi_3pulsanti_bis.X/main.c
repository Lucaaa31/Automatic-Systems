/**
P22_timer0_3giochi_3pulsanti_bis.X
il progetto prevede la realizzazione di tre giochi di luci infiniti, che si attivino ciascuno alla seguente sequenza:
GIOCO1: pressione di S1 per 5 secondi e successiva premuta di S2 per tre secondi 
GIOCO2: pressione di S1 per 6 secondi e successiva premuta di S3 per tre secondi 
GIOCO3: pressione di S1 per 8 secondi e successiva premuta simultanea di S2 e S3 per tre secondi 
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