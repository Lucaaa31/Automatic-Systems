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
P40_servo_tergi
Creare il nuovo progetto in modo tale che due servomotori partano dalla posizione -90° (appoggiati a sx come tergicristallo auto)

- se si preme il pulsante s1 della scheda demoPIC i due servomotori ruotano di 135° e poi ritornano alla posizione iniziale, ripetendo continuamente il ciclo dopo lo stesso tempo di 4 secondi

- se si preme il pulsante s2, il ritardo nella rotazione si abbassa a 2 secondi

- se si preme il pulsante s3, il ritardo nella rotazione si abbassa a 0,5 secondi

- se si preme il pulsante s1 contemporaneamente a s2 della scheda demoPIC, i due servomotori si posizionano alla posizione di riposo e non ruotano fino alla premuta di uno degli altri tasti
  
 * Attivi ECCP1 e ECCP2 per comando dei servo e TMR2
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    
    SYSTEM_Initialize();
    EPWM1_Initialize(); //inizializzazione del modulo epwm1
    EPWM2_Initialize(); //inizializzazione del modulo epwm2

    int a;
    
    while (1){
      
      PSTR1CON = 0x01; //PWM Solo Su Bit 3 PORTB (0x08 attiva il pwm sul pin RB7)
      PSTR2CON = 0x01; //PWM Solo Su Bit 6 PORTB (0x08 attiva il pwm sul pin RB7)
      EPWM1_LoadDutyValue(22);      //stato iniziale motore 1
      EPWM2_LoadDutyValue(22);      //stato iniziale motore 2
      __delay_ms(500);
  
        if(IO_RA2_PORT==1){a=1;}
        if(IO_RA3_PORT==1){a=2;}
        if(IO_RA4_PORT==1){a=3;}
        if(IO_RA2_PORT==1 && IO_RA3_PORT==1){a=4;}      //reset
      
        switch(a){                  //in base al valore di "a" i motori ruotano con un certo ritardo
            case 1:
                EPWM1_LoadDutyValue(69);
                EPWM2_LoadDutyValue(69);
                __delay_ms(4000);           //ritardo di 4 secondi
                break;
            case 2:
                EPWM1_LoadDutyValue(69);
                EPWM2_LoadDutyValue(69);
                __delay_ms(2000);           //ritardo di 2 secondi
                break;
            case 3:
                EPWM1_LoadDutyValue(69);
                EPWM2_LoadDutyValue(69);
                __delay_ms(500);            //ritardo di 0.5 secondi
                break;
            case 4:
                EPWM1_LoadDutyValue(22);
                EPWM2_LoadDutyValue(22);
                __delay_ms(500);
                break;
        }

    }
}
/**
 End of File
*/