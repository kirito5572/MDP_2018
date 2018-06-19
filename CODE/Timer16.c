//T3(PIN8)에 연결된 스위치 SW15를 누를 때마다 LED를 한 bit씩 shift하면서 ON시키는
//프로그램을 작성하라.(T3핀 clock 입력) 즉, T/C3을 counter로 이용하여 SW15를 누를
//때마다 T/C3에 Overflow interrupt가 발생시키도록 해보자. ※ T1(pin31), T3(pin8)
#include <mega128.h>
unsigned unsigned led = 0xfe;
void main() {
    DDRC = 0xff;
    PORTC = led;
    TCCR3A =0x00;
    TCCR3B =0x06;
    ETIMSK = 0b00000100;
    TCNT3H = 0xff;
    TCNT3L = 0x8f;
    SREG = 0x80;
    while(1);
}
interrupt [TIM3_OVF] void timer_int3(void) {
    led <<= 1;
    led |= 0x01;
    if(led == 0xff) led = 0xfe;
    PORTC = led;
    TCNT3H = 0xff;
    TCNT3L = 0x8f;
}
