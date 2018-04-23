//041217:13:01

#include <mega128.h>
#include <delay.h>
#define FND PORTB   //FND
#define LED PORTC   //LEDs
char seg_part[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int num = 0;
int count(int);
 void main() {
    unsigned char key;
    DDRB = 0xff;
    DDRE = 0;
    DDRF = 0xf0;
    while(1) {
        if (num > 9999) {
            num = 0;
        }
        else if (num < 0) {
            num = 0;
        }
        key= PINE & 0Xf0;
        switch(key) { 
            case 0b11100000: 
            num++;
            break;
            case 0b11010000: 
            num++;
            break;
            case 0b10110000: 
            --num;
            break;
            case 0b01110000: 
            --num;
            break;
            default: break; 
        }
        num = count(num);
    }
 }
 int count(int count) {
    unsigned char i,st,nd,rd,th;
    th = (count/1000)%10;
    rd = (count/100)%10;
    nd = (count/10)%10;
    st = count%10;
    for( i = 0; i< 10; i++) { 
        PORTF = 0B11100000; 
        FND = seg_part[th]; 
        delay_ms(25);
        PORTF = 0B11110000;
        PORTF = 0B11010000; 
        FND = seg_part[rd]; 
        delay_ms(25);
        PORTF = 0B11110000;
        PORTF = 0B10110000; 
        FND = seg_part[nd]; 
        delay_ms(25);
        PORTF = 0B11110000;
        PORTF = 0B01110000; 
        FND = seg_part[st]; 
        delay_ms(25);
        PORTF = 0B11110000;
    }
    return count;
}
        
        
    