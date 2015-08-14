#include <reg52.h>
#include "adc0832.h"

#define uchar unsigned char
#define uint unsigned int

sbit led0 = P2^6;
sbit led1 = P2^5;
sbit led2 = P2^4;
sbit led3 = P2^7;
//无点
unsigned char code numbers[10] = {0x5f,0x0a,0x9d,0xd5,0xc6,0xd3,0xdb,0x45,0xdf,0xd7};

//有点
unsigned char code numbers2[10] = {0x5f,0x0a,0x9d,0xd5,0xc6,0xd3,0xdb,0x45,0xdf,0xd7};

void delay(unsigned int i) { //实现了0.001秒的延时
	
	unsigned int x,j;
	
	for(j=0;j<i;j++) {
		for(x=0;x<=148;x++) {
		}	
	}
}

void main() {
	uchar i;
	uint r;

	r = ADC0832ReadInfo() * 215;

	while(1) {
		//显示第一位
		led0 = 0; 
		P0 = numbers2[r/10000];
		delay(4);
		led0 = 1;
		//显示第二位
		led1 = 0;
		P0 = numbers[r/1000%10];
		delay(4);
		led1 = 1;
		//显示第三位
		led2 = 0;
		P0 = numbers[r%100/100];
		delay(4);
		led2 = 1;	
		//显示第四位
		led3 = 0;
		P0 = numbers[r%10000];
		delay(4);
		led3 = 1;

	if(i > 20) {
			r =  ADC0832ReadInfo()* 215;
			i = 0;
		}
		i++;
	}
}