#include "24C02.h"

void delay (unsigned int time)  {//实现了0.01秒的延时	
	unsigned int i,j;
	for(i = 0; i < time; i++) {
		for(j = 0; j < 125; j++) {
		}
	} 
	
}

void main() {
	while(1) {
		unsigned char num;
		writeData(3,0xaa);
		 delay(1);//记得中间要暂停下
		num = readData(3);
		//显示
		P0 = num;
		while(1);		
	}
}
