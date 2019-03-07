;******************************************************************************
; The ft_tolower() function converts a lower-case letter to the corresponding 
; lower-case letter. The value of the argument must be representable as an 
; unsigned char or the value of EOF.
; If the argument is a lower-case letter, the tolower() function returns 
; the corresponding lower-case letter if there is one; otherwise, the 
; argument is returned unchanged.
; prototype:
; int			ft_tolower(int c);
;******************************************************************************

section	.text
	global _ft_tolower
	extern _ft_isupper
	
_ft_tolower:
	push		rbp
	mov		rbp, rsp

	mov		rax, 0			; reset ret value
	call		_ft_isupper		; call ft_isupper
	cmp		rax, 1			; check if the char is uppercase
	je		true_statement		; if so, then the statement is true

	mov		rax, rdi		; the char is not uppercase
	jmp		exit_process		; return the given char

	true_statement:				; one of the statements is true so ret = 1
		mov	rax, rdi		; store the char to ret
		add	rax, 32			; add 32 to the char to make it uppercase

	exit_process:				
		leave
		ret
