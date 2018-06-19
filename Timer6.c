//T/C 0 CTC 모드를 이용하여 출력비교 인터럽트가 발생할 때마다 led를 1비트씩
//shift하면서 on 시키는 프로그램을 작성하라. T/C 인터럽트 주기는 최대가 되게 TCNT0
//= 0 으로 하고 프리스케일러는 1024 분주로 한다. (CTC 모드)
#include <mega128.h>
unsigned char led = 0xfe;
void main(void) {
    DDRC = 0xff;
    SREG = 0x80;
    TIMSK = 0x02;
    TCCR0 = 0b00001111;
    TCNT0 = 0x00;
    OCR0 = 255;
    while(1) {
        PORTC = led;
    }
}
interrupt [TIM0_COMP] void a (void)
{
    led <<= 1;
    led |= 0x01;
    if(led == 0xff) {
        led = 0xfe; 
    }
}