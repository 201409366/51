#include "ir.h"

//unsigned char readData [4];

void initIR() {
	EA = 1;//打开中断总开关
	EX1 = 1;//打开外部中断1
	IT0 = 0;//当IT0=0时，为电平触发方式(低电平)		
}
