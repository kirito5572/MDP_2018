//타이머 카운터 값이 출력비교매치 인터럽트에서 led를 1칸씩 이동하게 프로그램을
//작성하시오. 출력비교 레지스터 OCR1A = 10000, 256 분주된 clock을 T/C1 CTC을
//이용하여 출력비교매치 interrupt를 발생시키는 프로그램을 작성하라. (CTC 모드)
#include <mega128.h>
unsigned char led = 0xfe;
void main(void) {
    DDRC = 0xff;
    PORTC = led;
    TIMSK = 0x10;
    TCCR1A = 0x00;
    TCCR1B = 0x0C;
    OCR1A = 10000;
    SREG = 0x80; 
    while(1);
}
interrupt [TIM1_COMPA] void timer_int1(void) {
    led <<= 1;
    led |= 0x01;
    if(led == 0xff) led = 0xfe;
    PORTC = led;
}
