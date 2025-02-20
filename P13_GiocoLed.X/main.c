/**
P13_GiocoLed.X
Realizzare un programma che utilizza due pulsanti S1 e S2: 
-premendo il primo pulsante (S1) si accende un led
-premendolo nuovamente se ne accende una altro fino ad accenderli tutti. 
-con il secondo pulsante (S2) li vado a spegnere uno alla volta.
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
                        PORTB = 0b10000000;
                        __delay_ms(100);
                        break;
                    case 2: 
                        PORTB = 0b11000000;
                        __delay_ms(100);
                        break;
                    case 3: 
                        PORTB = 0b11100000;
                        __delay_ms(100);
                        break;
                    case 4: 
                        PORTB = 0b11110000;
                        __delay_ms(100);
                        break;
                    case 5: 
                        PORTB = 0b11111000;
                        __delay_ms(100);
                        break;
                    case 6: 
                        PORTB = 0b11111100;
                        __delay_ms(100);
                        break;
                    case 7: 
                        PORTB = 0b11111110;
                        __delay_ms(100);
                        break;
                    case 8: 
                        PORTB = 0b11111111;
                        __delay_ms(100);
                        break;
                }
            }
            
        

        if(IO_RA3_PORT == 1){
            i=i--;
            
                switch(i){
                    case 1: 
                        PORTB = 0b00000000;
                        __delay_ms(100);
                        break;
                    case 2: 
                        PORTB = 0b10000000;
                        __delay_ms(100);
                        break;
                    case 3: 
                        PORTB = 0b11000000;
                        __delay_ms(100);
                        break;
                    case 4: 
                        PORTB = 0b11100000;
                        __delay_ms(100);
                        break;
                    case 5: 
                        PORTB = 0b11110000;
                        __delay_ms(100);
                        break;
                    case 6: 
                        PORTB = 0b11111000;
                        __delay_ms(100);
                        break;
                    case 7: 
                        PORTB = 0b11111100;
                        __delay_ms(100);
                        break;
                    case 8: 
                        PORTB = 0b11111110;
                        __delay_ms(100);
                        break;
                    }
                
            }
        }
    }

/**
 End of File
*/