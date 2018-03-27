/*
 * LED15.c
 * 
 * Created: 2018-03-27 ¿ÀÈÄ 7:01:05
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char);
 void main() {
    unsigned char led = 0xff, Right01 = 0xff, Right02, Left01 = 0xff, Left02;
    DDRC = 0xff;
      LED_On_Off = led;
      while(1) {
            while(led != 0) {
                Right01 >>= 1;
                Left01 <<= 1;
                led = (Right01 & Left01);
                LED_On_Off = led;
                Delay(10);
            }
            while(led != 0xff) {
                Right01 >>= 1;
                Left01 <<= 1;
                Right02 = ~Right01;
                Left02 = ~Left01;
                led = (Right02 & Left02);
                LED_On_Off = led;
                Delay(10);
                if(led ==0xff){
                    led = 0xff;
                    Right01 = 0xff;
                    Left01 = 0xff;
                    break;
                }
            }
      }
 }
 void Delay(unsigned char count) {
    unsigned int i, j;
    for(i = 0; i < count; i++) {
        j = 50000;
        while(--j);
    }
 }
  
            