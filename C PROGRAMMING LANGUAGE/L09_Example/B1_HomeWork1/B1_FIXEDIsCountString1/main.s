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
	.ascii "nam hoang tuan nam thai hoang thai hoang tuan yen\0"
	.text
	.def	NumberElement;	.scl	3;	.type	32;	.endef
	.seh_proc	NumberElement
NumberElement:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movb	$1, -1(%rbp)
	leaq	String(%rip), %rax
	movq	%rax, -16(%rbp)
	jmp	.L4
.L6:
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L5
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
.L5:
	addq	$1, -16(%rbp)
.L4:
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L6
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
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movb	$0, -1(%rbp)
	movb	$1, -2(%rbp)
	movzbl	24(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	movzbl	-1(%rbp), %eax
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
	movzbl	-1(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-2(%rbp), %eax
	movb	%al, 8(%rdx)
	movb	$1, -2(%rbp)
	addq	$1, 16(%rbp)
	addb	$1, -1(%rbp)
	movzbl	-1(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	.L9
.L10:
	addq	$1, 16(%rbp)
	movzbl	-2(%rbp), %eax
	addl	$1, %eax
	movb	%al, -2(%rbp)
.L9:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L11
	movzbl	-1(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-2(%rbp), %eax
	movb	%al, 8(%rdx)
	movq	-16(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	IsLager;	.scl	3;	.type	32;	.endef
	.seh_proc	IsLager
IsLager:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	jmp	.L14
.L17:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L15
	movl	$1, %eax
	jmp	.L16
.L15:
	addq	$1, 16(%rbp)
	addq	$1, 24(%rbp)
.L14:
	movq	16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L17
	movq	16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jle	.L18
	movl	$1, %eax
	jmp	.L16
.L18:
	movl	$0, %eax
.L16:
	popq	%rbp
	ret
	.seh_endproc
	.def	IsSwapElement;	.scl	3;	.type	32;	.endef
	.seh_proc	IsSwapElement
IsSwapElement:
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
	.globl	SortAlphabet
	.def	SortAlphabet;	.scl	2;	.type	32;	.endef
	.seh_proc	SortAlphabet
SortAlphabet:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movb	$0, -1(%rbp)
	jmp	.L21
.L25:
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -2(%rbp)
	jmp	.L22
.L24:
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movzbl	-1(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	IsLager
	testb	%al, %al
	je	.L23
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-1(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	%rax, %rcx
	call	IsSwapElement
.L23:
	movzbl	-2(%rbp), %eax
	addl	$1, %eax
	movb	%al, -2(%rbp)
.L22:
	movzbl	-2(%rbp), %eax
	cmpb	24(%rbp), %al
	jb	.L24
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
.L21:
	movzbl	-1(%rbp), %edx
	movzbl	24(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, %edx
	jl	.L25
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	FindTheSameName
	.def	FindTheSameName;	.scl	2;	.type	32;	.endef
	.seh_proc	FindTheSameName
FindTheSameName:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movb	$0, -1(%rbp)
	movb	$0, -2(%rbp)
	movb	$0, -3(%rbp)
	jmp	.L27
.L35:
	movzbl	-2(%rbp), %eax
	addl	$1, %eax
	movb	%al, -2(%rbp)
	movzbl	-4(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movzbl	-2(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	je	.L29
	movzbl	-4(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movzbl	-2(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L30
	movzbl	-3(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movzbl	-2(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	je	.L29
.L30:
	movzbl	-3(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movzbl	-2(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L31
.L29:
	movl	$1, %eax
	jmp	.L32
.L31:
	movl	$0, %eax
.L32:
	movb	%al, -5(%rbp)
	andb	$1, -5(%rbp)
	cmpb	$0, -5(%rbp)
	je	.L28
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
	cmpb	$1, -1(%rbp)
	jbe	.L33
	movzbl	-3(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movb	$1, 9(%rax)
.L33:
	movb	$0, -2(%rbp)
	jmp	.L34
.L28:
	movzbl	-4(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movzbl	-2(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movzbl	-3(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rcx
	movzbl	-2(%rbp), %eax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L35
.L34:
	movb	$0, -2(%rbp)
	movzbl	-3(%rbp), %eax
	addl	$1, %eax
	movb	%al, -3(%rbp)
.L27:
	movzbl	-3(%rbp), %eax
	cmpb	24(%rbp), %al
	jb	.L28
	movzbl	-4(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-1(%rbp), %eax
	movb	%al, 10(%rdx)
	movzbl	-4(%rbp), %eax
	addl	$1, %eax
	movb	%al, -4(%rbp)
	movb	$0, -1(%rbp)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%c\0"
.LC1:
	.ascii ":\11%d\12:\0"
	.text
	.globl	PrintWords
	.def	PrintWords;	.scl	2;	.type	32;	.endef
	.seh_proc	PrintWords
PrintWords:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movb	$0, -1(%rbp)
	jmp	.L38
.L42:
	movzbl	-1(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	9(%rax), %eax
	testb	%al, %al
	jne	.L39
	movb	$0, -2(%rbp)
	jmp	.L40
.L41:
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movzbl	-2(%rbp), %eax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movzbl	-2(%rbp), %eax
	addl	$1, %eax
	movb	%al, -2(%rbp)
.L40:
	movzbl	-2(%rbp), %edx
	movzbl	-2(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	8(%rax), %eax
	movzbl	%al, %eax
	subl	$1, %eax
	cmpl	%eax, %edx
	jl	.L41
	movzbl	-1(%rbp), %eax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	10(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L39:
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
.L38:
	movzbl	-1(%rbp), %eax
	cmpb	24(%rbp), %al
	jb	.L42
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
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	call	NumberElement
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	String(%rip), %rax
	movq	%rax, %rcx
	call	SplitString
	movq	%rax, -16(%rbp)
	movzbl	-1(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	FindTheSameName
	movzbl	-1(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	PrintWords
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
