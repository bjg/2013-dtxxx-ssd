	.file	"authenticated.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"Failed for user %s\n"
	.text
	.globl	authenticate
	.type	authenticate, @function
authenticate:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 1072
	mov	QWORD PTR [rbp-1064], rdi
	mov	QWORD PTR [rbp-1072], rsi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR [rbp-8], rax
	xor	eax, eax
	mov	rdx, QWORD PTR [rbp-1072]
	mov	rax, QWORD PTR [rbp-1064]
	mov	rsi, rdx
	mov	rdi, rax
	mov	eax, 0
	call	verify
	mov	DWORD PTR [rbp-1044], eax
	cmp	DWORD PTR [rbp-1044], 0
	jne	.L2
	mov	rdx, QWORD PTR [rbp-1064]
	lea	rax, [rbp-1040]
	mov	esi, OFFSET FLAT:.LC0
	mov	rdi, rax
	mov	eax, 0
	call	sprintf
.L2:
	mov	eax, DWORD PTR [rbp-1044]
	mov	rdx, QWORD PTR [rbp-8]
	xor	rdx, QWORD PTR fs:40
	je	.L4
	call	__stack_chk_fail
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	authenticate, .-authenticate
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
