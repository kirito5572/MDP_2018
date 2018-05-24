/*
 * Interrupt18.c
 * 
 * Created: 2018-05-08 ¿ÀÈÄ 6:53:30
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define FND PORTB
 #define FNDC PORTF
 unsigned char FNDCN[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},i;
 char outC = 0,inC = 0,leftC = 0;
 void counts(unsigned int,unsigned int, unsigned int);
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b10101010;
    EIMSK = 0xf0;
    while(1) {
        for(i=0;i<5;i++) {
            counts(leftC,outC,inC);
            delay_ms(10);
        }       
    }   
 }
 interrupt [EXT_INT4] void f_Door_In(void) {
    leftC++;
    inC++;
    if(leftC < 0) {
        leftC = 0;
    }
    if(inC > 9) {
        inC = 9;
    }      
 }
 interrupt [EXT_INT5] void f_Door_Out(void) {
    leftC--;
    outC--;
    if(leftC < 100) {
        leftC = 0;
    }
    if(outC > 0) {
        outC = 0;
    }    
 }
 interrupt [EXT_INT6] void r_Door_In(void) {
    leftC++;
    inC++;
    if(leftC < 0) {
        leftC = 0;
    }
    if(inC > 9) {
        inC = 9;
    }   
 }
 interrupt [EXT_INT7] void r_Door_Out(void) {
    leftC--;
    outC--;
    if(leftC < 100) {
        leftC = 0;
    }
    if(outC > 0) {
        outC = 0;
    }    
 }
 void counts(unsigned int leftC,unsigned int outC,unsigned int inC) {
    unsigned char leftC_st,leftC_nd;
    leftC_st = leftC % 10;
    leftC_nd = (leftC/10) % 10;
    outC = outC % 10;
    inC = inC % 10;
    FNDC = 0x70;
    FND = FNDCN[inC];
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xb0;
    FND = FNDCN[outC];
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xd0;
    FND = FNDCN[leftC_st];
    delay_ms(10);
    FNDC = 0xf0;
    FNDC = 0xe0;
    FND = FNDCN[leftC_nd];
    delay_ms(10);
    FNDC = 0xf0;
 }