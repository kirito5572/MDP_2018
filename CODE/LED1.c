/*
 * LED1.c
 * LED1 Ư�� bit(PORTC.0)�� on, off �ϴ� ���α׷� ����
 * Created: 2018-03-22 ���� 8:00:46
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define LED_On_Off PORTC.0
void main(void)
{
    DDRC = 0Xff;
    while(1){ 
        LED_On_Off = 0;
        delay_ms(500);
        LED_On_Off = 1;
        delay_ms(500);
        }
}
