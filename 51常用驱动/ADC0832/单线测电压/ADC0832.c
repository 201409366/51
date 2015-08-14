#include "adc0832.h"

#define uchar unsigned char
#define uint unsigned int

sbit ADC0832CS = P1^4;
sbit ADC0832CLK = P1^5;
sbit ADC0832D0_D1 = P1^6;

uchar ADC0832ReadInfo() {
	uchar i = 0;
	uchar Value1 = 0;
	uchar Value2 = 0;
	

	
	ADC0832CS = 1;//关掉AD;
	ADC0832CLK = 0;
	ADC0832D0_D1 = 0;
	
	ADC0832CS = 0;//开启芯片
	
	ADC0832D0_D1 = 1;//开始位
	ADC0832CLK = 0;
	ADC0832CLK = 1;
	
	ADC0832D0_D1 = 1;//并分/单通首
	ADC0832CLK =0;
	ADC0832CLK = 1;
	
	ADC0832D0_D1 = 0;//通首选择位
	ADC0832CLK = 0;
	ADC0832CLK = 1;
	
	ADC0832D0_D1 = 1;//空闲位
	ADC0832CLK = 0;
	ADC0832CLK = 1;
	
	for(i = 0;i <8 ;i++)			//读第一次数据
	{
		ADC0832CLK = 1;
		ADC0832CLK = 0;
		if(ADC0832D0_D1)
		{
			Value1 |= 0x80 >> i;
		}
	}
	
	for(i = 0; i < 8; i++)			//读第二次数据
	{
		if(ADC0832D0_D1)
		{
			Value2 |= 0x01 << i;
		}
		ADC0832CLK = 1;
		ADC0832CLK = 0;
	}
	
	ADC0832CS = 1;					//关掉芯片
	
	if(Value1 == Value2)			//数据校难
	{
		return Value1;
	}
	else
	{
		return 0;
	}
}
