#ifndef DS18B20_H
#define DS18B20_H
#include <reg52.h>

/**
 * getTemperatur : 获取当前温度
 * 
 *
 * 	具体温度需要转换	temp = d * 0.0625; //得到真实十进制温度值，因为DS18B20 	
		//可以精确到0.0625度，所以读回数据的最低位代表的是0.0625度。
 */
unsigned int getTemperatur ();


#endif