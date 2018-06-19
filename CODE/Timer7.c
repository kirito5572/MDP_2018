//T/C�� overflow ���ͷ�Ʈ�� �̿��Ͽ� 0.5[sec]���� ��� led�� on/off ��Ű��
//���α׷��� �ۼ��϶�. �׸��� 1024 ���ָ� �̿��ϰ� normal ��带 �̿��϶�.
#include <mega128.h>
unsigned char led = 0xff,count;
void main(void) {
    DDRC = 0xff;
    SREG = 0x80;
    TIMSK = 0x01;
    TCCR0 = 0b00000111;
    TCNT0 = 0;
    while(1) {
        PORTC = led;
    }
}
interrupt [TIM0_OVF] void a(void)
{
    count++;
    if(count == 31) {
        led = ~led;
        count = 0; 
    }
}