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
P38_doppio_servo
1) Pilotare un secondo servomotore, che esegua rotazioni opposte al primo servo motore:
Esempio:
    se il primo servo è a -90°, il secondo è a +90°.
    se il primo servo è a 45° il secondo è a -45°
    se il primo servo è a 0° il secondo è a 0°
    se il primo servo è a +45° il secondo è a -45°
    se il primo servo è a +90° il secondo è a -90°
    e così via...

Utilizzare modulo ECCP2. Si dovrà settare l'uscita del secondo servo con registro PSTR2CON e utilizzare la funzione EPWM2_LoadDutyValue().

2) TASK: a riposo entrambi i servomotori sono in posizione centrale (0°).
Alla premuta di un pulsante il servo1 si posiziona a -90° e dopo 5 secondi ruota fino a +90°, e lì vi rimane fino alla premuta del pulsante s2 che riporta il servo1 nella posizione di riposo. 
Il servo2 si muoverà sfasato di 180° rispetto a servo1 come da consegna.
  
 * Attivi ECCP1 e ECCP2 per dei comando servo e TMR2
 
*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
   
    SYSTEM_Initialize();
    EPWM1_Initialize(); //inizializzazione del moduo epwm1
    EPWM2_Initialize(); //inizializzazione del moduo epwm1
    
   
    while (1)
    {
       PSTR1CON = 0x01; //PWM Solo Su Bit 3 PORTB (0x08 attiva il pwm sul pin RB7)
       PSTR2CON = 0x01; //PWM Solo Su Bit 5 PORTB (0x08 attiva il pwm sul pin RB7)
       EPWM1_LoadDutyValue(46);             //0°
       EPWM2_LoadDutyValue(46);             //0°
       
       if(IO_RA2_PORT== 1){
           
           EPWM1_LoadDutyValue(22);         //-90°
           EPWM2_LoadDutyValue(69);         //+90
           __delay_ms(5000);
           
           do{
           EPWM1_LoadDutyValue(69);         //+90°
           EPWM2_LoadDutyValue(22);         //-90
           }while(IO_RA3_PORT==0);
       }
    }
}