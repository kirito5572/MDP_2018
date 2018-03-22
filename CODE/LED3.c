/*
 * LED3.c
 * LED 상위 4bit를 on, off 하는 프로그램 구현
 * Created: 2018-03-22 오후 8:36:10
 * Author: KHJ
 */

 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char); 
 void main(void) {
 DDRC = 0xff; 
    while(1) {
        Delay(10); 
        LED_On_Off = 0x0f; 
        Delay(10); 
        LED_On_Off = 0xff; 
        }
}
void Delay(unsigned char count) { 
    unsigned int i, j; 
    for(i = 0; i < count; i++) {
        j = 50000;
        while(--j);
        }
}