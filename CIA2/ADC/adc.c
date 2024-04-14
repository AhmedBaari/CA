#include <LPC214x.h>

int main() {
	unsigned int val;

	
	// ADC is in 28th bit
	PINSEL1 = 0x01000000;
	
	// Start Fast IO
	SCS = 0X2; // wrong in PDF
	
	// Masking
	FIO1MASK = 0xFF00FFFF;
	
	// LED output
	FIO1DIR = 0x00FF0000;
	
	// Clear all bits - USE PIN, not SET
	FIO1PIN = 0x00000000;
	
	// Configure ADC - memorize
	AD0CR = 0x00200E02; // X
	
	
	while (1) {
		// Start Conversion
		AD0CR |= 0x01000000;
		
		// do while 
		do {val = AD0DR1;} while ((val & 0x80000000) == 0); // X
		
		FIO1PIN = val << 8; // X
	}

	
}



