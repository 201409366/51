#ifndef IR_SEND_H
#define IR_SEND_H

#include <reg52.h>

/**
 * sendCode: 通过红外二极管发送数据
 * 
 * 
 * void : 无返回值
 */
void sendCode(unsigned char syscode,unsigned char keydat);

#endif