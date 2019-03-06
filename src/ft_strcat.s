;******************************************************************************
; The strcat() function append a copy of the null-terminated string s2 to the 
; end of the null-terminated string s1, then add a terminating `\0'.
; prototype:
; char			*ft_strcat(char *restrict s1, const char *restrict s2);
;******************************************************************************

section	.text
	global		_ft_strcat
	extern		_printf

_ft_strcat:
	push		rbp
	mov		rbp, rsp

	mov		rax, rdi
	
	leave
	ret
