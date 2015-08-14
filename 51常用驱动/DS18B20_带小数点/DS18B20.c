#include <reg52.h>
#include "DS18B20.h"
#include <intrins.h>//这个东西里面有_nop_这个函数

#define uchar unsigned char

sbit DS18B20_DQ = P2^7;

//--------------------------------DS18B20--------------------------

void flash(uchar i) {
	while(-- i);
}

bit ResetDS18B20() {//返回0说明正常
	DS18B20_DQ = 1;
	DS18B20_DQ = 0;
	flash(247);
	DS18B20_DQ = 1;
	flash(27);
	if(DS18B20_DQ == 0) {
		while(DS18B20_DQ == 0);//等待DQ被拉高
		return 0;
	}
	return 1;
	
}

void writeDS18B20(uchar d) {
	uchar i = 0;
	for(i = 0; i < 8; i ++)
		{
			DS18B20_DQ = 1;
			DS18B20_DQ = 0;
			flash(5);			
			DS18B20_DQ = d & 0x01;
			flash(20);
			DS18B20_DQ = 1;
			d >>= 1;
		}
}

uchar readDS18B20 () {
	uchar i = 0;   //就一个初始化的问题。。。困扰我这么久。。。。。fuck
	uchar d = 0;
	for(i = 0; i < 8; i ++) {
		DS18B20_DQ = 1;
		DS18B20_DQ = 0;
		flash(1);//7us
		DS18B20_DQ = 1;
		flash(1);
		if(DS18B20_DQ) {//读数据
			d |= 0x01 << i;
		}
		flash(17);//45us
		DS18B20_DQ = 1;
		_nop_();
	}
	return d;
}

unsigned int getTemperatur() {
	uchar tempL;
	uchar tempH;
	unsigned int temperature;//temperature
	
	ResetDS18B20();	//DS18B20复位
	writeDS18B20(0xCC);	//跳过ROM 0xcc
	writeDS18B20(0x44);	//开始温度转换
	ResetDS18B20();	//DS18B20复位
	writeDS18B20(0xCC);		//跳过ROM
	writeDS18B20(0xBE);	//读取温度值.因为温度值在暂存器里面。所以我们读取暂存器里面的东西。
	//因为发了读取指令过去，所以暂存器里面的东西会全部给我们发过来.根据它的结构，
	//我们只要连续读两次
	tempL = readDS18B20();	//先读低8位数据
	tempH = readDS18B20();	//再读高8位数据
	//合成温度数据.可以看存储结构图想到算法

	temperature =  tempH;
	temperature <<= 8;
	temperature |= tempL;//得到整数部分
	//温度显示

	return temperature;
}
