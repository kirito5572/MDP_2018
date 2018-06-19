#include <mega128.h>
unsigned char led = 0xfe;
void main(void) {
    DDRC = 0xff;
    PORTC = led;
    TIMSK = 0x80;
    TCCR2 = 0x6d;
    OCR2 = 255;
    TCNT2 = 0;
    SREG = 0x80;
    while(1);
}
interrupt [TIM2_COMP] void timer_comp2(void) {
    led <<= 1;
    led |= 0x01;
    if(led == 255) {
        led = 254;
    }
    PORTC = led;
}