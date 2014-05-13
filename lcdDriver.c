/*
 * lcdDriver.c
 *
 *    C file for initializing the LCD screen and writing characters to it.
 */

#include "lcdDriver.h"

/*    Initializes the LCD screen to two line mode a blinking cursor */
void lcd_init() {
    //set GPIO pins to outputs
    DDRB |= 0x07;
    DDRD |= 0xF0;
   	 
    _delay_ms(40);

    //set function
    lcd_wr_cmd(0x20);
    lcd_wr_cmd(0x20);
    lcd_wr_cmd(0xC0);
    
    //set display
    lcd_wr_cmd(0x00);
    lcd_wr_cmd(0xF0);
    
    lcd_clear();
}

/*    Clears the LCD Screen */
void lcd_clear() {
    lcd_wr_cmd(0x00);
    lcd_wr_cmd(0x10);
    _delay_us(1600);
}

/*    Sends command <cmd> to the LCD screen */
void lcd_wr_cmd(char cmd) {
    PORTB = 0x00;
    PORTB = 0x04;
    PORTD &= 0x0F;
    PORTD |= cmd;
    _delay_us(1);
    PORTB = 0x00;
    _delay_us(40);
}

/*    Writes character <character> to the screen */
void lcd_wr_char(char character) {
    PORTB = 0x01;
    PORTB = 0x05;
    PORTD &= 0x0F;
    PORTD |= (character & 0xF0);
    _delay_us(1);
    PORTB = 0x01;
    _delay_us(34);
    
    PORTB = 0x01;
    PORTB = 0x05;
    PORTD &= 0x0F;
    PORTD |= (character & 0x0F) << 4;
    _delay_us(1);
    PORTB = 0x01;
    _delay_us(34);
}

/*    Writes string <str> to the screen one character at a time */
void lcd_wr_str(char *str) {
    while (*str)
   	 lcd_wr_char(*str++);
}
