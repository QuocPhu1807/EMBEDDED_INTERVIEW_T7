	.file	"main.cpp"
	.text
	.align 2
	.globl	_ZN8GPSPointC2Edd
	.def	_ZN8GPSPointC2Edd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8GPSPointC2Edd
_ZN8GPSPointC2Edd:
.LFB2650:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	%xmm2, 32(%rbp)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movq	16(%rbp), %rax
	movsd	32(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN8GPSPointC1Edd
	.def	_ZN8GPSPointC1Edd;	.scl	2;	.type	32;	.endef
	.set	_ZN8GPSPointC1Edd,_ZN8GPSPointC2Edd
	.section .rdata,"dr"
	.align 8
.LC4:
	.ascii " The latitude and the longitude are not right!!\0"
	.text
	.align 2
	.globl	_ZN8GPSPoint14isValidOfPointEv
	.def	_ZN8GPSPoint14isValidOfPointEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8GPSPoint14isValidOfPointEv
_ZN8GPSPoint14isValidOfPointEv:
.LFB2652:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	(%rax), %xmm0
	comisd	.LC0(%rip), %xmm0
	jb	.L3
	movq	16(%rbp), %rax
	movsd	(%rax), %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jb	.L3
	movq	16(%rbp), %rax
	movsd	8(%rax), %xmm0
	comisd	.LC2(%rip), %xmm0
	jb	.L3
	movq	16(%rbp), %rax
	movsd	8(%rax), %xmm1
	movsd	.LC3(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jb	.L3
	movl	$1, %eax
	jmp	.L8
.L3:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
.L8:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN8GPSPoint16convertToRadiansEdd
	.def	_ZN8GPSPoint16convertToRadiansEdd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8GPSPoint16convertToRadiansEdd
_ZN8GPSPoint16convertToRadiansEdd:
.LFB2653:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	%xmm2, 32(%rbp)
	movsd	24(%rbp), %xmm1
	movsd	.LC5(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movq	16(%rbp), %rax
	movsd	%xmm0, (%rax)
	movsd	32(%rbp), %xmm1
	movsd	.LC5(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movq	16(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN8GPSPoint11getLatitudeEv
	.def	_ZN8GPSPoint11getLatitudeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8GPSPoint11getLatitudeEv
_ZN8GPSPoint11getLatitudeEv:
.LFB2654:
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
	.globl	_ZN8GPSPoint12getLongitudeEv
	.def	_ZN8GPSPoint12getLongitudeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8GPSPoint12getLongitudeEv
_ZN8GPSPoint12getLongitudeEv:
.LFB2655:
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
	.section .rdata,"dr"
	.align 8
.LC6:
	.ascii " Calculate the distance between two coordinate on Earth according to the Haversine formula: \0"
	.align 8
.LC9:
	.ascii " The distances between two coodinates on the Earth: \0"
.LC10:
	.ascii " (km)\0"
	.text
	.globl	_Z21distanceBetweenPointsdddd
	.def	_Z21distanceBetweenPointsdddd;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z21distanceBetweenPointsdddd
_Z21distanceBetweenPointsdddd:
.LFB2656:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$80, %rsp
	.seh_stackalloc	80
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	movups	%xmm6, 0(%rbp)
	.seh_savexmm	%xmm6, 48
	movups	%xmm7, 16(%rbp)
	.seh_savexmm	%xmm7, 64
	.seh_endprologue
	movsd	%xmm0, 48(%rbp)
	movsd	%xmm1, 56(%rbp)
	movsd	%xmm2, 64(%rbp)
	movsd	%xmm3, 72(%rbp)
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movsd	64(%rbp), %xmm0
	subsd	48(%rbp), %xmm0
	movsd	.LC7(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	sin
	movq	%xmm0, %rax
	movl	$2, %edx
	movq	%rax, %xmm0
	call	_ZSt3powIdiEN9__gnu_cxx11__promote_2IDTplcvNS1_IT_XsrSt12__is_integerIS2_E7__valueEE6__typeELi0EcvNS1_IT0_XsrS3_IS7_E7__valueEE6__typeELi0EEXsrS3_ISB_E7__valueEE6__typeES2_S7_
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	sqrt
	movapd	%xmm0, %xmm6
	movq	48(%rbp), %rax
	movq	%rax, %xmm0
	call	cos
	movapd	%xmm0, %xmm7
	movq	64(%rbp), %rax
	movq	%rax, %xmm0
	call	cos
	mulsd	%xmm0, %xmm7
	movsd	64(%rbp), %xmm0
	subsd	48(%rbp), %xmm0
	movsd	.LC7(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	sin
	movq	%xmm0, %rax
	movl	$2, %edx
	movq	%rax, %xmm0
	call	_ZSt3powIdiEN9__gnu_cxx11__promote_2IDTplcvNS1_IT_XsrSt12__is_integerIS2_E7__valueEE6__typeELi0EcvNS1_IT0_XsrS3_IS7_E7__valueEE6__typeELi0EEXsrS3_ISB_E7__valueEE6__typeES2_S7_
	mulsd	%xmm7, %xmm0
	addsd	%xmm0, %xmm6
	movq	%xmm6, %rax
	movq	%rax, %xmm0
	call	asin
	movsd	.LC8(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cerr(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movsd	-8(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZNSolsEd
	movq	%rax, %rcx
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	movups	0(%rbp), %xmm6
	movups	16(%rbp), %xmm7
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC11:
	.ascii " Latitude of point: \0"
	.align 8
.LC12:
	.ascii " Enter the value in range of [-90,90].\0"
.LC13:
	.ascii " Longitude of point: \0"
	.align 8
.LC14:
	.ascii "Enter the value in range of [-180,180]. \0"
	.text
	.globl	_Z14inputCoodinatedd
	.def	_Z14inputCoodinatedd;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z14inputCoodinatedd
_Z14inputCoodinatedd:
.LFB2657:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
.L23:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	16(%rbp), %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERd
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSi6ignoreEv
	movsd	16(%rbp), %xmm0
	comisd	.LC0(%rip), %xmm0
	jb	.L20
	movsd	16(%rbp), %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jnb	.L22
.L20:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L23
.L22:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERd
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSi6ignoreEv
	movsd	24(%rbp), %xmm0
	comisd	.LC2(%rip), %xmm0
	jb	.L24
	movsd	24(%rbp), %xmm1
	movsd	.LC3(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jnb	.L29
.L24:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L22
.L29:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC15:
	.ascii " Please enter the coordinate of point 1:\0"
	.align 8
.LC16:
	.ascii " Please enter the coordinate of point 2:\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2658:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$104, %rsp
	.seh_stackalloc	104
	leaq	96(%rsp), %rbp
	.seh_setframe	%rbp, 96
	.seh_endprologue
	movl	%ecx, 48(%rbp)
	movq	%rdx, 56(%rbp)
	call	__main
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	_Z14inputCoodinatedd
	movsd	-16(%rbp), %xmm1
	movsd	-8(%rbp), %xmm0
	leaq	-48(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN8GPSPointC1Edd
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8GPSPoint14isValidOfPointEv
	testb	%al, %al
	je	.L31
	movsd	-16(%rbp), %xmm1
	movsd	-8(%rbp), %xmm0
	leaq	-48(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN8GPSPoint16convertToRadiansEdd
.L31:
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	%rax, %rcx
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movsd	-32(%rbp), %xmm0
	movq	-24(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	_Z14inputCoodinatedd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	leaq	-64(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN8GPSPointC1Edd
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8GPSPoint14isValidOfPointEv
	testb	%al, %al
	je	.L32
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	leaq	-64(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN8GPSPoint16convertToRadiansEdd
.L32:
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8GPSPoint12getLongitudeEv
	movq	%xmm0, %rdi
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8GPSPoint11getLatitudeEv
	movq	%xmm0, %rsi
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8GPSPoint12getLongitudeEv
	movq	%xmm0, %rbx
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8GPSPoint11getLatitudeEv
	movq	%xmm0, %rax
	movq	%rdi, %xmm3
	movq	%rsi, %xmm2
	movq	%rbx, %xmm1
	movq	%rax, %xmm0
	call	_Z21distanceBetweenPointsdddd
	movl	$0, %eax
	addq	$104, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt3powIdiEN9__gnu_cxx11__promote_2IDTplcvNS1_IT_XsrSt12__is_integerIS2_E7__valueEE6__typeELi0EcvNS1_IT0_XsrS3_IS7_E7__valueEE6__typeELi0EEXsrS3_ISB_E7__valueEE6__typeES2_S7_,"x"
	.linkonce discard
	.globl	_ZSt3powIdiEN9__gnu_cxx11__promote_2IDTplcvNS1_IT_XsrSt12__is_integerIS2_E7__valueEE6__typeELi0EcvNS1_IT0_XsrS3_IS7_E7__valueEE6__typeELi0EEXsrS3_ISB_E7__valueEE6__typeES2_S7_
	.def	_ZSt3powIdiEN9__gnu_cxx11__promote_2IDTplcvNS1_IT_XsrSt12__is_integerIS2_E7__valueEE6__typeELi0EcvNS1_IT0_XsrS3_IS7_E7__valueEE6__typeELi0EEXsrS3_ISB_E7__valueEE6__typeES2_S7_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3powIdiEN9__gnu_cxx11__promote_2IDTplcvNS1_IT_XsrSt12__is_integerIS2_E7__valueEE6__typeELi0EcvNS1_IT0_XsrS3_IS7_E7__valueEE6__typeELi0EEXsrS3_ISB_E7__valueEE6__typeES2_S7_
_ZSt3powIdiEN9__gnu_cxx11__promote_2IDTplcvNS1_IT_XsrSt12__is_integerIS2_E7__valueEE6__typeELi0EcvNS1_IT0_XsrS3_IS7_E7__valueEE6__typeELi0EEXsrS3_ISB_E7__valueEE6__typeES2_S7_:
.LFB2968:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movl	%edx, 24(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2sdl	24(%rbp), %xmm0
	movq	16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$32, %rsp
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
.LC0:
	.long	0
	.long	-1068072960
	.align 8
.LC1:
	.long	0
	.long	1079410688
	.align 8
.LC2:
	.long	0
	.long	-1067024384
	.align 8
.LC3:
	.long	0
	.long	1080459264
	.align 8
.LC5:
	.long	-1571644103
	.long	1066524486
	.align 8
.LC7:
	.long	0
	.long	1073741824
	.align 8
.LC8:
	.long	0
	.long	1086907136
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	sin;	.scl	2;	.type	32;	.endef
	.def	sqrt;	.scl	2;	.type	32;	.endef
	.def	cos;	.scl	2;	.type	32;	.endef
	.def	asin;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERd;	.scl	2;	.type	32;	.endef
	.def	_ZNSi6ignoreEv;	.scl	2;	.type	32;	.endef
	.def	pow;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cerr, "dr"
	.globl	.refptr._ZSt4cerr
	.linkonce	discard
.refptr._ZSt4cerr:
	.quad	_ZSt4cerr
