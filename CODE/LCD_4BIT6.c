#include <mega128.h>
#include <delay.h>
#asm
.equ __lcd_port = 0x12 ; // PORTD
#endasm
#include <lcd.h>
typedef unsigned char han;
han font_st[8]= {0x1d,0x05,0x19,0x00,0x1f,0x11,0x1f,0x00};
han font_nd[8]= {0x1d,0x0b,0x15,0x0b,0x00,0x1f,0x01,0x00};
han font_rd[8]= {0x1d,0x09,0x15,0x15,0x00,0x10,0x1f,0x00};
void han_input(han *ch, han add) {
    han i, a;
    a = (add << 3) | 0x40;
    for (i = 0; i < 8; i++) lcd_write_byte(a++,*ch++);
}
void main(void) {
    DDRD = 0xff;
    lcd_init(16);
    lcd_clear();
    han_input(font_st,0);
    han_input(font_nd,1);
    han_input(font_rd,2);
    lcd_gotoxy(5,0);
    lcd_putchar(0);
    lcd_putchar(1);
    lcd_putchar(2);

}