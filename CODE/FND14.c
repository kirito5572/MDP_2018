//0501 17:06:23
#include <mega128.h>
#include <delay.h>
#define FND PORTB   //FND
#define LED PORTC   //LEDs
char seg_part[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned short num = 0;
void count(int);
void main() {
    DDRB = 0xff;
    DDRE = 0;
    DDRF = 0xf0;
    while(1) {
        num++;
        count(num);
        if(num == 720) {
            num = 0;
        }
    }
}
 void count(int count) {
    unsigned char i,min_st,min_nd,hour_st,hour_nd;
    hour_nd = (count/600)%2;
    hour_st = (count/60)%10;
    min_nd = (count/10)%6;
    min_st = count%10;
    for( i = 0; i< 2; i++) { 
        PORTF = 0B11100000; 
        FND = seg_part[hour_nd]; 
        delay_ms(10);
        PORTF = 0B11110000;
        PORTF = 0B11010000; 
        FND = seg_part[hour_st]; 
        delay_ms(10);
        PORTF = 0B11110000;
        PORTF = 0B10110000; 
        FND = seg_part[min_nd]; 
        delay_ms(10);
        PORTF = 0B11110000;
        PORTF = 0B01110000; 
        FND = seg_part[min_st]; 
        delay_ms(10);
        PORTF = 0B11110000;
    }
}