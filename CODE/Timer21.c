#include <mega128.h>
unsigned int PWMC = 0x0200;
void main(void) {
    DDRB = 0xff;
    EIMSK = 0b00110000;
    EICRB = 0b00001010;
    TCCR1A = 0b00001011;
    TCCR1B = 0x05;
    TCCR1C = 0x00;
    TCNT1 = 0x0000;
    OCR1CH = (PWMC & 0xff00) >> 8;
    OCR1CL = PWMC & 0x00ff;
    SREG = 0x80;
    while(1);
}
interrupt [EXT_INT4] void external_int4(void) {
    if(PWMC > 0x0040) {
        PWMC -= 0x0040; 
    }
    OCR1CH = (PWMC & 0xff00) >> 8;
    OCR1CL = PWMC & 0x00ff;
}
interrupt [EXT_INT5] void external_int5(void) {
    if(PWMC < 0x0400) {
        PWMC += 0x0040;
    }
    OCR1CH = (PWMC & 0xff00) >> 8;
    OCR1CL = PWMC & 0x00ff;
}