//0410 17:35:50

#include <mega128.h>
#include <delay.h>
#define FND PORTB   //FND
#define LED PORTC   //LEDs
 void main() {
    char num[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //0~9 ���� ����
    unsigned int up = 0;
    unsigned char one,two,three,four;   //�� �ڸ��� ���� ����
    DDRF = 0xf0;                        //FND�ڸ� ��¼���
    DDRB = 0xff;                        //FND��¼���
    DDRC = 0xff;                        //LED��¼���
    FND = 0x00;                         //FND�ʱⰪ(ALL OFF)
    LED = 0xff;                         //LED�ʱⰪ(ALL OFF)
    while(1) {
        for(;up != 9999; up++) {
            four = (up/1000)%10;        //4��° �ڸ� ���� ����
            three = (up/100)%10;        //3��° �ڸ� ���� ����
            two = (up/10)%10;           //2��° �ڸ� ���� ����
            one = up%10;                //1��° �ڸ� ���� ����
            PORTF = 0b11100000;         //4��° �ڸ� ���� ���
            FND = num[four];
            delay_ms(20);
            PORTF = 0b11110000;
            PORTF = 0b11010000;         //3��° �ڸ� ���� ���
            FND = num[three];
            delay_ms(20);
            PORTF = 0b11110000; 
            PORTF = 0b10110000;         //2��° �ڸ� ���� ���
            FND = num[two];
            delay_ms(20);
            PORTF = 0b11110000;
            PORTF = 0b01110000;         //1��° �ڸ� ���� ���
            FND = num[one];
            delay_ms(20);
            PORTF = 0b11110000;
            
            if(up >= 1000) {
                if((two % 2) == 0) {    //2��° �ڸ� ���ڰ� ¦�� �϶� On
                    LED = 0xff;    
                }
                else {                  //2��° �ڸ� ���ڰ� ¦�� �϶� Off
                    LED = 0x00;
                }
            }
        }
        up = 0;                         //9999���� ���� �ٽ� ó������
    }
 }    