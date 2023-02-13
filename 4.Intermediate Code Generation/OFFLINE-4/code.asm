main PROC
	MOV AX,@DATA
	MOV DS,AX
	PUSH BP
	MOV BP,SP
	SUB SP,2
	SUB SP,2
	SUB SP,2
	SUB SP,2
	SUB SP,2
	SUB SP,2
	MOV AX,i
	MOV AX,1
	MOV i, AX
	PUSH AX
	MOV AX,i

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,j
	MOV AX,5
	MOV DX,AX
	MOV AX,8
	ADD DX,AX
	PUSH DX
	POP AX ;always keep first part of expression in AX then move it to DX
	MOV j, AX
	PUSH AX
	MOV AX,j

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,[BP-2]
	MOV AX,i
	MOV DX,AX
	MOV AX,j
	ADD DX,AX
	PUSH DX
	POP AX ;always keep first part of expression in AX then move it to DX
	MOV DX,AX
	MOV AX,[BP-10]
	ADD DX,AX
	PUSH DX
	POP AX ;always keep first part of expression in AX then move it to DX
	MOV [BP-2],AX
	PUSH AX
	MOV AX,[BP-2]

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,[BP-8]
	MOV AX,[BP-6]
	PUSH AX
	INC AX
	MOV [BP-6],AX
	POP AX
	MOV [BP-8],AX
	PUSH AX
	MOV AX,[BP-8]

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,[BP-10]
	MOV AX,i
	MOV [BP-10],AX
	PUSH AX
	MOV AX,[BP-10]

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,[BP-12]
	MOV AX,[BP-8]
	PUSH AX
	MOV AX,[BP-10]
	MOV DX, AX
	POP AX
	CMP AX,DX
	JE L1
	JMP L2
L1:
	MOV AX , 1
	JMP L3
L2:
	MOV AX , 0
L3:
	MOV [BP-12],AX
	PUSH AX
	MOV AX,[BP-12]

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,[BP-12]
	MOV AX,[BP-8]
	PUSH AX
	MOV AX,[BP-10]
	MOV DX, AX
	POP AX
	CMP AX,DX
	JL L4
	JMP L5
L4:
	MOV AX , 1
	JMP L6
L5:
	MOV AX , 0
L6:
	MOV [BP-12],AX
	PUSH AX
	MOV AX,[BP-12]

	CALL printnumber
	CALL NEWLINE
	POP AX
	MOV AX,0
	ADD SP,12
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

