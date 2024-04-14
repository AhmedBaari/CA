	area bubble, code, readonly
start
	
	LDR r0, =0x40000000
	; get number of elements
	LDR r1, [r0] ; POST
	
	; We will have 1 lesser iterations
	SUB r1,r1, #1

	; r1 = I
	; r2 = J

OUTER
	MOV r2,r1 ; J counter
	
	LDR r0, =0x40000004 ; Runner
	
INNER
	LDR r4, [r0], #0x4
	LDR r5, [r0]
	
	CMP r4, r5
	BLE continue
	
	; SWAP
	STR r4, [r0]
	STR r5, [r0,#-0x4]
	
continue
	; decrement J
	SUBS R2, R2, #1
	BNE INNER
	
	; Decrement I
	SUBS R1,R1, #1
	BNE OUTER
	
L	B	L
	end