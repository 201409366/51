#include "led.h"
#include "reg52.h"

void light (unsigned char no) {//ʵ��
	P0 = (~no) & P0;	
}

void blow (unsigned char no) {
	P0 = no | P0;
}