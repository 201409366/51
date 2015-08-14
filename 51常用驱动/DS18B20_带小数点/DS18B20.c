#include <reg52.h>
#include "DS18B20.h"
#include <intrins.h>//�������������_nop_�������

#define uchar unsigned char

sbit DS18B20_DQ = P2^7;

//--------------------------------DS18B20--------------------------

void flash(uchar i) {
	while(-- i);
}

bit ResetDS18B20() {//����0˵������
	DS18B20_DQ = 1;
	DS18B20_DQ = 0;
	flash(247);
	DS18B20_DQ = 1;
	flash(27);
	if(DS18B20_DQ == 0) {
		while(DS18B20_DQ == 0);//�ȴ�DQ������
		return 0;
	}
	return 1;
	
}

void writeDS18B20(uchar d) {
	uchar i = 0;
	for(i = 0; i < 8; i ++)
		{
			DS18B20_DQ = 1;
			DS18B20_DQ = 0;
			flash(5);			
			DS18B20_DQ = d & 0x01;
			flash(20);
			DS18B20_DQ = 1;
			d >>= 1;
		}
}

uchar readDS18B20 () {
	uchar i = 0;   //��һ����ʼ�������⡣������������ô�á���������fuck
	uchar d = 0;
	for(i = 0; i < 8; i ++) {
		DS18B20_DQ = 1;
		DS18B20_DQ = 0;
		flash(1);//7us
		DS18B20_DQ = 1;
		flash(1);
		if(DS18B20_DQ) {//������
			d |= 0x01 << i;
		}
		flash(17);//45us
		DS18B20_DQ = 1;
		_nop_();
	}
	return d;
}

unsigned int getTemperatur() {
	uchar tempL;
	uchar tempH;
	unsigned int temperature;//temperature
	
	ResetDS18B20();	//DS18B20��λ
	writeDS18B20(0xCC);	//����ROM 0xcc
	writeDS18B20(0x44);	//��ʼ�¶�ת��
	ResetDS18B20();	//DS18B20��λ
	writeDS18B20(0xCC);		//����ROM
	writeDS18B20(0xBE);	//��ȡ�¶�ֵ.��Ϊ�¶�ֵ���ݴ������档�������Ƕ�ȡ�ݴ�������Ķ�����
	//��Ϊ���˶�ȡָ���ȥ�������ݴ�������Ķ�����ȫ�������Ƿ�����.�������Ľṹ��
	//����ֻҪ����������
	tempL = readDS18B20();	//�ȶ���8λ����
	tempH = readDS18B20();	//�ٶ���8λ����
	//�ϳ��¶�����.���Կ��洢�ṹͼ�뵽�㷨

	temperature =  tempH;
	temperature <<= 8;
	temperature |= tempL;//�õ���������
	//�¶���ʾ

	return temperature;
}
