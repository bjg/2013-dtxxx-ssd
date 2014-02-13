	.file	"wack.c"
	.globl	shellcode
	.data
	.type	shellcode, @object
	.size	shellcode, 13
shellcode:
	.string	"\273"
	.string	""
	.string	""
	.string	""
	.string	"\270\001"
	.string	""
	.string	""
	.string	"\315\200"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	-8(%rbp), %rax
	addq	$32, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$shellcode, %edx
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
