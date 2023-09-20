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
	.globl	date
	.data
	.align 2
date:
	.byte	1
	.byte	1
	.word	1
	.globl	DateCurrent
	.align 2
DateCurrent:
	.byte	19
	.byte	8
	.word	2009
	.globl	Days
	.section .rdata,"dr"
.LC0:
	.ascii "Sunday\0"
.LC1:
	.ascii "Monday\0"
.LC2:
	.ascii "Tuesday\0"
.LC3:
	.ascii "Wednesday\0"
.LC4:
	.ascii "Thursday\0"
.LC5:
	.ascii "Friday\0"
.LC6:
	.ascii "Saturday\0"
	.data
	.align 32
Days:
	.quad	.LC0
	.quad	.LC1
	.quad	.LC2
	.quad	.LC3
	.quad	.LC4
	.quad	.LC5
	.quad	.LC6
	.text
	.globl	CheckDate
	.def	CheckDate;	.scl	2;	.type	32;	.endef
	.seh_proc	CheckDate
CheckDate:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movzbl	date(%rip), %edx
	movzbl	DateCurrent(%rip), %eax
	cmpb	%al, %dl
	jne	.L4
	movzbl	1+date(%rip), %edx
	movzbl	1+DateCurrent(%rip), %eax
	cmpb	%al, %dl
	jne	.L4
	movzwl	2+date(%rip), %edx
	movzwl	2+DateCurrent(%rip), %eax
	cmpw	%ax, %dx
	jne	.L4
	movl	$1, %eax
	jmp	.L5
.L4:
	movl	$0, %eax
.L5:
	popq	%rbp
	ret
	.seh_endproc
	.globl	IsCountDays
	.def	IsCountDays;	.scl	2;	.type	32;	.endef
	.seh_proc	IsCountDays
IsCountDays:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movw	$0, -2(%rbp)
.L37:
	movzwl	-2(%rbp), %eax
	addl	$1, %eax
	movw	%ax, -2(%rbp)
	call	CheckDate
	testb	%al, %al
	je	.L7
	movzwl	-2(%rbp), %eax
	jmp	.L38
.L7:
	movzbl	1+date(%rip), %eax
	movzbl	%al, %eax
	cmpl	$12, %eax
	ja	.L39
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L11(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L11(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L11:
	.long	.L39-.L11
	.long	.L22-.L11
	.long	.L21-.L11
	.long	.L20-.L11
	.long	.L19-.L11
	.long	.L18-.L11
	.long	.L17-.L11
	.long	.L16-.L11
	.long	.L15-.L11
	.long	.L14-.L11
	.long	.L13-.L11
	.long	.L12-.L11
	.long	.L10-.L11
	.text
.L22:
	movzbl	date(%rip), %eax
	cmpb	$31, %al
	jne	.L23
	movb	$2, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L23:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L21:
	movzwl	2+date(%rip), %eax
	andl	$3, %eax
	testw	%ax, %ax
	je	.L25
	movzbl	date(%rip), %eax
	cmpb	$28, %al
	jne	.L26
	movb	$3, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L25:
	movzbl	date(%rip), %eax
	cmpb	$29, %al
	jne	.L26
	movb	$3, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L26:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L20:
	movzbl	date(%rip), %eax
	cmpb	$31, %al
	jne	.L27
	movb	$4, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L27:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L19:
	movzbl	date(%rip), %eax
	cmpb	$30, %al
	jne	.L28
	movb	$5, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L28:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L18:
	movzbl	date(%rip), %eax
	cmpb	$31, %al
	jne	.L29
	movb	$6, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L29:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L17:
	movzbl	date(%rip), %eax
	cmpb	$30, %al
	jne	.L30
	movb	$7, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L30:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L16:
	movzbl	date(%rip), %eax
	cmpb	$31, %al
	jne	.L31
	movb	$8, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L31:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L15:
	movzbl	date(%rip), %eax
	cmpb	$31, %al
	jne	.L32
	movb	$9, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L32:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L14:
	movzbl	date(%rip), %eax
	cmpb	$30, %al
	jne	.L33
	movb	$10, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L33:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L13:
	movzbl	date(%rip), %eax
	cmpb	$31, %al
	jne	.L34
	movb	$11, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L34:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L12:
	movzbl	date(%rip), %eax
	cmpb	$30, %al
	jne	.L35
	movb	$12, 1+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L35:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L10:
	movzbl	date(%rip), %eax
	cmpb	$31, %al
	jne	.L36
	movb	$1, 1+date(%rip)
	movzwl	2+date(%rip), %eax
	addl	$1, %eax
	movw	%ax, 2+date(%rip)
	movb	$1, date(%rip)
	jmp	.L24
.L36:
	movzbl	date(%rip), %eax
	addl	$1, %eax
	movb	%al, date(%rip)
	jmp	.L24
.L39:
	nop
.L24:
	jmp	.L37
.L38:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC7:
	.ascii " The Day of week: %s\0"
	.text
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
	call	__main
	call	IsCountDays
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	movzwl	%ax, %edx
	imull	$9363, %edx, %edx
	movl	%edx, %ecx
	shrl	$16, %ecx
	movl	%eax, %edx
	subl	%ecx, %edx
	shrw	%dx
	addl	%ecx, %edx
	movl	%edx, %ecx
	shrw	$2, %cx
	movl	%ecx, %edx
	sall	$3, %edx
	subl	%ecx, %edx
	subl	%edx, %eax
	movl	%eax, %ecx
	movzwl	%cx, %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	Days(%rip), %rax
	movq	(%rdx,%rax), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
