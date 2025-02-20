#include "mcc_generated_files/mcc.h"
#include "lib_talpa.h"

void velocizza ()
{
    if ((IO_RA2_PORT == 0)&&(IO_RA3_PORT == 0)&&(IO_RA4_PORT == 0))     //se i pulsanti non sono premuti
    {
        z=1;                                                            //z viene impostata ad 1
    }
    if (z==1)                                                           //permettendo la lettura dei 3 pulsanti premuti contemporaneamente
    {                                                                   //viene usato per prevenire che g aumenti continuando a tenere premuti i pulsanti contemporaneamente
        if ((IO_RA2_PORT == 1)&&(IO_RA3_PORT == 1)&&(IO_RA4_PORT == 1))
        {
            g=g+1;                                                      //g viene aumentata ogni volta che vengono premuti i pulsanti contemporaneamente
            z=0;                                                        //per impedire che rientri subito dopo e incrementi la velocità
        
        }
    }
    if (g>10)
    {
        g=10;                                                            //il valore massimo di g è 10
    }
    if (g==0)
    {
        __delay_ms(200);                                                //quando g vale 0 aspetta 200 ms
    }
    if (g==1)
    {
        __delay_ms(200);                                                //quando premo una sola volta tutti i pulsanti (g vale 1) aspetta 200 ms per non aumentare la velocità 
    }
    if (g==2)
    {
        __delay_ms(100);                                                 //quando premo 2 volte di fila i pulsanti (g vale 2) il tempo d'attesa è 100 ms 
    }
    if (g==3)
    {
        __delay_ms(65);                                                 //quando premo 3 volte di fila i pulsanti (g vale 3) il tempo d'attesa è 65 ms
    }
    if (g==4)
    {
        __delay_ms(50);                                                 //quando premo 4 volte di fila i pulsanti (g vale 4) il tempo d'attesa è 50 ms 
    }
    if (g==5)
    {
        __delay_ms(40);                                                 //quando premo 5 volte di fila i pulsanti (g vale 5) il tempo d'attesa è 40ms
    }
    if (g==6)
    {
        __delay_ms(30);                                                 //quando premo 6 volte di fila i pulsanti (g vale 6) il tempo d'attesa è 30ms
    }
    if (g==7)
    {
        __delay_ms(25);                                                 //quando premo 7 volte di fila i pulsanti (g vale 7) il tempo d'attesa è 25ms
    }
    if (g==8)
    {
        __delay_ms(20);                                                 //quando premo 8 volte di fila i pulsanti (g vale 8) il tempo d'attesa è 20ms
    }
    if (g==9)
    {
        __delay_ms(10);                                                 //quando premo 9 volte di fila i pulsanti (g vale 9) il tempo d'attesa è 10ms
    }
    if (g==10)
    {                                                                   //quando premo 10 volte di fila i pulsanti (g vale 10) il tempo d'attesa è 0ms (tutti i segmenti sono accesi)
        if (conta>=100)
        {
            if (z==1)
            {
                if ((IO_RA2_PORT == 1)&&(IO_RA3_PORT == 1)&&(IO_RA4_PORT == 1))
                {
                    g=0;                                                        //se il conteggio dei giri ha superato i 100 è possibile riportare la velocità normale premendo tutti i pulsanti contemporaneamente
                    z=0;
                }
            }
        }
    }
}

void p0()
{
    PORTB = 0b00000001;		//attivo il segmento a del display PORTB
    velocizza ();           //entra nella funzione velocizza per leggere il delay
}
void p1()
{
    PORTB = 0b00000010;		//attivo il segmento b del display PORTB
    velocizza ();           //entra nella funzione velocizza per leggere il delay
}

void p2()
{
    PORTB = 0b00000100; 	//attivo il segmento c del display PORTB
    velocizza ();           //entra nella funzione velocizza per leggere il delay
}

void p3()
{
    PORTB = 0b00001000;		//attivo il segmento d del display PORTB
    velocizza ();           //entra nella funzione velocizza per leggere il delay
}

void p4()
{
    IO_RA1_PORT = 1;			//abilito il display dei decimi(RA1)
    PORTB = 0b00001000;		//attivo il segmento d del display dei decimi(RA1)
    velocizza ();           //entra nella funzione velocizza per leggere il delay
    IO_RA1_PORT = 0;			//disabilito il display dei decimi (RA1)
}

void p5()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00001000;		//attivo il segmento d del display dei secondi(RA0)
    velocizza ();           //entra nella funzione velocizza per leggere il delay
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p6()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00010000;		//attivo il segmento e del display dei secondi(RA0)
    velocizza ();           //entra nella funzione velocizza per leggere il delay
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p7()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00100000;		//attivo il segmento f del display dei secondi(RA0)
    velocizza ();           //entra nella funzione velocizza per leggere il delay
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p8()
{
    IO_RA0_PORT = 1;			//abilito il display dei secondi (RA0)
    PORTB = 0b00000001;		//attivo il segmento a del display dei secondi(RA0)
    velocizza ();           //entra nella funzione velocizza per leggere il delay
    IO_RA0_PORT = 0;			//disabilito il display dei secondi (RA0)
}

void p9()
{
    IO_RA1_PORT = 1;			//abilito il display dei decimi (RA1)
    PORTB = 0b00000001;		//attivo il segmento d del display dei decimi(RA1)
    velocizza ();           //entra nella funzione velocizza per leggere il delay
    IO_RA1_PORT = 0;			//disabilito il display dei decimi (RA1)
}