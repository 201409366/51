#include "24c02.h"

#define uchar unsigned char
#define uint unsigned int

sbit at24c02_SCL = P1^2;
sbit at24c02_SDA = P1^3;

void delay() { //�շ�������ѭ��������11.0592MHz�ľ�������ʱ5us
	;;//����;��ʾ����nop
}

void getResponseMessage() {
	//��9��ʱ��ʱ���ȴ�at24c02_SDA��Ϊ0.��ʾat24c02����pcһ��Ӧ��
	//���ʱ�䳬��һ��ʱ�䡣ҲĬ��at24c02Ҳ�ܵ������ݡ����ǿ��Լ���������
	uchar i;
	at24c02_SCL = 1;//�ڸߵ�ƽ�ڼ��ȡ�ź�
	delay();
	while((at24c02_SDA == 1) && (i < 250)) {	  //�ȴ�Ӧ��
		i ++;
	}
	at24c02_SCL = 0;//ʱ�����ͣ���ʾ��9������
	delay();
}

void sendStartMessage () {
	at24c02_SDA = 1;
	delay();
	at24c02_SCL = 1;
	delay();
	at24c02_SDA = 0;
	delay();
}

void sendStopMessage () {
	at24c02_SDA = 0;
	delay();
	at24c02_SCL = 1;
	delay();
	at24c02_SDA = 1;
	delay();
}

void writeByte(uchar d) {
	uchar i,t;
	t = d;
	for(i = 0; i < 8; i++) {
		t = t<<1;
		at24c02_SCL = 0;//Ϊ�����������׼��
		at24c02_SDA = CY;//�ȸ����ݣ���Ϊ�������˲��at24c02��������
		delay();//��ʱȷ�����ݵ�λ
		at24c02_SCL = 1;//���䣬֪ͨat24c02��������
		delay();//��ʱȷ�����ݱ�����
	}
	at24c02_SCL = 0;
	delay();
}


uchar readByte() {
	uchar i,d,t;
	at24c02_SCL = 0;//׼��ʱ��,����������߸��ߵ�ƽ
	//��ʼ������
	for(i = 0; i < 8;i++) {
		delay();
		at24c02_SCL = 1;//���ߺ��ʾ���Զ�����
		delay();//ȷ��at24c02���ܵ��ź�
		d=d<<1;
		t = at24c02_SDA;
		at24c02_SCL = 0;//���ݶ�ȡ���
		d = d|t;//0|0=0,0|1=1,1|0=1,1|1=1   ���������ǾͿ��԰�Ҫ���ص�t�ͽ��ܵ�����������������
	}
	return d;
}


void writeData(uchar address,uchar d) {
	sendStartMessage();
	writeByte(0xa0);//дI2C�豸�ĵ�ַ�������ǰ��������оƬAT24C02
	
	getResponseMessage();//�ȴ�Ӧ��
	writeByte(address);//д���̵ĵ�ַ������AT24C02�洢���ݵĵ�ַ��
	//���ǵ�оƬ��2k�ģ�ֻҪ��ַ�ռ䲻�������ֵ�Ϳ�����

	getResponseMessage();
	writeByte(d);//�������ǲ���д���ǵ����ݣ�

	getResponseMessage();
	sendStopMessage();
	delay();//�����ĺ�����ֱ��ִ��
}

uchar readData(uchar address) {
	uchar d;
	sendStartMessage();
	writeByte(0xa0);//Ѱַ
	
	getResponseMessage();
	writeByte(address);

	getResponseMessage();
	sendStartMessage();
	writeByte(0xa1);//Ѱַ

	getResponseMessage();
	d = readByte();

	delay();
	sendStopMessage();
	delay();//�����ĺ�����ֱ��ִ��
	return d;
}

