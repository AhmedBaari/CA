	area test,code,readonly
start
	LDR r0, =0x40000000
	
	; I want to load r1-r4
	LDMIA r0!, {r1-r4}
	
	; r1 = a, r2 = b, r3 = c, r4 = x
	
	; b * x
	MUL r2,r4,r2;
	
	; bx + c
	ADD r2,r2,r3
	
	; ax
	MUL r1,r4,r1
	
	; ax^2
	MUL r1, r4, r1
	
	; ax^2 + bx + c
	ADD r1,r1,r2
	
	; Store result in mem
	STR r1, [r0]
	
L	B L
	end