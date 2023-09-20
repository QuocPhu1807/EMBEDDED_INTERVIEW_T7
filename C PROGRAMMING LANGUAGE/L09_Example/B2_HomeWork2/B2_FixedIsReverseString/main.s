	.file	"main.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	String
	.data
	.align 32
String:
	.ascii "Getting ahead in a difficult profession requires avid faith.\0"
	.text
	.globl	IsSizeSpace
	.def	IsSizeSpace;	.scl	2;	.type	32;	.endef
	.seh_proc	IsSizeSpace
IsSizeSpace:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	leaq	String(%rip), %rax
	movq	%rax, -8(%rbp)
	movb	$0, -9(%rbp)
	jmp	.L4
.L6:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L5
	movzbl	-9(%rbp), %eax
	addl	$1, %eax
	movb	%al, -9(%rbp)
.L5:
	addq	$1, -8(%rbp)
.L4:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L6
	movzbl	-9(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	AddWords
	.def	AddWords;	.scl	2;	.type	32;	.endef
	.seh_proc	AddWords
AddWords:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	jmp	.L9
.L12:
	movzbl	24(%rbp), %eax
	movzbl	i.0(%rip), %edx
	movzbl	%dl, %ecx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	cltq
	leaq	String(%rip), %rcx
	movzbl	(%rax,%rcx), %eax
	movb	%al, (%rdx)
	movzbl	i.0(%rip), %eax
	addl	$1, %eax
	movb	%al, i.0(%rip)
	movzbl	24(%rbp), %eax
	addl	$1, %eax
	movb	%al, 24(%rbp)
	movzbl	24(%rbp), %eax
	cltq
	leaq	String(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	cmpb	$32, %al
	je	.L10
	movzbl	24(%rbp), %eax
	cltq
	leaq	String(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	testb	%al, %al
	jne	.L9
.L10:
	movzbl	i.0(%rip), %eax
	movzbl	%al, %edx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movb	$32, (%rax)
	movzbl	i.0(%rip), %eax
	addl	$1, %eax
	movb	%al, i.0(%rip)
	jmp	.L11
.L9:
	movzbl	i.0(%rip), %eax
	movzbl	%al, %eax
	cltq
	leaq	String(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	testb	%al, %al
	jne	.L12
	nop
.L11:
	nop
	popq	%rbp
	ret
	.seh_endproc
	.def	ReverseWords;	.scl	3;	.type	32;	.endef
	.seh_proc	ReverseWords
ReverseWords:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	call	IsSizeSpace
	movb	%al, -1(%rbp)
	movb	$0, -2(%rbp)
	movb	$0, -4(%rbp)
	jmp	.L14
.L19:
	movzbl	-2(%rbp), %eax
	cltq
	leaq	String(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	cmpb	$32, %al
	jne	.L16
	movzbl	-3(%rbp), %eax
	addl	$1, %eax
	movb	%al, -3(%rbp)
	movzbl	-3(%rbp), %eax
	cmpb	-1(%rbp), %al
	jne	.L16
	movzbl	-2(%rbp), %eax
	addl	$1, %eax
	movzbl	%al, %edx
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	AddWords
	movb	$0, -3(%rbp)
	movzbl	-1(%rbp), %eax
	subl	$1, %eax
	movb	%al, -1(%rbp)
	movb	$1, -4(%rbp)
	jmp	.L17
.L16:
	cmpb	$1, -4(%rbp)
	je	.L21
	movzbl	-2(%rbp), %eax
	addl	$1, %eax
	movb	%al, -2(%rbp)
.L15:
	movzbl	-2(%rbp), %eax
	cltq
	leaq	String(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	testb	%al, %al
	jne	.L19
	jmp	.L17
.L21:
	nop
.L17:
	movb	$0, -4(%rbp)
	movb	$0, -2(%rbp)
.L14:
	cmpb	$0, -1(%rbp)
	jne	.L15
	movq	16(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	AddWords
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%c\0"
	.text
	.globl	PrintArray
	.def	PrintArray;	.scl	2;	.type	32;	.endef
	.seh_proc	PrintArray
PrintArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L23
.L24:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L23:
	movl	-4(%rbp), %eax
	cltq
	leaq	String(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	testb	%al, %al
	jne	.L24
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$336, %rsp
	.seh_stackalloc	336
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, 224(%rbp)
	movq	%rdx, 232(%rbp)
	call	__main
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	ReverseWords
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	PrintArray
	movl	$0, %eax
	addq	$336, %rsp
	popq	%rbp
	ret
	.seh_endproc
.lcomm i.0,1,1
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
