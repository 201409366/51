#ifndef IR_H
#define IH_H

typedef struct {
	unsigned char (*dat);
	unsigned char (*flag);
	void (* init) ();
}IR_T;

extern IR_T ir;

#endif