	area sumseries,code,readonly
start
	
	LDR R0, =0X40000000
	LDR r1, [r0] ; count
	
	MOV r5, #0
	
loop	
	ADD r6, r6, #1
	ADD r5,r5,r6
	
	SUBS r1,r1, #1
	BEQ L
	B loop
	
L	B	L
	end