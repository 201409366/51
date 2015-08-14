#ifndef __KEY_H__
#define __KEY_H__

#include <reg52.h>

/**
 * getKey : 获取当前按下按键
 * 
 * 
 * 返回当前按下的键码; unsigned char 类型; 0为没有按键按下
 */
unsigned char getKey ();

#endif
