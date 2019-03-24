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
%define BUFF_SIZE						63
%define WRITE							4

section	.text
	global _ft_cat
	extern _ft_bzero

_ft_cat:
	push		rbp								; stack frame init
	mov			rbp, rsp						;
	sub			rsp, 96

	cmp			rdi, 0							; if fd < 0 
	jl			exit_process					; return

	mov			[rsp + 64], rdi					; saving fd in stack frame

	read_line:									; read_line marker
		mov			rdi, rsp					; loading args for ft_bzero (s)
		mov			rsi, BUFF_SIZE + 1			; (size)
		call		_ft_bzero					;

		mov			rdi, [rsp + 64]				; loading args for syscall read (fd)
		mov			rsi, rsp					; (buffer)
		mov			rdx, BUFF_SIZE				; (nbytes)
		mov			rax, MACH_SYSCALL(READ) 	; (syscall)
		syscall									;

		jc			exit_process				; if carry flag is set, then return

		cmp			rax, 0						; if read returns 0 then return 
		je			exit_process				; 

		mov			rdi, 1						; loading arguments for syscall write (fd)
		mov			rsi, rsp					; (buffer)
		mov			rdx, BUFF_SIZE				; (nbytes)
		mov			rax, MACH_SYSCALL(WRITE)	; (syscall)
		syscall
		jmp			read_line					; jump to the read_line marker

	exit_process:								; exit marker
		leave									; leave stack frame
		ret										; return

