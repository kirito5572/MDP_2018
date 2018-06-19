#include <mega128.h>
#include <delay.h>
unsigned char seg_pat[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char pos;
unsigned char hour,min,sec;
void Time_out(void);
void main(void) {

    DDRB = 0xff;
    DDRC = 0xff;
    DDRF = 0xff;
    PORTC = 0;       
    EIMSK = 0b00110000;
    TIMSK = 0x04;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCNT1 = 49911;
    SREG = 0x80;
    while(1) {
        Time_out();
        if(sec >= 60) {
            sec = 0;
            min = min + 1;
            if(min >= 60) {
                min = 0;
                hour = (hour + 1) % 24;
                if(hour == 24) {
                    sec = 0;
                    min = 0;
                    hour = 0;
                } 
            }
        }
    }
}
void Time_out(void) {
    PORTF = 0b11111110;
    PORTB= seg_pat[sec % 10];
    delay_ms(2);
    PORTF = 0xff;
    PORTF = 0b11111101;
    PORTB= seg_pat[sec / 10];
    delay_ms(2);
    PORTF = 0xff;
    PORTF = 0b11111011;
    PORTB= seg_pat[min % 10];
    delay_ms(2);
    PORTF = 0xff;
    PORTF = 0b11110111;
    PORTB= seg_pat[min / 10];
    delay_ms(2);
    PORTF = 0xff;
    PORTF = 0b11101111;
    PORTB= seg_pat[hour % 10];
    delay_ms(2);
    PORTF = 0xff;
    PORTF = 0b11011111;
    PORTB= seg_pat[hour / 10];
    delay_ms(2);
    PORTF = 0xff;
}
interrupt [EXT_INT4] void external_int4(void) {
    switch(pos) {
        case 0: sec++;      break;
        case 1: sec+=10;  
                if(sec >= 60) {
                    sec = sec % 60;
                    min = min + 1;
                }
                break;
        case 2: min++;      break;
        case 3: min+=10;    
                if(min >= 60) {
                    min = min % 60;
                    hour = (hour + 1) % 24;
                }
                break;
        case 4: hour++;     break;
        case 5: hour+=10;   
                if(hour >= 24) {
                    hour = hour % 24;
                }
                break;  
    }
}
interrupt [EXT_INT5] void external_int5(void) {
    pos = (pos + 1) % 6;
}
interrupt [TIM1_OVF] void count(void) {
    sec++;
    TCNT1 = 49911;
    PORTC = ~PORTC;
}