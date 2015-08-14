#ifndef WATCHDOG_H
#define WATCHDOG_H

#include "reg52.h"

/**
 * launchDog : 启动看门狗
 * 
 * 
 * void : 无返回值
 */
void launchDog ();	 //11.0592MHz复位时间大概是1.1377s

/**
 * feedDog : 喂狗; //11.0592MHz复位时间大概是1.1377s
 * 
 * 
 * void : 无返回值
 */
void feedDog ();


#endif