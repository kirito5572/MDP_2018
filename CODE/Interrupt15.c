/*
 * Interrupt15.c
 * 
 * Created: 2018-05-08 ¿ÀÈÄ 6:40:26
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define FND PORTB
 #define FNDC PORTF
 unsigned char FNDCN[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},i;
 unsigned int count;
 void counts(unsigned int);
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b10101010;
    EIMSK = 0xf0;
    while(1) {
        for(i=0;i<5;i++) {
            counts(count);
            delay_ms(10);
        }
        if(count == 10000) {
            count = 0;
        }       
    }   
 }
 interrupt [EXT_INT4] void ext_int4(void) {
    count++;   
 }
 interrupt [EXT_INT5] void ext_int5(void) {
    count+=10;   
 }
 interrupt [EXT_INT6] void ext_int6(void) {
    count+=100;   
 }
 interrupt [EXT_INT7] void ext_int7(void) {
    count+=1000;   
 }
 void counts(unsigned int count) {
    unsigned char st,nd,rd,th;
    th = (count/1000)%10;
    rd = (count/100)%10;
    nd = (count/10)%10;
    st = count%10;
    FNDC = 0x70;
    FND = FNDCN[st];
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xb0;
    FND = FNDCN[nd];
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xd0;
    FND = FNDCN[rd];
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xe0;
    FND = FNDCN[th];
    delay_ms(10);
    FNDC = 0xf0;
 }