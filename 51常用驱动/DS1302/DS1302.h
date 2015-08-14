#ifndef DS1302_H
#define DS1302_H

#include <reg52.h>

#define uchar unsigned char
#define uint unsigned int

/**
 * DS1302SetTime: 设置时间
 * *time	: 时间数据，格式参考main.c
 * void : 无返回值
 */
void DS1302SetTime(unsigned char *time);

/**
 * DS1302GetTime:读取时间
 * *time	: 时间数据，格式参考main.c
 * void : 无返回值
 */
void DS1302GetTime(unsigned char *time);

/**
 * DS1302Init:初始化
 *
 * void : 无返回值
 */
void DS1302Init();	

#endif