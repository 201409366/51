#ifndef LCD1602_H
#define LCD1602_H

typedef struct {
	
	void (* show) (unsigned char x, unsigned char y, unsigned char d);
	void (* init) ();

} LCD1602;

extern LCD1602 lcd1602;

#endif