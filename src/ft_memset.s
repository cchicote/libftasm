;****************************************************************************** 
; The ft_memset() function writes len bytes of value c (converted to an
; unsigned char) to the string b.
; The ft_memset() function returns its first argument.
; prototype:
; void			*ft_memset(void *b, int c, size_t len);
;******************************************************************************

section	.text
	global		_ft_memset

_ft_memset:
	push		rbp						; stack frame init
	mov			rbp, rsp				;

	mov			r8, rdi					; save the rdi[0] address

	cmp			rdx, 0					; if len is zero
	je			exit_process			; ft_memset() does nothing

	mov			rcx, rdx				; copy len into rcx
	mov			rax, rsi				; copy c into rax (the char to write)
	cld									; clear direction flag so rep increments rdi
	rep			stosb					; store rax into rdi then increment rdi and repeat rcx times

	exit_process:						; exit marker
		mov			rax, r8				; return the address of rdi
		leave							; leave stack frame
		ret								; return

