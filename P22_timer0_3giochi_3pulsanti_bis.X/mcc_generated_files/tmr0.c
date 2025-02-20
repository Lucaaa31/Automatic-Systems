/**
  TMR0 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr0.c

  @Summary
    This is the generated driver implementation file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR0.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1827
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45
*/

/*
 Modifiche righe:
 * 37 e 38, dichiarazione libreria mcc.h e define Display;
 * da 93 a 136, dichiarazione variabili e funzioni dei giochi;
 * da 150 a 195, funzionamento programma;
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr0.h"
#include "mcc.h"
#define Display PORTB
/**
  Section: Global Variables Definitions
*/

volatile uint8_t timer0ReloadVal;
void (*TMR0_InterruptHandler)(void);
/**
  Section: TMR0 APIs
*/

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface
	
    // PSA assigned; PS 1:256; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits
    OPTION_REG = (uint8_t)((OPTION_REG & 0xC0) | (0xD7 & 0x3F)); 
	
    // TMR0 61; 
    TMR0 = 0x3D;
	
    // Load the TMR value to reload variable
    timer0ReloadVal= 61;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
}

uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TMR0;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer0 register
    TMR0 = timerVal;
}

void TMR0_Reload(void)
{
    // Write to the Timer0 register
    TMR0 = timer0ReloadVal;
}

int i,count,count1,ciclo1,ciclo2,ciclo3, reset;

void Supercar(){
    Display=0b00000001;  //accendo l'ultimo led
    for(i=0;i<7;i++)  //ciclo che si ripete 7 volte
    {
        Display=Display<<1;  //scalo di 1 a sinistra lo stato dei led
        __delay_ms(100);  //aspetto 100ms
    }
    for(i=0;i<7;i++)  //ciclo che si ripete 7 volte
    {
        Display=Display>>1;  //scalo di 1 a destra lo stato dei led
        __delay_ms(100);  //aspetto 100ms
    }
    Display=0b00000000;
}

void PalleR(){
    int a=0b00010000;
    int b=0b00001000;
        for(i=0;i<3;i++)  //ciclo che si ripete 3 volte
           {
                Display=a|b;  //il valore del PORTB è dato dalla somma di a e b
                a=a<<1;  //scalo di 1 a sinistra il valore binario di a
                b=b>>1;  //scalo di 1 a sinistra il valore binario di b
                __delay_ms(50);  //aspetto 50ms
           }
          for(i=0;i<3;i++)  //ciclo che si ripete 3 volte
          {
                Display=a|b;  //il valore del PORTB è dato dalla somma di a e b
                a=a>>1;  //scalo di 1 a sinistra il valore binario di a
                b=b<<1;  //scalo di 1 a sinistra il valore binario di b
                __delay_ms(50);  //aspetto 50ms
          }
    Display=0b00000000;    
}

void LampSfas (){  //funzione che simula le lucine di natale che si accendono e spengono
    Display=0b01010101; //accendo tutti i Led pari
    __delay_ms(100);
    Display=0b10101010;  // accendo tutti i LED dispari
    __delay_ms(100);
    Display=0b00000000;
}

void TMR0_ISR(void){

    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    TMR0 = timer0ReloadVal;

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }
    
    if(IO_RA2_PORT==1 && IO_RA3_PORT==1 && IO_RA4_PORT==1){
        reset++;
        if(reset==60){
            count=0;
            count1=0;
            ciclo1=0;
            ciclo2=0;
            ciclo3=0;
            reset=0;
        }
        Display=0b11111111;
    }
    
    else if(IO_RA2_PORT==1 && IO_RA3_PORT==0 && IO_RA4_PORT==0){
        count++;
    }
    
    else if(count<100 && IO_RA2_PORT==0){
        count=0;
    }
    
    else if(count>100 && count<120 && (IO_RA3_PORT==1 || ciclo1==1) && ciclo2==0 && ciclo3==0){            
        count1++;
        if((IO_RA3_PORT==1 || ciclo1==1) && count1>60){
            Supercar();
            ciclo1=1;
            reset=0;
        }
    }
    
    else if(count>120 && count<160 && IO_RA3_PORT==0 && (IO_RA4_PORT==1 || ciclo2==1) && ciclo1==0 && ciclo3==0){
        count1++;
        if((IO_RA4_PORT==1 || ciclo2==1) && count1>60){
            PalleR(); 
            ciclo2=1;
            reset=0;
        }
    }
    
    else if(count>160 && ((IO_RA3_PORT==1 && IO_RA4_PORT==1) || ciclo3==1) && ciclo1==0 && ciclo2==0){
        count1++;
        if(((IO_RA3_PORT==1 && IO_RA4_PORT==1) || ciclo3==1) && count1>60){
            LampSfas(); 
            ciclo3=1;
            reset=0;
        }
    }
}






void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void){
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
}

/**
  End of File
*/
