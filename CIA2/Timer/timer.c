#include <LPC214x.h>

void pll() {
	// 60 hz
	PLL0CFG = 0x24;
	
	// Connected, disabled
	PLL0CON = 0x01;
	
	// Feed
	PLL0FEED = 0XAA;
	PLL0FEED = 0X55;
	
	// Enable
	PLL0CON = 0x03; // 11
	
	// ?
	while(!(PLL0STAT & (1 << 10)));
	
	// Feed
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	// VPBDIV, probably for peripherals
	VPBDIV = 0x01; // needed?
	
	
}

/* Timer Based Delay */
void delay(unsigned int z) {
	// timer mode
	T0CTCR = 0x0;
	
	// timer disable
	T0TCR = 0x0;
	
	// Prescale value
	T0PR = 59999;
	
	// timer enable
	T0TCR = 0x01;
	
	while(T0TC < z); // keep going till z
	
	T0TCR = 0x0; //disable
	
	T0TC = 0x0; //reset tc
	
}

int main () {
	PINSEL1 = 0X0;
	IODIR1 = 0x00FF0000;
	IOCLR1 = 0xFF0000;
	
	
	pll();
	
	while (1) {
		IOSET1 = 0X00FF0000;
		delay(200);
		IOCLR1 = 0X00FF0000;
		delay(200);
	}
	
}
