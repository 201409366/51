#include "l298.h"

//��������
void foreward() {//��out1
	en1 = 1;
	in1 = 1;
	in2 = 0;				
}

//��ת����
void reverse() {
	en2 = 1;
	in3 = 0;
	in4 = 1;
}

//ֹͣ����	
void stop() {
	en1 = 0;
	en2 = 0;
}


