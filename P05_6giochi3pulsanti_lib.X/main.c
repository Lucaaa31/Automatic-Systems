/**
  Generated Main Source File

  Company:    Microchip Technology Inc.

  File Name:    main.c

  Summary:    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F1847
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"
#define Display PORTB
#include "my_lib_giochi.h"
/***
                         Main application
Pulsante S1 della DemoPic seleziona 3 Giochi diversi, il pulsante S2 azzera qualsiasi gioco, il pulsante S3 esegue
altri 3 giochi.
Eseguendo questo programma si testano i 3 pulsanti ed i 3 Leds della DemoPic
senza interrupt e timer quindi occorre premerlo piu volte per cambiare gioco
Realizzato con plugin CodeConfigurator
***/


char s;
char c=0;
char f=0;

void main(void)
{
    Display=0b00000000;

    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        if(IO_RA3_GetValue()==1)
        {
            c=0;
            f=0;
            Display=0b00000000;
        }
        if(IO_RA2_GetValue()==1)
        {
            c++;  //se premo il Puls1 incremento il valore di c
            f=0;
        }
        if(IO_RA4_GetValue()==1)
        {
            c=0;
            f++;
        }
        if(c==1)
        {
            Supercar();  
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
        if(f==1)
        {
             LampSfas();
        }
        if(f==2)
        {
            ZoomLamp();  //se c e' uguale a 3 esegui la funzione PariDispari
        }
         if(f==3)
        {
            Cascata();  //se c e' uguale a 3 esegui la funzione PariDispari
        }
         if(f==4)
        {
            f=0;  //se f e' uguale a 4 imposta f uguale a 0
        }
    }
}

/**
 End of File
**/