//7:01:26
#include <mega128.h>
#include <delay.h>
char fnd_array[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,
 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
 void main() {
    unsigned char turn;
    DDRB = 0xff;
    DDRF = 0xf0;
    PORTF = 0xe0;
    while(1) {
        for(turn = 0; turn <16; turn++) {
            PORTB = fnd_array[turn];
            delay_ms(500);
        }
    }
 }   
    
