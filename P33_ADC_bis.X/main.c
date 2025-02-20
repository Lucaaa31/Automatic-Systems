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
    P33_ADC_bis.X
    Realizzare un progetto che acquisisca DUE segnali analogici (partitore di tensione tramite trimmer)  sfruttando il modulo ADC e che nel display LCD venga scritto "lampeggiando" con freq.1Hz, il segnale maggiore dei due (Segnale 1 oppure Segnale 2) 
    Esempio: se Segnale1=Vdd e Segnale2=Vss lampeggerà la scritta "Segnale1".


    Per risolvere questo esercizio occorre:
    acquisire e convertire il primo segnale (channel_0)
    memorizzare tale valore
    cambiare canale per il secondo segnale (channel_1)
    acquisire e convertire il secondo segnale
    confrontare le due conversioni
    agire sul display LCD
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
#include "LCD2004a.h"
#include "LCD2004a.c"




int x=0;
int a0, a1, b0, b1, c0, c1, resto0, resto1;
int risultato0, risultato1;
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    ADC_Initialize();
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
    LCD_Init(0x27); // Initialize LCD module with I2C address = 0x27
    while (1)
    {
        x++;
        if(x%2==0){
            ADCON0bits.CHS = channel_AN0;
            ADC_StartConversion();
            while(ADCON0bits.GO_nDONE == 1){
            
            }
            risultato0 = 0.0046 * (ADRESL + (256 * ADRESH));
            a0= risultato0/100;
            resto0= risultato0%100;
            b0= resto0/10;
            c0= resto0%10;
        }else{
            ADCON0bits.CHS = channel_AN1;
            ADC_StartConversion();
            while(ADCON0bits.GO_nDONE == 1){
            
            }
            risultato1 = 0.0046 * (ADRESL + (256 * ADRESH));
            a1= risultato1/100;
            resto1= risultato1%100;
            b1= resto1/10;
            c1= resto1%10;
        }
        void LCD_TypeWriter(int* risultato0, int d);

    }
    
}
/**
 End of File
*/