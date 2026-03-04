	.file	"main.c"
	.text
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
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
	movl	%edx, 40(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	40(%rbp), %eax
	jl	.L3
	nop
	nop
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d \0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
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
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	leaq	.LC0(%rip), %rcx
	movl	%eax, %edx
	call	__mingw_printf
	addl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L6
	movl	$10, %ecx
	call	putchar
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "data.bin\0"
.LC2:
	.ascii "data2.bin\0"
.LC3:
	.ascii "all good\0"
.LC4:
	.ascii "something's wrong\0"
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
	call	__main
	movl	$0, %ecx
	call	_time64
	movl	%eax, %ecx
	call	srand
	movl	$10, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -32(%rbp)
	movl	-4(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fillArray
	movl	-4(%rbp), %edx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	fillArray
	movl	-4(%rbp), %edx
	movq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	fillArray
	movl	-4(%rbp), %edx
	movq	-16(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movl	%edx, %r8d
	movq	%rax, %rdx
	call	saveToFile
	movl	-4(%rbp), %edx
	movq	-32(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movl	%edx, %r8d
	movq	%rax, %rdx
	call	saveToFile
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, -40(%rbp)
	leaq	-40(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movl	$0, %r8d
	movq	%rax, %rdx
	call	loadFromFile
	movq	%rax, -16(%rbp)
	movl	-4(%rbp), %edx
	movq	-24(%rbp), %rax
	leaq	.LC2(%rip), %rcx
	movl	%edx, %r8d
	movq	%rax, %rdx
	call	saveToFile
	movq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	-40(%rbp), %eax
	cltq
	addq	$1, %rax
	sall	$2, %eax
	movl	%eax, -36(%rbp)
	movl	$0, -44(%rbp)
	movl	-36(%rbp), %edx
	leaq	-44(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movl	%edx, %r8d
	movq	%rax, %rdx
	call	loadFromFile
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, -48(%rbp)
	leaq	-48(%rbp), %rax
	leaq	.LC2(%rip), %rcx
	movl	$0, %r8d
	movq	%rax, %rdx
	call	loadFromFile
	movq	%rax, -24(%rbp)
	movq	.refptr.saveCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L8
	movq	.refptr.loadCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L8
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	puts
	jmp	.L9
.L8:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
.L9:
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.loadCount, "dr"
	.p2align	3, 0
	.globl	.refptr.loadCount
	.linkonce	discard
.refptr.loadCount:
	.quad	loadCount
	.section	.rdata$.refptr.saveCount, "dr"
	.p2align	3, 0
	.globl	.refptr.saveCount
	.linkonce	discard
.refptr.saveCount:
	.quad	saveCount
