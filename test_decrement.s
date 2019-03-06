;****************************************************************************** 
; The bzero() function writes n zeroed bytes to the string s.		
; If n is zero, bzero() does nothing.
; prototype:
; void			ft_bzero(void *s, size_t n);
;******************************************************************************

section .rodata
format: db "Ma string: [%s] et ma len: [%zu]", 10, 0

section	.text
	global		_ft_bzero
	extern		_printf

_ft_bzero:
	push		rbp
	mov		rbp, rsp
	
	mov		rcx, rsi		; Copie n dans le registre compteur
	mov		rsi, rdi		; Copie s dans le 2nd parametre
	lea		rdi, [rel format]	; Copie le format dans le 1er parametre

	loop1:					; Declaration de la boucle 1
		cmp	rcx, 0			; On compare le compteur avec X
		je	exit_process		; Si compteur == X, alors on jump a exit_process
		dec	rcx			; On decremente le registre compteur
		jmp	loop1			; On revient au debut de la boucle while

	exit_process:
	mov		rdx, rcx		; Copie du compteur dans le 3eme parametre
	call		_printf			; Appel de printf avec les 3 parametres
	leave					; Depile la stack
	ret	

_ft_abzero:
	push 		rbp
	mov		rbp, rsp
	sub		rsp, 16
	
	mov		[rbp - 8], rdi		; On prend
	mov		[rbp - 16], rsi		; les cartouches

	lea		rdi, [rel format]	; On charge
	mov		rsi, [rbp - 8]		; les cartouches
	mov		rdx, [rbp - 16]		; dans printf

	call		_printf			; On tire

	leave
	ret
