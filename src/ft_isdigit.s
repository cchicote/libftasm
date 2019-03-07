;******************************************************************************
; The ft_isdigit() function tests for a decimal digit character.
; The ft_isdigit() function returns zero if the character tests false and 
; returns non-zero if the character tests true.
; prototype:
; int			ft_isdigit(int c);
;******************************************************************************

section	.text
	global _ft_isdigit
	
_ft_isdigit:
	push		rbp
	mov		rbp, rsp

	cmp		rdi, '0'		; if (c < '0')
	jl		false_statement		; jump to false_statement
		
	cmp		rdi, '9'		; if (c > '9')
	jg		false_statement		; jump to false_statement

	mov		rax, 1			; ret = 1
	jmp		exit_process		; return

	false_statement:			; called only if (c < '0' || c > '9')
		mov	rax, 0			; ret = 0

	exit_process:				
		leave
		ret
