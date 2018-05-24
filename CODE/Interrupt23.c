/*
 * Interrupt21.c
 * 
 * Created: 2018-05-08 ¿ÀÈÄ 7:13:40
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define FND PORTB
 #define FNDC PORTF
 unsigned char FNDCN[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},i = 0;
 unsigned int count = 0, sCount = 0;
 unsigned char flag = 1 ,stopC = 0;
 unsigned char st = 0,nd = 0,rd = 0,th = 0;
 void FNDs(unsigned int);
 void stop(); 
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    #asm("sei")
    EICRB = 0b00001010;
    EIMSK = 0x30;
    while(1) {
        //stop();
        FNDs(count);
        delay_ms(2); 
        if(flag == 1) {
            for(;;) {
                FNDs(count);
                delay_ms(2);
                i++;
                sCount++;
                if(count == 3600) {
                    count = 0;
                }
                if(sCount >= 10) {
                    count++;
                    sCount = 0;
                }
                if(flag == 0) {
                    break;
                }
            }
        }
                  
    }   
 }
 void FNDs(unsigned int count) {
    th = (count/600)%6;
    rd = (count/60)%10;
    nd = (count/10)%6;
    st = count%10;
    FNDC = 0x70;
    FND = FNDCN[st];
    delay_ms(2);
    FNDC = 0xf0;
    FNDC = 0xb0;
    FND = FNDCN[nd];
    delay_ms(2);
    FNDC = 0xf0;
    FNDC = 0xd0;
    FND = FNDCN[rd];
    delay_ms(2);
    FNDC = 0xf0;
    FNDC = 0xe0;
    FND = FNDCN[th];
    delay_ms(2);
    FNDC = 0xf0;
 }
 void stop() {
    if (stopC < 10) {
        FNDC = 0x70;
        FNDC = 0x70;
        FND = 0x80 | FNDCN[st];
        delay_ms(2);
        FNDC = 0xf0;
        FNDC = 0xb0;
        FND = 0x80 | FNDCN[nd];
        delay_ms(2);
        FNDC = 0xf0;
        FNDC = 0xd0;
        FND = 0x80 | FNDCN[rd];
        delay_ms(2);
        FNDC = 0xf0;
        FNDC = 0xe0;
        FND = 0x80 | FNDCN[th];
        delay_ms(2);
        FNDC = 0xf0;
    } 
    if (stopC >= 10) {
        FNDC = 0x70;
        FNDC = 0x70;
        FND = 0x00 | FNDCN[st];
        delay_ms(2);
        FNDC = 0xf0;
        FNDC = 0xb0;
        FND = 0x00 | FNDCN[nd];
        delay_ms(2);
        FNDC = 0xf0;
        FNDC = 0xd0;
        FND = 0x00 | FNDCN[rd];
        delay_ms(2);
        FNDC = 0xf0;
        FNDC = 0xe0;
        FND = 0x00 | FNDCN[th];
        delay_ms(2);
        FNDC = 0xf0;
    }
    if (stopC >= 20) {
        stopC = 0;
    }
    stopC++;
 }
  interrupt [EXT_INT4] void ext_int4(void) {
     flag = flag ^ flag; 
 }
 interrupt [EXT_INT5] void ext_int5(void) {
    count = 0;
    th = 0;
    rd = 0;
    nd = 0;
    st = 0;   
 }
