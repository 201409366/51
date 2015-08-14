#ifndef UART_H
#define UART_H
#include <reg52.h>

/**
 * initUart : ��ʼ������
 * 
 *
 * void : �޷���ֵ
 */
void initUart ();

/**
 * UartSendByte : ͨ�����ڷ���һ���ֽ�
 * value	: Ҫ���͵�����
 *
 * void : �޷���ֵ
 */
void UartSendByte (unsigned char value);

/**
 * UartReadByte : ͨ�����ڶ�ȡһ���ֽ�
 * 
 *
 * ���ض�ȡ��������   unsigned char ����
 */
unsigned char UartReadByte();

#endif

/*
//д�ж�
void handler() interrupt 4 {
//�ж�����һ��5��
flag = 1;
P0 = SBUF;
_data = P0;
   RI = 0;
 
}
*/

/*
printf();�÷�
ES = 0;
TI = 1;
printf("abc");
while(!TI);
ES = 1;
*/