#ifndef LCD12864_H
#define LCD12864_H


/**
 * lcd12864Init : 初始化lcd1286

 * void : 无返回值
 */
void lcd12864Init();

/**
 * lcd12864Show : 在lcd1286上面显示字符
 * x	: x地址
 * y 	: y地址
 * data_	: 要显示的字符
 * void : 无返回值
 */
void lcd12864Show(unsigned char x, unsigned char y, unsigned char data_);

#endif