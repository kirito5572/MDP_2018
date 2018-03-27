/*
 * SWITCH1.c
 *
 * Created: 2018-03-27 ¿ÀÈÄ 9:09:55
 * Author: KHJ
 */

 #include <mega128.h>
 #define LED_On_Off PORTC
 #define Sw_Input PORTE
 void main(void) {
    unsigned char VALUE,NIBBLE,MODERN;
    DDRC = 0xff;
    DDRE = 0x00;
    LED_On_Off = 0xff;
    while (1) {
        VALUE = PINE & 0xf0;
        MODERN = 0xf0 ^ VALUE;
        NIBBLE = (VALUE >> 4);
        LED_On_Off = MODERN | NIBBLE;
    }
 }
 void Delay(unsigned char count) {
    int i,j;
    for(i = 0; i < count; i++) {
        j = 50000;
        while(--j);
    }
 }