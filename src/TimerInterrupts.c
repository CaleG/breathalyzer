/*
* TimerInterrupts.c
*
*    File initialize the Timer for interrupts at certain intervals of time
*/

#include "TimerInterrupts.h"

void initTimer0(int count, int prescaler)
{
    OCR0A = count; //0x0F;
    TCCR0A = 0x02; // timer CTC mode
    TCCR0B = prescaler; // timer clk = system clk / prescaler
    TIFR0 = 0x02; // clear previous timer compare match
    TIMSK0 = 0x02; // timer compare match A interrupt enable
}

void stopTimer0()
{
    TIMSK0 = 0x00;
}
