/*
 * Interrupt9.c
 * 
 * Created: 2018-05-03 ¿ÀÈÄ 4:59:31
 * Author: Administrator
 */

 #include <mega128.h>
 #include <delay.h>
 unsigned char FNDC[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},i,flag = 1;
 char count = 0;
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b10000010;
    EIMSK = 0x90;
    while(1) {
        if(flag == 1) {
            for(i = 0;i<25; i++) {
                PORTB = FNDC[count];
                PORTF = 0x70;
                delay_ms(10);
            }
            count++;
            if(count == 10) {
                count = 0;
            }
        }   
    }   
 }
 interrupt [EXT_INT4] void ext_int4(void) {
    flag = flag ^ 1;
 }