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
	sub			rsp, 16					; reserve 16 bytes of memory on the stack

	mov			[rbp - 8], rdi			; save s1 address in stack frame

	call		_ft_strlen				; call strlen on s1 
	inc			rax						; inc the result of strlen to count the \0
	mov 		[rbp - 16], rax			; save len in stack frame

	mov			rdi, rax				; load the len into rdi
	call		_malloc					;
	test		rax, rax				; check the return of malloc
	js			exit_process			; if malloc returns NULL, then we jump to exit_process marker

	mov			rsi, [rbp - 8]			; load s1
	mov			rdx, [rbp - 16]			; load len
	mov			rdi, rax				; malloc-ed area
	call		_ft_memcpy				; copy the content of s1 into the malloc-ed area

	exit_process:						; exit marker
		leave							; leave stack frame
		ret								; return

