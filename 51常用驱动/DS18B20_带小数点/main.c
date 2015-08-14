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
	unsigned int d = 0;
	float temp = 0;
	initUart();

	while(1) {
		d = getTemperatur();
		temp = d * 0.0625; //得到真实十进制温度值，因为DS18B20 	
		//可以精确到0.0625度，所以读回数据的最低位代表的是0.0625度。
		d = temp*10  + 0.5;   	//放大十倍，这样做的目的将小数点后第一位也转换为可显示数字，同时进行一个四舍五入操作。
		UartSendByte(d);
		d >>= 8;
		UartSendByte(d);
	   delay(100);
	}
}