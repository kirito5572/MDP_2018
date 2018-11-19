#include <mega128.h>
#include <delay.h>
#asm
    .equ __lcd_port = 0x12 ; // PORTD
#endasm
#include <lcd.h>
typedef unsigned char chr;
void main() {
    DDRD = 0xff;
    DDRA = 0xff;
    PORTA.0 = 1;
    lcd_init(16);
    delay_ms(5);
    lcd_clear();
    delay_ms(5);
    lcd_gotoxy(5,0);
    delay_ms(5);
    lcd_puts("Serial");
}