#ifndef DS1302_H
#define DS1302_H

#include <reg52.h>

#define uchar unsigned char
#define uint unsigned int

/**
 * DS1302SetTime: ����ʱ��
 * *time	: ʱ�����ݣ���ʽ�ο�main.c
 * void : �޷���ֵ
 */
void DS1302SetTime(unsigned char *time);

/**
 * DS1302GetTime:��ȡʱ��
 * *time	: ʱ�����ݣ���ʽ�ο�main.c
 * void : �޷���ֵ
 */
void DS1302GetTime(unsigned char *time);

/**
 * DS1302Init:��ʼ��
 *
 * void : �޷���ֵ
 */
void DS1302Init();	

#endif