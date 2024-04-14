// some confusion about pinsel and iodir points

#include <LPC214x.h>

void delay() {
	int i,j;
	for(i=0;i<1000;i++);
	for(j=0;j<1000;j++);
}
int main () {
	
	PINSEL0 = 0x0;
	PINSEL1 = 0x0;
	PINSEL2 = 0x0;
	IODIR0 = 0x0;
	IODIR1 = 0x00FF0000; // Light
	
	while (1) {
		// Checking for input from pin
		// PIN 15
		if(IO0PIN & 0x00008000) {
			IOSET1  = 0x00550000;
			delay();
			IOCLR1 = 0x00550000;
			delay();
		} else {
			IOSET1  = 0x00aa0000;
			delay();
			IOCLR1 = 0x00aa0000;
			delay();
		}
	}
	
	return 0;
}
