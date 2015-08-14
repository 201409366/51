#include <reg52.h>
#include "uart.h"

void initUart() {
	PCON = 0x00; //ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50; //8λ����,�ɱ䲨����
	TMOD &= 0x0f; //�����ʱ��1ģʽλ
	TMOD |= 0x20; //�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	
	TL1 = 0xFD; //�趨��ʱ��ֵ
	TH1 = 0xFD; //�趨��ʱ����װֵ
	
	ET1 = 0; //��ֹ��ʱ��1�ж�
	TR1 = 1; //������ʱ��1
	ES = 1;
	EA = 1;
}

void UartSendByte (unsigned char value) {
	ES = 0;
	SBUF = value;
	while(!TI);
	TI = 0;	//�ǵ�Ҫ����,��Ȼ�ᷢ������
	ES = 1;
}

unsigned char UartReadByte () {
	unsigned char d;
	while(RI != 1);
	d = SBUF;
	RI = 0;
	return (d);
}