/** PIC16F1826-I/P pin to pin compatibile con PIC16F84A
* I=> -40°C/85°C
* P=> PDIP
** 
** TEMPLATE MPLabX 5.05 compilatore XC8 2.00 ***
                                ______________
                               |    16F1826   |
                   RA2     x---|1           18|---x RA1
                   RA3     x---|2           17|---x RA0
                   RA4     x---|3           16|---x RA7
                   RA5     x---|4           15|---x RA6
                       Vss x---|5           14|---x Vdd
                   RB0     x---|6           13|---x RB7
                   RB1     x---|7           12|---x RB6
                   RB2     x---|8           11|---x RB5
                   RB3     x---|9           10|---x RB4
                               |______________|    
*********************************** PINNING O PINOUT *****************/
/* Appena questo programma viene caricato parte un ciclo che gira in senso antiorario 
 * a partire dal segmento a del display PORTB, i segmenti si accendono e spengono nella 
 * sequenza sopra indicata se vengono premuti il primo e il terzo pulsante contemporaneamente 
 * il ciclo diventa in senso orario sempre a partire dal segmento a del display PORTB
*/
/**
  Generated Main Source File

  Company:    Microchip Technology Inc.
  File Name:    main.c

  Summary:    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F1826
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.
*/
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    char count;              //variabile conta
    
    while(1){			// ciclo infinito
        count == 0;		//inizializzo la variabile count a 0
        PORTB = 0b00000001;		//attivo il segmento a del terzo display
        __delay_ms(100);			//aspetto 100ms
        PORTB = 0B00000010;		//attivo il segmento b del terzo display
        __delay_ms(100);			//aspetto 100ms
        PORTB = 0b00000100; 	//attivo il segmento c del terzo display
        __delay_ms(100);			//aspetto 100ms
        PORTB = 0b00001000;		//attivo il segmento d del terzo display
        __delay_ms(100);			//aspetto 100ms
        
        IO_RA1_PORT = 1;			//abilito il secondo display
        PORTB = 0b00001000;		//attivo il segmento d del secondo display
        __delay_ms(100);			//aspetto 100ms
        IO_RA1_PORT = 0;			//disabilito il secondo display
        
        IO_RA0_PORT = 1;			//abilito il primo display 
        PORTB = 0b00001000;		//attivo il segmento d del primo display
        __delay_ms(100);        	//aspetto 100ms
        if(IO_RA2_GetValue() == 1){		//se premo il pulsante 1 inizio un secondo ciclo infinito
            count == 1;			//contatore
            while(1){			//ciclo infinito
                PORTB = 0b00001000;		//attivo il segmento d del terzo display
                IO_RA0_PORT = 0;			//disabilito il primo display
                
                IO_RA1_PORT = 1;			//abilito il secondo display 
                PORTB = 0b00001000;		//attivo il segmento d del secondo display
                __delay_ms(100);			//aspetto 100ms
                IO_RA1_PORT = 0;			//disabilito il secondo display
                
                PORTB = 0b00001000;		//attivo il segmento d del primo display 
                __delay_ms(100);			//aspetto 100ms
                PORTB = 0b00000100;		//attivo il segmento c del primo display 
                __delay_ms(100);			//aspetto 100ms
                PORTB = 0B00000010;		//attivo il segmento b del primo display 
                __delay_ms(100);			//aspetto 100ms
                PORTB = 0b00000001;		//attivo il segmento a del primo display 
                __delay_ms(100);			//aspetto 100ms
                
                IO_RA1_PORT = 1;			//abilito il secondo display
                PORTB = 0b00000001;		//attivo il segmento a del secondo display
                __delay_ms(100);			//aspetto 100ms
                IO_RA1_PORT = 0;			//disabilito il secondo display
                
                IO_RA0_PORT = 1;			//abilito il primo display 
                PORTB = 0B00000001;		//attivo il segmento a del primo display 
                __delay_ms(100);			//aspetto 100ms
                PORTB = 0b00100000;		//attivo il segmento f del primo display 
                __delay_ms(100);			//aspetto 100ms
                PORTB = 0b00010000;		//attivo il segmento e del primo display 
                __delay_ms(100);			//aspetto 100ms
                PORTB = 0b00001000;		//attivo il segmento d del primo display 
                __delay_ms(100);			//attivo ritardo
                if(IO_RA2_PORT && IO_RA4_PORT == 1){		//se premo il pulsante S1 ed S3 riprende a fare il primo ciclo
                    count==0;			//variabile conta uguale 0
                    break;				//interrompe il ciclo
                }
                IO_RA0_PORT = 0;			//disabilito il terzo display 
                }
        }
        PORTB = 0b00010000;				//attivo il segmento e del terzo display
        __delay_ms(100);					//aspetto 100ms
        PORTB = 0b00100000;				//attivo il segmento f del terzo display
        __delay_ms(100);					//aspetto 100ms
        PORTB = 0B00000001;				//attivo il segmento a del terzo display
        __delay_ms(100);					//aspetto 100ms
        IO_RA0_PORT = 0;					//disabilito il terzo display 
        
        IO_RA1_PORT = 1;					//abilito il secondo display 
        PORTB = 0b00000001;				//attivo il segmento a del secondo display
        __delay_ms(100);					//aspetto 100ms
        IO_RA1_PORT = 0;					//disabilito il secondo display 
        }

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

    //while (1)
    //{
        // Add your application code
    //}
}
/**
 End of File
*/