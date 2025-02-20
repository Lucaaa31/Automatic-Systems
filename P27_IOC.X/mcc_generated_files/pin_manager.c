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
 * da 37 a 77, dichiarazione variabili e funzioni dei giochi;
 * 126 e 133, variabili che contano il numero di premute nei pulsanti;
 * da 175 a 177, funzione dentro a IOCBF0_ISR().
*/
#include "pin_manager.h"
#include "mcc.h"
#define Display PORTB

int count,a,b,c,d;
void Supercar(){
    int i;
    __delay_ms(200);
    Display=0b00001000;  //accendo penultimo led
    for(i=3;i<7;i++)  //ciclo che si ripete 7 volte
    {
        Display=Display<<1;  //scalo di 1 a sinistra lo stato dei led
        __delay_ms(100);  //aspetto 100ms
    }
    for(i=3;i<7;i++)  //ciclo che si ripete 7 volte
    {
        Display=Display>>1;  //scalo di 1 a destra lo stato dei led
        __delay_ms(100);  //aspetto 100ms
    }
    Display=0b00000000;
}

void LampSfas(){  //funzione che simula le lucine di natale che si accendono e spengono
    Display=0b01010100; //accendo tutti i Led pari
    __delay_ms(100);
    Display=0b10101010;  // accendo tutti i LED dispari
    __delay_ms(100);
    Display=0b00000000;
}                 

void Led_DX_SX(){
    Display=0b00001000;
    __delay_ms(100);
    Display=0b10000000;
    __delay_ms(100);
    Display=0b00010000;
    __delay_ms(100);
    Display=0b01000000;
    __delay_ms(100);
    Display=0b00100000;
    __delay_ms(100);
    Display=0b00000000;
    __delay_ms(100);
    
}

void (*IOCBF0_InterruptHandler)(void);
void (*IOCBF1_InterruptHandler)(void);
void (*IOCBF2_InterruptHandler)(void);


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
    TRISB = 0x07;

    /**
    ANSELx registers
    */
    ANSELB = 0xF8;
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
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF1 = 0;
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF2 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN0 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN1 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN2 = 0;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP0 = 1;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP1 = 1;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP2 = 1;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCBF0+
    if(IOCBFbits.IOCBF0 == 1 && IOCBFbits.IOCBF1 == 1){
        IO_RB6_SetHigh();
        __delay_ms(6000);
        IOCBF0_ISR();
    }
    else if(IOCBFbits.IOCBF0 == 1 && IOCBFbits.IOCBF1 == 0)
    {
        __delay_ms(5000);
        a=1;
        __delay_ms(3000);
        a=2;
        if(a==2 && IOCBFbits.IOCBF1 == 1 && IOCBFbits.IOCBF0 == 1){
            IOCBF2_ISR();
        }
    }	
	// interrupt on change for pin IOCBF1
    else if(IOCBFbits.IOCBF1 == 1 && IOCBFbits.IOCBF0 == 0)
    {
        __delay_ms(3000);
        b=1;
        IOCBF1_ISR();
    }	
	// interrupt on change for pin IOCBF2
    else if(IOCBFbits.IOCBF2 == 1)
    {
        IOCBF2_ISR();
    }	
}

/**
   IOCBF0 Interrupt Service Routine
*/
void IOCBF0_ISR(void) {

    // Add custom IOCBF0 code
    while(IOCBFbits.IOCBF0 == 0 && IOCBFbits.IOCBF1 == 0 && IOCBFbits.IOCBF2 == 0){
        IO_RB7_SetHigh();
    }
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
   IOCBF1 Interrupt Service Routine
*/
void IOCBF1_ISR(void) {

    // Add custom IOCBF1 code
    
    if(a==1 && b==1){
        while(IOCBFbits.IOCBF0 == 0 && IOCBFbits.IOCBF1 == 0 && IOCBFbits.IOCBF2 == 0){
        LampSfas();
        }
        a=0;
        b=0;
    }
    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF1_InterruptHandler)
    {
        IOCBF1_InterruptHandler();
    }
    IOCBFbits.IOCBF1 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF1 at application runtime
*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF1
*/
void IOCBF1_DefaultInterruptHandler(void){
    // add your IOCBF1 interrupt custom code
    // or set custom function using IOCBF1_SetInterruptHandler()
}

/**
   IOCBF2 Interrupt Service Routine
*/
void IOCBF2_ISR(void) {

    // Add custom IOCBF2 code
    while(IOCBFbits.IOCBF0 == 0 && IOCBFbits.IOCBF1 == 0 && IOCBFbits.IOCBF2 == 0){
    Led_DX_SX();
    }
    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF2_InterruptHandler)
    {
        IOCBF2_InterruptHandler();
    }
    IOCBFbits.IOCBF2 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF2 at application runtime
*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF2
*/
void IOCBF2_DefaultInterruptHandler(void){
    // add your IOCBF2 interrupt custom code
    // or set custom function using IOCBF2_SetInterruptHandler()
}

/**
 End of File
*/