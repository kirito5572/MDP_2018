/*
 * SWITCH8.c
 *
 * Created: 2018-03-29 ¿ÀÈÄ 7:05:09
 * Author: KHJ
 */

 #include <mega128.h>
 #define LED_On_Off PORTC
 #define Sw_Input PINE
 void main(void) {
    unsigned char old1,new1,old2,new2,old3,new3,old4,new4,led;
    DDRC = 0xff;
    DDRE = 0x00;
    led = 0xfe;
    LED_On_Off = led;
    old1 = Sw_Input & 0x10;
    old2 = Sw_Input & 0x20;
    old3 = Sw_Input & 0x40;
    old4 = Sw_Input & 0x80;
    while(1) {
        new1 = Sw_Input & 0x10;
        new2 = Sw_Input & 0x20;
        new3 = Sw_Input & 0x40;
        new4 = Sw_Input & 0x80;
        if((!new1 && old1) || (!new2 && old2) || 
        (!new3 && old3) || (!new4 && old4)) {
            led = (led << 1) | 0x01;
            if(led == 0xff) led = 0xfe;
            LED_On_Off = led;
        }
        old1 = new1;
        old2 = new2;
        old3 = new3;
        old4 = new4;
    }
 }