/*
 * ADC.c
 *
 * C file for utilizing the ADC
 */
#include "ADC.h"

void adc_init() {
    ADCSRA = 0x87;	//Turn On ADC and set prescaler (CLK/128)
    ADCSRB = 0x00;	//Set gain & turn off autotrigger
    ADMUX = 0x00; 	//Set ADC channel ADC0 with 1X gain
}

int adc_read() {
    ADCSRA = 0xC7; 	 
    _delay_us(260);
    return ADC;
}