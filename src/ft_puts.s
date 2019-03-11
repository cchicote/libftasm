;******************************************************************************
; The function ft_puts() writes the string s, and a terminating newline 
; character, to the stream stdout.
; The functions ft_puts() return a nonnegative integer on success and 
; EOF on error.
; prototype:
; int			ft_puts(const char *s);
;******************************************************************************

%define MACH_SYSCALL(nb) 	0x2000000 | nb
%define STDOUT			1
%define WRITE			4
%define EOF			-1

section .rodata
new_line: db 10
str_null: 
	.value db "(null)"
	.len equ $ - str_null.value 

section .text
	global		_ft_puts
	extern		_ft_strlen

_ft_puts:
	push		rbp
	mov		rbp, rsp

	IF:
		cmp		rdi, 0
		jne		ELSE
	
	THEN:
		lea		r9, [rel str_null.value]
		lea		r8, [rel str_null.len]
		jmp		ENDIF

	ELSE:
		mov		r9, rdi
		call		_ft_strlen
		mov		r8, rax
		cmp		r8, 0
		jne		ENDIF
		mov		rax, EOF
		call		_ft_putnl
		jmp		exit_process
	
	ENDIF:
		mov		rsi, r9 
		mov		rdx, r8
		mov		rax, MACH_SYSCALL(WRITE)
		mov		rdi, 1
		syscall

	mov		r10, 0
	adc		r10, 0 

	mov		rax, -1
	cmp		r10, 0
	jne		exit_process

	call		_ft_putnl
	mov		rax, 10

	exit_process:
		leave
		ret

_ft_putnl:
	push		rbp
	mov		rbp, rsp

	lea		rsi, [rel new_line] 
	mov		rdx, 1
	mov		rax, MACH_SYSCALL(WRITE)
	mov		rdi, 1
	syscall
	
	leave
	ret
