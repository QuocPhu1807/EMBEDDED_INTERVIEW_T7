	.file	"main.cpp"
	.text
	.align 2
	.globl	_ZN17DCMotorControllerC2Efff
	.def	_ZN17DCMotorControllerC2Efff;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorControllerC2Efff
_ZN17DCMotorControllerC2Efff:
.LFB2433:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	%xmm2, 32(%rbp)
	movss	%xmm3, 40(%rbp)
	movq	16(%rbp), %rax
	movss	24(%rbp), %xmm0
	movss	%xmm0, (%rax)
	movq	16(%rbp), %rax
	movss	32(%rbp), %xmm0
	movss	%xmm0, 4(%rax)
	movq	16(%rbp), %rax
	movss	40(%rbp), %xmm0
	movss	%xmm0, 12(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN17DCMotorControllerC1Efff
	.def	_ZN17DCMotorControllerC1Efff;	.scl	2;	.type	32;	.endef
	.set	_ZN17DCMotorControllerC1Efff,_ZN17DCMotorControllerC2Efff
	.align 2
	.globl	_ZN17DCMotorController13setSpeedMotorEf
	.def	_ZN17DCMotorController13setSpeedMotorEf;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController13setSpeedMotorEf
_ZN17DCMotorController13setSpeedMotorEf:
.LFB2435:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movss	24(%rbp), %xmm0
	movss	%xmm0, 8(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN17DCMotorController12setDirectionE21typeRotationDirection
	.def	_ZN17DCMotorController12setDirectionE21typeRotationDirection;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController12setDirectionE21typeRotationDirection
_ZN17DCMotorController12setDirectionE21typeRotationDirection:
.LFB2436:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 16(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN17DCMotorController8setStartEv
	.def	_ZN17DCMotorController8setStartEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController8setStartEv
_ZN17DCMotorController8setStartEv:
.LFB2437:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	$1, 20(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN17DCMotorController7setStopEv
	.def	_ZN17DCMotorController7setStopEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController7setStopEv
_ZN17DCMotorController7setStopEv:
.LFB2438:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	$0, 20(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN17DCMotorController13getSpeedMotorEv
	.def	_ZN17DCMotorController13getSpeedMotorEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController13getSpeedMotorEv
_ZN17DCMotorController13getSpeedMotorEv:
.LFB2439:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movss	8(%rax), %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN17DCMotorController12getDirectionEv
	.def	_ZN17DCMotorController12getDirectionEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController12getDirectionEv
_ZN17DCMotorController12getDirectionEv:
.LFB2440:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	16(%rax), %eax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii " Voltage or current are overload! \0"
	.text
	.align 2
	.globl	_ZN17DCMotorController13checkOverLoadEff
	.def	_ZN17DCMotorController13checkOverLoadEff;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController13checkOverLoadEff
_ZN17DCMotorController13checkOverLoadEff:
.LFB2441:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	%xmm2, 32(%rbp)
	movss	24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	comiss	%xmm1, %xmm0
	jbe	.L11
	movq	16(%rbp), %rax
	movss	(%rax), %xmm0
	comiss	24(%rbp), %xmm0
	jb	.L11
	movss	32(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	comiss	%xmm1, %xmm0
	jbe	.L11
	movq	16(%rbp), %rax
	movss	4(%rax), %xmm0
	comiss	32(%rbp), %xmm0
	jb	.L11
	movl	$1, %eax
	jmp	.L16
.L11:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, %eax
.L16:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii " Detecte overtemperature!\0"
	.text
	.align 2
	.globl	_ZN17DCMotorController13checkOverHeatEf
	.def	_ZN17DCMotorController13checkOverHeatEf;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN17DCMotorController13checkOverHeatEf
_ZN17DCMotorController13checkOverHeatEf:
.LFB2442:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	comiss	%xmm1, %xmm0
	jb	.L22
	movq	16(%rbp), %rax
	movss	12(%rax), %xmm0
	comiss	24(%rbp), %xmm0
	jb	.L22
	movl	$1, %eax
	jmp	.L25
.L22:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, %eax
.L25:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN14FeedbackSystemC2ER17DCMotorController
	.def	_ZN14FeedbackSystemC2ER17DCMotorController;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN14FeedbackSystemC2ER17DCMotorController
_ZN14FeedbackSystemC2ER17DCMotorController:
.LFB2444:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movss	.LC3(%rip), %xmm3
	movss	.LC4(%rip), %xmm2
	movss	.LC5(%rip), %xmm1
	movq	%rax, %rcx
	call	_ZN17DCMotorControllerC2Efff
	movq	16(%rbp), %rax
	addq	$24, %rax
	movss	.LC3(%rip), %xmm3
	movss	.LC4(%rip), %xmm2
	movss	.LC5(%rip), %xmm1
	movq	%rax, %rcx
	call	_ZN17DCMotorControllerC1Efff
	movq	16(%rbp), %rcx
	movq	24(%rbp), %r8
	movq	(%r8), %rax
	movq	8(%r8), %rdx
	movq	%rax, 24(%rcx)
	movq	%rdx, 32(%rcx)
	movq	16(%r8), %rax
	movq	%rax, 40(%rcx)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN14FeedbackSystemC1ER17DCMotorController
	.def	_ZN14FeedbackSystemC1ER17DCMotorController;	.scl	2;	.type	32;	.endef
	.set	_ZN14FeedbackSystemC1ER17DCMotorController,_ZN14FeedbackSystemC2ER17DCMotorController
	.align 2
	.globl	_ZN14FeedbackSystem15getDcControllerEv
	.def	_ZN14FeedbackSystem15getDcControllerEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN14FeedbackSystem15getDcControllerEv
_ZN14FeedbackSystem15getDcControllerEv:
.LFB2446:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	addq	$24, %rax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii " DC Motor active at speed : \0"
.LC7:
	.ascii " (rpm)\0"
	.align 8
.LC8:
	.ascii " Detecte the fault! Stopping the DC motor. \0"
	.text
	.align 2
	.globl	_ZN14FeedbackSystem13controllMotorEfff
	.def	_ZN14FeedbackSystem13controllMotorEfff;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN14FeedbackSystem13controllMotorEfff
_ZN14FeedbackSystem13controllMotorEfff:
.LFB2447:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movss	%xmm1, 40(%rbp)
	movss	%xmm2, 48(%rbp)
	movss	%xmm3, 56(%rbp)
	movq	32(%rbp), %rax
	movss	56(%rbp), %xmm0
	movaps	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN17DCMotorController13checkOverHeatEf
	testb	%al, %al
	je	.L32
	movq	32(%rbp), %rax
	movss	48(%rbp), %xmm1
	movss	40(%rbp), %xmm0
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN17DCMotorController13checkOverLoadEff
	testb	%al, %al
	je	.L32
	movl	$1, %eax
	jmp	.L33
.L32:
	movl	$0, %eax
.L33:
	testb	%al, %al
	je	.L34
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rbx
	movq	32(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rcx
	call	_ZN17DCMotorController13getSpeedMotorEv
	movd	%xmm0, %eax
	movd	%eax, %xmm1
	movq	%rbx, %rcx
	call	_ZNSolsEf
	movq	%rax, %rcx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L36
.L34:
	movq	32(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rcx
	call	_ZN17DCMotorController7setStopEv
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.L36:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2448:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$112, %rsp
	.seh_stackalloc	112
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	leaq	-32(%rbp), %rax
	movss	.LC3(%rip), %xmm3
	movss	.LC4(%rip), %xmm2
	movss	.LC9(%rip), %xmm1
	movq	%rax, %rcx
	call	_ZN17DCMotorControllerC1Efff
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN17DCMotorController8setStartEv
	leaq	-32(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rcx
	call	_ZN17DCMotorController12setDirectionE21typeRotationDirection
	leaq	-32(%rbp), %rax
	movss	.LC10(%rip), %xmm1
	movq	%rax, %rcx
	call	_ZN17DCMotorController13setSpeedMotorEf
	leaq	-32(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN14FeedbackSystemC1ER17DCMotorController
	leaq	-80(%rbp), %rax
	movss	.LC3(%rip), %xmm3
	movss	.LC11(%rip), %xmm2
	movss	.LC5(%rip), %xmm1
	movq	%rax, %rcx
	call	_ZN14FeedbackSystem13controllMotorEfff
	movl	$0, %eax
	addq	$112, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.align 4
.LC3:
	.long	1117782016
	.align 4
.LC4:
	.long	1069547520
	.align 4
.LC5:
	.long	1094713344
	.align 4
.LC9:
	.long	1095761920
	.align 4
.LC10:
	.long	1157234688
	.align 4
.LC11:
	.long	1068708659
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEf;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cerr, "dr"
	.globl	.refptr._ZSt4cerr
	.linkonce	discard
.refptr._ZSt4cerr:
	.quad	_ZSt4cerr
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
