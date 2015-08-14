#include "24c02.h"

#define uchar unsigned char
#define uint unsigned int

sbit at24c02_SCL = P1^2;
sbit at24c02_SDA = P1^3;

void delay() { //空方法，空循环，对于11.0592MHz的晶振大概延时5us
	;;//两个;表示两个nop
}

void getResponseMessage() {
	//第9个时钟时，等待at24c02_SDA变为0.表示at24c02给了pc一个应答。
	//如果时间超过一定时间。也默认at24c02也受到了数据。我们可以继续发数据
	uchar i;
	at24c02_SCL = 1;//在高电平期间读取信号
	delay();
	while((at24c02_SDA == 1) && (i < 250)) {	  //等待应答
		i ++;
	}
	at24c02_SCL = 0;//时钟拉低，表示第9个结束
	delay();
}

void sendStartMessage () {
	at24c02_SDA = 1;
	delay();
	at24c02_SCL = 1;
	delay();
	at24c02_SDA = 0;
	delay();
}

void sendStopMessage () {
	at24c02_SDA = 0;
	delay();
	at24c02_SCL = 1;
	delay();
	at24c02_SDA = 1;
	delay();
}

void writeByte(uchar d) {
	uchar i,t;
	t = d;
	for(i = 0; i < 8; i++) {
		t = t<<1;
		at24c02_SCL = 0;//为后面的跳变做准备
		at24c02_SDA = CY;//先给数据，因为在跳变的瞬间at24c02读走数据
		delay();//延时确保数据到位
		at24c02_SCL = 1;//跳变，通知at24c02读走数据
		delay();//延时确保数据被读走
	}
	at24c02_SCL = 0;
	delay();
}


uchar readByte() {
	uchar i,d,t;
	at24c02_SCL = 0;//准备时钟,方便后面拉高给高电平
	//开始读数据
	for(i = 0; i < 8;i++) {
		delay();
		at24c02_SCL = 1;//拉高后表示可以读数据
		delay();//确保at24c02接受到信号
		d=d<<1;
		t = at24c02_SDA;
		at24c02_SCL = 0;//数据读取完成
		d = d|t;//0|0=0,0|1=1,1|0=1,1|1=1   这样，我们就可以把要返回的t和接受到的数据连接起来了
	}
	return d;
}


void writeData(uchar address,uchar d) {
	sendStartMessage();
	writeByte(0xa0);//写I2C设备的地址，即我们板子上面的芯片AT24C02
	
	getResponseMessage();//等待应答
	writeByte(address);//写磁盘的地址，即在AT24C02存储数据的地址，
	//我们的芯片是2k的，只要地址空间不超过这个值就可以了

	getResponseMessage();
	writeByte(d);//这里我们才能写我们的数据，

	getResponseMessage();
	sendStopMessage();
	delay();//方便别的函数能直接执行
}

uchar readData(uchar address) {
	uchar d;
	sendStartMessage();
	writeByte(0xa0);//寻址
	
	getResponseMessage();
	writeByte(address);

	getResponseMessage();
	sendStartMessage();
	writeByte(0xa1);//寻址

	getResponseMessage();
	d = readByte();

	delay();
	sendStopMessage();
	delay();//方便别的函数能直接执行
	return d;
}

