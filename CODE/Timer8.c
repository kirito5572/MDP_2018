//T/C�� overflow ���ͷ�Ʈ�� �̿��Ͽ� 1[sec]���� ��� led�� on/off ��Ű�� ���α׷���
//�ۼ��϶�
#include <mega128.h>
unsigned char led = 0xff,count;
void main(void) {
    DDRC = 0xff;
    SREG = 0x80;
    TIMSK = 0x01;
    TCCR0 = 0b00000110;
    TCNT0 = 6;
    while(1) {
        PORTC = led;
    }
}
interrupt [TIM0_OVF] void a(void)
{
    count++;
    if(count == 250) {
        led = ~led;
        count = 0; 
    }
}