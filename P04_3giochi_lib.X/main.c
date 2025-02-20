#include "mcc_generated_files/mcc.h"
#include "my_lib_giochi.h"
#define Display PORTB

/*
                         Main application
Pulsante S1 della DemoPic seleziona 3 Giochi diversi
senza interrupt quindi occorre premerlo piu volte per cambiare gioco
Programma realizzato con plugin Code Configurator
 * Il pulsante S2 è il reset
 * In questo programma si utilizzano 2 librerie: my_lib_giochi.c e my_lib_giochi.h 
 */

char s;
char c=0;

void main(void)
{
    Display=0b00000000;
    


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
        if(IO_RA3_GetValue()==1)
        {
            c=0;
            Display=0b00000000;
            
        }
        if(IO_RA2_GetValue()==1)
        {
            c++;  //se premo il Puls1 incremento il valore di c
        }
        if(c==1)
        {
            Supercar();  //se c e' uguale a 1 esegui la funzione Supercar
        }
        if(c==2)
        {
            PalleR();  //se c e' uguale a 2 esegui la funzione PalleR
        }
        if(c==3)
        {
            PariDispari();  //se c e' uguale a 3 esegui la funzione PariDispari
        }
        if(c==4)
        {
            c=0;  //se c e' uguale a 4 imposta c uguale a 0
        }
        // Add your application code
    }
}

/**
 End of File
*/