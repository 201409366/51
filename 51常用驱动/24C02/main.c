#include "24C02.h"

void delay (unsigned int time)  {//ʵ����0.01�����ʱ	
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
		 delay(1);//�ǵ��м�Ҫ��ͣ��
		num = readData(3);
		//��ʾ
		P0 = num;
		while(1);		
	}
}
