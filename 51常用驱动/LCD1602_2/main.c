#include "lcd1602.h"

void main () {

	initLcd1602();		
	lcd1602ShowString( 0, 0, " ID:            " );	
	while (1);
}