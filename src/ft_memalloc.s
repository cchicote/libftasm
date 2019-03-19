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
	je			exit_process			; do nothing and return NULL (rax value)

	mov			[rbp - 8], rdi			; save size in stack frame

	call		_malloc					; malloc the size asked
	test		rax, rax				; check malloc return
	js			exit_process			; if malloc returns NULL then return NULL

	mov			[rbp - 16], rax			; save malloc-ed zone into stack frame

	mov			rsi, [rbp - 8]			; prepare arguments for ft_bzero (size)
	mov			rdi, [rbp - 16]			; (zone)
	call		_ft_bzero				;

	mov			rax, [rbp - 16]			; return the malloc-ed zone

	exit_process:						; exit marker
		leave							; leave stack frame
		ret								; return

