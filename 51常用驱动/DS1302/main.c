#include <reg52.h>
#include "LCD1602.h"

#include "ds1302.h"
#include "uart.h"
#include <stdio.h>

#define uchar unsigned char
#define uint unsigned int


uchar time [7] = {0x00,0x50,0x16,0x14,0x10,0x07,0x12};

uchar code num [] = "0123456789";
uchar y[] = "2012/10/14";
uchar t[] = "17:01:00";

void delay(unsigned int i) { //实现了0.001秒的延时	
	unsigned int x,j;	
	for(j=0;j<i;j++) {
		for(x=0;x<=148;x++) {
		}	
	}
}

void main() {
	uchar i;

	DS1302Init();
	initLcd1602();
	initUart();

	DS1302SetTime(time);

	for(i = 3; i < 13; i++) {
		lcd1602Show(i,0,y[i-3]);	
	}

	for(i = 4; i < 12; i++) {
		lcd1602Show(i,1,t[i - 4]);	
	}

	while(1) {
		DS1302GetTime(time);

		lcd1602Show(11,1,num[time[0] % 10]);
		lcd1602Show(10,1,num[time[0] / 10]);		
		lcd1602Show(8,1,num[time[1] % 10]);
		lcd1602Show(7,1,num[time[1] / 10]);
		lcd1602Show(5,1,num[time[2] % 10]);
		lcd1602Show(4,1,num[time[2] / 10]);

		lcd1602Show(12,0,num[time[3] % 10]);
		lcd1602Show(11,0,num[time[3] / 10]);		
		lcd1602Show(9,0,num[time[4] % 10]);
		lcd1602Show(8,0,num[time[4] / 10]);
		lcd1602Show(6,0,num[time[6] % 10]);
		lcd1602Show(5,0,num[time[6] / 10]);						

		UartSendByte(time[0]);
		UartSendByte(time[1]);
		UartSendByte('\t');
		delay(100);
	}

}

 