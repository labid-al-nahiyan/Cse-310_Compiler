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
	lea si,number
	mov bx,10
	add si,4
	cmp ax,0
	jnge negate
print:
	xor dx,dx
	div bx
	mov [si],dl
	add [si],0
	dec si
	cmp ax,0
	jne print
	inc si
	lea dx,si
	mov ah,9
	int 21h
pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	negate:
	push ax
	mov ah,2
	mov dl,'-'
	int 21h
	pop ax
	neg ax	
jmp print
	printnumber ENDP

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
;i=1
	MOV AX,1
	MOV i, AX
;println(i)
	MOV AX,i

	CALL printnumber
	CALL NEWLINE
;j=5+8
	MOV AX,5
	MOV DX,AX
	MOV AX,8
	ADD DX,AX
	PUSH DX
	POP AX ;always keep first part of expression in AX then move it to DX
	MOV j, AX
;println(j)
	MOV AX,j

	CALL printnumber
	CALL NEWLINE
;k=i+j
;i
	MOV AX,i
	MOV DX,AX
;j
	MOV AX,j
	ADD DX,AX
	PUSH DX
	POP AX ;always keep first part of expression in AX then move it to DX
	MOV [BP-2],AX
;println(k)
	MOV AX,[BP-2]

	CALL printnumber
	CALL NEWLINE
;n=m++
;m
	MOV AX,[BP-6]
	PUSH AX
	INC AX
	MOV [BP-6],AX
	POP AX
	MOV [BP-8],AX
;println(n)
	MOV AX,[BP-8]

	CALL printnumber
	CALL NEWLINE
;o=i
;i
	MOV AX,i
	MOV [BP-10],AX
;println(o)
	MOV AX,[BP-10]

	CALL printnumber
	CALL NEWLINE
;p=n==o
;n==o
;n
	MOV AX,[BP-8]
	PUSH AX
;o
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
;println(p)
	MOV AX,[BP-12]

	CALL printnumber
	CALL NEWLINE
;p=n<o
;n<o
;n
	MOV AX,[BP-8]
	PUSH AX
;o
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
;println(p)
	MOV AX,[BP-12]

	CALL printnumber
	CALL NEWLINE
	ADD SP,12
	MOV AH, 4CH
	INT 21H
main ENDP
END main
