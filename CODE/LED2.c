/*
 * LED2.c
 * LED1(bit0)�� on, off�� 10ȸ�ϴ� ���α׷� ����
 * Created: 2018-03-22 ���� 8:08:20
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