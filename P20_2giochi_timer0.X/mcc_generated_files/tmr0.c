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
 * 38, dichiarazione libreria mcc.h;
 * da 93 a 96, dichiarazione variabili;
 * da 110 a 139, funzionamento programma;
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr0.h"
#include "mcc.h"
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
	
    // TMR0 236; 
    TMR0 = 0xEC;
	
    // Load the TMR value to reload variable
    timer0ReloadVal= 236;

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

int i, c, l;
int a=0b00010000;  
int b=0b00001000;  
int i=0;
    
void TMR0_ISR(void)
{

    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    TMR0 = timer0ReloadVal;

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }
    if(IO_RA2_PORT == 1){
        l=1;
        do{
        PORTB = 0b00000001;
            for(c=0; c<7; c++){
                PORTB=PORTB<<1;
                __delay_ms(50);
            }
            for(c=0; c<7; c++){
                PORTB=PORTB>>1;
                __delay_ms(50);       
            }
        }while(IO_RA3_PORT == 0);
            if(IO_RA3_PORT == 1){ 
                do{
                    for(i=0;i<3;i++){
                        PORTB=a|b;  
                        a=a<<1;  
                        b=b>>1;  
                        __delay_ms(50);  
                }
                for(i=0;i<3;i++){
                    PORTB=a|b;  
                    a=a>>1;  
                    b=b<<1;  
                    __delay_ms(50);  
                }
                }while(IO_RA2_PORT == 0);
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
