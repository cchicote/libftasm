;******************************************************************************
; The strcat() function append a copy of the null-terminated string s2 to the 
; end of the null-terminated string s1, then add a terminating `\0'.
; prototype:
; char			*ft_strcat(char *restrict s1, const char *restrict s2);
;******************************************************************************

section	.text
	global		_ft_strcat

_get_dest_len:
	mov		rcx, 0
	loop1:
		cmp	byte [r8 + rcx], 0
		je	ret_process
		inc	rcx
		jmp	loop1
	ret_process:
		ret

_get_src_len:
	mov		rcx, 0
	loop2:
		cmp	byte [r9 + rcx], 0
		je	ret_process
		inc	rcx
		jmp	loop2

_ft_strcat:
	push		rbp
	mov		rbp, rsp

	mov		r8, rdi
	mov		r9, rsi
	call		_get_dest_len
	cld
	lea		rdx, [rdi + rcx]
	call		_get_src_len
	mov		rdi, rdx
	rep		movsb
	call		_get_dest_len
	sub		rdi, rcx
	mov		byte [rdi + rcx], 0

	exit_process:
		mov	rax, rdi
		leave
		ret
