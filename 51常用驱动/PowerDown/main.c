#include "reg52.h"
#include "Power.h"

void main() {
	while(1){
		P0 = 0xff;
		if(getResetMode() == 0x10) {//����ϵ縴λ��ֱ�ӽ������ģʽ
			clearReset();	//�ǵ������ʶλ
			P0 &= 0xfe;
			enterPowerDown();
			P0 &= 0x00;
		} else
			P0 &= 0xfb;
		while(1);
	}
}

/*
//������󲻹����жϻ��ǰ�����λ���Ǵӳ���ͷִ�У����������ĵ�����д����������ִ��

ע�����Ҫ���жϻ��ѳ���Ļ�����Ҫ�����ж�

������õ��жϻ��ѵĻ����ǵ�ɾ��  enterPowerDown �������濪���жϵĳ����
*/