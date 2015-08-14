#include "ds1302.h"

#define uchar unsigned char
#define uint unsigned int

sbit DS1302_SCLK = P2^2;
sbit DS1302_IO = P2^1;
sbit DS1302_RST = P2^0;

void write1Byte(uchar address) {
	unsigned int i;
	for(i=8; i>0; i--){
		DS1302_IO = address&0x01;////取address的最低位
		DS1302_SCLK = 1;
		DS1302_SCLK= 0;
		address >>= 1; //相当于汇编中的 RRC
	}
}

uchar readDS1302() {
	unsigned char i;
	unsigned char da = 0;

	for(i = 0; i < 8; i++) { //读数据
		DS1302_SCLK = 0;  //一拉低就能读取数据了
		if(DS1302_IO) //读走数据
			da |=  0x01 << i;
		DS1302_SCLK = 1;
	}
	return (da);
}

void wirteData(uchar address, uchar value) {
	DS1302_RST = 0;
	DS1302_SCLK = 0;
	DS1302_RST = 1;
	write1Byte(address); // 地址，命令
	write1Byte(value); // 写1Byte数据
	DS1302_SCLK = 1;
	DS1302_RST= 0;
}

uchar readData(uchar address) {
	unsigned char data_;
	DS1302_RST = 0;
	DS1302_SCLK = 0;
	DS1302_RST = 1;
	write1Byte(address);
	data_ = readDS1302();
	DS1302_SCLK = 1;
	DS1302_RST  = 0;
	
//	data_ = data_/16*10 + data_ % 16;

	return (data_);
}

void DS1302Init() {
	wirteData(0x8E,0x00);//打开保护，是寄存器可读可写
	wirteData(0x84,0x00);//时寄存器全部置零,是计时器变为24小时制

	//写数据 min h date month day year
	wirteData(0x82,0x00);
	wirteData(0x84,0x12);
	wirteData(0x86,0x23);
	wirteData(0x88,0x12);
	wirteData(0x8a,0x05);
	wirteData(0x8c,0x11);//11年 因为这个芯片只有年的后面两位

	wirteData(0x80,0x00); //秒位全部置零,启动时钟
	//向DS1302的ram中写一个数，表示DS1302已经被启动了
	wirteData(0x8E,0x80);//关闭保护
}

void DS1302SetTime (unsigned char *time) {//一个字符数组 数据从小到大
	//写数据sec min h date month day year
	char i,t;
	unsigned char address = 0x80;

	wirteData(0x8E,0x00);//打开保护，是寄存器可读可写

	for(i = 0; i < 7; i++) {
		t = *time;
		t =  t / 10 * 16 + t % 10; //转码
		wirteData(address,t);
		time ++;
		address += 2;
	}
	wirteData(0x8E,0x80);//关闭保护
}

void DS1302GetTime (unsigned char *time) {//一个字符数组
	char i;
	unsigned char address = 0x81;

	for(i = 0; i < 7; i++) {
		*time = readData(address);//读取的时间为BCD码,这里需要转码
		*time = *time/16*10 + *time%16;
		time ++;
		address += 2;
	}
}

