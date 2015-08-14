#include "ir.h"
#include "reg52.h"
#include "uart.h"

unsigned char readData [4];

void main() {

	initIR();
	initUart();
	while (1) {

	}
}

void delay_IR(unsigned char x)  {   //x*0.14MS
	unsigned char i;
	while(x--) {
		for (i = 0; i<13; i++) {}
	}
}


void IRHandle() interrupt 2 {
/*这个是解析函数，按键的键码被放到了readData[2]里面*/
	unsigned char j,k,N=0;

	EX1 = 0; //关闭外部中断1  
	delay_IR(15);//延时15*0.14MS=2.1ms

	if (IR==1) { //如果此时IR为高说明什么呢？好像是一开始应该是9ms的低电平
		EX1 =1;//信号没有出现，返回。这次是干扰
		return;
	} 
	//确认IR信号出现
	while (!IR) { //等IR变为高电平，跳过9ms的前导低电平信号。           
		delay_IR(1);//延时0.14ms
	}						
	
	for (j=0;j<4;j++)  {       //收集四组数据	 
		for (k=0;k<8;k++) {       //每组数据有8位
			while (IR) {           //等 IR 变为低电平，跳过4.5ms的前导高电平信号。
				delay_IR(1);
			}
			while (!IR) {         //等 IR 变为高电平
				delay_IR(1);
			}
			while (IR) {          //计算IR高电平时长
				delay_IR(1);
				N++;           
				if (N>=30) {//这里会有抖动,所以千万别认为按一次键只解码了一次
					EX1=1;
					return;
				}                  //0.14ms计数过长自动离开。
			}                        //高电平计数完毕     		    
			//数据处理       
			readData[j]=readData[j] >> 1; //数据移位
			if (N>=8) { //8*0.14 = 1.12  如果超过了这个时间，该位为1
				readData[j] |= 0x80;
			}  
			N=0;
		}//end for k
	}//end for j
	
	if (readData[2] == ~readData[3]) {	 //这里验证是为了保证解码成功
		//这里直接做解码后面的逻辑处理
		UartSendByte(readData[2]);
	}
	EX1 = 1; 
}

