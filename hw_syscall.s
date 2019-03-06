%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT			1
%define WRITE			4

section .data
hw:
	.string db "Hello, World!", 10
	.len equ $ - hw.string

section .text
	global start
	global _main

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rdi, STDOUT
	lea rsi, [rel hw.string]
	mov rdx, hw.len
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	leave
	ret
