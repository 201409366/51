#include "uart.h"
#include "reg52.h"
#include <stdio.h>

void main() {
	unsigned char d = 0;
	initUart();

	while(1) {
		d = UartReadByte();
		UartSendByte(d);
	}
}