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
	.globl	string1
	.data
	.align 32
string1:
	.ascii "nhat nam hoang tuan nam nhat tuan hoang nhat nam bao quoc nam\0"
	.text
	.globl	numofEle
	.def	numofEle;	.scl	2;	.type	32;	.endef
	.seh_proc	numofEle
numofEle:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movb	$1, -1(%rbp)
	jmp	.L4
.L6:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L5
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
.L5:
	addq	$1, 16(%rbp)
.L4:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L6
	movzbl	-1(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	SplitString
	.def	SplitString;	.scl	2;	.type	32;	.endef
	.seh_proc	SplitString
SplitString:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movb	$1, -1(%rbp)
	movb	$0, -2(%rbp)
	movl	24(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	.L9
.L11:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L10
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-1(%rbp), %eax
	movb	%al, 8(%rdx)
	movb	$1, -1(%rbp)
	addq	$1, 16(%rbp)
	addb	$1, -2(%rbp)
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	.L9
.L10:
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
	addq	$1, 16(%rbp)
.L9:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L11
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-1(%rbp), %eax
	movb	%al, 8(%rdx)
	movq	-16(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%c\0"
	.text
	.globl	printArr
	.def	printArr;	.scl	2;	.type	32;	.endef
	.seh_proc	printArr
printArr:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	64(%rsp), %rbp
	.seh_setframe	%rbp, 64
	.seh_endprologue
	movq	%rcx, %rbx
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L14
.L15:
	movq	-32(%rbp), %rdx
	movl	-4(%rbp), %eax
	cltq
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L14:
	movzbl	-24(%rbp), %eax
	movzbl	%al, %eax
	cmpl	%eax, -4(%rbp)
	jl	.L15
	nop
	nop
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	isLarger
	.def	isLarger;	.scl	2;	.type	32;	.endef
	.seh_proc	isLarger
isLarger:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	jmp	.L17
.L20:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L18
	movl	$1, %eax
	jmp	.L19
.L18:
	addq	$1, 16(%rbp)
	addq	$1, 24(%rbp)
.L17:
	movq	16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L20
	movq	16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jle	.L21
	movl	$1, %eax
	jmp	.L19
.L21:
	movl	$0, %eax
.L19:
	popq	%rbp
	ret
	.seh_endproc
	.globl	swap
	.def	swap;	.scl	2;	.type	32;	.endef
	.seh_proc	swap
swap:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	16(%rbp), %rcx
	movq	24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	24(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	isAlphabet
	.def	isAlphabet;	.scl	2;	.type	32;	.endef
	.seh_proc	isAlphabet
isAlphabet:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L24
.L28:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L25
.L27:
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	isLarger
	testb	%al, %al
	je	.L26
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	%rax, %rcx
	call	swap
.L26:
	addl	$1, -8(%rbp)
.L25:
	movl	-8(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L27
	addl	$1, -4(%rbp)
.L24:
	movl	24(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%rbp)
	jl	.L28
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	ischeck
	.def	ischeck;	.scl	2;	.type	32;	.endef
	.seh_proc	ischeck
ischeck:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, %rbx
	movq	(%rbx), %rcx
	movq	8(%rbx), %rbx
	movq	%rcx, -32(%rbp)
	movq	%rbx, -24(%rbp)
	movq	%rdx, %rbx
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movb	$0, -1(%rbp)
	jmp	.L30
.L34:
	movq	-32(%rbp), %rdx
	movzbl	-1(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movq	-48(%rbp), %rcx
	movzbl	-1(%rbp), %eax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L31
	movl	$1, %eax
	jmp	.L32
.L31:
	movq	-32(%rbp), %rdx
	movzbl	-1(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movq	-48(%rbp), %rcx
	movzbl	-1(%rbp), %eax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L33
	movl	$0, %eax
	jmp	.L32
.L33:
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
.L30:
	movzbl	-24(%rbp), %edx
	movzbl	-40(%rbp), %eax
	cmpb	%al, %dl
	je	.L34
	movl	$0, %eax
.L32:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	ischeck1
	.def	ischeck1;	.scl	2;	.type	32;	.endef
	.seh_proc	ischeck1
ischeck1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movb	$0, -1(%rbp)
	jmp	.L36
.L38:
	addq	$1, 16(%rbp)
	addq	$1, 24(%rbp)
	movzbl	-1(%rbp), %edx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movzbl	-1(%rbp), %ecx
	movq	24(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L36
	movl	$1, %eax
	jmp	.L37
.L36:
	movq	16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L38
	movl	$0, %eax
.L37:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "\11 xuat hien: %d lan\12\0"
	.text
	.globl	countElemt
	.def	countElemt;	.scl	2;	.type	32;	.endef
	.seh_proc	countElemt
countElemt:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movb	$1, -1(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L40
.L43:
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	ischeck1
	testb	%al, %al
	je	.L41
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
	jmp	.L42
.L41:
	movl	-8(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	printArr
	movzbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movb	$1, -1(%rbp)
.L42:
	addl	$1, -8(%rbp)
.L40:
	movl	-8(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L43
	nop
	nop
	addq	$64, %rsp
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
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	leaq	string1(%rip), %rax
	movq	%rax, %rcx
	call	numofEle
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	string1(%rip), %rax
	movq	%rax, %rcx
	call	SplitString
	movq	%rax, -16(%rbp)
	movzbl	-1(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	isAlphabet
	movzbl	-1(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	countElemt
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
