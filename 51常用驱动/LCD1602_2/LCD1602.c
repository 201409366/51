#include "lcd1602.h"
#include "reg52.h"

sbit lcdenable = P1^0;
sbit lcdRS = P1^2;
sbit lcdRW = P1^1;

void lcd1602_writeCommand(unsigned char c);
void lcd1602Delay(unsigned int i);

void lcd1602Delay(unsigned int i) { //实现了0.001秒的延时	
	unsigned int x,j;	
	for(j=0;j<i;j++) {
		for(x=0;x<=148;x++) {
		}	
	}
}

void lcd1602_writeCommand(unsigned char c) {
	//RS = L为写指令状态,RS = H 为写数据状态
	lcdRS = 0;	 //设置液晶为写命令状态
	lcdRW = 0;	//设置为写状态
	P0 = c;	//送数据
	lcd1602Delay(5);  //按照手册,延时一会儿
	//给一个高脉冲,让数据有效的被读走
	lcdenable = 1; 
	lcd1602Delay(5);
	lcdenable = 0;
}

void lcd1602Show(unsigned char x, unsigned char y, unsigned char d) {
	//RS = L为写指令状态,RS = H 为写数据状态
	if(y == 0) //如果没有postion == -1,说明没有设置位置.我没就接着上一次的地址写
		lcd1602_writeCommand(0x80 + x);	
	if(y == 1)
		lcd1602_writeCommand(0x80 + 0x40 + x);	
	
	lcdRS = 1;	 //设置液晶为写数据状态
	lcdRW = 0;	//设置为写状态
	P0 = d;	//送数据
	lcd1602Delay(5);  //按照手册,延时一会儿
	//给一个高脉冲,让数据有效的被读走
	lcdenable = 1; 
	lcd1602Delay(5);
	lcdenable = 0;	
}


void initLcd1602() {
	//初始化总的环境			   
	lcdenable = 0;//是液晶能接收信号
	lcd1602_writeCommand(0x38);//设置16x02显示,8位数据口
	lcd1602_writeCommand(0x01);//清楚当前显示的数据
	lcd1602_writeCommand(0x0c);//设置显示:开;光标:显示光标:开;闪烁:开
	lcd1602_writeCommand(0x06);//读写一个字符地址:自动加一;自动滚屏:否  
	lcd1602_writeCommand(0x80);//设置地址为第一个字符处
}																		   

void lcd1602ShowString(unsigned char x, unsigned char y, unsigned char *s) {
	//RS = L为写指令状态,RS = H 为写数据状态
	if(y == 0) //如果没有postion == -1,说明没有设置位置.我没就接着上一次的地址写
		lcd1602_writeCommand(0x80 + x);	
	if(y == 1)
		lcd1602_writeCommand(0x80 + 0x40 + x);	
	while(*s != 0) {
		lcdRS = 1;	 //设置液晶为写数据状态
		lcdRW = 0;	//设置为写状态
		P0 = *s;	//送数据
		lcd1602Delay(5);  //按照手册,延时一会儿
		//给一个高脉冲,让数据有效的被读走
		lcdenable = 1; 
		lcd1602Delay(5);
		lcdenable = 0;	
		s++;
	}	
}

