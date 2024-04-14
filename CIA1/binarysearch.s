	area binarysearch,code,readonly
start
	; Base address
	LDR r0, =0x40000000
	
	; Get number of elements
	LDRB r1, [r0], #0x1
	
	; Get target
	LDRB r2, [r0], #0x1
	
	MOV r3, #0 ; low = 0
	MOV r4, r1 ; high = no. of elements


loop
	; middle
	; (low + high) / 2
	;   r3    r4
	CMP r3,r4
	BGE L
	ADD r5,r3,r4
	LSR r5,#1
	
	; Get the element
	LDRB r7, [r0,r5]
	
	; Compare
	CMP r2,r7
	BEQ found
	BLT	LEFT
	BGE RIGHT
	

LEFT
	mov r4,r5
	B loop
	
RIGHT
	mov r3,r5
	B loop

found
	mov r6, #1

L	B	L
	end
		
		
;
;
;
;
;