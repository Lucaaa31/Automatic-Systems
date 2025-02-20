#include "mcc_generated_files/mcc.h"
#include "lib_conta99.h"
 
void p0(){
   PORTB = 0b00111111;
   __delay_ms(20);
}
void p1(){
   PORTB = 0b00000110;
   __delay_ms(20);
}
void p2(){
   PORTB = 0b01011011;
   __delay_ms(20);
}
void p3(){
   PORTB = 0b01001111;
   __delay_ms(20);
}
void p4(){
   PORTB = 0b01100110;
   __delay_ms(20);
}
void p5(){
   PORTB = 0b01101101;
   __delay_ms(20);
}
void p6(){
   PORTB = 0b01111101;
   __delay_ms(20);
}
void p7(){
   PORTB = 0b00000111;
   __delay_ms(20);
}
void p8(){
   PORTB = 0b01111111;
   __delay_ms(20);
}
void p9(){
   PORTB = 0b01100111;
   __delay_ms(20);
}

display_1(int i){
        IO_RA0_SetLow();
        IO_RA1_SetHigh();
        switch(i){
            case 0: 
                p0();
                __delay_ms(30);
                break;
            case 1: 
                p1();
                __delay_ms(30);
                break;
            case 2: 
                p2();
                __delay_ms(30);
                break;
            case 3: 
                p3();
                __delay_ms(30);
                break;
            case 4: 
                p4();
                __delay_ms(30);
                break;
            case 5: 
                p5();
                __delay_ms(30);
                break;
            case 6: 
                p6();
                __delay_ms(30);
                break;
            case 7: 
                p7();
                __delay_ms(30);
                break;
            case 8: 
                p8();
                __delay_ms(30);
                break;
            case 9: 
                p9();
                __delay_ms(30);
                    
        }
}
    

display_2(int l){
    IO_RA0_SetHigh();
    IO_RA1_SetLow();
        switch(l){
            case 0: 
                p0();
                __delay_ms(30);
                break;
            case 1: 
                p1();
                __delay_ms(30);
                break;
            case 2: 
                p2();
                __delay_ms(30);
                break;
            case 3: 
                p3();
                __delay_ms(30);
                break;
            case 4: 
                p4();
                __delay_ms(30);
                break;
            case 5: 
                p5();
                __delay_ms(30);
                break;
            case 6: 
                p6();
                __delay_ms(30);
                break;
            case 7: 
                p7();
                __delay_ms(30);
                break;
            case 8: 
                p8();
                __delay_ms(30);
                break;
            case 9: 
                p9();
                __delay_ms(30);
                    
        }
}