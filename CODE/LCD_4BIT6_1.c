#include <mega128.h>
#include <delay.h>
#asm
.equ __lcd_port = 0x12 ; // PORTD
#endasm
#include <lcd.h>
typedef unsigned char han;
han font_0st[8]= {0x1d,0x05,0x19,0x00,0x1f,0x11,0x1f,0x00};
han font_0nd[8]= {0x1d,0x0b,0x15,0x0b,0x00,0x1f,0x01,0x00};
han font_0rd[8]= {0x1d,0x09,0x15,0x15,0x00,0x10,0x1f,0x00};
han font_1st[8]= {0x09,0x15,0x09,0x00,0x10,0x10,0x1f,0x00};
han font_1nd[8]= {0x02,0x1e,0x16,0x17,0x16,0x1e,0x02,0x00};
han font_1rd[8]= {0x1f,0x01,0x01,0x05,0x04,0x04,0x1f,0x00};
void han_input(han *ch, han add) {
    han i, a;
    a = (add << 3) | 0x40;
    for (i = 0; i < 8; i++) lcd_write_byte(a++,*ch++);
}
void main(void) {
    unsigned char i;
    DDRD = 0xff;
    lcd_init(16);
    lcd_clear();
    han_input(font_0st,0);
    han_input(font_0nd,1);
    han_input(font_0rd,2);
    han_input(font_1st,4);
    han_input(font_1nd,5);
    han_input(font_1rd,6);
    lcd_gotoxy(8,0);
    lcd_putchar(0);
    lcd_putchar(1);
    lcd_putchar(2);
    lcd_gotoxy(8,1);
    lcd_putchar(4);
    lcd_putchar(5);
    lcd_putchar(6);
    for(i=0;i<11;i++) {
            _lcd_ready();
            _lcd_write_data(0x1c);
            delay_ms(300);
    }
    while(1) {
        for(i=0;i<19;i++) {
            _lcd_ready();
            _lcd_write_data(0x18);
            delay_ms(300);
        }
        for(i=0;i<19;i++) {
            _lcd_ready();
            _lcd_write_data(0x1c);
            delay_ms(300);
        }
    }
}