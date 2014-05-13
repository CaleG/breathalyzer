/*
 * breathalyzer.c
 *
 * Created: 5/13/2013 9:08:50 AM
 *
 * Main program to measure the amount of alcohol in the air, and translate
 *  that into a number of drinks, lit-up LEDs, and sounding a buzzer.
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ADC.h"
#include "lcdDriver.h"
#include "TimerInterrupts.h"

int main(void)
{
    DDRC |= 0x3C;
    DDRD |= 0x04;
    int adc_value = 0;
    char adc_string[10];
    
    lcd_init();
    adc_init();
    sei();
    
	while(1)
	{
   	 adc_value = adc_read();
   	 itoa(adc_value, adc_string, 10);
   	 
   	 if (adc_value > 830) {
   		 PORTC = 0x3C;
   		 initTimer0(0x41, 0x02);
   		 lcd_wr_str("# Drinks: 4+");
   	 }   		 
   	 else if (adc_value > 790) {
   		 PORTC = 0x1C;
   		 initTimer0(0x62, 0x02);    
   		 lcd_wr_str("# Drinks: 3-4");
   	 }   		 
   	 else if (adc_value > 720) {
   		 PORTC = 0xC;
   		 initTimer0(0xC5, 0x02);    
   		 lcd_wr_str("# Drinks: 2-3");
   	 }   		 
   	 else if (adc_value > 510) {
   		 PORTC = 0x4;
   		 stopTimer0();
   		 lcd_wr_str("# Drinks: 1-2");
   	 }   		 
   	 else {
   		 PORTC = 0;
   		 stopTimer0();    
   		 lcd_wr_str("# Drinks: <1");
   	 }
   	 
   	 _delay_ms(100);
   	 lcd_clear();
	}
}

ISR(TIMER0_COMPA_vect)
{
    PORTD ^= 0x04;
}
