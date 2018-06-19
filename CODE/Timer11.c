#include <mega128.h>
unsigned char led = 0xff, cnt = 0;
void main(void) { 
    DDRC = 0xff; 
    PORTC = led; 
    TIMSK = 0x40;
    TCCR2 = 0x04;
    TCNT2 = 0;
    SREG = 0x80;
    while(1);
}
interrupt [TIM2_OVF] void timer_int2(void) {
    cnt++;
    if (cnt == 250) {
        led <<= 1;
        led |= 0x01;
        if (led == 0xff) {
            led = 0xfe; 
        }
        PORTC = led;
        cnt = 0;
    }
}