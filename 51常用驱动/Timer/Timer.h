#ifndef TIMER_H
#define  TIMER_H

#include "reg52.h"

typedef struct {
	unsigned int period;
	void (* handler) ();
	void (* init) ();
} Timer_T;

typedef struct {
	Timer_T timer1;
	Timer_T timer2;
} Timer;

extern Timer timer;

#endif