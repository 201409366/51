#include "ds1302.h"

#define uchar unsigned char
#define uint unsigned int

sbit DS1302_SCLK = P2^2;
sbit DS1302_IO = P2^1;
sbit DS1302_RST = P2^0;

static void write1Byte(uchar address);
static uchar readDS1302();
static void wirteData(uchar address, uchar value);
static uchar readData(uchar address);

void init_ds1302(); 
void setTime (unsigned char *time);	 //����ʱ���ʱ�� �ǵ�ת��
void getTime (unsigned char *time);

DS1302 ds1302 = {
	setTime,
	getTime,
	init_ds1302
};

static void write1Byte(uchar address) {
	unsigned int i;
	for(i=8; i>0; i--){
		DS1302_IO = address&0x01;////ȡaddress�����λ
		DS1302_SCLK = 1;
		DS1302_SCLK= 0;
		address >>= 1; //�൱�ڻ���е� RRC
	}
}

static uchar readDS1302() {
	unsigned char i;
	unsigned char da = 0;

	for(i = 0; i < 8; i++) { //������
		DS1302_SCLK = 0;  //һ���;��ܶ�ȡ������
		if(DS1302_IO) //��������
			da |=  0x01 << i;
		DS1302_SCLK = 1;
	}
	return (da);
}

static void wirteData(uchar address, uchar value) {
	DS1302_RST = 0;
	DS1302_SCLK = 0;
	DS1302_RST = 1;
	write1Byte(address); // ��ַ������
	write1Byte(value); // д1Byte����
	DS1302_SCLK = 1;
	DS1302_RST= 0;
}

static uchar readData(uchar address) {
	unsigned char data_;
	DS1302_RST = 0;
	DS1302_SCLK = 0;
	DS1302_RST = 1;
	write1Byte(address);
	data_ = readDS1302();
	DS1302_SCLK = 1;
	DS1302_RST  = 0;
	
//	data_ = data_/16*10 + data_ % 16;

	return (data_);
}

void init_ds1302() {
		
	if(readData(0x81) == 0x80) {//���û�г�ʼ���ͽ��г�ʼ�� 
		wirteData(0x8E,0x00);//�򿪱�����ʹ�Ĵ����ɶ���д
		wirteData(0x84,0x00);//ʱ�Ĵ���ȫ������,�Ǽ�ʱ����Ϊ24Сʱ��
		
		//д���� min h date month day year
		wirteData(0x82,0x45);
		wirteData(0x84,0x08);
		wirteData(0x86,0x21);
		wirteData(0x88,0x12);
		wirteData(0x8a,0x05);
		wirteData(0x8c,0x12);//11�� ��Ϊ���оƬֻ����ĺ�����λ
		
		wirteData(0x80,0x00); //��λȫ������,����ʱ��
		//��DS1302��ram��дһ��������ʾDS1302�Ѿ���������
		wirteData(0x8E,0x80);//�رձ���
	}
	
}

void setTime (unsigned char *time) {//һ���ַ����� ���ݴ�С����
	//д����sec min h date month day year
	char i,t;
	unsigned char address = 0x80;

	wirteData(0x8E,0x00);//�򿪱������ǼĴ����ɶ���д

	for(i = 0; i < 7; i++) {
		t = *time;
		t =  t / 10 * 16 + t % 10; //ת��
		wirteData(address,t);
		time ++;
		address += 2;
	}
	wirteData(0x8E,0x80);//�رձ���
}

void getTime (unsigned char *time) {//һ���ַ�����
	char i;
	unsigned char address = 0x81;

	for(i = 0; i < 7; i++) {
		*time = readData(address);//��ȡ��ʱ��ΪBCD��,������Ҫת��
		*time = *time/16*10 + *time%16;
		time ++;
		address += 2;
	}
}

