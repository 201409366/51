#include "ir.h"
#include "reg52.h"
#include "uart.h"

unsigned char readData [4];

void main() {

	initIR();
	initUart();
	while (1) {

	}
}

void delay_IR(unsigned char x)  {   //x*0.14MS
	unsigned char i;
	while(x--) {
		for (i = 0; i<13; i++) {}
	}
}


void IRHandle() interrupt 2 {
/*����ǽ��������������ļ��뱻�ŵ���readData[2]����*/
	unsigned char j,k,N=0;

	EX1 = 0; //�ر��ⲿ�ж�1  
	delay_IR(15);//��ʱ15*0.14MS=2.1ms

	if (IR==1) { //�����ʱIRΪ��˵��ʲô�أ�������һ��ʼӦ����9ms�ĵ͵�ƽ
		EX1 =1;//�ź�û�г��֣����ء�����Ǹ���
		return;
	} 
	//ȷ��IR�źų���
	while (!IR) { //��IR��Ϊ�ߵ�ƽ������9ms��ǰ���͵�ƽ�źš�           
		delay_IR(1);//��ʱ0.14ms
	}						
	
	for (j=0;j<4;j++)  {       //�ռ���������	 
		for (k=0;k<8;k++) {       //ÿ��������8λ
			while (IR) {           //�� IR ��Ϊ�͵�ƽ������4.5ms��ǰ���ߵ�ƽ�źš�
				delay_IR(1);
			}
			while (!IR) {         //�� IR ��Ϊ�ߵ�ƽ
				delay_IR(1);
			}
			while (IR) {          //����IR�ߵ�ƽʱ��
				delay_IR(1);
				N++;           
				if (N>=30) {//������ж���,����ǧ�����Ϊ��һ�μ�ֻ������һ��
					EX1=1;
					return;
				}                  //0.14ms���������Զ��뿪��
			}                        //�ߵ�ƽ�������     		    
			//���ݴ���       
			readData[j]=readData[j] >> 1; //������λ
			if (N>=8) { //8*0.14 = 1.12  ������������ʱ�䣬��λΪ1
				readData[j] |= 0x80;
			}  
			N=0;
		}//end for k
	}//end for j
	
	if (readData[2] == ~readData[3]) {	 //������֤��Ϊ�˱�֤����ɹ�
		//����ֱ�������������߼�����
		UartSendByte(readData[2]);
	}
	EX1 = 1; 
}

