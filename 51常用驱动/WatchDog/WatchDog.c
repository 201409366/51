#include "WatchDog.h"

sfr WDT_CONTR = 0XE1;  

void launchDog () { //11.0592MHz复位时间大概是1.1377s
	WDT_CONTR = 0x34;   
	/* 0011,0100   
	EN_WDT = 1,   看门狗启动  
	CLR_WDT = 1,  看门狗清零  
	IDLE_WDT = 0, 看门狗定时器在“空闲模式”时不计数  
	PS2 = 1,  32分频  
	PS1 = 0,   
    PS0 = 0*/  
}
void feedDog () {
	WDT_CONTR &= 0x10; 
}