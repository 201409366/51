#ifndef UART_H
#define UART_H
#include <reg52.h>

/**
 * initUart : 初始化串口
 * 
 *
 * void : 无返回值
 */
void initUart ();

/**
 * UartSendByte : 通过串口发送一个字节
 * value	: 要发送的数据
 *
 * void : 无返回值
 */
void UartSendByte (unsigned char value);

/**
 * UartReadByte : 通过串口读取一个字节
 * 
 *
 * 返回读取到的数据   unsigned char 类型
 */
unsigned char UartReadByte();

#endif

/*
//写中断
void handler() interrupt 4 {
//中断种类一个5个
flag = 1;
P0 = SBUF;
_data = P0;
   RI = 0;
 
}
*/

/*
printf();用法
ES = 0;
TI = 1;
printf("abc");
while(!TI);
ES = 1;
*/