/*
 * LCD1.c
 *
 * Created: 2018-06-21 ¿ÀÈÄ 6:56:29
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define LINE1 0x80;
#define LINE2 0xc0;
#define CMD_WRITE 0xfe;
#define DATA_WRITE 0xff;
#define LCD_EN 0x02;
void LCD_cmd_write(char cmd) {
    PORTG = CMD_WRITE;
    PORTD = cmd;
    PORTG = PORTG^LCD_EN;
    delay_ms(2);
}
void LCD_data_write(char data) {
    PORTG = DATA_WRITE;
    PORTD = data;
    PORTG = PORTG^LCD_EN;
    delay_ms(2);
}
void init_LCD(void) {
    delay_ms(15);
    LCD_data_write(0x38);
    delay_ms(5);
    LCD_data_write(0x38);
    delay_us(100);
    LCD_data_write(0x38);
    LCD_data_write(0x08);
    LCD_data_write(0x01);
    LCD_data_write(0x06);
    LCD_data_write(0x0c);
}
void init_SYSTEM(void) {
    DDRG = 0x03;
    DDRD = 0xff;
    PORTD = 0xff;
    PORTG = 0xff;
}
void main(void) {
    init_SYSTEM();
    init_LCD();
    LCD_cmd_write(0x80);
    LCD_data_write('-');
    LCD_data_write('A');
    LCD_data_write('T');
    LCD_data_write('M');
    LCD_data_write('E');
    LCD_data_write('G');
    LCD_data_write('A');
    LCD_data_write('1');
    LCD_data_write('2');
    LCD_data_write('8');
    LCD_data_write(' ');
    LCD_data_write('T');
    LCD_data_write('E');
    LCD_data_write('S');
    LCD_data_write('T');
    LCD_data_write('-');
    LCD_cmd_write(0xc0);
    LCD_data_write('!');
    LCD_data_write('@');
    LCD_data_write('#');
    LCD_data_write('$');
    LCD_data_write('%');
    LCD_data_write('^');
    LCD_data_write('&');
    LCD_data_write('*');
    LCD_data_write('(');
    LCD_data_write(')');
    LCD_data_write('<');
    LCD_data_write('>');
    LCD_data_write('{');
    LCD_data_write('}');
    LCD_data_write('-');
    LCD_data_write('+');
}

