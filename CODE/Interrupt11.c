/*
 * Interrupt11.c
 * 
 * Created: 2018-05-08 ¿ÀÈÄ 4:58:40
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 unsigned char FNDC[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},i,flag = 1;
 unsigned count = 0;
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b00000010;
    EIMSK = 0b00010000;
    while(1) {
        for(i=0;i<50;i++) {
            PORTF = 0x70;
            PORTB = FNDC[count];
            delay_ms(10);
        }
        if(flag == 1) {
            count++;
            delay_ms(10);
        }
        if(count == 10) {
            count = 0;
        }   
    }   
 }
 interrupt [EXT_INT4] void ext_int4(void) {
    flag = flag ^ 1;
 }