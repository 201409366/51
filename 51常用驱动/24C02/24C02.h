#ifndef AT24C02_H
#define AT24C02_H

#include "reg52.h"

/**
 * writeData : ��24c02��д����
 * address	: ���ݵ�ַ
 * dat 	: Ҫд�������
 * void : �޷���ֵ
 */
void  writeData (unsigned char address, unsigned char dat);

/**
 * readData : ��24c02������
 * address	: ��ȡ���ݵĵ�ַ
 * ���ض�ȡ�������� unsigned char ����
 */
unsigned char readData (unsigned char address);


#endif