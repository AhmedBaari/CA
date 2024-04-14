	area evenodd, code, readonly
start
	LDR r0, =0x40000000
	LDR r1, [r0, #0x4]!
	
	AND r2,r1,#1
	
	STR R2, [R0]
	end
L	B L