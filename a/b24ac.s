	area aswini, code, readonly
start
	;b2-4ac
	;a,b,c
	;r1 = a, r2= b, r3=c
	LDR r0, =0x40000000
	
	; Load r1,r2,r3
	LDM r0!,{r1-r3}
	
	MUL r4, r2,r2 ;b^2
	MUL r3, r1,r3 ; ac
	; When using 3 reg, LSL cannot be used
	LSL r3, #2 ; 4ac
	
	SUB r3,r4,r3 ; b^2 - 4ac 
	
	
	LSR r3,r1; 

	STR r3, [r0] 

L	B	L
	end