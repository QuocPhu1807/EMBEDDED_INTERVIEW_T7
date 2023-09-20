	.file	"main.c"
	.text
	.def	scanf;	.scl	3;	.type	32;	.endef
	.seh_proc	scanf
scanf:
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
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfscanf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
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
	.globl	number
	.section .rdata,"dr"
.LC0:
	.ascii "khong\0"
.LC1:
	.ascii "mot\0"
.LC2:
	.ascii "hai\0"
.LC3:
	.ascii "ba\0"
.LC4:
	.ascii "bon\0"
.LC5:
	.ascii "nam\0"
.LC6:
	.ascii "sau\0"
.LC7:
	.ascii "bay\0"
.LC8:
	.ascii "tam\0"
.LC9:
	.ascii "chin\0"
	.data
	.align 32
number:
	.quad	.LC0
	.quad	.LC1
	.quad	.LC2
	.quad	.LC3
	.quad	.LC4
	.quad	.LC5
	.quad	.LC6
	.quad	.LC7
	.quad	.LC8
	.quad	.LC9
	.globl	number1
	.align 32
number1:
	.quad	.LC0
	.quad	.LC1
	.quad	.LC2
	.quad	.LC3
	.quad	.LC4
	.quad	.LC5
	.quad	.LC6
	.quad	.LC7
	.quad	.LC8
	.quad	.LC9
	.globl	unit
	.section .rdata,"dr"
.LC10:
	.ascii " \0"
.LC11:
	.ascii "muoi\0"
.LC12:
	.ascii "tram\0"
.LC13:
	.ascii "nghin\0"
.LC14:
	.ascii "trieu\0"
.LC15:
	.ascii "ty\0"
.LC16:
	.ascii "nghin ty\0"
.LC17:
	.ascii "trieu ty\0"
	.data
	.align 32
unit:
	.quad	.LC10
	.quad	.LC11
	.quad	.LC12
	.quad	.LC13
	.quad	.LC11
	.quad	.LC12
	.quad	.LC14
	.quad	.LC11
	.quad	.LC12
	.quad	.LC15
	.quad	.LC11
	.quad	.LC12
	.quad	.LC16
	.quad	.LC11
	.quad	.LC12
	.quad	.LC17
	.globl	unit1
	.section .rdata,"dr"
.LC18:
	.ascii "linh\0"
	.data
	.align 32
unit1:
	.quad	.LC10
	.quad	.LC18
	.quad	.LC12
	.quad	.LC13
	.quad	.LC11
	.quad	.LC12
	.quad	.LC14
	.quad	.LC11
	.quad	.LC12
	.quad	.LC15
	.quad	.LC11
	.quad	.LC12
	.quad	.LC16
	.quad	.LC11
	.quad	.LC12
	.quad	.LC17
	.globl	unit2
	.section .rdata,"dr"
.LC19:
	.ascii " muoi \0"
	.data
	.align 32
unit2:
	.quad	.LC10
	.quad	.LC19
	.quad	.LC12
	.quad	.LC13
	.quad	.LC10
	.quad	.LC10
	.quad	.LC14
	.quad	.LC10
	.quad	.LC10
	.quad	.LC15
	.quad	.LC10
	.quad	.LC10
	.quad	.LC16
	.quad	.LC10
	.quad	.LC10
	.quad	.LC17
	.section .rdata,"dr"
.LC20:
	.ascii " INPUT\11 : \0"
.LC21:
	.ascii "%d\0"
	.align 8
.LC22:
	.ascii "So khong hop le! Hay nhap so khac.\12\0"
	.text
	.globl	input
	.def	input;	.scl	2;	.type	32;	.endef
	.seh_proc	input
input:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	.LC20(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC21(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movl	-4(%rbp), %eax
	testl	%eax, %eax
	jg	.L6
	leaq	.LC22(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L6:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	SplitArr
	.def	SplitArr;	.scl	2;	.type	32;	.endef
	.seh_proc	SplitArr
SplitArr:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$0, -8(%rbp)
	movb	$0, -9(%rbp)
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
.L9:
	movl	-4(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %ecx
	sarl	$2, %ecx
	movl	%edx, %eax
	sarl	$31, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	addl	%eax, %eax
	subl	%eax, %edx
	movl	%edx, -28(%rbp)
	movzbl	-9(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-28(%rbp), %eax
	movl	%eax, (%rdx)
	addl	$1, -8(%rbp)
	movzbl	-9(%rbp), %eax
	addl	$1, %eax
	movb	%al, -9(%rbp)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$2, %ecx
	cltd
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jg	.L9
	movq	-24(%rbp), %rax
	movq	%rax, -48(%rbp)
	movl	-8(%rbp), %eax
	movb	%al, -40(%rbp)
	movq	16(%rbp), %rcx
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	16(%rbp), %rax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	convertNumber
	.def	convertNumber;	.scl	2;	.type	32;	.endef
	.seh_proc	convertNumber
convertNumber:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$0, 16(%rbp)
	js	.L12
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	number(%rip), %rax
	movq	(%rdx,%rax), %rax
	jmp	.L13
.L12:
	leaq	.LC10(%rip), %rax
.L13:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC23:
	.ascii " %s %s \0"
.LC24:
	.ascii "%s %s \0"
.LC25:
	.ascii "<dong>\0"
	.text
	.globl	printEleme1
	.def	printEleme1;	.scl	2;	.type	32;	.endef
	.seh_proc	printEleme1
printEleme1:
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
	movq	(%rbx), %rcx
	movq	8(%rbx), %rbx
	movq	%rcx, -32(%rbp)
	movq	%rbx, -24(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	movzbl	-24(%rbp), %eax
	movzbl	%al, %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.L15
.L21:
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jne	.L16
	movq	-32(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jne	.L16
	movzbl	-24(%rbp), %eax
	movzbl	%al, %eax
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movzbl	-24(%rbp), %edx
	movzbl	%dl, %edx
	salq	$2, %rdx
	subq	$4, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %ecx
	call	convertNumber
	movq	%rbx, %r8
	movq	%rax, %rdx
	leaq	.LC23(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L17
.L16:
	movq	-32(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jne	.L18
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	48(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %ecx
	call	convertNumber
	movq	%rbx, %r8
	movq	%rax, %rdx
	leaq	.LC24(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L19
.L18:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jne	.L20
	movq	-32(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L20
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	56(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %ecx
	call	convertNumber
	movq	%rbx, %r8
	movq	%rax, %rdx
	leaq	.LC24(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L19
.L20:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %ecx
	call	convertNumber
	movq	%rbx, %r8
	movq	%rax, %rdx
	leaq	.LC24(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L19:
	subl	$1, -4(%rbp)
.L15:
	cmpl	$0, -4(%rbp)
	jns	.L21
.L17:
	leaq	.LC25(%rip), %rax
	movq	%rax, %rcx
	call	printf
	nop
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC26:
	.ascii " %d \0"
	.text
	.globl	printEleme
	.def	printEleme;	.scl	2;	.type	32;	.endef
	.seh_proc	printEleme
printEleme:
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
	jmp	.L23
.L24:
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC26(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L23:
	movzbl	-24(%rbp), %eax
	movzbl	%al, %eax
	cmpl	%eax, -4(%rbp)
	jl	.L24
	nop
	nop
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	CountArr
	.def	CountArr;	.scl	2;	.type	32;	.endef
	.seh_proc	CountArr
CountArr:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L26
.L27:
	addl	$1, -4(%rbp)
.L26:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L27
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC27:
	.ascii "OUTPUT\11 : \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	call	input
	movl	%eax, -4(%rbp)
	leaq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movq	%rax, %rcx
	call	SplitArr
	leaq	.LC27(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	leaq	-48(%rbp), %rax
	leaq	unit2(%rip), %r9
	leaq	unit1(%rip), %r8
	leaq	unit(%rip), %rdx
	movq	%rax, %rcx
	call	printEleme1
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
