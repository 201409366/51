#include "lcd1602.h"
#include "reg52.h"

sbit lcdenable = P1^0;
sbit lcdRS = P1^2;
sbit lcdRW = P1^1;
	
void lcd1602_writeData (unsigned char x, unsigned char y, unsigned char d);
void lcd1602_init ();

static void lcd1602_writeCommand(unsigned char c);
static void lcd1602Delay(unsigned int i);

LCD1602 lcd1602 = {
	lcd1602_writeData,
	lcd1602_init
};

static void lcd1602Delay(unsigned int i) { //ʵ����0.001�����ʱ	
	unsigned int x,j;	
	for(j=0;j<i;j++) {
		for(x=0;x<=148;x++) {
		}	
	}
}

static void lcd1602_writeCommand(unsigned char c) {
	//RS = LΪдָ��״̬,RS = H Ϊд����״̬
	lcdRS = 0;	 //����Һ��Ϊд����״̬
	lcdRW = 0;	//����Ϊд״̬
	P0 = c;	//������
	lcd1602Delay(5);  //�����ֲ�,��ʱһ���
	//��һ��������,��������Ч�ı�����
	lcdenable = 1; 
	lcd1602Delay(5);
	lcdenable = 0;
}

void lcd1602_writeData (unsigned char x, unsigned char y, unsigned char d) {
	//RS = LΪдָ��״̬,RS = H Ϊд����״̬
	if(y == 0) //���û��postion == -1,˵��û������λ��.��û�ͽ�����һ�εĵ�ַд
		lcd1602_writeCommand(0x80 + x);	
	if(y == 1)
		lcd1602_writeCommand(0x80 + 0x40 + x);	
	
	lcdRS = 1;	 //����Һ��Ϊд����״̬
	lcdRW = 0;	//����Ϊд״̬
	P0 = d;	//������
	lcd1602Delay(5);  //�����ֲ�,��ʱһ���
	//��һ��������,��������Ч�ı�����
	lcdenable = 1; 
	lcd1602Delay(5);
	lcdenable = 0;	
}


void lcd1602_init () {
	//��ʼ���ܵĻ���			   
	lcdenable = 0;//��Һ���ܽ����ź�
	lcd1602_writeCommand(0x38);//����16x02��ʾ,8λ���ݿ�
	lcd1602_writeCommand(0x01);//�����ǰ��ʾ������
	lcd1602_writeCommand(0x0c);//������ʾ:��;���:��ʾ���:��;��˸:��
	lcd1602_writeCommand(0x06);//��дһ���ַ���ַ:�Զ���һ;�Զ�����:��  
	lcd1602_writeCommand(0x80);//���õ�ַΪ��һ���ַ���
}


