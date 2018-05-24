/*
 * Interrupt21.c
 * 
 * Created: 2018-05-08 ¿ÀÈÄ 7:13:40
 * Author: KHJ
 */

 #include <mega128.h>
 #define FND PORTB
 #define FNDC PORTF
 unsigned char FNDCN[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},i = 0,sum = 1;
 unsigned int count = 0;
 void FNDs(unsigned int); 
 void delay_mss(unsigned int);
 void main(void) {
    unsigned char j = 0;
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b00001010;
    EIMSK = 0x30;
    while(1) {
        for(i=0;i<10;i++) {
            FNDs(count);
            delay_mss(10);
            j++;
        }
        if(count == 3600) {
            count = 0;
        }
        if(j==10) {
            j = 0;
            count++;
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
        case 3:  count+=60;
                 break;
        case 4:  count+=600;
                 break;
        default:

        break;
    }   
 }
 void FNDs(unsigned int count) {
    unsigned char st,nd,rd,th;
    th = (count/600)%6;
    rd = (count/60)%10;
    nd = (count/10)%6;
    st = count%10;
    FNDC = 0x70;
    FND = FNDCN[st];
    if(sum == 1) {
        FND = 0x80 | FND;    
    }
    delay_mss(10);
    FNDC = 0xf0;
    FNDC = 0xb0;
    FND = FNDCN[nd];
    if(sum == 2) {
        FND = 0x80 | FND;    
    }
    delay_mss(10);
    FNDC = 0xf0;
    FNDC = 0xd0;
    FND = FNDCN[rd];
    if(sum == 3) {
        FND = 0x80 | FND;    
    }
    delay_mss(10);
    FNDC = 0xf0;
    FNDC = 0xe0;
    FND = FNDCN[th];
    if(sum == 4) {
        FND = 0x80 | FND;    
    }
    delay_mss(10);
    FNDC = 0xf0;
 }
 void delay_mss(unsigned int delay) {
    unsigned int dI,dJ;
    for(dI = 0; dI < delay; dI++) {
        for(dJ = 0; dJ < 500; dJ++) {
        }
    }
 }