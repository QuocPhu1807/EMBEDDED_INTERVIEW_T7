	.file	"main.cpp"
	.text
	.align 2
	.globl	_ZN5Wheel16setSpeedForWheelEd
	.def	_ZN5Wheel16setSpeedForWheelEd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN5Wheel16setSpeedForWheelEd
_ZN5Wheel16setSpeedForWheelEd:
.LFB2070:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN5Wheel16getSpeedForWheelEv
	.def	_ZN5Wheel16getSpeedForWheelEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN5Wheel16getSpeedForWheelEv
_ZN5Wheel16getSpeedForWheelEv:
.LFB2071:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	(%rax), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN3CarC2Ed
	.def	_ZN3CarC2Ed;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3CarC2Ed
_ZN3CarC2Ed:
.LFB2073:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN3CarC1Ed
	.def	_ZN3CarC1Ed;	.scl	2;	.type	32;	.endef
	.set	_ZN3CarC1Ed,_ZN3CarC2Ed
	.align 2
	.globl	_ZN3Car8getWheelEv
	.def	_ZN3Car8getWheelEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3Car8getWheelEv
_ZN3Car8getWheelEv:
.LFB2075:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	addq	$16, %rax
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN3Car12getMassOfCarEv
	.def	_ZN3Car12getMassOfCarEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3Car12getMassOfCarEv
_ZN3Car12getMassOfCarEv:
.LFB2076:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	(%rax), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN3Car19addMassOfPassengersEd
	.def	_ZN3Car19addMassOfPassengersEd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3Car19addMassOfPassengersEd
_ZN3Car19addMassOfPassengersEd:
.LFB2077:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movsd	(%rax), %xmm0
	addsd	24(%rbp), %xmm0
	movq	16(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN3Car17getTotalMassOfCarEv
	.def	_ZN3Car17getTotalMassOfCarEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3Car17getTotalMassOfCarEv
_ZN3Car17getTotalMassOfCarEv:
.LFB2078:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	8(%rax), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN3ABSC2ER3Car
	.def	_ZN3ABSC2ER3Car;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3ABSC2ER3Car
_ZN3ABSC2ER3Car:
.LFB2080:
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
	pxor	%xmm1, %xmm1
	movq	%rax, %rcx
	call	_ZN3CarC1Ed
	movq	16(%rbp), %rcx
	movq	24(%rbp), %r8
	movq	(%r8), %rax
	movq	8(%r8), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	16(%r8), %rax
	movq	%rax, 16(%rcx)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN3ABSC1ER3Car
	.def	_ZN3ABSC1ER3Car;	.scl	2;	.type	32;	.endef
	.set	_ZN3ABSC1ER3Car,_ZN3ABSC2ER3Car
	.align 2
	.globl	_ZN3ABS6getCarEv
	.def	_ZN3ABS6getCarEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3ABS6getCarEv
_ZN3ABS6getCarEv:
.LFB2082:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii " Brake Forces are applied normally.\0"
	.align 8
.LC3:
	.ascii " Warning: The wheel is locking up! Adjusting the brake force based on the mass of car: \0"
.LC4:
	.ascii " (kg)\0"
.LC5:
	.ascii " The speed of wheel now: \0"
.LC6:
	.ascii " (rpm)\0"
	.text
	.align 2
	.globl	_ZN3ABS17forceBrakeAppliedEv
	.def	_ZN3ABS17forceBrakeAppliedEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3ABS17forceBrakeAppliedEv
_ZN3ABS17forceBrakeAppliedEv:
.LFB2083:
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
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS6getCarEv
	movq	%rax, %rcx
	call	_ZN3Car8getWheelEv
	movq	%rax, %rcx
	call	_ZN5Wheel16getSpeedForWheelEv
	movq	%xmm0, %rax
	movq	%rax, %xmm2
	comisd	.LC1(%rip), %xmm2
	setnb	%al
	testb	%al, %al
	je	.L16
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L17
.L16:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rbx
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS6getCarEv
	movq	%rax, %rcx
	call	_ZN3Car17getTotalMassOfCarEv
	movq	%xmm0, %rax
	movq	%rax, %xmm1
	movq	%rbx, %rcx
	call	_ZNSolsEd
	movq	%rax, %rcx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.L17:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rbx
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS6getCarEv
	movq	%rax, %rcx
	call	_ZN3Car8getWheelEv
	movq	%rax, %rcx
	call	_ZN5Wheel16getSpeedForWheelEv
	movq	%xmm0, %rax
	movq	%rax, %xmm1
	movq	%rbx, %rcx
	call	_ZNSolsEd
	movq	%rax, %rcx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
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
.LFB2084:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movsd	.LC7(%rip), %xmm0
	leaq	-32(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN3CarC1Ed
	leaq	-32(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABSC1ER3Car
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS6getCarEv
	movq	%rax, %rcx
	call	_ZN3Car8getWheelEv
	movsd	.LC8(%rip), %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN5Wheel16setSpeedForWheelEd
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS17forceBrakeAppliedEv
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS6getCarEv
	movsd	.LC9(%rip), %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN3Car19addMassOfPassengersEd
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS6getCarEv
	movq	%rax, %rcx
	call	_ZN3Car8getWheelEv
	movsd	.LC10(%rip), %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN5Wheel16setSpeedForWheelEd
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ABS17forceBrakeAppliedEv
	movl	$0, %eax
	addq	$96, %rsp
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
	.align 8
.LC1:
	.long	0
	.long	1076101120
	.align 8
.LC7:
	.long	0
	.long	1083129856
	.align 8
.LC8:
	.long	0
	.long	1076494336
	.align 8
.LC9:
	.long	0
	.long	1079083008
	.align 8
.LC10:
	.long	0
	.long	1075970048
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEd;	.scl	2;	.type	32;	.endef
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
