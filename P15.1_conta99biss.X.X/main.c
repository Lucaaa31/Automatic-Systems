/**
P15.1_conta99bis.X
Realizzare un contatore sincrono da 0 a 99. All'esecuzione del programma dalla situazione "00" 
sui due display parte il conteggio fino a "99" con passo 100ms. Arrivato a "99" riparte da "00". 
S1 è il pulsante di start e S2 è il pulsante di stop e S3 è il RESET.
*/

#include "mcc_generated_files/mcc.h"
#include "lib_conta99bis.h"

void main(void)
{

    SYSTEM_Initialize();

    while (1){
        if(IO_RA2_PORT == 1){
            c=0;
            do{
            for(int i=0; i<10; i++){
            for(int l=0; l<10; l++){
                display_1(l);
                display_2(i);
                __delay_ms(20);
                if(IO_RA3_PORT == 1){
                    do{
                    display_1(l);
                    display_2(i);
                    c=1;
                    __delay_ms(20);
                    if(IO_RA2_PORT == 1){
                        c = 2;
                    }
                    }while(c == 1);
                }
                if(IO_RA4_PORT == 1){
                    i = 0;
                    l = -1;
                }
        } 
            }
    }while(1);
    
    }
 }   
}
/**
 End of File
*/