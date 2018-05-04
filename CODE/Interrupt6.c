/*
 * Interrupt6.c
 * S/W8�� ������ ù ��° FND ���ڰ� up count �ǰ� S/W14�� ������ ù ��° FND
���ڰ� down count �Ǵ� ���α׷��� �ۼ��Ͻÿ�.
 * Created: 2018-05-03 ���� 4:59:31
 * Author: Administrator
 */

 #include <mega128.h>
 unsigned char FNDC[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
 char count = 0;
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b10000010;
    EIMSK = 0x90;
    while(1) {
        PORTB = FNDC[count];
        PORTF = 0x70;
    }   
 }
 interrupt [EXT_INT4] void ext_int4(void) {
    if(count != 9)
        count++;
 }
 interrupt [EXT_INT7] void ext_int7(void) {
    if(count != 0)
        count--;
 }