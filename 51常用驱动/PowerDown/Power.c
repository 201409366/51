#include "Power.h"

#define uchar unsigned char
#define uint unsigned int

unsigned char getResetMode() {
	return PCON &  0x10;
}

void enterPowerDown () {
	EA = 1;//打开中断总开关
	EX1 = 1;//打开外部中断1
	IT0 = 0;//当IT0=0时，为电平触发方式(低电平)	
	PCON |= 0x02;
}

void exitPowerDown () {
	PCON ^= 0x02;
}

void clearReset() {
	PCON &=  0xef;
}