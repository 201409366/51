#include "l298.h"

void delay(unsigned int i) { //ʵ����0.001�����ʱ
	unsigned int x,j;	
	for(j=0;j<i;j++) {
		for(x=0;x<=148;x++) {
		}	
	}
}

void main() {
	while(1) {
		foreward();
		delay(5000);
		reverse();
		delay(5000);
		stop();
		delay(5000);	
	}
}