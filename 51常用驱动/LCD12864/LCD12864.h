#ifndef LCD12864_H
#define LCD12864_H


/**
 * lcd12864Init : ��ʼ��lcd1286

 * void : �޷���ֵ
 */
void lcd12864Init();

/**
 * lcd12864Show : ��lcd1286������ʾ�ַ�
 * x	: x��ַ
 * y 	: y��ַ
 * data_	: Ҫ��ʾ���ַ�
 * void : �޷���ֵ
 */
void lcd12864Show(unsigned char x, unsigned char y, unsigned char data_);

#endif