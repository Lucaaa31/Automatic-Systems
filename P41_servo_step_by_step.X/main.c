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
P41_servo_step_by_step
Creare il nuovo progetto in modo tale che un servomotore parta dalla posizione -90° (appoggiato a sx)
- se si preme il pulsante s1 della scheda demoPIC il servomotore ruota di un solo passo verso destra (il più piccolo possibile, al momento abbiamo visto solo passi di 3°).

-ad ogni premuta di s1 si aumenta la rotazione di un passo

-ad ogni premuta di s2 si decrementa il passo rispetto alla situazione in cui è arrivato

-alla premuta di s3 si resetta la posizione (il servo ritorna a riposo appoggiato a -90°)

NB.Quando si è raggiunto il finecorsa un tentativo di continuo rotazione non deve essere consentito.
  
 * Attivi ECCP1 per comando servo e TMR2
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    SYSTEM_Initialize();
    EPWM1_Initialize(); //inizializzazione del modulo epwm1

    int duty = 80; //stato di partenza del motore (-90°)
    
    while (1){
           
        PSTR1CON = 0x01;//PWM Solo Su Bit 3 PORTB
        do{
            EPWM1_LoadDutyValue(duty);  //imposta l'angolazione
            __delay_ms(100);  //delay per dare tempo al motore di fare il movimento
            if(IO_RA2_PORT==1){duty=duty-3;if(duty<22){IO_RB4_PORT=1;}}     //se premo S1 aumenta la rotazione di un passo
            if(IO_RA3_PORT==1){duty=duty+3;if(duty>80){IO_RB2_PORT=1;}}     //se premo S2 aumenta la rotazione di un passo
        }while(duty>=22 && duty<=80);     //finecorsa
        if(IO_RA4_PORT==1){duty=80;}      //reset
    }
}
/**
 End of File
*/