;******************************************************************************
; The ft_strclr() sets every char of the string s to 0 
; prototype:
; void 			ft_strclr(char *s);
;******************************************************************************

section .text					;
	global		_ft_strclr		;
	extern		_ft_memset		;
	extern		_ft_strlen		;

_ft_strclr:						;
	push		rbp				; stack frame init
	mov			rbp, rsp		;
	sub			rsp, 16			; 

	mov			[rbp - 8], rdi	; save s in stack frame
	call		_ft_strlen		; get the len of s

	mov			rdi, [rbp - 8]	; load parameters for memset (s)
	mov			rsi, 0			; (0, that is the char to set)
	mov			rdx, rax		; (len)
	call		_ft_memset		; ft_memset call, rax value will be the cleared string

	exit_process:				; exit_process marker
		leave					; leaving stack frame
		ret						;
