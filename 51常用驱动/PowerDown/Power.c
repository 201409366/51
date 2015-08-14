#include "Power.h"

#define uchar unsigned char
#define uint unsigned int

unsigned char getResetMode() {
	return PCON &  0x10;
}

void enterPowerDown () {
	EA = 1;//���ж��ܿ���
	EX1 = 1;//���ⲿ�ж�1
	IT0 = 0;//��IT0=0ʱ��Ϊ��ƽ������ʽ(�͵�ƽ)	
	PCON |= 0x02;
}

void exitPowerDown () {
	PCON ^= 0x02;
}

void clearReset() {
	PCON &=  0xef;
}