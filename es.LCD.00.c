/**
  Generated Main Source File

  Company:    Microchip Technology Inc.

  File Name:    main.c

  Summary:    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18877
        Driver Version    :  2.00
*/

/** PIC16F18877 con MPLABX 6.0 , xc8 V.2.35 ,CODE CONFIGURATOR 5.1.0, Packs DFP1.11.176
 * DFP,1.9.163,Microchip

                                ______________
                               | PIC16F18877  |
                       RE3 x---|01          40|---x RB7
                       RA0 x---|02          39|---x RB6
                       RA1 x---|03          38|---x RB5
                       RA2 x---|04          37|---x RB4
                       RA3 x---|05          36|---x RB3
                       RA4 x---|06          35|---x RB2
                       RA5 x---|07          34|---x RB1
                       RE0 x---|08          33|---x RB0
                       RE1 x---|09          32|-----x VDD 3.3V
                       RE2 x---|10          31|----x GND
                3.3V VDD x-----|11          30|---x RD7
                      GND x----|12          29|---x RD6
                       RA7 x---|13          28|---x RD5
                       RA6 x---|14          27|---x RD4
                       RC0 x---|15          26|---x RC7
                       RC1 x---|16          25|---x RC6
                       RC2 x---|17          24|---x RC5
                       RC3 x---|18          23|---x RC4
                       RD0 x---|19          22|---x RD3
                       RD1 x---|20          21|---x RD2
                               |______________|    

 *********************************** PINNING O PINOUT *****************/

/* N.B. in fase di nuovo Progetto OBBLIGATORIO selelezionare come TOOL >>>> SimuLaTor
 * N.B. per fase di burning PIC16F18877 
 * 1) usare tasto Maiusc + F11 oppure F11 oppure Clean and BuiLD per compilare correttamente
 * 2) Trasferire con DRAG and DROP tramite mouse il file Nomeprogetto.production.hex presente nella
 * cartella di progetto dist >>>> default >>>> production
 * nel DRIVE virtuale denominato XPRESS, 
 * oppure invia a >>>> XPRESS (D:)
 * P.S. di default VDD = 3.3V
*/


/***
 HFINTOSC clock 32MHZ e clock divider 4.  
***/

/*** 
 * Curiosity Pic16F18877   RD7 >>>> STB della Led&Key TM1638
 * Curiosity Pic16F18877   RD6 >>>> CLK della Led&Key TM1638
 * Curiosity Pic16F18877   RD5 >>>> DIO della Led&Key TM1638
 *
 * le seguenti dichiarazioni devono essere fatte nella libreria TM1638picD.h
#define DO  LATDbits.LATD5
#define DI  PORTDbits.RD5
#define CLK LATDbits.LATD6 
#define STB LATDbits.LATD7
 32mHZ e clock divider a 4 
 * Specifiche programma: SCL RC3, SDA RC4 ok scitte con lib.h  cambiata a 32MHZ 
 * Questo programma simula un contatore.
 * aggiunge testo in ogni riga ad intervalli di 999msec
 * 
 * N.B.
 * Programma scrive permanentemente in un i2c LCD 2004A, testo in tutte le righe
*
 * 
*/




#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

#include "LCD2004a.h"
#include "LCD2004a.c"

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
    
    LCD_Init(0x27); // Initialize LCD module with I2C address = 0x27
     while (1) { //ciclo infinito rende permantente il testo
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" Prima Riga !! ");
   
    LCD_Set_Cursor(2, 1);
    LCD_Write_String(" Seconda Riga ! ");
   
    LCD_Set_Cursor(3, 1);
    LCD_Write_String(" Terza Riga ! ");
   
    LCD_Set_Cursor(4, 1);
    LCD_Write_String(" Quarta Riga ! ");
	
   }
  }
/**
 End of File
*/