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
 * P37_servo_1
 * P1: partendo da posizione centrale (90) il servo si posiziona in posizione 0", ruota fino a 180° dopo una attesa di 3 secondo.
   Dopo un ulteriore attesa di 5 secondi torna nella posizione 90° e li vi rimane fino ad una successiva premuta premuta pulsante 
 
 * P2: servo si posiziona in posizione 0° e ruota fino a 180° con passi di 30° ogni 3 secondi.
   In ogni momento è possibile invertire la rotazione (tornare a 0, sempre con step di 30") con la premuta di pulsante p3.
 
 * Nota: in posizione 0 si accende LED (rb0) posizione centrale 90° si accende LED1 (rb1) posizione 180° si accende LED2(rb2)
 
 * Attivi ECCP1 per comando servo e TMR2

*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
   
    SYSTEM_Initialize();
    EPWM1_Initialize(); //inizializzazione del moduo epwm1

    
    while (1)
    {
       PSTR1CON = 0x01; //PWM Solo Su Bit 3 PORTB (0x08 attiva il pwm sul pin RB7)
        
        EPWM1_LoadDutyValue(46); //Duty 7.5%, 90°
        PORTB = 0b00000010;
        if(IO_RA2_GetValue()==1){
            EPWM1_LoadDutyValue(22); //Duty 3.75%, 0°
            PORTB = 0b00000001;
            __delay_ms(3000);
            EPWM1_LoadDutyValue(69); //Duty 11.25%, 180°
            PORTB = 0b00000100;
            __delay_ms(5000);
        }
        if(IO_RA3_GetValue()==1){
            int duty = 22;
            int inc = 8;
            do{
                EPWM1_LoadDutyValue(duty);
                __delay_ms(3000);
                if(IO_RA4_GetValue()==1){
                    inc=-8;}
                    duty=duty+inc;
            }while(duty<69&&duty>22);
           if(duty<23){
            PORTB = 0b00000001;
           } 
           if(duty>68){
            PORTB = 0b00000100;
           } 
           if(duty==46){
            PORTB = 0b00000010;
           } 
            
        }
    }
}