/*
 * Interrupt20.c
 * 
 * Created: 2018-05-08 ¿ÀÈÄ 7:13:40
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define FND PORTB
 #define FNDC PORTF
 unsigned char FNDCN[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},i = 0,sum = 1;
 unsigned int count = 0;
 void FNDs(unsigned int);
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b00001010;
    EIMSK = 0x30;
    while(1) {
        for(i=0;i<5;i++) {
            FNDs(count);
            delay_ms(10);
        }
        if(count == 10000) {
            count = 0;
        }       
    }   
 }
 interrupt [EXT_INT4] void ext_int4(void) {
    sum++;
    if(sum == 5) {
        sum = 1;
    }   
 }
 interrupt [EXT_INT5] void ext_int5(void) {
    switch(sum) {
        case 1:  count++;
                 break;
        case 2:  count+=10;
                 break;
        case 3:  count+=100;
                 break;
        case 4:  count+=1000;
                 break;
        default:

        break;
    }   
 }
 void FNDs(unsigned int count) {
    unsigned char st,nd,rd,th;
    th = (count/1000)%10;
    rd = (count/100)%10;
    nd = (count/10)%10;
    st = count%10;
    FNDC = 0x70;
    FND = FNDCN[st];
    if(sum == 1) {
        FND = 0x80 | FND;    
    }
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xb0;
    FND = FNDCN[nd];
    if(sum == 2) {
        FND = 0x80 | FND;    
    }
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xd0;
    FND = FNDCN[rd];
    if(sum == 3) {
        FND = 0x80 | FND;    
    }
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xe0;
    FND = FNDCN[th];
    if(sum == 4) {
        FND = 0x80 | FND;    
    }
    delay_ms(10);
    FNDC = 0xf0;
 }