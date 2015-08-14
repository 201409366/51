#include "lcd12864.h"

void main () {

	lcd12864Init();
	lcd12864Show(0,0,'N');
	lcd12864Show(0,1,'H');
	lcd12864Show(0,2,'!');

	while(1);
}