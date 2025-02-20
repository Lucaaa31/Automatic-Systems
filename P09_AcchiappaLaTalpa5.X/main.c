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
 * premendo il terzo pulsante parte un ciclo che gira in senso orario a partire dal 
 * segmento selezionato, i segmenti si accendono e spengono nella sequenza sopra indicata 
 * se vengono premuti il primo e il terzo pulsante contemporaneamente il ciclo diventa
 * in senso antiorario a partire da segmento scelto in partenza
*/

/*Le differenze tra AcchiappaLaTalpa5 e AcchiappaLaTalpa4 sono che puoi decidere da quale segmento 
 *far partire il ciclo, il cambio di direzione avviene nel segmento di partenza premendo il primo 
 *e il terzo pulsante,non c'è la possibilità di fermare il ciclo su di un segmento per un 
 *determinato tempo */


#include "mcc_generated_files/mcc.h"
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
//inizializzo variabili
char i=0;
char b,F1=0;
char a;

void main(void)
{
    while(1){
    // initialize the device
    SYSTEM_Initialize();
    if(F1==0)
    {
        if(IO_RA3_PORT==1)  //se premo il pulsante 1
        {
            i=i+1;  //incremento i
            F1=1;  //necessario per antirimbalzo
        }   
    }
    if(IO_RA3_PORT==0)  //necessario per antirimbalzo
    {
        F1=0;  //necessario per antirimbalzo
    }
    if(i==10)
    {
        i=0;  //se i=10 torna a 0
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
        PORTB = 0b00100000;				//attivo il segmento f del display dei secondi (RA0)
    }
    if(i==6)  //se i=6
    {
        IO_RA0_PORT = 1;                //abilito il display dei secondi (RA0)
        PORTB = 0b00010000;				//attivo il segmento e del display dei secondi (RA0)
    }
    if(i==5)  //se i=5
    {
        IO_RA1_PORT = 0;                //disabilito il display dei decimi (RA1)
        IO_RA0_PORT = 1;				//abilito il display dei secondi (RA0)
        PORTB = 0b00001000;             //attivo il segmento d del display dei secondi (RA0)
    }
    if(i==4)  //se i=4
    {
        IO_RA1_PORT = 1;                //abilito il display dei decimi (RA1)
        PORTB = 0b00001000;				//attivo il segmento d del display dei decimi (RA1)
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
                    p0();  //accendo in sequenza i display compiendo un intero
                    p1();  //giro che ha come origine il segmento a del
                    p2();  //display PORTB
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
                    p1();  //accendo in sequenza i display compiendo un intero
                    p2();  //giro che ha come origine il segmento b del
                    p3();  //display PORTB
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
                    p2();  //accendo in sequenza i display compiendo un intero
                    p3();  //giro che ha come origine il segmento c del
                    p4();  //display PORTB
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
                    p3();  //accendo in sequenza i display compiendo un intero
                    p4();  //giro che ha come origine il segmento d del
                    p5();  //display PORTB
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
                    p4();  //accendo in sequenza i display compiendo un intero
                    p5();  //giro che ha come origine il segmento d del
                    p6();  //display dei decimi (RA1)
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
                    p5();  //accendo in sequenza i display compiendo un intero
                    p6();  //giro che ha come origine il segmento d del
                    p7();  //display dei secondi(RA0)
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
                    p6();  //accendo in sequenza i display compiendo un intero
                    p7();  //giro che ha come origine il segmento e del
                    p8();  //display dei secondi(RA0)
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
                    p7();  //accendo in sequenza i display compiendo un intero
                    p8();  //giro che ha come origine il segmento f del
                    p9();  //display dei secondi(RA0)
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
                    p8();  //accendo in sequenza i display compiendo un intero
                    p9();  //giro che ha come origine il segmento a del
                    p0();  //display dei secondi(RA0)
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
                    p9();  //accendo in sequenza i display compiendo un intero
                    p0();  //giro che ha come origine il segmento a del
                    p1();  //display dei decimi (RA1)
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
            if(IO_RA2_PORT == 1)  //se premo il pulsante 1
            {
                a=!a;  //nego a permettendomi di invertire il senso del giro
            }
    }
    }   
}

void p0()
{
    PORTB = 0b00000001;		//attivo il segmento "a" del display PORTB
    __delay_ms(100);			//attivo ritardo di 100ms
}

void p1()
{
    PORTB = 0b00000010;		//attivo il segmento "b" del display PORTB
    __delay_ms(100);			//attivo ritardo di 100ms
}

void p2()
{
    PORTB = 0b00000100; 	//attivo il segmento "c" del display PORTB
    __delay_ms(100);			//attivo ritardo di 100ms
}

void p3()
{
    PORTB = 0b00001000;		//attivo il segmento "d" del display PORTB
    __delay_ms(100);			//attivo ritardo di 100ms
}

void p4()
{
    IO_RA1_PORT = 1;			//abilito il display dei decimi(RA1)
    PORTB = 0b00001000;		//attivo il segmento "d" del display dei decimi
    __delay_ms(100);			//attivo ritardo
    IO_RA1_PORT = 0;			//disabilito il display dei decimi (RA1)
}

void p5()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00001000;		//attivo il segmento "d" del display dei secondi
    __delay_ms(100);        	//attivo ritardo
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p6()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00010000;		//attivo il segmento "e" del display dei secondi
    __delay_ms(100);        	//attivo ritardo
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p7()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00100000;		//attivo il segmento "f" del display dei secondi
    __delay_ms(100);        	//attivo ritardo
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p8()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00000001;		//attivo il segmento "a" del display dei secondi
    __delay_ms(100);        	//attivo ritardo
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p9()
{
    IO_RA1_PORT = 1;			//abilito il display dei decimi (RA1)
    PORTB = 0b00000001;		//attivo il segmento "a" del display dei decimi
    __delay_ms(100);        	//attivo ritardo
    IO_RA1_PORT = 0;			//disabilito il display dei decimi (RA1)
}