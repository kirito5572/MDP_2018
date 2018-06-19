//T/C 0 CTC ��带 �̿��Ͽ� ��º� ���ͷ�Ʈ�� �߻��� ������ led�� 1��Ʈ��
//shift�ϸ鼭 on ��Ű�� ���α׷��� �ۼ��϶�. T/C ���ͷ�Ʈ �ֱ�� �ִ밡 �ǰ� TCNT0
//= 0 ���� �ϰ� ���������Ϸ��� 1024 ���ַ� �Ѵ�. (CTC ���)
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