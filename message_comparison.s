section .data
o1:
	.string db "Ceci est un message court!", 10, 0
	.len equ $ - o1.string

o2:	
	.string db "Ceci est un message super long!", 10, 0
	.len equ $ - o2.string

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
	lea r8, [o1.len]
	lea r9, [o2.len]
	if:	cmp r8, r9
		jng else
		lea rdi, [rel o1.string]
		jmp endif
	else:
		lea rdi, [rel o2.string]
	endif:
	call _printf
	leave
	ret
