//0410 17:00:23

#include <mega128.h>
#include <delay.h>
#define FND PORTB
#define LED PORTC
 void main() {
    char num[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    unsigned char i , down = 99;
    DDRF = 0xf0;
    DDRB = 0xff;
    DDRC = 0xff;
    FND = 0x00;
    LED = 0xff;
    while(1) {
        for(;down != 0; down--) {
            PORTF = 0b10110000;
            FND = num[(down/10)%10];
            delay_ms(20);
            PORTF = 0b11110000;
            PORTF = 0b01110000;
            FND = num[down%10];
            delay_ms(20);
            PORTF = 0b11110000;
        }
        for(i = 0; i <6; i++) {
            LED = 0xff;
            delay_ms(300);
            LED = 0x00;
            delay_ms(300);
        }
        down = 99;
    }
 }