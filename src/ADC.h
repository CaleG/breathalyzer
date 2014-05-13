/*
 * ADC.h
 *
 * Header file for the ADC
 */

#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void adc_init();
int adc_read();

#endif
