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
P36_PWM_2
Questo programma utilizza il modulo PWM per modulare l'intensità delle quattro uscite RB3,
RB5, RB6, RB7.
Usiamo anche 3 pulsanti per selezionare l'uscita.

 * Attivi ECCP1 per comando servo e TMR2
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void){
    SYSTEM_Initialize(); //Inizializzazione Del Microcontrollore while (1)
    EPWM1_Initialize();  //inizializzazione del modulo epwm1

    while(1){
        RB3_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso
        RB5_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso
        RB6_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso
        RB7_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso

        while(IO_RA2_GetValue() ==1 && IO_RA4_GetValue() ==0){
            PSTR1CON = 0x02; //PWM Solo Su Bit 5 PORTB (0x02 attiva il pwm sul pin RB5)
            EPWM1_LoadDutyValue(0); //Duty 0%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(99); //Duty 20%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(199); //Duty 40%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(299); //Duty 60%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(399); //Duty 80%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(499); //Duty 100%
            __delay_ms(500); //Aspetto 500ms
        }

        while(IO_RA3_GetValue() ==1){
            PSTR1CON = 0x04; //PWM Solo Su Bit 6 PORTB (0x04 attiva il pwm sul pin RB6)
            EPWM1_LoadDutyValue(499); //Duty 100%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(399); //Duty 80%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(299); //Duty 60%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(199); //Duty 40%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(99); //Duty 20%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(0); //Duty 0%
            __delay_ms(500); //Aspetto 500ms
        }

        while(IO_RA4_GetValue() ==1 && IO_RA2_GetValue() ==0){
            PSTR1CON = 0x08; //PWM Solo Su Bit 7 PORTB (0x08 attiva il pwm sul pin RB7)
            EPWM1_LoadDutyValue(0); //Duty 0%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(99); //Duty 20%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(199); //Duty 40%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(299); //Duty 60%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(399); //Duty 80%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(499); //Duty 100%
            __delay_ms(500); //Aspetto 500ms
        }

        while(IO_RA2_GetValue() ==1 && IO_RA4_GetValue() ==1){
            PSTR1CON = 0x01; //PWM Solo Su Bit 3 PORTB (0x01 attiva il pwm sul pin RB3)
            EPWM1_LoadDutyValue(499); //Duty 100%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(399); //Duty 80%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(299); //Duty 60%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(199); //Duty 40%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(99); //Duty 20%
            __delay_ms(500); //Aspetto 500ms
            EPWM1_LoadDutyValue(0); //Duty 0%
            __delay_ms(500); //Aspetto 500ms
        }
    }
}