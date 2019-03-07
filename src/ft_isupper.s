;******************************************************************************
; The ft_isupper() function tests for any upper-case letter.  The value of the 
; argument must be representable as an unsigned char or the value of EOF.
; The ft_isupper() function returns zero if the character tests false and 
; returns non-zero if the character tests true.
; prototype:
; int			ft_isupper(int c);
;******************************************************************************

section	.text
	global _ft_isupper
	
_ft_isupper:
	push		rbp
	mov		rbp, rsp

	cmp		rdi, 65			; if (c < 65)
	jl		false_statement		; jump to false_statement
		
	cmp		rdi, 90			; if (c > 90)
	jg		false_statement		; jump to false_statement

	mov		rax, 1			; ret = 1
	jmp		exit_process		; return

	false_statement:			; called only if (c < 65 || c > 90)
		mov	rax, 0			; ret = 0

	exit_process:				
		leave
		ret
