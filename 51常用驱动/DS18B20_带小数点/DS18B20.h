#ifndef DS18B20_H
#define DS18B20_H
#include <reg52.h>

/**
 * getTemperatur : ��ȡ��ǰ�¶�
 * 
 *
 * 	�����¶���Ҫת��	temp = d * 0.0625; //�õ���ʵʮ�����¶�ֵ����ΪDS18B20 	
		//���Ծ�ȷ��0.0625�ȣ����Զ������ݵ����λ�������0.0625�ȡ�
 */
unsigned int getTemperatur ();


#endif