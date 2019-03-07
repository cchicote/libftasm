;******************************************************************************
; The ft_toupper() function converts a lower-case letter to the corresponding 
; upper-case letter. The value of the argument must be representable as an 
; unsigned char or the value of EOF.
; If the argument is a lower-case letter, the toupper() function returns 
; the corresponding upper-case letter if there is one; otherwise, the 
; argument is returned unchanged.
; prototype:
; int			ft_toupper(int c);
;******************************************************************************

section	.text
	global _ft_toupper
	extern _ft_islower
	
_ft_toupper:
	push		rbp
	mov		rbp, rsp

	mov		rax, 0			; reset ret value
	call		_ft_islower		; call ft_islower
	cmp		rax, 1			; check if the char is lowercase
	je		true_statement		; if so, then the statement is true

	mov		rax, rdi		; the char is not lowercase	
	jmp		exit_process		; return the given char

	true_statement:				; one of the statements is true so ret = 1
		mov	rax, rdi		; store the char to ret
		sub	rax, 32			; substract 32 to the char to make it uppercase

	exit_process:				
		leave
		ret
