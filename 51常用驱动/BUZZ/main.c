#include "buzz.h"

void delay(unsigned int i) { //ʵ����0.001�����ʱ
	unsigned int x,j;
	for(j=0;j<i;j++) {
		for(x=0;x<=148;x++) {
		}	
	}
}

void main() {
	while(1) {
		noise();
		delay(10);
		quiet();
		delay(10);
	}
}

