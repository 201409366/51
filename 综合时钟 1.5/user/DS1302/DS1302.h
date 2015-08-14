#ifndef DS1302_H
#define DS1302_H

#include <reg52.h>

#define uchar unsigned char
#define uint unsigned int

typedef struct {
	void (* setTime) (unsigned char *time);
	void (* getTime) (unsigned char *time);
	void (* init) ();	
} DS1302;

extern DS1302 ds1302;

#endif