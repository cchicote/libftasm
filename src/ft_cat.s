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
	extern _malloc
	extern _free
	extern _ft_bzero

_ft_cat:
	push		rbp								; stack frame init
	mov			rbp, rsp						;
	sub			rsp, 16

	cmp			rdi, 0							; if fd < 0 
	jl			exit_process					; return

	mov			[rbp - 16], rdi					; saving fd in stack frame
	mov			rdi, BUFF_SIZE + 1				; loading args for malloc
	call		_malloc							;

	test		rax, rax						; check malloc return
	js			exit_process					; exit if malloc returns NULL
	
	mov			[rbp - 8], rax					; saving malloc return in stack frame
	
	read_line:									; read_line marker
		mov			rdi, [rbp - 8]				; loading args for ft_bzero (s)
		mov			rsi, BUFF_SIZE + 1			; (size)
		call		_ft_bzero					;

		mov			rdi, [rbp - 16]				; loading args for syscall read (fd)
		mov			rsi, [rbp - 8]				; (buffer)
		mov			rdx, BUFF_SIZE				; (nbytes)
		mov			rax, MACH_SYSCALL(READ) 	; (syscall)
		syscall									;

		jc			free_marker					; if carry flag is set, then return

		cmp			rax, 0						; if read returns 0 then return 
		je			free_marker					; 

		mov			rdi, 1						; loading arguments for syscall write (fd)
		mov			rsi, [rbp - 8]				; (buffer)
		mov			rdx, BUFF_SIZE				; (nbytes)
		mov			rax, MACH_SYSCALL(WRITE)	; (syscall)
		syscall
		jmp			read_line					; jump to the read_line marker
	
	free_marker:
		mov			rdi, [rbp - 8]
		call		_free

	exit_process:								; exit marker
		leave									; leave stack frame
		ret										; return

