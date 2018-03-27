/*
 * LED9.c
 * 
 * Created: 2018-03-26 ¿ÀÈÄ 8:41:18
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char);
 void main() {
    int led[5] = {0xff,0x7e,0x3c,0x18,0x00};
    int i;
    DDRC = 0xff;
    while(1) {
        for(i=0; i<5; i++) {
            LED_On_Off = led[i];
            Delay(20);
        }
        for(i=3; i>0; i--) {
            LED_On_Off = led[i];
            Delay(20);
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

 
