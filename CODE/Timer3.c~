/*
 * Timer3.c
 *
 * Created: 2018-05-17 ¿ÀÈÄ 6:52:35
 * Author: Administrator
 */ 
 #include <mega128.h>
 #include <delay.h>
 unsigned char count,FNDcount;
 void FNDN();
 char FND[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 void main(void) {
    DDRC = 0xff;
    DDRB = 0xff;
    DDRF = 0xff;
    TCNT0 = 0x00;
    TIMSK = 0x01;
    TCCR0 = 0x07;
    SREG = 0x80;
    while(1){
        FNDN();
    }

 }
 interrupt [TIM0_OVF] void TiM_OVF(void)
 {
     count++;
     if(count == 6) {
        count = 0;
        FNDcount++;
     }
     if(FNDcount == 10) {
        FNDcount = 0;
     }
 }
 void FNDN() {
    PORTF = 0xe0;
    PORTB = FND[FNDcount];
    while(1) {
        if(count%2 == 0) {
            break;
        }
    }
    PORTF = 0xf0;
}