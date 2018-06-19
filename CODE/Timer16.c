//T3(PIN8)�� ����� ����ġ SW15�� ���� ������ LED�� �� bit�� shift�ϸ鼭 ON��Ű��
//���α׷��� �ۼ��϶�.(T3�� clock �Է�) ��, T/C3�� counter�� �̿��Ͽ� SW15�� ����
//������ T/C3�� Overflow interrupt�� �߻���Ű���� �غ���. �� T1(pin31), T3(pin8)
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
