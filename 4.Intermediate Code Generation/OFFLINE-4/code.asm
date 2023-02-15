main PROC
	MOV AX,@DATA
	MOV DS,AX
	PUSH BP
	PUSH AX
	PUSH DX
	PUSH CX
	MOV BP,SP
	SUB SP,2
	SUB SP,2
	SUB SP,2
	SUB SP,2
	SUB SP,2
	SUB SP,2
	MOV AX,[BP-2]
	MOV AX,0
	MOV [BP-2],AX

	L1:
	MOV AX,[BP-2]
	PUSH AX
	MOV AX,10
	MOV DX, AX
	POP AX
	CMP AX,DX
	JL L2

JMP L3

	L2:
	PUSH AX
	MOV AX,[BP-2]

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,[BP-6]
	MOV AX,0
	MOV [BP-6],AX

	L4: 
	MOV AX,[BP-6]
	PUSH AX
	MOV AX,5
	MOV DX, AX
	POP AX
	CMP AX,DX
	JL L6

JMP L7

	L5:
	MOV AX,[BP-6]
	PUSH AX
	INC AX
	MOV [BP-6],AX
	POP AX

	JMP L4
L6: 
	PUSH AX
	MOV AX,[BP-6]

	CALL printnumber
	CALL NEWLINE
	POP AX
	ADD SP,0
JMP L5
	
L7:
	MOV AX,[BP-2]
	PUSH AX
	INC AX
	MOV [BP-2],AX
	POP AX
	ADD SP,0

	 JMP L1
L3:
	ADD SP,12

	POP CX
	POP DX
	POP AX
	POP BP
		MOV AH, 4CH
	INT 21H
main ENDP
END main
.MODEL SMALL
.STACK 500H
.DATA
	number DB "00000$"
	i DW 0
	j DW 0
.CODE

NEWLINE PROC
	PUSH AX
	PUSH DX
	MOV AH,2
	MOV DL,0DH
	INT 21h
	MOV AH,2
	MOV DL,0AH
	INT 21h
	POP DX
	POP ax
	RET
NEWLINE ENDP

printnumber proc  ;print what is in ax
	push ax
	push bx
	push cx
	push dx
	push si
	mov CX,0
	mov DX,0
	label1:
	cmp ax,0
	je print1

	;initialize bx to 10
	mov bx,10
	;extract last digit
	div bx
	;push it in the stack
	push dx
	;inc the count
	inc cx
	;set dx to 0
	xor dx,dx
	jmp label1

	print1:
	;check if count is greater than zero
	cmp cx,0
	je exit
	;pop the top of stack
	pop dx
	;add 48 to represent the ascii
	add dx,48
	;print a char
	mov ah,02h
	int 21h
	dec cx
	jmp print1
	exit:
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret
printnumber ENDP

