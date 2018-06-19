//Ÿ�̸� ī���� ���� ��º񱳸�ġ ���ͷ�Ʈ���� led�� 1ĭ�� �̵��ϰ� ���α׷���
//�ۼ��Ͻÿ�. ��º� �������� OCR1A = 10000, 256 ���ֵ� clock�� T/C1 CTC��
//�̿��Ͽ� ��º񱳸�ġ interrupt�� �߻���Ű�� ���α׷��� �ۼ��϶�. (CTC ���)
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
