;******************************************************************************
; The isascii() function tests for an ASCII character, which is any character 
; between 0 and octal 0177 inclusive.
; prototype:
; int			ft_isascii(int c);
;******************************************************************************

section	.text
	global _ft_isascii
	
_ft_isascii:
	push		rbp
	mov		rbp, rsp

	cmp		rdi, 0			; if (c < 0)
	jl		false_statement		; jump to false_statement
		
	cmp		rdi, 127		; if (c > 127)
	jg		false_statement		; jump to false_statement

	mov		rax, 1			; ret = 1
	jmp		exit_process		; return

	false_statement:			; called only if (c < 0 || c > 127)
		mov	rax, 0			; ret = 0

	exit_process:				
		leave
		ret
