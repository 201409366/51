#ifndef POWER_H
#define POWER_H

#include "reg52.h"

/**
 * enterPowerDown : �������ģʽ
 * 
 * 
 * void : �޷���ֵ
 */
void enterPowerDown ();

/**
 * exitPowerDown : �˳�����ģʽ
 * 
 * 
 * void : �޷���ֵ
 */
void exitPowerDown ();

/**
 * getResetMode : ��ȡ��λ��ʽ
 * 
 * 
 * ���ظ�λ��ʽ 0x10 �ϵ縴λ
 */
unsigned char getResetMode();

/**
 * clearReset : ���㸴λ��ʶλ
 * 
 * 
 * void : �޷���ֵ
 */
void clearReset();

#endif
