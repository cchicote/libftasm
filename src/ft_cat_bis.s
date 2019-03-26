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
%define MAX_SIZE						1000000	
%define BUFF_SIZE						63

section	.text
	global _ft_cat_bis
	extern _fstat
	extern _ft_bzero

_ft_cat_bis:
	push		rbp									; stack frame init
	mov			rbp, rsp							;
	sub			rsp, 224							; struct stat is 144 bytes long, we need 64 bytes for buffer and 8 bytes for fd amnd 8 for alignment

	cmp			rdi, 0								; if fd < 0 
	jl			exit_process						; return

	mov			[rsp + 208], rdi					; saving fd into stack frame

	cmp			rdi, 1								; if fd is 1
	je			THEN								; jump to the classic ft_cat

	lea			rsi, [rsp]							; loading the address of the zone reserved for the stat structure
	call		_fstat								;

	IF:
		mov			rdi, [rsp + 208]				; loading args for syscall read (fd)
		mov 		rdx, [rsp + 72]					; loading file size in comparison register
		cmp			rdx, MAX_SIZE					; comparing
		jle			ELSE							; 

	THEN:											;
		lea			rdi, [rsp + 144]				; loading args for ft_bzero (s)
		mov			rsi, BUFF_SIZE + 1				; (size)
		call		_ft_bzero						;

		mov			rdi, [rsp + 208]				; loading args for syscall read (fd)
		lea			rsi, [rsp + 144]				; (buffer)
		mov			rdx, BUFF_SIZE					; (nbytes)
		mov			rax, MACH_SYSCALL(READ) 		; (syscall)
		syscall										;

		jc			exit_process					; if carry flag is set, then return

		cmp			rax, 0							; if read returns 0 then return 
		je			exit_process					; 

		mov			rdi, 1							; loading arguments for syscall write (fd)
		lea			rsi, [rsp + 144]				; (buffer)
		mov			rdx, BUFF_SIZE					; (nbytes)
		mov			rax, MACH_SYSCALL(WRITE)		; (syscall)
		syscall
		jmp			THEN							; jump to the THEN marker

	ELSE:
		mov			rsi, [rsp + 144]				; (buffer)
		mov			rdx, [rsp + 72]					; (nbytes)
		mov			rax, MACH_SYSCALL(READ) 		; (syscall)
		syscall										;

		jc			exit_process					; if carry flag is set then something went wrong with the reading
		cmp			rax, 0							; if read returns 0 then free and return 
		je			exit_process					; 

		mov			rdi, 1							; loading arguments for syscall write (fd)
		mov			rsi, [rsp + 144]				; (buffer)
		mov			rdx, [rsp + 72]					; (nbytes)
		mov			rax, MACH_SYSCALL(WRITE)		; (syscall)
		syscall										;

	exit_process:
		leave										; leave stack frame
		ret											; return

