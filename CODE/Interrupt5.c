/*
 * Interrupt5.c
 *
 * Created: 2018-05-03 ¿ÀÈÄ 4:59:31
 * Author: Administrator
 */

 #include <mega128.h>
 unsigned char FNDC[4] = {0x66, 0x6d, 0x7d, 0x07};
 void main(void) {
    DDRB = 0xff;
    DDRE = 0x00;
    DDRF = 0xf0;
    SREG = 0x80;
    EICRB = 0b10101010;
    EIMSK = 0xf0;
    while(1) {
        
    }   
 }
 interrupt [EXT_INT4] void ext_int4(void) {
    PORTF = 0b01110000; 
    PORTB = FNDC[0];
 }
 interrupt [EXT_INT5] void ext_int5(void) {
    PORTF = 0b10110000;
    PORTB = FNDC[1];
 }
 interrupt [EXT_INT6] void ext_int6(void) {
    PORTF = 0b11010000; 
    PORTB = FNDC[2];
 }
 interrupt [EXT_INT7] void ext_int7(void) {
     PORTF = 0b11100000; 
    PORTB = FNDC[3];
 }