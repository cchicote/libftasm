section .data
hw:
	.string db "Hello, World!", 10

section .text
	global start
	global _main
	extern _printf

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	lea rdi, [rel hw.string]
	call _printf
	leave
	ret
