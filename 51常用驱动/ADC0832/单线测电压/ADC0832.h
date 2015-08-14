#ifndef ADC0832_H
#define ADC0832_H

#include "reg52.h"

/**
 * ADC0832ReadInfo : 从adc0832芯片里面读取数据
 * 返回读取到的数据  unsigned char 类型 具体电压需要转换 x/255*VCC
 */
unsigned char ADC0832ReadInfo ();

#endif