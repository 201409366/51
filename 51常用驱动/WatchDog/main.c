#include "reg52.h"
#include "WatchDog.h"
#include "power.h"

void main() {
	while(1){
		launchDog();
		P0 = 0xff;
		if(getResetMode() == 0x10) {
			clearReset();  //记得清零才有效
			P0 &= 0xfe;
		} else
			P0 &= 0xfb;
		while(1);
	}
}