;****************************************************************************** 
; The ft_bzero() function writes n zeroed bytes to the string s.		
; If n is zero, ft_bzero() does nothing.
; prototype:
; void			ft_bzero(void *s, size_t n);
;******************************************************************************

section	.text
	global		_ft_bzero

_ft_bzero:
	push		rbp			; stack frame init
	mov		rbp, rsp		;

	cmp		rsi, 0			; if n is zero
	je		exit_process		; ft_bzero() does nothing

	mov		rcx, 0			; init counter
	
	loop:					; loop declaration
		cmp	rcx, rsi		; compare counter and n
		je	exit_process		; if counter == n then exit
		mov	byte [rdi + rcx], 0 	; replace the char n[c] by 0
		inc	rcx			; increment the counter
		jmp	loop			; jump to loop

	exit_process:				; marqueur exit
		leave				; depile la stack
		ret				; return

