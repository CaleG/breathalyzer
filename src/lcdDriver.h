/*
 * lcdDriver.h
 *
 *    Header file for lcdDriver
 */

#ifndef LCDDRIVER_H
#define LCDDRIVER_H

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/*    Initializes the LCD screen to two line mode a blinking cursor */
void lcd_init();

/*    Clears the LCD Screen */
void lcd_clear();

/*    Sends command <cmd> to the LCD screen */
void lcd_wr_cmd(char);

/*    Writes character <character> to the screen */
void lcd_wr_char(char);

/*    Writes string <str> to the screen one character at a time */
void lcd_wr_str(char *);

#endif

