#ifndef AT24C02_H
#define AT24C02_H

#include "reg52.h"

/**
 * writeData : 向24c02中写数据
 * address	: 数据地址
 * dat 	: 要写入的数据
 * void : 无返回值
 */
void  writeData (unsigned char address, unsigned char dat);

/**
 * readData : 从24c02读数据
 * address	: 读取数据的地址
 * 返回读取到的数据 unsigned char 类型
 */
unsigned char readData (unsigned char address);


#endif