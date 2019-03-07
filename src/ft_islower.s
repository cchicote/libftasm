;******************************************************************************
; The ft_islower() function tests for any lower-case letters.  The value of the 
; argument must be representable as an unsigned char or the value of EOF.
; The ft_islower() function returns zero if the character tests false and 
; returns non-zero if the character tests true.
; prototype:
; int			ft_islower(int c);
;******************************************************************************

section	.text
	global _ft_islower
	
_ft_islower:
	push		rbp
	mov		rbp, rsp

	cmp		rdi, 97			; if (c < 97)
	jl		false_statement		; jump to false_statement
		
	cmp		rdi, 122		; if (c > 122)
	jg		false_statement		; jump to false_statement

	mov		rax, 1			; ret = 1
	jmp		exit_process		; return

	false_statement:			; called only if (c < 97 || c > 122)
		mov	rax, 0			; ret = 0

	exit_process:				
		leave
		ret
