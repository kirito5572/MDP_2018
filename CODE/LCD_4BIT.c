#include <mega128.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

void main(void) {
    DDRD = 0xff;
    lcd_init(16);

    lcd_putchar('A');
    lcd_putchar('B'); 
    lcd_putchar('C'); 
    lcd_putchar('D');
    lcd_putchar(' ');  
    lcd_putchar(0x61); 
    lcd_putchar(0x62); 
    lcd_putchar(0x63); 
    lcd_putchar(0x64);     
}
