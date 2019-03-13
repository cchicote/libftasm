;****************************************************************************** 
; The ft_cat() function writes the content of a file (from a file descriptor)
; to the standard output
; prototype:
; void 			ft_cat(int fd);
; prototype read:
; user_ssize_t read(int fd, user_addr_t cbuf, user_size_t nbyte);
;******************************************************************************

%define MACH_SYSCALL(nb)				0x2000000 | nb
%define STDOUT							1
%define READ							3
%define BUFF_SIZE						1000
%define WRITE							4

section .data
format: db "[%s]", 10

section	.text
	global _ft_cat
	extern _printf
	extern _malloc
	extern _ft_bzero

_ft_cat:
	push		rbp						; stack frame init
	mov			rbp, rsp				;
	sub			rsp, 16

	cmp			rdi, 0					; if fd < 0 
	jl			exit_process			; return

	mov			[rbp - 16], rdi
	mov			rdi, BUFF_SIZE + 1
	call		_malloc

	test		rax, rax
	js			exit_process
	
	mov			[rbp - 8], rax
	read_line:
		mov			rdi, [rbp - 8]
		mov			rsi, BUFF_SIZE + 1
		call		_ft_bzero

		mov			rdi, [rbp - 16]
		mov			rsi, [rbp - 8]
		mov			rdx, BUFF_SIZE
		mov			rax, MACH_SYSCALL(READ)
		syscall

		jc			exit_process

		cmp			rax, 0
		je			exit_process

		mov			rdi, 1
		mov			rsi, [rbp - 8]
		mov			rdx, BUFF_SIZE
		mov			rax, MACH_SYSCALL(WRITE)
		syscall
		jmp			read_line
	
	exit_process:						; exit marker
		leave							; leave stack frame
		ret								; return

