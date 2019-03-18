;******************************************************************************
; The ft_strlen() function computes the length of the string s.
; The ft_strlen() function returns the number of characters that precede the 
; terminating NUL character.
; prototype:
; size_t		ft_strlen(const char *s);
;******************************************************************************

section .text					;
	global		_ft_strlen		;

_ft_strlen:						;
	push		rbp				; stack frame init
	mov			rbp, rsp		;

	mov			al, 0			; set the value for the char to look for to 0 (bc we look for the \0)
	mov			rcx, -1			; we begin at -1 wo the count truly begins with the char 0
	cld							; clear direction so we increment rcx until we find the char stored in al register
	repne		scasb			; repeat while not equal scan string byte -> we scan the string byte per byte while the current byte is not equal to the one stored in al
	mov			rax, -2			; 
	sub			rax, rcx		; then we substract -2 to the negative counter to get the number of char that precede the \0

	exit_process:				;
		leave					;
		ret						;
