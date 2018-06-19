#include <mega128.h>
void main(void) {
    DDRB = 0xff;
    ETIMSK = 0x01;
    TCCR1A = 0x04;
    TCCR1B = 0x05;
    TCNT1 = 0x0000;
    OCR1CH = (7812 & 0xff00) >> 8;
    OCR1CL = 7812 & 0xff;
    SREG = 0x80;
    while(1);
}
interrupt [TIM1_COMPC] void timer1_compc(void) {
    TCNT1 = 0x0000;
}