/*
 * LED2.c
 * LED1(bit0)를 on, off를 10회하는 프로그램 구현
 * Created: 2018-03-22 오후 8:08:20
 * Author: KHJ
 */
 
 #include <mega128.h>
 #include <delay.h>
 #define LED_On_Off PORTC
 void main(void) {
    unsigned char count = 10; 
    DDRC = 0xff; 
    while(count != 0) {
        delay_ms(500); 
        LED_On_Off = 0b11111110; 
        delay_ms(500);
        LED_On_Off = 0b11111111; 
        count--; 
        }
}