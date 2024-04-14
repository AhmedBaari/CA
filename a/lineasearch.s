	area aswini, code, readonly
baari
	; Base Address
	LDR r0, =0x40000000
	;mov r0, #0x40000000
	
	LDR r1, [r0],#0x4 ; Number of elements
	
	LDR r2, [r0],#0x4 ; Target

		; r6 stores result
loop
	; Get an element
	LDR r3, [r0],#0x4 ; r3 = current
	CMP r2,r3
	
	BEQ found
	
	SUBS r1,r1,#1
	BEQ notfound
	B loop
	
found
	mov r6,#0x1
	
notfound B notfound
	end