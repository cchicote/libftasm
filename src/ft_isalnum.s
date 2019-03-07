;******************************************************************************
; The ft_isalnum() function tests for any character for which ft_isalpha or 
; ft_isdigit is true.  The value of the argument must be representable as 
; an unsigned char or the value of EOF.
; The ft_isalnum() function returns zero if the character tests false and 
; returns non-zero if the character tests true.
; prototype:
; int			ft_isalnum(int c);
;******************************************************************************

section	.text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit
	
_ft_isalnum:
	push		rbp
	mov		rbp, rsp

	mov		rax, 0			; reset ret value
	call		_ft_isalpha		; call ft_isalpha
	cmp		rax, 1			; check if the char is alphabetical
	je		true_statement		; if so, then the statement is true

	mov		rax, 0			; reset ret value
	call		_ft_isdigit		; call ft_isdigit
	cmp		rax, 1			; check if the char is digit
	je		true_statement		; if so, then the statement is true

	mov		rax, 0			; none of the statements is true so ret = 0
	jmp		exit_process		; return

	true_statement:				; one of the statements is true so ret = 1
		mov	rax, 1

	exit_process:				
		leave
		ret
