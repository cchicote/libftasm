;****************************************************************************** 
; The ft_memcpy() function copies n bytes from memory area src to memory area 
; dst. If dst and src overlap, behavior is undefined.
; The ft_memcpy() function returns the original value of dst.
; prototype:
; void 			*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
;******************************************************************************

section	.text
	global		_ft_memcpy

_ft_memcpy:
	push		rbp						; stack frame init
	mov			rbp, rsp				;

	mov			r8, rdi					; save the rdi[0] address

	cmp			rdx, 0					; if n is zero
	je			exit_process			; ft_memcpy() does nothing

	mov			rcx, rdx				; copy n into rcx
	mov			rax, rsi				; copy src into rax (the memory area to write)
	cld									; clear direction flag so rep increments rdi
	rep			movsb					; store byte of rax into rdi then increment both and repeat rcx times

	exit_process:						; exit marker
		mov			rax, r8				; return the address of rdi
		leave							; leave stack frame
		ret								; return

