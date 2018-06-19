//T/C의 overflow 인터럽트를 이용하여 0.5[sec]마다 모든 led를 on/off 시키는
//프로그램을 작성하라. 그리고 1024 분주를 이용하고 normal 모드를 이용하라.
#include <mega128.h>
unsigned char led = 0xff,count;
void main(void) {
    DDRC = 0xff;
    SREG = 0x80;
    TIMSK = 0x01;
    TCCR0 = 0b00000111;
    TCNT0 = 0;
    while(1) {
        PORTC = led;
    }
}
interrupt [TIM0_OVF] void a(void)
{
    count++;
    if(count == 31) {
        led = ~led;
        count = 0; 
    }
}