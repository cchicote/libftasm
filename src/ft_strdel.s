;******************************************************************************
; The ft_strdel() takes a string address as a parameter, frees it and set
; its pointer to NULL
; prototype:
; void 			ft_strdel(char **as);
;******************************************************************************

section .text					;
	global		_ft_strdel		;
	extern		_ft_memdel		;

_ft_strdel:						;
	push		rbp				; stack frame init
	mov			rbp, rsp		;

	call		_ft_memdel		;

	exit_process:				; exit_process marker
		leave					; leaving stack frame
		ret						;
