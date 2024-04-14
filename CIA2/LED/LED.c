#include <LPC214x.h>

void delay() {
	int i, j;
	for (i = 0; i < 500; i++);
	for (j = 0; j < 500; j++);	
};

int main () {
	
	PINSEL0 = 0x0;
	IO1DIR = 0x0;
	
	while (1) {
		IO1SET = 0x00FF0000;
		delay();
		IO1CLR = 0xFFFFFFFF;
		delay();
	}
	return 0;
}
