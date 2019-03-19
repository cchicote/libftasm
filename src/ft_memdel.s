;****************************************************************************** 
; The ft_memdel() takes as a parameter a pointer to the memory zone that
; must be freed, the pointer must be set to NULL after the operation
; prototype:
; void			ft_memdel(void **ap);
;******************************************************************************

section	.text
	global		_ft_memdel
	extern		_free

_ft_memdel:
	push		rbp						; stack frame init
	mov			rbp, rsp				;
	
	mov rsi, rdi						; store the pointer into rsi
	mov qword [rdi], 0					; set the pointer to NULL

	mov rdi, [rsi]						; load the pointer to rdi
	call _free							; free the pointer

	exit_process:						; exit marker
		leave							; leave stack frame
		ret								; return

