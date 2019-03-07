;******************************************************************************
; The isprint() function tests for any printing character, including 
; space (` '). The value of the argument must be representable as an unsigned
; char or the value of EOF.
; The ft_isprint() function returns zero if the character tests false and 
; returns non-zero if the character tests true.
; prototype:
; int			ft_isprint(int c);
;******************************************************************************

section	.text
	global _ft_isprint
	
_ft_isprint:
	push		rbp
	mov		rbp, rsp

	cmp		rdi, 32			; if (c < 32)
	jl		false_statement		; jump to false_statement
		
	cmp		rdi, 126		; if (c > 126)
	jg		false_statement		; jump to false_statement

	mov		rax, 1			; ret = 1
	jmp		exit_process		; return

	false_statement:			; called only if (c < 32 || c > 126)
		mov	rax, 0			; ret = 0

	exit_process:				
		leave
		ret
