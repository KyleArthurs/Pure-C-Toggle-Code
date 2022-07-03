#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t millisCount = 0;  //volatile tells optimiser to keep hands off


uint32_t millis(void)
{
  return millisCount;
}

void millisInit(void)
{
  sei();  //enable interupts - tells CPU to respond
  TIMSK2 |= (1 << OCIE2A); //tell timer to send interupt signal

  //put timer 2 into CTC mode
  TCCR2A |= (1 << WGM21);

  OCR2A = 249; // assumes count of 250 = 1 milli second.  minus 1 for reset

  //Start timer
  TCCR2B |= (1 << CS22); //starts timer with prescale 64 - 250kHz
}

ISR(TIMER2_COMPA_vect) //INTERUPT SERVICE ROUTINE
{
  //OCF2A must have just been set
  millisCount++;  //increments every 1 milli second
}

