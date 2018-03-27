/*
 * LED14.c
 * 
 * Created: 2018-03-26 ¿ÀÈÄ 4:10:05
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char);
 void main() {
    int i;
    unsigned char led = 255;
    DDRC = 0xff;
    while(1) {
        for(i = 0; i <127; i++) {
            PORTC = led;
            Delay(10);
            led -= 1;
        }
    }
 }
 void Delay(unsigned char count) {
 unsigned int i, j;
 for(i = 0; i < count; i++) {
    j = 50000;
    while(--j);
    }
 }