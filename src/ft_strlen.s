;******************************************************************************
; The ft_strlen() function computes the length of the string s.
; The ft_strlen() function returns the number of characters that precede the 
; terminating NUL character.
; prototype:
; size_t		ft_strlen(const char *s);
;******************************************************************************

section .text
	global		_ft_strlen

_ft_strlen:
	push		rbp
	mov		rbp, rsp

	mov		al, 0
	mov		rcx, -1
	cld
	repne	scasb
	mov		rax, -2
	sub		rax, rcx

	exit_process:
		leave
		ret
