#include <mega128.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

void main(void) {
    DDRD = 0xff;
    DDRE = 0xff;
    lcd_init(16);
    while(1){
        switch(PINE) {
            case 0x10: lcd_clear();
                       lcd_putsf("1st Floor");
            break;
            case 0x20: lcd_clear();
                       lcd_putsf("2nd Floor");
            break;
            case 0x40: lcd_clear();
                       lcd_putsf("Don't stop in 3rd & 4th Floor");
            break;
            case 0x80: lcd_clear();
                       lcd_putsf("Don't stop in 3rd & 4th Floor");
            break;
        
        }
    }    
}
