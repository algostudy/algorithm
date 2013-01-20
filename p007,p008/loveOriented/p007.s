	.file	"p007.c"
	.section	.rodata
.LC0:
	.string	"%u"
.LC1:
	.string	"yes"
.LC2:
	.string	"no"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$48, %rsp
.LCFI2:
	jmp	.L12
.L2:
.L12:
	leaq	-16(%rbp), %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	movl	-16(%rbp), %eax
	testl	%eax, %eax
	jne	.L3
	movl	$0, %eax
	movl	%eax, -28(%rbp)
	jmp	.L1
.L3:
	movl	-16(%rbp), %eax
	mov	%eax, %eax
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	js	.L5
	cvtsi2sdq	-40(%rbp), %xmm0
	movsd	%xmm0, -24(%rbp)
	jmp	.L6
.L5:
	movq	-40(%rbp), %rax
	shrq	%rax
	movq	-40(%rbp), %rdx
	andl	$1, %edx
	orq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -24(%rbp)
.L6:
	sqrtsd	-24(%rbp), %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	-48(%rbp), %xmm1
	ucomisd	-48(%rbp), %xmm1
	jp	.L13
	je	.L7
.L13:
	movsd	-24(%rbp), %xmm0
	call	sqrt
	movsd	%xmm0, -48(%rbp)
.L7:
	movsd	-48(%rbp), %xmm0
	cvttsd2si	%xmm0, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %edx
	imull	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L8
	movl	$.LC1, %edi
	call	puts
	jmp	.L2
.L8:
	movl	$.LC2, %edi
	call	puts
	jmp	.L2
.L1:
	movl	-28(%rbp), %eax
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x1
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-50)"
	.section	.note.GNU-stack,"",@progbits
