#include "WatchDog.h"

sfr WDT_CONTR = 0XE1;  

void launchDog () { //11.0592MHz��λʱ������1.1377s
	WDT_CONTR = 0x34;   
	/* 0011,0100   
	EN_WDT = 1,   ���Ź�����  
	CLR_WDT = 1,  ���Ź�����  
	IDLE_WDT = 0, ���Ź���ʱ���ڡ�����ģʽ��ʱ������  
	PS2 = 1,  32��Ƶ  
	PS1 = 0,   
    PS0 = 0*/  
}
void feedDog () {
	WDT_CONTR &= 0x10; 
}