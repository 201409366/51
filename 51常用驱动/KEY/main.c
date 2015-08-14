#include "key.h"
#include "reg52.h"

void main() {
	unsigned char k = 0;
	while (1) {		
		k = getKey();
		if(k != 0) {
			P0 = k;
		}
	}
}