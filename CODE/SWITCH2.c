/*
 * SWITCH2.c
 * PE4~PE7�� ����Ǿ� �ִ� 4���� ����ġ SW8, SW14, SW15, SW16�� ���¸� �״��
   PORT C�� ������ ����� 4���� LED�� ����ϰ� PORT C�� ������ ����� 4����
   LED���� �������� ����ϴ� ���α׷��� �ۼ��϶�. �� [���� switch.1] �������� ��
   ��� ����ϴ� ���α׷��� �ۼ��϶�.
 * Created: 2018-03-29 ���� 5:05:31
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
     