/**
  Generated Main Source File

  Company:    Microchip Technology Inc.

  File Name:    main.c

  Summary:    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F1827
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"
#define Display PORTB
/***
                         Main application
Pulsante S1 della DemoPic seleziona 3 Giochi diversi, il pulsante S2 azzera qualsiasi gioco, il pulsante S3 esegue
altri 3 giochi.
Eseguendo questo programma si testano i 3 pulsanti ed i 3 Leds della DemoPic
senza interrupt e timer quindi occorre premerlo piu volte per cambiare gioco
Realizzato con plugin CodeConfigurator
***/
void PalleR();  
void Supercar();
void PariDispari();
void LampSfas (); /*funzione aggiuntiva che si attiva premendo il pulsante RA4,ovvero 
                   il terzo, questo simula il lampggio sfasato delle lucine di natale con i LEDs*/
void ZoomLamp ();  /*funzione aggiuntiva che si attiva premendo il pulsante RA4 (il terzo),
                   questo simula un lampeggio continuo dei led in modalità interno/esterno  */
void Cascata ();  /*funzione aggiuntiva che si attiva premendo il pulsante RA4, questo gioco 
                   simula una cascata di accensione di led in maniera continua*/

char s;
char c=0;
char f=0;

void main(void)
{
    Display=0b00000000;

    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        if(IO_RA3_GetValue()==1)
        {
            c=0;
            f=0;
            Display=0b00000000;
        }
        if(IO_RA2_GetValue()==1)
        {
            c++;  //se premo il Puls1 incremento il valore di c
            f=0;
        }
        if(IO_RA4_GetValue()==1)
        {
            c=0;
            f++;
        }
        if(c==1)
        {
            Supercar();  //se c e' uguale a 1 esegui la funzione Supercar
        }
        if(c==2)
        {
            PalleR();  //se c e' uguale a 2 esegui la funzione PalleR
        }
        if(c==3)
        {
            PariDispari();  //se c e' uguale a 3 esegui la funzione PariDispari
        }
        if(c==4)
        {
            c=0;  //se c e' uguale a 4 imposta c uguale a 0
        }
        if(f==1)
        {
             LampSfas();
        }
        if(f==2)
        {
            ZoomLamp();  //se c e' uguale a 3 esegui la funzione PariDispari
        }
         if(f==3)
        {
            Cascata();  //se c e' uguale a 3 esegui la funzione PariDispari
        }
         if(f==4)
        {
            f=0;  //se f e' uguale a 4 imposta f uguale a 0
        }
    }
}
void Supercar()
{
    char i=0;  //inizializzo i
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
}
void PalleR()
{
    char a=0b00010000;  //inizializzo a
    char b=0b00001000;  //inizializzo b
    char i=0;  //inizializzo i
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
}
void PariDispari()
{
    char i=0;  //inizializzo i
        Display=0b00000010;  //accendo il penultimo led
        __delay_ms(200);  //aspetto 200ms
        for(i=0;i<3;i++)  //ciclo che si ripete 3 volte
        {
            Display=Display<<2;  //scalo a sinistra di 2 il valore del PORTB
            __delay_ms(200);  //aspetto 200ms
        }
        Display=0b01000000;  //accendo il secondo led
        __delay_ms(200);  //aspetto 200ms
        for(i=0;i<3;i++)  //ciclo che si ripete 3 volte
        {
            Display=Display>>2;  //scalo a destra di 2 il valore del PORTB
            __delay_ms(200);  //aspetto 200ms
        }
}
void LampSfas ()  //funzione che simula le lucine di natale che si accendono e spengono
{
    Display=0b01010101; //accendo tutti i Led pari
    __delay_ms(200);
    Display=0b10101010;  // accendo tutti i LED dispari
    __delay_ms(200);
}

void ZoomLamp () 
{
    Display=0b11000011;  //accendo le coppie di led esterne
    __delay_ms(200);
    Display=0b00111100;  // accendo i quattro led interni
    __delay_ms(200);
}

void Cascata() 
{
    char i=0;  //inizializzo i
        Display =0b10000001;  
        __delay_ms(1000);  //aspetto 1000s
        for(i=0;i<6;i++)  //ciclo che si ripete 6 volte
        {
            Display = Display<<1;  //scalo a sinistra di un valore del PORTB
            __delay_ms(100);  //aspetto 100ms
        }

}
/**
 End of File
**/