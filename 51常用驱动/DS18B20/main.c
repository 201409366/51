#include "uart.h"
#include "reg52.h"
#include "DS18B20.h"
#include <stdio.h>

void delay (unsigned int time)  {//ʵ����0.01�����ʱ

	unsigned int i,j;
	 for(i = 0; i < time; i++) {
	 	for(j = 0; j < 1872; j++) {
		}
	 } 

}

void main() {
	unsigned char d = 0;
	initUart();

	while(1) {
		d = getTemperatur();
		UartSendByte(d);
	   delay(100);
	}
}