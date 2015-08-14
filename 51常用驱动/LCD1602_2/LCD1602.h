#ifndef LCD1602_H
#define LCD1602_H

/**
 * lcd1602Show : 在lcd1602上面显示字符
 * x	: x地址
 * y 	: y地址
 * d	: 要显示的字符
 * void : 无返回值
 */
void lcd1602Show(unsigned char x, unsigned char y, unsigned char d);

/**
 * initLcd1602 : 初始化lcd1602

 * void : 无返回值
 */
void initLcd1602();

/**
 * lcd1602Show : 在lcd1602上面显示字符
 * x	: x地址
 * y 	: y地址
 * d	: 要显示的字符
 * void : 无返回值
 */
void lcd1602ShowString(unsigned char x, unsigned char y, unsigned char *s);

#endif