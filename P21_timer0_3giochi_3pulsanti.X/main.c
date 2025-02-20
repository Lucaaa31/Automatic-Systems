/*
P21_timer0_3giochi_3pulsanti.X
il progetto prevede la realizzazione di tre giochi di luci, che si attivino ciascuno alla pressione di uno dei pulsanti S1, S2, S3,
che impegni tutto il PORTB del PIC16F1827 utilizzando esclusivamente il TMR0, nessuna riga di codice deve essere inserita manualmente nel main.c.
-Aggiungere un anti-rimbalzo software per la lettura della pressione sul pulsante
-Gestire i 3 giochi in 3 ISR diverse TMR0_ISR_1  TMR0_ISR_2  TMR0_ISR_3
- Modifica di interrupt_manager.c, tmr0.h e tmr0.c
 * In interrupt_manager.c ho modificato TMR0_ISR(); aggiungendo TMR0_ISR_1(); TMR0_ISR_2(); TMR0_ISR_3();
 * Nel tmr0.h ho dichiarato TMR0_ISR_1(); TMR0_ISR_2(); TMR0_ISR_3();
 * Nel tmr0.c ho realizzato i tre giochi su TMR0_ISR_1(); TMR0_ISR_2(); TMR0_ISR_3(); 
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