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
P32_ADC.X
Realizzare un progetto che preveda la conversione in digitale di un segnale analogico 

(partitore di tensione tramite trimmer)    sfruttando il modulo ADC in modo tale che il valore analogico venga scritto in volt (cifra X.YZ) nei tre display della demoPIC.

*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
/*
                         Main application
 */
void p0();  //inizializzo funzioni che in fondo al programma vengono sviluppate
void p1();  //e rappresentano le varie posizioni dei segmenti nei display
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();
void p8();
void p9();

void p0(){
    PORTB=0b00111111;
}
void p1(){
    PORTB = 0b00000110;
}
void p2(){
    PORTB = 0b01011011;
}
void p3(){
    PORTB = 0b01001111;
}
void p4(){
    PORTB = 0b01100110;
}
void p5(){
    PORTB = 0b01101101;
}
void p6(){
    PORTB = 0b01111101;
}
void p7(){
    PORTB = 0b00000111;
}
void p8(){
    PORTB = 0b01111111;
}
void p9(){
    PORTB = 0b01100111;
}
int display1(int); 
int display2(int); 
int display3(int);
int risultato;
int a,b,c;
display1(int a){
    IO_RA0_PORT = 1;
    IO_RA1_PORT = 0;
    if (a==0){
        PORTB=0b10111111;
        __delay_ms(30);
    }
     if (a==1){
        PORTB = 0b10000110;
        __delay_ms(30);
     }
      if (a==2){
        PORTB = 0b11011011;
        __delay_ms(30);
      }
       if (a==3){
        PORTB = 0b11001111;
        __delay_ms(30);
       }
      if (a==4){
        PORTB = 0b11100110;
        __delay_ms(30);
      }
}
display2(int b){
    IO_RA0_PORT = 0;
    IO_RA1_PORT = 1;
    if (b==0){
        p0();
        __delay_ms(30);
    }
     if (b==1){
        p1();
        __delay_ms(30);
     }
      if (b==2){
        p2();
        __delay_ms(30);
      }
       if (b==3){
        p3();
        __delay_ms(30);
       }
      if (b==4){
        p4();
        __delay_ms(30);
      }
      if (b==5){
        p5();
        __delay_ms(30);
      }
      if (b==6){
        p6();
        __delay_ms(30);
      }
      if (b==7){
        p7();
        __delay_ms(30);
      }
       if (b==8){
        p8();
        __delay_ms(30);
       }
        if (b==9){
        p9();
        __delay_ms(30);
    }
}
display3(int c){
    IO_RA0_PORT = 0;
    IO_RA1_PORT = 0;
    if (c==0){
        PORTB=0b00111111;
        __delay_ms(30);
    }
     if (c==1){
        PORTB = 0b00000110;
        __delay_ms(30);
     }
      if (c==2){
        PORTB = 0b01011011;
        __delay_ms(30);
      }
       if (c==3){
        PORTB = 0b01001111;
        __delay_ms(30);
       }
      if (c==4){
        p4();
        __delay_ms(30);
      }
      if (c==5){
        p5();
        __delay_ms(30);
      }
      if (c==6){
        p6();
        __delay_ms(30);
      }
      if (c==7){
        p7();
        __delay_ms(30);
      }
       if (c==8){
        p8();
        __delay_ms(30);
       }
        if (c==9){
        p9();
        __delay_ms(30);
    }
}
int resto;
        
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    ADC_Initialize();
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
       
        ADC_StartConversion();
        
        while(ADCON0bits.GO_nDONE == 1){
            
        }
        risultato = 0.46 * (ADRESL + (256 * ADRESH));
        a= risultato/100;
        resto= risultato%100;
        b= resto/10;
        c= resto%10;
        display1(a);
        display2(b);
        __delay_ms(20);
        display3(c);
    }
}
/**
 End of File
*/