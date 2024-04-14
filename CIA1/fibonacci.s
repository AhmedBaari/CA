	area fibonacci, code, readonly
start
	; base
	LDR r0, =0x40000000
	
	; Get no. of elements
	LDR r1, [r0] ; r1 = count
	
	MOV r4,#0 ; A
	MOV r5, #1 ; B
	
	; A, B, A+B
loop
	ADD r7,r4,r5 ;  C = A + B
	MOV r4,r5; new A = B
	MOV r5,r7 ; new B = A+B
	
	SUBS r1,r1,#1
	BEQ L
	
	B loop
	
	
L	B	L
	end