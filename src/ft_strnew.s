;******************************************************************************
; The ft_strnew() function allocates a "fresh" 0-terminated string.
; Every char in the string is set to 0.
; If the allocation fails, the function returns NULL
; prototype:
; char			*ft_strnew(size_t size);
;******************************************************************************

section .text					;
	global		_ft_strnew		;
	extern		_ft_memalloc	;

_ft_strnew:						;
	push		rbp				; stack frame init
	mov			rbp, rsp		;

	mov			rax, 0			; set the return value to NULL
	cmp			rdi, 0			; if size is 0
	je			exit_process	; then return NULL

	inc			rdi				; increment rdi to count the final \0
	call		_ft_memalloc	;

	exit_process:				; exit_process marker
		leave					; leaving stack frame
		ret						;
