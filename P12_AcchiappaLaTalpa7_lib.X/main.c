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
/* Appena questo programma viene caricato viene acceso il segmento a del display PORTB
 * e a seconda di quante volte premo il secondo pulsante il segmento si sposta di una 
 * posizione in senso antiorario, dopo aver deciso da quale segmento far partire il ciclo,
 * premendo il terzo pulsante parte un ciclo che gira in senso antiorario a partire dal 
 * segmento selezionato, i segmenti si accendono e spengono nella sequenza sopra indicata 
 * se vengono premuti il primo  il ciclo diventa in senso orario a partire da segmento scelto in partenza
 * se vengono premuti tutti e tre i pulsanti il ciclo velocizza fino a che non rimangono tutti accesi,
 * posso premere massimo 10 volte poi il ciclo di ferma e rimangono accesi tutti i esterni segmneti se premo un 
 * undicesima volta oppure se supero i 600 giri ricomincia alla velocità iniziale 
*/

/*L'unica differenza fra AcchiappaLaTalpa7 e AcchiappaLaTalpa5 è che premendo tutti e tre i
 *pulsanti in questo programma posso velocizzare il giro del segmento e il ciclo di partenza è opposto 
 * Sono presenti anche 2 librerie: lib_talpa.c e lib_talpa.h
 */




#include "mcc_generated_files/mcc.h"
#include "lib_talpa.h"

void main(void)
{
    while(1){
        
    // initialize the device
    SYSTEM_Initialize();
    x=600;       //modificare il numero di giri dopo cui viene resettata la velocità normale     
    if(F1==0)
    {
        if(IO_RA3_PORT==1)  //se premo il pulsante 1
        {
            i=i+1;  //incremento i di 1
            F1=1;  //pongo la variabile F1 uguale a 1 necessario per antirimbalzo
        }   
    }
    if(IO_RA3_PORT==0)  //necessario per antirimbalzo
    {
        F1=0;  //pongo la variabile F1 uguale a 0 necessario per antirimbalzo
    }
    if(i==10) //sei=10
    {
        i=0;  //se i=10 lo rimetto uguale a 0
    }
    if(i==9)  //se i=9
    {
        IO_RA0_PORT = 0;                //disabilito il display dei secondi (RA0)
        IO_RA1_PORT = 1;				//abilito il display dei decimi (RA1)
        PORTB = 0b00000001;             //attivo il segmento a del display dei decimi(RA1)
    }
    if(i==8)  //se i=8
    {
        IO_RA0_PORT = 1;                //abilito il display dei secondi (RA0)
        PORTB = 0b00000001;				//attivo il segmento a del display dei secondi(RA0)
    }
    if(i==7)  //se i=7
    {
        IO_RA0_PORT = 1;				//abilito il display dei secondi (RA0)
        PORTB = 0b00100000;				//attivo il segmento f del display dei secondi(RA0)
    }
    if(i==6)  //se i=6
    {
        IO_RA0_PORT = 1;                //abilito il display dei secondi (RA0)
        PORTB = 0b00010000;				//attivo il segmento e del display dei secondi(RA0)
    }
    if(i==5)  //se i=5
    {
        IO_RA1_PORT = 0;                //disabilito il display dei decimi (RA1)
        IO_RA0_PORT = 1;				//abilito il display dei secondi (RA0)
        PORTB = 0b00001000;             //attivo il segmento d del display dei secondi(RA0)
    }
    if(i==4)  //se i=4
    {
        IO_RA1_PORT = 1;                //abilito il display dei decimi (RA1)
        PORTB = 0b00001000;				//attivo il segmento d del display dei decimi(RA1)
    }
    if(i==3)  //se i=3
    {
        PORTB = 0b00001000;		//attivo il segmento d del display PORTB
    }
    if(i==2)  //se i=2
    {
        PORTB = 0b00000100;		//attivo il segmento c del display PORTB
    }
    if(i==1)  //se i=1
    {
        PORTB = 0b00000010;		//attivo il segmento b del display PORTB
    }
    if(i==0)  //se i=0
    {
        PORTB = 0b00000001;		//attivo il segmento a del display PORTB
    }
    if(IO_RA4_PORT==1)  //se premo il pulsante 3
    {
        b=1;  //setto b a 1
    }
    while(b==1)  //se b=1 inizio un  ciclo infinito
    {
            if(i==0)  //se i=0
            {
                if(a==0)  //se a=0
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p0();  //accendo in sequenza i display compiendo un intero
                    p1();  //giro che ha come origine il segmento a 
                    p2();  //del display PORTB
                    p3();
                    p4();
                    p5();
                    p6();
                    p7();
                    p8();
                    p9();
                    p0();
                }
                if(a==1)  //se a=1
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p0();  //inverto il senso del giro
                    p9();
                    p8();
                    p7();
                    p6();
                    p5();
                    p4();
                    p3();
                    p2();
                    p1();
                    p0();
                }
            }
            if(i==1)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                       
                    }
                    
                    p1();  //accendo in sequenza i display compiendo un intero
                    p2();  //giro che ha come origine il segmento b
                    p3();  //del display PORTB
                    p4();
                    p5();
                    p6();
                    p7();
                    p8();
                    p9();
                    p0();
                    p1();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p1();  //inverto il senso del giro
                    p0();
                    p9();
                    p8();
                    p7();
                    p6();
                    p5();
                    p4();
                    p3();
                    p2();
                    p1();
                }
            }
            if(i==2)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p2();  //accendo in sequenza i display compiendo un intero
                    p3();  //giro che ha come origine il segmento c
                    p4();  //del display PORTB
                    p5();
                    p6();
                    p7();
                    p8();
                    p9();
                    p0();
                    p1();
                    p2();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p2();  //inverto il senso del giro
                    p1();
                    p0();
                    p9();
                    p8();
                    p7();
                    p6();
                    p5();
                    p4();
                    p3();
                    p2();
                    
                }
            }
            if(i==3)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p3();  //accendo in sequenza i display compiendo un intero
                    p4();  //giro che ha come origine il segmento d 
                    p5();  //del display PORTB
                    p6();
                    p7();
                    p8();
                    p9();
                    p0();
                    p1();
                    p2();
                    p3();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p3();  //inverto il senso del giro
                    p2();
                    p1();
                    p0();
                    p9();
                    p8();
                    p7();
                    p6();
                    p5();
                    p4();
                    p3();
                }
            }
            if(i==4)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p4();  //accendo in sequenza i display compiendo un intero
                    p5();  //giro che ha come origine il segmento d
                    p6();  //del display dei decimi (RA1)
                    p7();
                    p8();
                    p9();
                    p0();
                    p1();
                    p2();
                    p3();
                    p4();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p4();  //inverto il senso del giro
                    p3();
                    p2();
                    p1();
                    p0();
                    p9();
                    p8();
                    p7();
                    p6();
                    p5();
                    p4();
                }
            }
            if(i==5)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p5();  //accendo in sequenza i display compiendo un intero
                    p6();  //giro che ha come origine il segmento d
                    p7();  //del display dei secondi (RA0)
                    p8();
                    p9();
                    p0();
                    p1();
                    p2();
                    p3();
                    p4();
                    p5();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p5();  //inverto il senso del giro
                    p4();
                    p3();
                    p2();
                    p1();
                    p0();
                    p9();
                    p8();
                    p7();
                    p6();
                    p5();
                }
            }
            if(i==6)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                       
                    }
                    
                    p6();  //accendo in sequenza i display compiendo un intero
                    p7();  //giro che ha come origine il segmento e
                    p8();  //del display dei secondi (RA0)
                    p9();
                    p0();
                    p1();
                    p2();
                    p3();
                    p4();
                    p5();
                    p6();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p6();  //inverto il senso del giro
                    p5();
                    p4();
                    p3();
                    p2();
                    p1();
                    p0();
                    p9();
                    p8();
                    p7();
                    p6();
                }
            }
            if(i==7)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p7();  //accendo in sequenza i display compiendo un intero
                    p8();  //giro che ha come origine il segmento e
                    p9();  //del display dei secondi (RA0)
                    p0();
                    p1();
                    p2();
                    p3();
                    p4();
                    p5();
                    p6();
                    p7();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p7();  //inverto il senso del giro
                    p6();
                    p5();
                    p4();
                    p3();
                    p2();
                    p1();
                    p0();
                    p9();
                    p8();
                    p7();
                }
            }
            if(i==8)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p8();  //accendo in sequenza i display compiendo un intero
                    p9();  //giro che ha come origine il segmento a
                    p0();  //del display dei secondi (RA0)
                    p1();
                    p2();
                    p3();
                    p4();
                    p5();
                    p6();
                    p7();
                    p8();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p8();  //inverto il senso del giro
                    p7();
                    p6();
                    p5();
                    p4();
                    p3();
                    p2();
                    p1();
                    p0();
                    p9();
                    p8();
                }
            }
            if(i==9)
            {
                if(a==0)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                    }
                    
                    p9();  //accendo in sequenza i display compiendo un intero
                    p0();  //giro che ha come origine il segmento a
                    p1();  //del display dei decimi (RA1)
                    p2();
                    p3();
                    p4();
                    p5();
                    p6();
                    p7();
                    p8();
                    p9();
                }
                if(a==1)
                {
                    conta = conta + 1;      //la variabile conta tiene in memoria il numero di giri
                    if (conta==x)           //se il numero di giri corrisponde a x
                    {
                        conta=0;            //si resetta conta
                        g=0;                //si resetta la velocià normale
                        
                    }
                    
                    p9();  //inverto il senso del giro
                    p8();
                    p7();
                    p6();
                    p5();
                    p4();
                    p3();
                    p2();
                    p1();
                    p0();
                    p9();
                }
            }
            if((IO_RA2_PORT == 1)&&(IO_RA3_PORT == 0)&&(IO_RA4_PORT == 0))  //se premo il pulsante 1
            {
                a=!a;  //nego a permettendomi di invertire il senso del giro
            }
    }
    }   
}




