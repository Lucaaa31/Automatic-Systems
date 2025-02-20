/*
 * In questa librerie sono riportate le 3 funzioni precedentemente dichiarate in my_lib_giochi.h
 */
#include "mcc_generated_files/mcc.h"
#include "my_lib_giochi.h"
#define Display PORTB



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
