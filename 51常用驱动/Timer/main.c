#include "timer.h"

void h() {
	P0 = ~P0;
}

void main() {
	timer.timer1.period = 10000;
	timer.timer1.handler = h;
	timer.timer1.init();
	while(1);
}