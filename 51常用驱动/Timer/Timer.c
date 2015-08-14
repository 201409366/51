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
	TMOD = 0x01;//�����Ч��GATE=0 ,C/T=0,M0M1=01
	TH0=(65536 - timer1.period)/256;//������װ��ֵ
	TL0=(65536 - timer1.period)%256;
	EA=1;//���ж��ܿ���
	ET0=1;//�򿪶�ʱ���ж�
	TR0=1;//��һ����ʱ����ʼ��ʱ	
}

void init2 () {
	TMOD = 0x01;//�����Ч��GATE=0 ,C/T=0,M0M1=01
	TH1=(65536 - timer2.period)/256;//������װ��ֵ
	TL1=(65536 - timer2.period)%256;
	EA=1;//���ж��ܿ���
	ET1=1;//�򿪶�ʱ���ж�
	TR1=1;//��һ����ʱ����ʼ��ʱ	
}
