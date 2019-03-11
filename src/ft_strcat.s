;******************************************************************************
; The ft_strcat() function append a copy of the null-terminated string s2 to 
; the end of the null-terminated string s1, then add a terminating `\0'.
; prototype:
; char			*ft_strcat(char *restrict s1, const char *restrict s2);
;******************************************************************************

section	.text
	global		_ft_strcat
	extern		_ft_strlen

_ft_strcat:
	push		rbp			;
	mov		rbp, rsp		;

	mov		r8, rdi			; storing dest
	mov		r9, rsi			; storing src

	call		_ft_strlen		; getting the len of dest
	lea		r10, [r8 + rax]		; storing pointer to last char of dest in r10

	mov		rdi, r9			; moving src to rdi to call strlen
	call		_ft_strlen		; getting the len of src
	inc		rax			; to copy the \0
	mov		rcx, rax		; here, rax is the return of ft_strlen(src)
	mov		rdi, r10		; moving pointer to last char of dest to rdi
	rep		movsb			; rso to copy src after dest last char
	
	mov		rax, r8			; setting the return value to rdi
	leave					;
	ret					;

