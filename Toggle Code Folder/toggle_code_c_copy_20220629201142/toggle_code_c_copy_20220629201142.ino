#include <avr/io.h> //includes data sheet names

extern "C"  //used when adding c lib to c++ IDE
{
#include "millis.h"
#include "usart.h"
}

void LED_TOGGLE(void);

uint32_t BUTTON_VALUE = 0;

int main(void)
{
  //setup stuff here
  

  millisInit();
  usartInit(); //set up USART for 9600 N81 (no parity 8 data bits 1 stop bit)
  //usartInit115200(); //set up USART for 9600 N81 (no parity 8 data bits 1 stop bit)

  while (1) //same as loop() function (all embeded systems need endless loop)
  {
    BUTTON_VALUE = millis();
    /*check if a bit in a register is set to 1*/
    if (usartCharReceived())
    {
      char inChar = usartReadChar();

      switch (inChar)
      {
        case  'T':
          LED_TOGGLE();
          break;
      }
    }
  }
}

void LED_TOGGLE(void)
{
  if (BUTTON_VALUE = 1)
  {
    DDRB |= (1 << 5); //sets port B pin 5 as output
    PORTB ^= (1 << 5);
  }
}