/*
 * LED13.c
 * 
 * Created: 2018-03-27 ¿ÀÈÄ 5:28:23
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char);
 void main() {
    unsigned char Xturn = 0;
    DDRC = 0xff;
    while(1) {
        if( Xturn == 0xff) Xturn = 0;
        LED_On_Off = ~(++Xturn);
        Delay(10);
    }
 }
 void Delay(unsigned char count) {
 unsigned int i, j;
 for(i = 0; i < count; i++) {
    j = 50000;
    while(--j);
    }
 }