#include "LCD1602/lcd1602.h"
#include "DS1302/DS1302.h"
#include "KEY/key.h"
#include "RS232/RS232.h"
#include "ir/IR.h"
#include <stdio.h>

/*
1.1 用定时器来扫描按键,并加入声音(蜂鸣器)
	更换面向对象形式的驱动

1.2 添加串口调时功能

*/
#define uchar unsigned char

volatile  uchar time [7] = {0x00,0x50,0x16,0x14,0x10,0x07,0x12};
volatile uchar code num [] = "0123456789";
volatile uchar dataIndex = 0;
volatile uchar uartBuff [] = {0x00,0x50,0x16,0x14,0x10,0x07,0x12};
volatile uchar isSetting = 0;

void showTime() {
	lcd1602.show(3,0,num[time[6] % 10]);
	lcd1602.show(2,0,num[time[6] / 10]);//十位

	lcd1602.show(6,0,num[time[4] % 10]);
	lcd1602.show(5,0,num[time[4] / 10]);

 	lcd1602.show(9,0,num[time[3] % 10]);
	lcd1602.show(8,0,num[time[3] / 10]);

	lcd1602.show(15,0,num[time[5] % 10]);

  lcd1602.show(5,1,num[time[2] % 10]);
	lcd1602.show(4,1,num[time[2] / 10]);
	lcd1602.show(8,1,num[time[1] % 10]);
	lcd1602.show(7,1,num[time[1] / 10]);	
	lcd1602.show(11,1,num[time[0] % 10]);//个位
	lcd1602.show(10,1,num[time[0] / 10]);//十位
}

void updateTime() {
	isSetting = 1; //更新时间 
	ds1302.setTime(time);
	isSetting = 0;
	showTime();	
}

void init() {

	rs232.init();
	ds1302.init();
	lcd1602.init();
	ir.init();

	lcd1602.show(0,0,num[2]);
	lcd1602.show(1,0,num[0]);
	lcd1602.show(4,0,'-');//十位	
	lcd1602.show(7,0,'-');//十位
	lcd1602.show(10,0,' ');
	lcd1602.show(11,0,'D');
	lcd1602.show(12,0,'a');
	lcd1602.show(13,0,'y');
	lcd1602.show(14,0,':');
	lcd1602.show(6,1,':');
	lcd1602.show(9,1,':');

	ds1302.getTime(time);
	showTime();	
}

void irHandler() {

	if(*ir.flag == 1) {	
		uchar keyValue;	
		keyValue = *ir.dat;//得到键码
		switch (keyValue) {
			case 0x0c: 
				time[1] ++;	  
				break;
			case 0x18 :
				time[2] ++;
				if(time[2] >= 25)
					time[2] = 0;
				break;
			case 0x5E :
				time[3] ++;
				if(time[3] >= 32)
					time[3] = 0;								 	
				time[5] ++;
				if(time[5] >= 8)
					time[5] = 0;
				break;
			case 0x08 :
				time[4] ++;
				if(time[4] >= 13) {
					time[4] = 0;
					time[6] ++;
				}	
				break;
			case 0x1C :
				time[6] ++;	
				break;
			}

		 updateTime();

		*ir.flag = 0; //标志位置0
	}
}

void keyHandler() {
	uchar keyValue = 0;

	keyValue = key.getKey();
	if(keyValue != 0) {
		switch (keyValue) {
		case 1 : 
			time[1] ++;
			break;
		case 2 :
			time[2] ++;
			if(time[2] >= 25)
				time[2] = 0;
			break;
		case 3 :
			time[3] ++;
			if(time[3] >= 32)
				time[3] = 0;								 	
			time[5] ++;
			if(time[5] >= 8)
				time[5] = 0;
			break;
		case 4 :
			time[4] ++;
			if(time[4] >= 13) {
				time[4] = 0;
				time[6] ++;
			}	
			break;
		}
		updateTime();
	}
}

void main() {
	unsigned int timeScale = 0;
	init();

	while(1) {

		if(timeScale > 12000 && !isSetting) { //更新屏幕的时间
			ds1302.getTime(time);
			showTime();
			dataIndex = 0;//清零串口数据指针，提高纠错能力
		}
		
		irHandler();//接收到红外数据.写在上面，说明优先级比按键高

		keyHandler();

		//时间片
		timeScale++;
		if(timeScale > 12010)
			timeScale = 0;

	}	
}

//串口写中断
void handler() interrupt 4 {
	ES = 0;
	uartBuff[dataIndex] = SBUF;	//yezi--79657a690301

	if(dataIndex >= 5) {	//这里应该还有一个起始位和结束位的。但是由于时间原因就不写了.如果没有起始位和结束位的，出错率很高	
		if(uartBuff[0]=='y'&&uartBuff[1]=='e'&&uartBuff[2]=='z'&&uartBuff[3]=='i') {//验证成功
			time[uartBuff[4]] = uartBuff[5];//设置数据
			if(!isSetting) {
				isSetting = 1;
				ds1302.setTime(time);
				isSetting = 0;
				showTime();
			}
		}
	}

	dataIndex++;
	if(dataIndex > 5)
		dataIndex = 0;
	RI = 0;
	ES = 1;
}