//TCNT1 = 0x9C40(40000) �����ϰ� 256���� �� clock�� T/C1�� clock�� �̿��Ͽ�
//overflow interrupt�� �߻��� ������ led�� shift�ϸ鼭 ON��Ű�� ���α׷��� �ۼ��϶�.
//(Normal mode)
#include <mega128.h>
unsigned char led = 0xfe;
void main() {
    DDRC = 0xff;
    PORTC = led;
    TCNT1 = 0x9C40;
    TCCR1A = 0x00;
    TCCR1B = 0x04;
    TCCR1C = 0x00;
    TIMSK = 0x04;
    SREG = 0x80;
    while(1);
}
interrupt [TIM1_OVF] void timer_int1(void) {
    led <<= 1;
    led |= 0x01;
    if(led == 0xff) led = 0xfe;
    PORTC = led;
    TCNT1 = 0x9C40;
}