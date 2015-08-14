#include "uart.h"
#include "reg52.h"
#include "DS18B20.h"
#include <stdio.h>

void delay (unsigned int time)  {//实现了0.01秒的延时

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