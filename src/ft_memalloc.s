;****************************************************************************** 
; The ft_memalloc() function allocates size bytes with malloc and returns a 
; "fresh" memory zone which is set to 0. If the allocation fails ft_memalloc 
; returns NULL.
; prototype:
; void			*ft_memalloc(size_t size);
;******************************************************************************

section	.text
	global		_ft_memalloc
	extern		_ft_bzero
	extern		_malloc

_ft_memalloc:
	push		rbp						; stack frame init
	mov			rbp, rsp				;
	sub			rsp, 16

	mov			rax, 0					; set rax to NULL

	cmp			rdi, 0					; if size is zero
	je			exit_process			; do nothing and return NULL

	mov			[rbp - 8], rdi			; save size in stack frame

	call		_malloc					; 
	test		rax, rax				; 
	js			exit_process			; 

	mov			[rbp - 16], rax

	mov			rsi, [rbp - 8]
	mov			rdi, [rbp - 16]
	call		_ft_bzero

	mov			rax, [rbp - 16]

	exit_process:						; exit marker
		leave							; leave stack frame
		ret								; return

