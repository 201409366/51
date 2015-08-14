#include "machine.h"

#define uchar unsigned char
#define uint unsigned int

unsigned char code F_Rotation[8]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};    //˳ʱ��ת��� 1.0--1.3
unsigned char code B_Rotation[8]={0x09,0x08,0x0c,0x04,0x6,0x02,0x03,0x01};    //��ʱ��ת���

void delay_machine(unsigned i) {
	unsigned char x,j;
	for(j=0;j<i;j++)
	for(x=0;x<=135;x++);	
}

 //��ʱ��ת��
void fStep() {
	uchar i;
	for(i = 0; i < 8; i++) {     		//��Ϊ��8·�Ŀ���ʱ��
		P1 = F_Rotation[i];  
		delay_machine(2);
	}			
}

//��ʱ��ת��
void bStep() {
	uchar i;
	for(i = 0; i < 8; i++) {     		//��Ϊ��8·�Ŀ���ʱ��
		P1 = B_Rotation[i];  
		delay_machine(2);
	}		
}