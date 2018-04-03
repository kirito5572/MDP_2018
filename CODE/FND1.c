/*
 * FND1.c
 *
 * Created: 2018-04-03 ¿ÀÈÄ 4:54:02
 * Author: Administrator
 */

#include <mega128.h>
void Delay(unsigned char);
void main(void)
{ 
    char i, val;
    DDRB = 0xff; 
    DDRF = 0b11110000; 
    PORTF = 0b11100000; 
    while(1)
    { val = 0b00000001;
        for(i = 0; i < 7; i++)
        { PORTB = val;
            Delay(20);
            val = val << 1;
        }
    }
}
void Delay(unsigned char count) {
    int i, j=50000;
    for (i = 0;i < count; i++) {
        while(j--);
    }
}
