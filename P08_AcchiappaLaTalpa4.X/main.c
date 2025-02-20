/** PIC16F1826-I/P pin to pin compatibile con PIC16F84A
* I=> -40°C/85°C
* P=> PDIP
** 
** TEMPLATE MPLabX 5.05 compilatore XC8 2.00 ***
                                ______________
                               |    16F1826   |
                   RA2     x---|1           18|---x RA1
                   RA3     x---|2           17|---x RA0
                   RA4     x---|3           16|---x RA7
                   RA5     x---|4           15|---x RA6
                       Vss x---|5           14|---x Vdd
                   RB0     x---|6           13|---x RB7
                   RB1     x---|7           12|---x RB6
                   RB2     x---|8           11|---x RB5
                   RB3     x---|9           10|---x RB4
                               |______________|    
*********************************** PINNING O PINOUT *****************/
/* Appena questo programma viene caricato parte un ciclo che gira in senso antiorario 
 * a partire dal segmento d del display dei secondi(RA0), i segmenti si accendono e spengono nella 
 * sequenza sopra indicata se vengono premuti il primo e il terzo pulsante contemporaneamente 
 * il ciclo diventa in senso orario a partire da segmento a del display PORTB e se 
 * premo tutti e tre i pulsanti contemporaneamente il segmento a del dislpay PORTB
 * rimane acceso per 1 secondo prima di far continuare il ciclo sempre in verso orario
*/
/**
  Generated Main Source File
  Company:    Microchip Technology Inc.
  File Name:    main.c
  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F1826
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/* La differenza fra AcchiappaLaTalpa3 e AcchiappaLaTalpa4 è che  il primo display ad accendersi
 * è il d del display dei secondi  e che il segmentoche rimane fermo per 1 secondo  è il segmento 
 * a del display PORTBe e indipendentemente dal giro che stava eseguendo continua il ciclo in senso orario*/
 

#include "mcc_generated_files/mcc.h"

/*                         Main application */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

     while(1){   // ciclo infinito
        
        IO_RA0_PORT = 1;		//abilito il display dei secondi (RA0)
        PORTB = 0b00001000;		//attivo il segmento "d" del display dei secondi
        __delay_ms(100);        	//ritardo di 100ms
        IO_RA0_PORT = 0;
        
        IO_RA1_PORT = 1;		//abilito il display dei decimi(RA1)
        PORTB = 0b00001000;		//attivo il quarto display
        __delay_ms(100);			//ritardo di 100ms
        IO_RA1_PORT = 0;		//disabilito il display dei decimi (RA1)
        
        PORTB = 0b00001000;		//attivo il segmento "d" del display PORTB
        __delay_ms(100);			//ritardo di 100ms
        PORTB = 0b00000100; 	//attivo il segmento "c" del display PORTB
        __delay_ms(100);			//ritardo di 100ms
        PORTB = 0B00000010;		//attivo il segmento "b" del display PORTB
        __delay_ms(100);			//ritardo di 100ms
        PORTB = 0b00000001;		//attivo il segmento "a" del display PORTB
        __delay_ms(100);			//ritardo di 100ms

        if(IO_RA2_PORT == 1 && IO_RA4_PORT == 1){ // se premo il primo e il terzo pulsante si esegue il secondo ciclo infinito
             
            while(1){	//ciclo infinito
                
                if (IO_RA2_PORT == 1 && IO_RA3_PORT == 1 && IO_RA4_PORT == 1){ // se premo tutti e tre i pulsanti si blocca sul segmento "a" del display dei secondi
                     __delay_ms (1000) ;    // ritardo di 1000 ms 
                } 

                PORTB = 0B00000010;		//attivo il segmento "b" del display PORTB 
                __delay_ms(100);			//ritardo di 100ms
                PORTB = 0b00000100;		//attivo il segmento "c" del display PORTB  
                __delay_ms(100);			//ritardo di 100ms
                PORTB = 0b00001000;		//attivo il segmento "d" del display PORTB 
                __delay_ms(100);			//ritardo di 100ms

                IO_RA1_PORT = 1;		//abilito display il display dei decimi(RA1)
                PORTB = 0b00001000;		//attivo il segmento "d" 
                __delay_ms(100);			//ritardo di 100ms
                IO_RA1_PORT = 0;		//disabilito il display dei decimi(RA1)

                IO_RA0_PORT = 1;		//abilito il display dei secondi (RA0)
                PORTB = 0b00001000;		//attivo il segmento "d" del display secondi 
                __delay_ms(100);			//ritardo di 100ms
                PORTB = 0b00010000;		//attivo il segmento "e" del display secondi
                __delay_ms(100);			//ritardo di 100ms
                PORTB = 0b00100000;		//attivo il segmento "f" del display secondi
                __delay_ms(100);			//ritardo di 100ms
                PORTB = 0b00000001;		//attivo il segmento "a" del display secondi
                 __delay_ms(100);	
                IO_RA0_PORT = 0; 

                IO_RA1_PORT = 1;		//abilito il display dei decimi (RA1)
                PORTB = 0b00000001;		//attivo il segmento "a" del display dei secondi
                __delay_ms(100);			//ritardo di 100ms
                IO_RA1_PORT = 0;		//disabilito il display dei decimi(RA1)
                
                PORTB = 0b00000001;     //attivo il segmento "a" del display dei decimi
                __delay_ms(100);

                if (IO_RA2_PORT == 1 && IO_RA3_PORT == 1 && IO_RA4_PORT == 1){
                     __delay_ms (1000) ;
                } 
                else if(IO_RA2_PORT == 1 && IO_RA4_PORT == 1){ //se premo il primo e il terzo pulsante eseguo il primo ciclo 
                    break;				//interrompe il ciclo
                }
                    IO_RA0_PORT = 0;	//disabilito il display dei secondi (RA0)
            }
                
        }
        
        IO_RA1_PORT = 1;				//abilito il display dei decimi (RA1)
        PORTB = 0b00000001;				//attivo il segmento "a" del display dei decimi
        __delay_ms(100);					//ritardo di 100ms
        IO_RA1_PORT = 0;				//disabilito il display dei decimi(RA1)
        
        IO_RA0_PORT = 1;
        PORTB = 0B00000001;				//attivo il segmento "a" del display dei secondi 
        __delay_ms(100);					//ritardo di 100ms
        PORTB = 0b00100000;				//attivo il segmento "f" del display dei secondi
        __delay_ms(100);					//ritardo di 100ms
        PORTB = 0b00010000;				//attivo il segmento "e" del display dei secondi
        __delay_ms(100);					//ritardo di 100ms
        IO_RA0_PORT = 0;				//disabilito il display dei secondi(RA0)
        
    }
}
/**
 End of File
*/