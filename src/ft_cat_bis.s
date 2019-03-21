;****************************************************************************** 
; The ft_cat_bis() function writes the content of a file (from a file descriptor)
; to the standard output
; prototype:
; void 			ft_cat_bis(int fd);
; prototype read:
; user_ssize_t read(int fd, user_addr_t cbuf, user_size_t nbyte);
;******************************************************************************

%define MACH_SYSCALL(nb)				0x2000000 | nb
%define STDOUT							1
%define READ							3
%define WRITE							4

section	.text
	global _ft_cat_bis
	extern _malloc
	extern _fstat
	extern _free

_ft_cat_bis:
	push		rbp								; stack frame init
	mov			rbp, rsp						;
	sub			rsp, 160						; struct stat is 144 bytes long, we need 8 bytes for buffer and 8 bytes for fd

	cmp			rdi, 0							; if fd < 0 
	jl			exit_process					; return

	mov			[rbp - 152], rdi				; saving fd into stack frame

	lea			rsi, [rbp - 144]				; loading the address of the zone reserved for the stat structure
	call		_fstat							; 

	mov			rdi, [rbp - 72]					; loading args for malloc (rbp - 72 leads to st_size of the stat struct)
	call		_malloc							; 

	test		rax, rax						; check malloc return
	js			exit_process					; exit if malloc returns NULL
	
	mov			[rbp - 160], rax				; saving malloc return in stack frame

	mov			rdi, [rbp - 152]				; loading args for syscall read (fd)
	mov			rsi, [rbp - 160]				; (buffer)
	mov			rdx, [rbp - 72]					; (nbytes)
	mov			rax, MACH_SYSCALL(READ) 		; (syscall)
	syscall										;

	jc			free_marker						; if carry flag is set then something went wrong with the reading
	cmp			rax, 0							; if read returns 0 then free and return 
	je			free_marker						; 

	mov			rdi, 1							; loading arguments for syscall write (fd)
	mov			rsi, [rbp - 160]				; (buffer)
	mov			rdx, [rbp - 72]					; (nbytes)
	mov			rax, MACH_SYSCALL(WRITE)		; (syscall)
	syscall										;

	free_marker:
		mov			rdi, [rbp - 160]			; load the buffer to rdi
		call		_free						;

	exit_process:
		leave									; leave stack frame
		ret										; return

