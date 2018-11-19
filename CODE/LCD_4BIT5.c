#include <mega128.h>
// Alphanumeric LCD functions
#asm
.equ __lcd_port = 0x12 ; // PORTD
#endasm
#include <lcd.h>
// Declare your global variables here
#include <delay.h>
void main(void) {
    unsigned char i = 0;
    DDRD = 0xff;
    DDRE = 0xff;
    lcd_init(16);
    lcd_gotoxy(0,0);
    lcd_puts("Kim Hyeokjin");
    while(1) {
        for(i = 0;i < 8; i++) {
            _lcd_ready();
            _lcd_write_data(0x1c); // 오른쪽으로 문자 이동
            delay_ms(300);
        }
        for(i = 0;i < 8; i++) {
            _lcd_ready();
            _lcd_write_data(0x18); // 왼쪽으로 문자 이동
            delay_ms(300);
    }
}
}