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
  P15_conta99.X
Realizzare un contatore sincrono da 0 a 99. All'esecuzione del programma dalla situazione "00"
sui due display parte il conteggio fino a "99" con passo 100ms. Arrivato a "99" riparte da "00".
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
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        if(INTCONbits.T0IF==1){
            
            INTCONbits.T0IF=0;
            IO_RB0_Toggle();
            IO_RB1_Toggle();
            IO_RB2_Toggle();
            IO_RB3_Toggle();
            IO_RB4_Toggle();
            IO_RB5_Toggle();
            IO_RB6_Toggle();
            
        }
    }
}
/**
 End of File
*/