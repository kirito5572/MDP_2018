/*
 * LED6.c
 * 
 * Created: 2018-03-26 ¿ÀÈÄ 4:01:19
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char);
 void main() {
    unsigned char led = 0xfc , k=64;
    DDRC = 0xff;
    while(k!=0){
        LED_On_Off = led;
        Delay(5);
        led <<= 2;
        led |= 0x03;
        k--;
        if(led == 0xff) led = 0xfc;
    }
 }
 void Delay(unsigned char count) {
    unsigned int i,j;
    for(i = 0; i < count; i++) {
        j = 50000;
        while(--j);
    }
 }