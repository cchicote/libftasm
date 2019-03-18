;******************************************************************************
; The function ft_puts() writes the string s, and a terminating newline 
; character, to the stream stdout.
; The functions ft_puts() return a nonnegative integer on success and 
; EOF on error.
; prototype:
; int			ft_puts(const char *s);
;******************************************************************************

%define MACH_SYSCALL(nb) 	0x2000000 | nb
%define STDOUT				1
%define WRITE				4
%define EOF					-1

section .rodata								; read-only data section
new_line: db 10								;
str_null: 
	.value db "(null)"						;
	.len equ $ - str_null.value 			;

section .text								;
	global		_ft_puts
	extern		_ft_strlen					;

_ft_puts:
	push		rbp							; init stack frame	
	mov			rbp, rsp					;

	IF:										; IF marker
		cmp		rdi, 0						; if the string is not NULL 
		jne		ELSE						; then jump to the ELSE marker
	
	THEN:									; THEN marker (the string is NULL)
		lea		r9, [rel str_null.value]	; load effective address for the (null) message
		lea		r8, [rel str_null.len]		; same for the length of the message
		jmp		ENDIF						; jump to the ENDIF marker

	ELSE:									; ELSE marker
		mov		r9, rdi						; save s on r9
		call	_ft_strlen					; get the len 
		mov		r8, rax						; save the len on r8
		cmp		r8, 0						; if the len is not 0 
		jne		ENDIF						; then jump to ENDIF marker
		mov		rax, EOF					; if the len is 0 
		call	_ft_putnl					; then print only a new line
		jmp		exit_process				; and jump to exit_process marker
	
	ENDIF:									; ENDIF marker
		mov		rsi, r9						; load s in rsi (was saved on r9)
		mov		rdx, r8						; load len in rdx (was saved on r8)
		mov		rax, MACH_SYSCALL(WRITE)	; load the syscall
		mov		rdi, 1						; load fd
		syscall								;

	mov		r10, 0							; set r10 to 0 
	adc		r10, 0 							; "add with carry" -> adds 0 and the value of the carry flag to r10

	mov		rax, -1							; load a potential error return value
	cmp		r10, 0							; if r10 is not 0 (which means the carry flag is not = to zero so there has been an error)
	jne		exit_process					; then jump to the exit_process marker with a return value of -1

	call	_ft_putnl						; otherwise, we print a newline
	mov		rax, 10							; and we return the value of the last printed character which is the newline (so 10)

	exit_process:							; exit_process marker
		leave								;
		ret									;

_ft_putnl:									; function that prints a newline
	push	rbp								; stack frame init
	mov		rbp, rsp						;

	lea		rsi, [rel new_line] 			; load the newline value to rsi
	mov		rdx, 1							; load len (which is 1 because we only print a newline char)  
	mov		rax, MACH_SYSCALL(WRITE)		; load syscall value
	mov		rdi, 1							; load fd
	syscall									; 
	
	leave									;
	ret										;
