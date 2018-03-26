/*
 * LED5.c
 * 
 * Created: 2018-03-22 ¿ÀÈÄ 9:10:09
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned int); 
 void main(void) {
 unsigned char led = 0x7f;
 unsigned char k = 64;
 DDRC = 0xff; 
    while(k!=0) {
        LED_On_Off = led; 
        Delay(5); 
        led >>= 1; 
        led |= 0x80;
        k--; 
        if(led == 0xff) led = 0xfe; 
}
void Delay(unsigned int cnt) {
    unsigned int i, j;
    for(i = 0;i < cnt;i++) {
        j = 50000;
            while(--j);
    }
}