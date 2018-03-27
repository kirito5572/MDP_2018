/*
 * LED7.c
 * 
 * Created: 2018-03-26 ¿ÀÈÄ 4:10:05
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char count);
 void main() {
     unsigned char led=0b11111100;
     DDRC = 0xff;
     while(1){
        while(led != 63) {
            LED_On_Off = led;
            Delay(5);
            led <<= 2;
            led |= 0b00000011;
        }
        while(led != 252) {
            LED_On_Off = led;
            Delay(5);
            led >>= 2;
            led |= 0b11000000;
        }
     }
 }
 void Delay(unsigned char count) {
    unsigned int i,j;
    for(i = 0; i < count; i++) {
        j = 50000;
        while(--j);
    }
 }