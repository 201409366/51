#include "uart.h"
#include "reg52.h"
#include "DS18B20.h"
#include <stdio.h>

void delay (unsigned int time)  {//ʵ����0.01�����ʱ

	unsigned int i,j;
	 for(i = 0; i < time; i++) {
	 	for(j = 0; j < 1872; j++) {
		}
	 } 

}

void main() {
	unsigned int d = 0;
	float temp = 0;
	initUart();

	while(1) {
		d = getTemperatur();
		temp = d * 0.0625; //�õ���ʵʮ�����¶�ֵ����ΪDS18B20 	
		//���Ծ�ȷ��0.0625�ȣ����Զ������ݵ����λ�������0.0625�ȡ�
		d = temp*10  + 0.5;   	//�Ŵ�ʮ������������Ŀ�Ľ�С������һλҲת��Ϊ����ʾ���֣�ͬʱ����һ���������������
		UartSendByte(d);
		d >>= 8;
		UartSendByte(d);
	   delay(100);
	}
}