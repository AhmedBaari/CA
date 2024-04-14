#include <LPC214x.h>

void pll() {
	PLL0CFG = 0x24;// Freq
	PLL0CON = 0x01;// Connect
	
	//Feed
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	// Enable
	PLL0CON = 0x03;//Enable
	while( !(PLL0STAT & (1 << 10) ) );
	
	//Feed
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;	
	
	//peripheral
	VPBDIV = 0x1;
	
}

void uart () { 
	// Alternate Function 1
	PINSEL0 = 0x5;
	
	// Enable Divisor latch lock
	U0LCR = 0x83;
	
	// Set Latch
	U0DLM = 0x1;
	U0DLL= 0x87;
	
	// Disable divisor Latch lock
	U0LCR = 0x03;
	
}

/* Receive */
char rx() {
	// character
	unsigned char c;
	
	// wait for RDR: Recieve data ready
	while ( (U0LSR & (1<<0))==0 );
	c = U0RBR;
	
	return c;
	
}

void tx(unsigned char c) {

	// Wait till THRE
	while((U0LSR &(1 << 5))==0);
	
	// Set the THR
	U0THR = c;
}

int main () {
	unsigned char c;
	pll();
	uart();
	
	while(1) {
	c = rx();
	tx(c);
	}
	
}