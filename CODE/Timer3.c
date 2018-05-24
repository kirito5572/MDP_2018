/*
 * Timer3.c
 *
 * Created: 2018-05-17 ���� 6:52:35
 * Author: Administrator
 */ 
 #include <mega128.h>
 unsigned char count,FNDcount;
 void FNDN();
 char FND[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 void main(void) {
    DDRC = 0xff;
    TCNT0 = 0x00;
    TIMSK = 0x01;
    TCCR0 = 0x07;
    SREG = 0x80;
    while(1);

 }
 interrupt [TIM0_OVF] void TiM_OVF(void)
 {
     count++;
     if(count == 30) {
        FNDN();
        count = 0;
        FNDcount++;
     }
 }
 void FNDN() {
    PORTF = 0xe0;
    PORTB = FND[FNDcount];
    PORTF = 0xf0;
}