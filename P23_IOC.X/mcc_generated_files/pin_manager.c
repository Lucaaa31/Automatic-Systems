/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1827
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB             :  MPLAB X 5.45

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
 Modifiche righe:
 * 34 e 35, dichiarazione libreria mcc.h e define Display;
 * da 38 a 54, dichiarazione funzione del gioco;
 * 128, funzione dentro a IOCBF0_ISR().
*/

#include "pin_manager.h"
#include "mcc.h"
#define Display PORTB


void Supercar(){
    int i;
    __delay_ms(200);
    Display=0b00000010;  //accendo penultimo led
    for(i=1;i<7;i++)  //ciclo che si ripete 7 volte
    {
        Display=Display<<1;  //scalo di 1 a sinistra lo stato dei led
        __delay_ms(100);  //aspetto 100ms
    }
    for(i=1;i<7;i++)  //ciclo che si ripete 7 volte
    {
        Display=Display>>1;  //scalo di 1 a destra lo stato dei led
        __delay_ms(100);  //aspetto 100ms
    }
    Display=0b00000000;
    
}

void (*IOCBF0_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0xFF;
    TRISB = 0x01;

    /**
    ANSELx registers
    */
    ANSELB = 0x00;
    ANSELA = 0x1F;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    WPUA = 0x00;
    OPTION_REGbits.nWPUEN = 1;


    /**
    APFCONx registers
    */
    APFCON0 = 0x00;
    APFCON1 = 0x00;

    /**
    IOCx registers 
    */
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF0 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN0 = 0;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP0 = 1;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCBF0
    if(IOCBFbits.IOCBF0 == 1)
    {
        IOCBF0_ISR();  
    }	
}

/**
   IOCBF0 Interrupt Service Routine
*/
void IOCBF0_ISR(void) {

    // Add custom IOCBF0 code
    Supercar();
    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF0_InterruptHandler)
    {
        IOCBF0_InterruptHandler();
    }
    IOCBFbits.IOCBF0 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF0 at application runtime
*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF0_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF0
*/
void IOCBF0_DefaultInterruptHandler(void){
    // add your IOCBF0 interrupt custom code
    // or set custom function using IOCBF0_SetInterruptHandler()
}

/**
 End of File
*/