#include "l298.h"

//正传函数
void foreward() {//接out1
	en1 = 1;
	in1 = 1;
	in2 = 0;				
}

//翻转函数
void reverse() {
	en2 = 1;
	in3 = 0;
	in4 = 1;
}

//停止函数	
void stop() {
	en1 = 0;
	en2 = 0;
}


