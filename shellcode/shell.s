	.file	"shell.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"/bin/sh"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-16], OFFSET FLAT:.LC0
	mov	QWORD PTR [rbp-8], 0
	mov	rax, QWORD PTR [rbp-16]
	lea	rcx, [rbp-16]
	mov	edx, 0
	mov	rsi, rcx
	mov	rdi, rax
	call	execve
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
