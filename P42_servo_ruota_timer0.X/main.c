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
P42_servo_ruota_timer0
Creare un nuovo progetto che esegua il task riportato sotto ma con la scansione temporale gestita dal timer0 
Un servo parte da posizione -90° 
-Alla premuta di s1 inizia una rotazione fino alla massima escursione (+90°) con passo di 30° ogni 5 secondi, e lì vi rimane fino alla premuta della condizione di RESET
-Alla premuta di s2 inizia una rotazione fino alla massima escursione (+90°) con passo di 15° ogni 3 secondi, e lì vi rimane fino alla premuta della condizione di RESET
-Alla premuta di s3 inizia una rotazione fino alla massima escursione (+90°) con passo di 3° ogni secondo, e lì vi rimane fino alla premuta della condizione di RESET

CONDIZIONE DI RESET: premendo i 3 pulsanti contemporaneamente si ritorna alla condizione di riposo

Una premuta di un altro pulsante durante l'esecuzione del compito non deve essere rilevata

 * Attivo Interrupt globale e periferiale
 * Programma scritto su TMR0.c
 * Attivi ECCP1 e TMR0 per comando servo.
*/

#include "mcc_generated_files/mcc.h"
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    EPWM1_Initialize(); //inizializzazione del modulo epwm1
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