#include <mega128.h>
unsigned char led = 0Xfe;
unsigned int N1;
char a[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void main(void) {
    DDRB = 0xff;
    DDRF = 0xff;
    DDRC = 0xff;
    PORTC = led;
    ETIMSK = 0x04;
    TCCR3A = 0x00;
    TCCR3B = 0x06;
    TCCR3C = 0x00;
    TCNT3H = 0xff;
    TCNT3L = 0xf0;
    SREG = 0x80;
    while(1) {
        PORTB = a[N1];
    }
}
interrupt [TIM3_OVF] void timer(void) {
    led <<= 1;
    led |= 0x01;
    if(led == 0xff) {
        led = 0xfe;
    }
    PORTC = led;
    if(N1==10) {
        N1=0;
    }
    N1 = (N1 + 1)% 10;
    TCNT3H = 0xff;
    TCNT3L = 0xf0;
}