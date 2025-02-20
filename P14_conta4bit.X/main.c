/**
P14_conta4bit.X
Creare un nuovo progetto dove, si realizzi un contatore avanti/indietro binario modulo 16, asincrono.
Servono: 
4 bit di portB (led come uscite)
Un ingresso su portA (pulsante p1) per conteggio in avanti
Un ingresso su portA (pulsante p2) per conteggio all'indietro
Ad ogni premuta del pulsante p1 parte il conteggio da 0 a 15 e il rispettivo valore binario viene visualizzato su 4 bit.
Ad ogni premuta del pulsante p2 parte si decrementa il conteggio di una unità e il rispettivo valore binario viene visualizzato su 4 bit.
*/

#include "mcc_generated_files/mcc.h"


void main(void)
{
    int i;
    SYSTEM_Initialize();
    while (1)
    {
        if(IO_RA2_PORT == 1){
            i=i++;
                switch(i){
                    case 1: 
                        PORTB = 0b000000001;
                        __delay_ms(100);
                        break;
                    case 2: 
                        PORTB = 0b00000010;
                        __delay_ms(100);
                        break;
                    case 3: 
                        PORTB = 0b00000011;
                        __delay_ms(100);
                        break;
                    case 4: 
                        PORTB = 0b00000100;
                        __delay_ms(100);
                        break;
                    case 5: 
                        PORTB = 0b00000101;
                        __delay_ms(100);
                        break;
                    case 6: 
                        PORTB = 0b00000110;
                        __delay_ms(100);
                        break;
                    case 7: 
                        PORTB = 0b00000111;
                        __delay_ms(100);
                        break;
                    case 8: 
                        PORTB = 0b00001000;
                        __delay_ms(100);
                        break;
                    case 9: 
                        PORTB = 0b00001001;
                        __delay_ms(100);
                        break;
                    case 10:
                        PORTB = 0b00001010;
                        __delay_ms(100);
                        break;
                    case 11:
                        PORTB = 0b00001011;
                        __delay_ms(100);
                        break;
                    case 12:
                        PORTB = 0b00001100;
                        __delay_ms(100);
                        break;
                    case 13:
                        PORTB = 0b00001101;
                        __delay_ms(100);
                        break;
                    case 14:
                        PORTB = 0b00001110;
                        __delay_ms(100);
                        break;
                    case 15:
                        PORTB = 0b00001111;
                        __delay_ms(100);
                        break;
                    
                }
            }
            
        

        if(IO_RA3_PORT == 1){
            i=i--;
            switch(i){
                    case 1: 
                        PORTB = 0b000000001;
                        __delay_ms(100);
                        break;
                    case 2: 
                        PORTB = 0b00000010;
                        __delay_ms(100);
                        break;
                    case 3: 
                        PORTB = 0b00000011;
                        __delay_ms(100);
                        break;
                    case 4: 
                        PORTB = 0b00000100;
                        __delay_ms(100);
                        break;
                    case 5: 
                        PORTB = 0b00000101;
                        __delay_ms(100);
                        break;
                    case 6: 
                        PORTB = 0b00000110;
                        __delay_ms(100);
                        break;
                    case 7: 
                        PORTB = 0b00000111;
                        __delay_ms(100);
                        break;
                    case 8: 
                        PORTB = 0b00001000;
                        __delay_ms(100);
                        break;
                    case 9: 
                        PORTB = 0b00001001;
                        __delay_ms(100);
                        break;
                    case 10:
                        PORTB = 0b00001010;
                        __delay_ms(100);
                        break;
                    case 11:
                        PORTB = 0b00001011;
                        __delay_ms(100);
                        break;
                    case 12:
                        PORTB = 0b00001100;
                        __delay_ms(100);
                        break;
                    case 13:
                        PORTB = 0b00001101;
                        __delay_ms(100);
                        break;
                    case 14:
                        PORTB = 0b00001110;
                        __delay_ms(100);
                        break;
                    case 15:
                        PORTB = 0b00001111;
                        __delay_ms(100);
                        break;
                    
                }
                
                
            }
        }
    }

/**
 End of File
*/