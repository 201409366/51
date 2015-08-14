#include "lcd1602.h"

void main () {

	initLcd1602();		
	lcd1602Show(0,0,'H');	
	while (1);
}