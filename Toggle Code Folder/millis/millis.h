#ifndef MILLIS_H
#define MILLIS_H

//set up timer 2 to interupt every 1 ms
void millisInit(void);

//returns no. of milli seconds passed since millisInit was called
//rolls over to 0 after about 50 days
uint32_t millis(void);

#endif
