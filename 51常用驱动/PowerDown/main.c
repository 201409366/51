#include "reg52.h"
#include "Power.h"

void main() {
	while(1){
		P0 = 0xff;
		if(getResetMode() == 0x10) {//如果上电复位就直接进入掉电模式
			clearReset();	//记得清零标识位
			P0 &= 0xfe;
			enterPowerDown();
			P0 &= 0x00;
		} else
			P0 &= 0xfb;
		while(1);
	}
}

/*
//掉电过后不管是中断还是按键复位都是从程序头执行，而不是像文档里面写那样。继续执行

注意如果要用中断唤醒程序的话，需要开启中断

如果不用的中断唤醒的话，记得删除  enterPowerDown 函数里面开启中断的程序段
*/