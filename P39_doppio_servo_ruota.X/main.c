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
P39_doppio_servo_ruota
I due servomotori partono in posizione opposta (uno -90° e uno +90°). 
-Alla premuta di s1 iniziano una rotazione fino alla massima escursione (+90° e -90° rispettivamente) con passo di 30° ogni 5 secondi
-Alla premuta di s2 iniziano una rotazione fino alla massima escursione (+90° e -90° rispettivamente) con passo di 15° ogni 3 secondi

-Alla premuta di s3 iniziano una rotazione fino alla massima escursione (+90° e -90° rispettivamente) con passo di 3° ogni secondo

premendo i 3 pulsanti contemporaneamente si ritorna alla condizione di riposo

Una premuta di un altro pulsante durante l'esecuzione del compito non deve essere rilevata
 
 * Attivi ECCP1 e ECCP2 per dei comando servo e TMR2
*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
   
    SYSTEM_Initialize();
    EPWM1_Initialize(); //inizializzazione del moduo epwm1
    EPWM2_Initialize(); //inizializzazione del moduo epwm2
    
   
    while (1)
    {
       PSTR1CON = 0x01; //PWM Solo Su Bit 3 PORTB (0x08 attiva il pwm sul pin RB7)
       PSTR2CON = 0x01; //PWM Solo Su Bit 6 PORTB (0x08 attiva il pwm sul pin RB7)
       EPWM1_LoadDutyValue(22);
       EPWM2_LoadDutyValue(69);   
       
       if(IO_RA2_PORT== 1){
           int inc = 8;
           int duty1 = 22;
           int duty2 = 69;
           do{
            EPWM1_LoadDutyValue(duty1);
            EPWM2_LoadDutyValue(duty2);
            __delay_ms(500);
            duty1=duty1+inc;
            duty2=duty2-inc;
           }while(duty1<69 && duty2>22);
       }    
        if(IO_RA3_PORT== 1){
           int inc = 4;
           int duty1 = 22;
           int duty2 = 69;
           do{
            EPWM1_LoadDutyValue(duty1);
            EPWM2_LoadDutyValue(duty2);
            __delay_ms(500);
            duty1=duty1+inc;
            duty2=duty2-inc;
           }while(duty1<69 && duty2>22);
        }
       if(IO_RA4_PORT== 1){
           int inc = 1;
           int duty1 = 22;
           int duty2 = 69;
           do{
           EPWM1_LoadDutyValue(duty1);
           EPWM2_LoadDutyValue(duty2);
           __delay_ms(500);
           duty1=duty1+inc;
           duty2=duty2-inc;
           }while(duty1<69 && duty2>22);
        }
    }
}