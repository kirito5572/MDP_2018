/*
 * SWITCH2.c
 * PE4~PE7에 연결되어 있는 4개의 스위치 SW8, SW14, SW15, SW16의 상태를 그대로
   PORT C의 상위에 연결된 4개의 LED에 출력하고 PORT C의 하위에 연결된 4개의
   LED에는 반전시켜 출력하는 프로그램을 작성하라. 단 [예제 switch.1] 실행결과와 반
   대로 출력하는 프로그램을 작성하라.
 * Created: 2018-03-29 오후 5:05:31
 * Author: KHJ
 */
 
 #include <mega128.h>
 #define LED_On_Off PORTC
 #define Sw_Input PORTE
 void main(void) {
    unsigned char VALUE,NIBBLE,MODERN;
    DDRC = 0xff;
    DDRE = 0x00;
    LED_On_Off = 0xff;
        while(1) {
            VALUE = PINE & 0xf0;
            MODERN = VALUE;
            VALUE >>= 4;
            NIBBLE = 0x0f ^ VALUE;
            LED_On_Off = MODERN | NIBBLE;
        }
 }
     