;******************************************************************************
; The ft_isalpha() function tests for any character for which ft_isupper or 
; ft_islower is true.  The value of the argument must be representable as 
; an unsigned char or the value of EOF.
; The ft_isalpha() function returns zero if the character tests false and 
; returns non-zero if the character tests true.
; prototype:
; int			ft_isalpha(int c);
;******************************************************************************

section	.text
	global _ft_isalpha
	extern _ft_isupper
	extern _ft_islower
	
_ft_isalpha:
	push		rbp
	mov		rbp, rsp

	mov		rax, 0			; reset ret value
	call		_ft_isupper		; call ft_isupper
	cmp		rax, 1			; check if the char is uppercase
	je		true_statement		; if so, then the statement is true

	mov		rax, 0			; reset ret value
	call		_ft_islower		; call ft_islower
	cmp		rax, 1			; check if the char is lowercase
	je		true_statement		; if so, then the statement is true

	mov		rax, 0			; none of the statements is true so ret = 0
	jmp		exit_process		; return

	true_statement:				; one of the statements is true so ret = 1
		mov	rax, 1

	exit_process:				
		leave
		ret
