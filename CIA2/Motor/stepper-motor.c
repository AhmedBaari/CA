#include <LPC214x.h>

// i is for motor.
/*
1 bit = 1.8 degree

0x0000100
*/

unsigned int i;
void delay () {
	int a,b;
	for (a = 0; a < 10000; a++);
	for (b = 0; b < 10000; b++);
}

int main () {
	unsigned int i;
	
	// No. of iterations 
	int a = 200;
	
	// Use same pins as light
	IODIR0 = 0x00000000;
	

	
	// i should start with 24th bit (and go till 16th)
	i = 0x00100000;
	
	while(a) {
		//send to motor
		IOSET0 = i;
		delay(); // Wait for rotation
		
		// Clear all
		IOCLR0 = 0x00FF0000;
		
		// Right shift 
		i = i >> 1;
		
		// Check if beyond last (24) bit
		if(i == 0x00001000) {
			// go back to 16th bit
			i = 0x00100000;
		}
	// Decrement a
	a = a-1;
	}
	
}
