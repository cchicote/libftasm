;******************************************************************************
; The ft_striter() sets every char of the string s to 0 
; prototype:
; void	ft_striter(char *s, void (*f)(char *));
;******************************************************************************

section .text					;
	global		_ft_striter		;

_ft_striter:						;
	push		rbp				; stack frame init
	mov			rbp, rsp		;
	sub			rsp, 16

	mov			[rsp], rsi
	iterloop:
		cmp		rdi, 0
		je		exit_process

		mov		[rsp + 8], rdi
		mov		rax, [rsp]
		call	rax
		
		mov		rdi, [rsp + 8]
		inc		rdi
		jmp		iterloop

	exit_process:				; exit_process marker
		leave					; leaving stack frame
		ret						;
