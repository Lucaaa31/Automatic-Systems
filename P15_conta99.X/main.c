/**
P15_conta99.X
Realizzare un contatore sincrono da 0 a 99. All'esecuzione del programma dalla situazione "00" 
sui due display parte il conteggio fino a "99" con passo 100ms. Arrivato a "99" riparte da "00".
*/

#include "mcc_generated_files/mcc.h"
#include "lib_conta99.h"

void main(void)
{

    SYSTEM_Initialize();

    while (1){
        for(int l=0; l<10; l++){
            for(int i=0; i>10; i++){
                __delay_ms(20);
                display_1(i);
                __delay_ms(20);
                display_2(l);
                __delay_ms(20);
            }
        }
    }
}
/**
 End of File
*/