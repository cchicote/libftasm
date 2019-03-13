;****************************************************************************** 
; The ft_strdup() function allocates sufficient memory for a copy of the 
; string s1, does the copy, and returns a pointer to it.  
; If insufficient memory is available, NULL is returned and errno is set 
; to ENOMEM.
; prototype:
; char 			*strdup(const char *s1);
;******************************************************************************

section	.text
	global		_ft_strdup
	extern		_ft_strlen
	extern		_ft_memcpy
	extern		_malloc

_ft_strdup:
	push		rbp						; stack frame init
	mov			rbp, rsp				;
	sub			rsp, 16

	mov			[rbp - 8], rdi			; save s1 address

	call		_ft_strlen
	inc			rax
	mov			rdi, rax
	mov 		[rbp - 16], rax			; save len

	call		_malloc
	test		rax, rax
	js			exit_process

	mov			rsi, [rbp - 8]			; load s1
	mov			rdx, [rbp - 16]			; load len
	mov			rdi, rax				; malloc-ed area
	call		_ft_memcpy

	exit_process:						; exit marker
		leave							; leave stack frame
		ret								; return

