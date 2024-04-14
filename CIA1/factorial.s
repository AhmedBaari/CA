	area factorial, code, readonly
start
	LDR r0, =0x40000000
	LDR r1, [r0] ; Get the number
	
	MOV r5, #1 ; the storage of X for X * (n-1)
	
loop
	CMP r1, #1
	BLE stop ; STOP condition - 1
	
	MUL r5, r1, r5 ; X * (n-1)
	SUB	r1, r1, #1 ; Reduce n by -1 -> (n-1)
	
stop
	STR r5, [r0,#4]
	end
	
L	B	L