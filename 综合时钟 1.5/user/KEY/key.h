#ifndef __KEY_H__
#define __KEY_H__

#include <reg52.h>

typedef struct {
	unsigned char (* getKey) ();
} KEY;

extern KEY key;

#endif
