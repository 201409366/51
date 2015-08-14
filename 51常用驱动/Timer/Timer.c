#include "timer.h"

static void init1 ();
static void init2 ();

Timer_T timer1;
timer1.init = init1;

Timer_T timer2;
timer2.init = init2;

Timer timer = {
	timer1,
	timer2
};

void init1 () {
	TMOD = 0x01;//这个等效于GATE=0 ,C/T=0,M0M1=01
	TH0=(65536 - timer1.period)/256;//计数器装初值
	TL0=(65536 - timer1.period)%256;
	EA=1;//打开中断总开关
	ET0=1;//打开定时器中断
	TR0=1;//第一个计时器开始计时	
}

void init2 () {
	TMOD = 0x01;//这个等效于GATE=0 ,C/T=0,M0M1=01
	TH1=(65536 - timer2.period)/256;//计数器装初值
	TL1=(65536 - timer2.period)%256;
	EA=1;//打开中断总开关
	ET1=1;//打开定时器中断
	TR1=1;//第一个计时器开始计时	
}
