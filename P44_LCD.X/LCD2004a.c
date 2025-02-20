
/*

Modificata il 22.3.2022

*/
#include "LCD2004a.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
//per usare 2 X LCD2004a aggiungere ../i2c2_master_example.h..
#include <xc.h>

unsigned char RS, i2c_add, BackLight_State = LCD_BACKLIGHT;

void LCD_Init(unsigned char I2C_Add)
{
  i2c_add = I2C_Add;
  __delay_ms(50);
  IO_Expander_Write(LCD_NOBACKLIGHT);
  __delay_ms(99); // era 1000
  
  RS = 0; // Command Register Select
  LCD_Write_4Bit(0x03 << 4);
  __delay_us(4500);
  
   LCD_Write_4Bit(0x03 << 4);
  __delay_us(4500);
  
   LCD_Write_4Bit(0x03 << 4);
  __delay_us(150);
  
   LCD_Write_4Bit(0x02 << 4);
  __delay_us(150);

  LCD_CMD(LCD_RETURN_HOME);
  __delay_ms(5);
  LCD_CMD(0x20 | (LCD_TYPE << 2));
  __delay_ms(50);
  LCD_CMD(LCD_TURN_ON);
  __delay_ms(50);
  LCD_CMD(LCD_CLEAR);
  __delay_ms(50);
  LCD_CMD(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
  __delay_ms(50);
}

void IO_Expander_Write(unsigned char Data)
{
  uint8_t dt[1];
  dt[0]=Data | BackLight_State;
  I2C1_WriteNBytes(i2c_add, &dt, 1);
  
}

void IO_pulseEnable(unsigned char Data){
	IO_Expander_Write(Data | LCD_En);	// En high
	__delay_us(1);
	IO_Expander_Write(Data | ~LCD_En);	// En high
	__delay_us(50);		// commands need > 37us to settle
} 

void LCD_Write_4Bit(unsigned char Data)
{
  // Get The RS Value To LSB OF Data
  Data |= RS;
  IO_Expander_Write(Data);
  IO_pulseEnable(Data);
}
void LCD_CMD(unsigned char CMD)
{
  RS = 0; // Command Register Select
  LCD_Write_4Bit(CMD & 0xF0);
  LCD_Write_4Bit((CMD << 4) & 0xF0);
}

void LCD_Write_Char(char Data)
{
  RS = 1; // Data Register Select
  LCD_Write_4Bit(Data & 0xF0);
  LCD_Write_4Bit((Data << 4) & 0xF0);
}
void LCD_Write_String(char* Str)
{
  for(int i=0; Str[i]!='\0'; i++)
    LCD_Write_Char(Str[i]);
}

void LCD_Set_Cursor(unsigned char ROW, unsigned char COL)
{
  switch(ROW) 
  {
    case 2:
      LCD_CMD(0xC0 + COL-1);
      break;
    case 3:
      LCD_CMD(0x94 + COL-1);
      break;
    case 4:
      LCD_CMD(0xD4 + COL-1);
      break;
    // Case 1
    default:
      LCD_CMD(0x80 + COL-1);
  }
}

void Backlight()
{
  BackLight_State = LCD_BACKLIGHT;
  IO_Expander_Write(0);
}
void noBacklight()
{
  BackLight_State = LCD_NOBACKLIGHT;
  IO_Expander_Write(0);
}

void LCD_SL()
{
  LCD_CMD(0x18);
  __delay_us(40);
}
void LCD_SR()
{
  LCD_CMD(0x1C);
  __delay_us(40);
}
void LCD_Clear()
{
  LCD_CMD(0x01);
  __delay_us(40);
}

void LCD_TypeWriter(char* risultato0, int d)
{
    int indx=0;
    for(int i=0; text[i]!='\0'; i++){
        LCD_Write_Char(risultato0[i]);
        for(indx=0; indx<=d; indx++){
            __delay_ms(1);
        }
        indx=0;
    }
}

void LCD_Scroll(char* text, int v, unsigned char r){
    int indx=0;
    unsigned char c=1;
    for(int i=0; i<21;i++){
        LCD_Set_Cursor(r, c);
        LCD_Write_Char(' ');
        c++;
        LCD_Set_Cursor(r, c);
        LCD_Write_String(text);
        for(indx=0; indx<=v; indx++){
            __delay_ms(1);
        }
        indx=0;
    }
}

//LCD Scroll 2 funziona solo su riga 2 e 3
//questa è la funzione scroll, gli dici che cosa scrivere e scrive il testo facendolo avanzare di una colonna
//ogni un tempo definito da te.

//devi inserire 4 valori per farlo funzionare
//1)primo valore da inserire è il testo che si vuole scrivere
//2)secondo valore da inserire è il tempo per ogni scorrimento
//3)terzo valore da inserire è il valore della riga, si seleziona della riga in cui si scrive
//4)quarto valore da inserire è il valore della colonna, si seleziona la colonna in cui si scrive 
void LCD_Scroll2(char* text, int v, unsigned char r, unsigned char c){
//c'è la variavile indice(indx) che serve per la temporizzazione e la variabile x che serve per
//cancellare l'ultima colonna in cui si arriva (altrimenti rimarrebbe accesa)
    int indx=0, x=21-c;
    //for che scrive il testo e lo scorre di colonna in colonna
    for(int i=0; i<x;i++){
        LCD_Set_Cursor(r, c);
        LCD_Write_Char(' ');
        c++;
        LCD_Set_Cursor(r, c);
        LCD_Write_String(text);
        
        //qui c'è la piu grande differenza tra scroll e scroll2, questo è un ciclo che:
        //sovrascrive con un " " tutta la riga successiva, in questo modo si ha che quando il
        //testo viene inviato sulla riga successiva perche il testo oltrepassa la capienza della riga
        //viene immediatamente cancellate senza che rimanga
        for(int i=1;i<21;i++){
			LCD_Set_Cursor(r, i+20);
        	LCD_Write_Char(' ');
		}
		
		//ciclo for in cui si imposta il tempo di attesa tra uno scorrimento all'altro
        for(indx=0; indx<=v; indx++){
            __delay_ms(1);
        }
        indx=0; 
    }

}


