/* 
 * File:   LCD2004a.h
 * Author: Lumen Paolo
 * Modificata il 22.3.2022
 * 
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

//#define _XTAL_FREQ            32000000 //impostazione NON necessaria fatta da Code Configurator
//#define I2C_BaudRate          100000 // uguale a I2C Clock Frequency(Hz)in Code Configurator
#define LCD_BACKLIGHT         0x08
#define LCD_NOBACKLIGHT       0x00
#define LCD_FIRST_ROW         0x80
#define LCD_SECOND_ROW        0xC0
#define LCD_THIRD_ROW         0x94
#define LCD_FOURTH_ROW        0xD4
#define LCD_CLEAR             0x01
#define LCD_RETURN_HOME       0x02
#define LCD_ENTRY_MODE_SET    0x04
#define LCD_CURSOR_OFF        0x0C
#define LCD_UNDERLINE_ON      0x0E
#define LCD_BLINK_CURSOR_ON   0x0F
#define LCD_MOVE_CURSOR_LEFT  0x10
#define LCD_MOVE_CURSOR_RIGHT 0x14
#define LCD_TURN_ON           0x0C
#define LCD_TURN_OFF          0x08
#define LCD_SHIFT_LEFT        0x18
#define LCD_SHIFT_RIGHT       0x1E
#define LCD_TYPE              2 // 0 -> 5x7 | 1 -> 5x10 | 2 -> 2 lines

#define LCD_En                0b00000100  // Enable bit
#define LDC_Rw                0b00000010  // Read/Write bit

void LCD_Init(unsigned char I2C_Add);
void IO_Expander_Write(unsigned char Data);
void IO_pulseEnable(unsigned char Data);
void LCD_Write_4Bit(unsigned char Nibble);
void LCD_CMD(unsigned char CMD);
void LCD_Set_Cursor(unsigned char ROW, unsigned char COL);
void LCD_Write_Char(char);
void LCD_Write_String(char*);
void Backlight();
void noBacklight();
void LCD_SR();
void LCD_SL();
void LCD_Clear();
void LCD_TypeWriter(char*,int);
void LCD_Scroll(char*,int,unsigned char);
void LCD_Scroll2(char*, int, unsigned char, unsigned char);
