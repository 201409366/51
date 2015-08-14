#ifndef POWER_H
#define POWER_H

#include "reg52.h"

/**
 * enterPowerDown : 进入掉电模式
 * 
 * 
 * void : 无返回值
 */
void enterPowerDown ();

/**
 * exitPowerDown : 退出掉电模式
 * 
 * 
 * void : 无返回值
 */
void exitPowerDown ();

/**
 * getResetMode : 获取复位方式
 * 
 * 
 * 返回复位方式 0x10 上电复位
 */
unsigned char getResetMode();

/**
 * clearReset : 清零复位标识位
 * 
 * 
 * void : 无返回值
 */
void clearReset();

#endif
