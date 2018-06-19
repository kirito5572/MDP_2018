#include <mega128.h>
unsigned char FND[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char led = 0xfe;
unsigned char count = 0, seg = 0;
void main(void) { 
    DDRB = 0xff;
    DDRC = 0xff;
    DDRA = 0xff;
    PORTF = 0b11100000;
    TIMSK = 0x01;
    TCCR0 = 0b0000111;
    TCNT0 = 0x00;
    SREG = 0x80;
    PORTA = 0x01;
    PORTC = led;
    PORTB = FND[seg];
}
interrupt [TIM0_OVF] void timer_int0(void) {
    count++;
    if(count == 61) { 
        count=0;
        seg++;
        if(seg == 8) {
            seg = 0;
        }
        led = (led << 1) | 0x01; 
        if(led == 0xff) {
            led = 0xfe; 
        }
        PORTC = led; 
        PORTB = FND[seg]; 
    }
}