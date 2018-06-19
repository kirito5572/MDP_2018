#include <mega128.h>
unsigned char led = 0xfe;
void main(void) {
    DDRC = 0xff;
    PORTC = led; 
    TIMSK = 0x10;
    TCCR1A = 0x00;
    TCCR1B = 0x04;
    TCCR1C = 0x00;
    TCNT1 = 0x0000;
    OCR1A = 0x8000;
    SREG = 0x80;
    while(1);
}
interrupt [TIM1_COMPA] void COMP(void) {
    led <<= 1;
    led |= 0x01;
    if(led == 0xff){
        led = 0xfe;
    }
    PORTC = led;
    TCNT1 = 0x0000;
}