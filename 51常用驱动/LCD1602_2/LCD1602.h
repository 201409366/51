#ifndef LCD1602_H
#define LCD1602_H

/**
 * lcd1602Show : ��lcd1602������ʾ�ַ�
 * x	: x��ַ
 * y 	: y��ַ
 * d	: Ҫ��ʾ���ַ�
 * void : �޷���ֵ
 */
void lcd1602Show(unsigned char x, unsigned char y, unsigned char d);

/**
 * initLcd1602 : ��ʼ��lcd1602

 * void : �޷���ֵ
 */
void initLcd1602();

/**
 * lcd1602Show : ��lcd1602������ʾ�ַ�
 * x	: x��ַ
 * y 	: y��ַ
 * d	: Ҫ��ʾ���ַ�
 * void : �޷���ֵ
 */
void lcd1602ShowString(unsigned char x, unsigned char y, unsigned char *s);

#endif