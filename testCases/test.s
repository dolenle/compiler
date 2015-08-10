#[C--, The Shitty C Compiler]
	.text
	.globl main
main:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp
.BB.1.1:
	subl $8, %esp
	movl $.S0, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call inputText
	movl %eax, user.0
	subl $12, %esp
	movl user.0, %eax
	movl %eax, 4(%esp)
	movl $.S1, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S2, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call basics
	subl $8, %esp
	movl $.S3, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call staticLocal
	subl $4, %esp
	call staticLocal
	subl $4, %esp
	call staticLocal
	subl $8, %esp
	movl $.S4, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call nestedFor
	subl $8, %esp
	movl $.S5, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call pointers
	subl $8, %esp
	movl $.S6, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call arrayPtr
	subl $4, %esp
	call condExpr
	subl $12, %esp
	movl user.0, %eax
	movl %eax, 4(%esp)
	movl $.S7, %eax
	movl %eax, 0(%esp)
	call printf
	leave
	ret
	.size main,.-main
	.comm user.0, 4, 4
	.section .rodata
.S0:
	.string "Welcome to C--, the Shitty C Compiler. Please enter your name: "
.S1:
	.string "Hello, %s!\n"
.S2:
	.string "\nTesting basic operations...\n"
.S3:
	.string "\nTesting local static variable...\n"
.S4:
	.string "\nTesting nested for loops...\n"
.S5:
	.string "\nTesting pointers...\n"
.S6:
	.string "\nTesting arrays and pointers...\n"
.S7:
	.string "\nGoodbye, %s!\n"
# Allocated offset 4 to IDENT i
# Allocated offset 8 to %T1
# Allocated offset 12 to %T2
# Allocated offset 16 to %T3
# Allocated offset 20 to %T4
# Allocated offset 24 to IDENT j
# Allocated offset 28 to %T5
	.text
	.globl basics
basics:
	pushl %ebp
	movl %esp, %ebp
	subl $32, %esp
.BB.2.1:
	subl $4, %esp
	call inputInt
	movl %eax, -4(%ebp)
	movl $26, %eax
	movl -4(%ebp), %edx
	addl %eax, %edx
	movl %edx, -8(%ebp)
	movl -8(%ebp), %eax
	movl $7, %edx
	imull %eax, %edx
	movl %edx, -12(%ebp)
	movl $0, %edx
	movl -12(%ebp), %eax
	movl $3, %ecx
	idivl %ecx
	movl %eax, -16(%ebp)
	movl $0, %edx
	movl -16(%ebp), %eax
	movl $69, %ecx
	idivl %ecx
	movl %edx, -20(%ebp)
	movl $1, %eax
	movl -20(%ebp), %edx
	subl %eax, %edx
	movl %edx, -24(%ebp)
	subl $16, %esp
	movl -24(%ebp), %eax
	movl %eax, 8(%esp)
	movl -4(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S8, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S9, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call inputInt
	movl %eax, -4(%ebp)
	subl $16, %esp
	movl -4(%ebp), %eax
	cmpl $50, %eax
	jg .BB.2.2
	jmp .BB.2.3
.BB.2.2:
	movl $0, -28(%ebp)
	jmp .BB.2.4
.BB.2.3:
	movl $1, -28(%ebp)
	jmp .BB.2.4
.BB.2.4:
	movl -28(%ebp), %eax
	movl %eax, 8(%esp)
	movl -4(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S10, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S11, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S12, %eax
	movl %eax, 0(%esp)
	call printf
	subl $12, %esp
	movl $4, %eax
	movl %eax, 4(%esp)
	movl $.S13, %eax
	movl %eax, 0(%esp)
	call printf
	subl $12, %esp
	movl $120, %eax
	movl %eax, 4(%esp)
	movl $.S14, %eax
	movl %eax, 0(%esp)
	call printf
	subl $12, %esp
	movl $4, %eax
	movl %eax, 4(%esp)
	movl $.S15, %eax
	movl %eax, 0(%esp)
	call printf
	subl $12, %esp
	movl $4, %eax
	movl %eax, 4(%esp)
	movl $.S16, %eax
	movl %eax, 0(%esp)
	call printf
	leave
	ret
	.size basics,.-basics
	.comm user.0, 4, 4
	.section .rodata
.S8:
	.string "(7*(%i+26)/3)%69-1 = %i\n"
.S9:
	.string "\nBoolean expressions are also evaluated to 1 or 0.\n"
.S10:
	.string "!(%i > 50) = %i\n"
.S11:
	.string "\nThe SIZEOF operator is implemented for integer, array, and pointer types.\n"
.S12:
	.string "int k, a[10][3], *p;\n"
.S13:
	.string "sizeof(k) = %i\n"
.S14:
	.string "sizeof(a) = %i\n"
.S15:
	.string "sizeof(p) = %i\n"
.S16:
	.string "sizeof(int*) = %i\n"
	.text
	.globl staticLocal
staticLocal:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp
.BB.3.1:
	movl xx.1, %eax
	cmpl $0, %eax
	jne .BB.3.2
	jmp .BB.3.3
.BB.3.2:
	movl $0, xx.1
	jmp .BB.3.4
.BB.3.3:
	movl $100, xx.1
	jmp .BB.3.4
.BB.3.4:
	subl $12, %esp
	movl xx.1, %eax
	movl %eax, 4(%esp)
	movl $.S17, %eax
	movl %eax, 0(%esp)
	call printf
	leave
	ret
	.size staticLocal,.-staticLocal
	.comm xx.1, 4, 4
	.section .rodata
.S17:
	.string "Local static variable xx is %i\n"
# Allocated offset 4 to IDENT i
# Allocated offset 8 to IDENT j
# Allocated offset 12 to %T6
# Allocated offset 16 to %T7
# Allocated offset 20 to %T8
	.text
	.globl nestedFor
nestedFor:
	pushl %ebp
	movl %esp, %ebp
	subl $24, %esp
.BB.4.1:
.BB.4.2:
	movl $0, -4(%ebp)
	movl -4(%ebp), %eax
	cmpl $10, %eax
	jle .BB.4.3
	jmp .BB.4.5
.BB.4.3:
.BB.4.6:
	movl $0, -8(%ebp)
	movl -8(%ebp), %eax
	cmpl $10, %eax
	jle .BB.4.7
	jmp .BB.4.9
.BB.4.7:
	subl $12, %esp
	movl -8(%ebp), %eax
	movl -4(%ebp), %edx
	imull %eax, %edx
	movl %edx, -12(%ebp)
	movl -12(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S18, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.4.8
.BB.4.8:
	movl -8(%ebp), %eax
	movl %eax, -16(%ebp)
	incl -8(%ebp)
	movl -8(%ebp), %eax
	cmpl $10, %eax
	jle .BB.4.7
	jmp .BB.4.9
.BB.4.9:
	subl $8, %esp
	movl $.S19, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.4.4
.BB.4.4:
	movl -4(%ebp), %eax
	movl %eax, -20(%ebp)
	incl -4(%ebp)
	movl -4(%ebp), %eax
	cmpl $10, %eax
	jle .BB.4.3
	jmp .BB.4.5
.BB.4.5:
	leave
	ret
	.size nestedFor,.-nestedFor
	.comm xx.1, 4, 4
	.section .rodata
.S18:
	.string "%i\t"
.S19:
	.string "\n"
# Allocated offset 4 to IDENT a
# Allocated offset 8 to %T10
# Allocated offset 12 to %T11
# Allocated offset 16 to %T9
	.text
	.globl inputInt
inputInt:
	pushl %ebp
	movl %esp, %ebp
	subl $20, %esp
.BB.5.1:
	subl $8, %esp
	movl $.S20, %eax
	movl %eax, 0(%esp)
	call printf
.BB.5.2:
	subl $12, %esp
	leal -4(%ebp), %edx
	movl %edx, -8(%ebp)
	movl -8(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S21, %eax
	movl %eax, 0(%esp)
	call scanf
	movl %eax, -12(%ebp)
	movl -12(%ebp), %eax
	cmpl $0, %eax
	jne .BB.5.5
	jmp .BB.5.6
.BB.5.5:
	movl $0, -16(%ebp)
	jmp .BB.5.7
.BB.5.6:
	movl $1, -16(%ebp)
	jmp .BB.5.7
.BB.5.7:
	movl -16(%ebp), %eax
	cmpl $0, %eax
	jne .BB.5.3
	jmp .BB.5.4
.BB.5.3:
	jmp .BB.5.2
.BB.5.4:
	movl -4(%ebp), %eax
	leave
	ret
	.size inputInt,.-inputInt
	.comm xx.1, 4, 4
	.section .rodata
.S20:
	.string "Enter an integer: "
.S21:
	.string "%d"
# Allocated offset 4 to IDENT buf
# Allocated offset 8 to %T13
# Allocated offset 12 to %T12
	.text
	.globl inputText
inputText:
	pushl %ebp
	movl %esp, %ebp
	subl $16, %esp
.BB.6.1:
	subl $8, %esp
	movl $100, %eax
	movl %eax, 0(%esp)
	call malloc
	movl %eax, -4(%ebp)
.BB.6.2:
	subl $12, %esp
	movl -4(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S22, %eax
	movl %eax, 0(%esp)
	call scanf
	movl %eax, -8(%ebp)
	movl -8(%ebp), %eax
	cmpl $0, %eax
	jne .BB.6.5
	jmp .BB.6.6
.BB.6.5:
	movl $0, -12(%ebp)
	jmp .BB.6.7
.BB.6.6:
	movl $1, -12(%ebp)
	jmp .BB.6.7
.BB.6.7:
	movl -12(%ebp), %eax
	cmpl $0, %eax
	jne .BB.6.3
	jmp .BB.6.4
.BB.6.3:
	jmp .BB.6.2
.BB.6.4:
	movl -4(%ebp), %eax
	leave
	ret
	.size inputText,.-inputText
	.comm xx.1, 4, 4
	.section .rodata
.S22:
	.string "%s"
# Allocated offset 4 to IDENT i
# Allocated offset 8 to %T14
# Allocated offset 12 to %T15
# Allocated offset 16 to %T16
# Allocated offset 20 to %T17
# Allocated offset 24 to %T18
# Allocated offset 28 to %T19
# Allocated offset 32 to %T20
# Allocated offset 36 to %T21
# Allocated offset 40 to %T22
# Allocated offset 80 to IDENT a2
# Allocated offset 84 to %T23
# Allocated offset 88 to %T24
# Allocated offset 92 to %T25
# Allocated offset 96 to %T26
# Allocated offset 100 to %T27
# Allocated offset 104 to %T28
# Allocated offset 108 to %T29
# Allocated offset 112 to %T30
# Allocated offset 116 to %T31
# Allocated offset 120 to %T32
# Allocated offset 124 to %T33
# Allocated offset 128 to %T34
# Allocated offset 132 to %T35
# Allocated offset 136 to %T36
# Allocated offset 140 to %T37
# Allocated offset 144 to %T38
# Allocated offset 148 to IDENT p2
# Allocated offset 152 to %T39
# Allocated offset 156 to %T40
# Allocated offset 160 to %T41
# Allocated offset 164 to %T42
	.text
	.globl arrayPtr
arrayPtr:
	pushl %ebp
	movl %esp, %ebp
	subl $168, %esp
.BB.7.1:
	subl $8, %esp
	movl $.S23, %eax
	movl %eax, 0(%esp)
	call printf
.BB.7.2:
	movl $0, -4(%ebp)
	movl -4(%ebp), %eax
	cmpl $10, %eax
	jl .BB.7.3
	jmp .BB.7.5
.BB.7.3:
	leal a.2, %edx
	movl %edx, -8(%ebp)
	movl $4, %eax
	movl -4(%ebp), %edx
	imull %eax, %edx
	movl %edx, -12(%ebp)
	movl -12(%ebp), %eax
	movl -8(%ebp), %edx
	addl %eax, %edx
	movl %edx, -16(%ebp)
	movl $2, %eax
	movl -4(%ebp), %edx
	imull %eax, %edx
	movl %edx, -20(%ebp)
	movl -16(%ebp), %eax
	movl -20(%ebp), %edx
	movl %edx, (%eax)
	subl $16, %esp
	leal a.2, %edx
	movl %edx, -24(%ebp)
	movl $4, %eax
	movl -4(%ebp), %edx
	imull %eax, %edx
	movl %edx, -28(%ebp)
	movl -28(%ebp), %eax
	movl -24(%ebp), %edx
	addl %eax, %edx
	movl %edx, -32(%ebp)
	movl -32(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -36(%ebp)
	movl -36(%ebp), %eax
	movl %eax, 8(%esp)
	movl -4(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S24, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.7.4
.BB.7.4:
	movl -4(%ebp), %eax
	movl %eax, -40(%ebp)
	incl -4(%ebp)
	movl -4(%ebp), %eax
	cmpl $10, %eax
	jl .BB.7.3
	jmp .BB.7.5
.BB.7.5:
	subl $8, %esp
	movl $.S25, %eax
	movl %eax, 0(%esp)
	call printf
	subl $16, %esp
	leal -80(%ebp), %edx
	movl %edx, -84(%ebp)
	leal a.2, %edx
	movl %edx, -88(%ebp)
	movl $40, %eax
	movl %eax, 8(%esp)
	movl -88(%ebp), %eax
	movl %eax, 4(%esp)
	movl -84(%ebp), %eax
	movl %eax, 0(%esp)
	call memcpy
.BB.7.6:
	movl $0, -4(%ebp)
	movl -4(%ebp), %eax
	cmpl $10, %eax
	jl .BB.7.7
	jmp .BB.7.9
.BB.7.7:
	subl $16, %esp
	leal -80(%ebp), %edx
	movl %edx, -92(%ebp)
	movl $4, %eax
	movl -4(%ebp), %edx
	imull %eax, %edx
	movl %edx, -96(%ebp)
	movl -96(%ebp), %eax
	movl -92(%ebp), %edx
	addl %eax, %edx
	movl %edx, -100(%ebp)
	movl -100(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -104(%ebp)
	movl -104(%ebp), %eax
	movl %eax, 8(%esp)
	movl -4(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S26, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.7.8
.BB.7.8:
	movl -4(%ebp), %eax
	movl %eax, -108(%ebp)
	incl -4(%ebp)
	movl -4(%ebp), %eax
	cmpl $10, %eax
	jl .BB.7.7
	jmp .BB.7.9
.BB.7.9:
	leal a.2, %edx
	movl %edx, -112(%ebp)
	movl $4, %eax
	movl $2, %edx
	imull %eax, %edx
	movl %edx, -116(%ebp)
	movl -116(%ebp), %eax
	movl -112(%ebp), %edx
	addl %eax, %edx
	movl %edx, -120(%ebp)
	movl -120(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -124(%ebp)
	leal -124(%ebp), %edx
	movl %edx, p.3
	subl $12, %esp
	movl p.3, %eax
	movl (%eax), %edx
	movl %edx, -128(%ebp)
	movl -128(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S27, %eax
	movl %eax, 0(%esp)
	call printf
	leal -80(%ebp), %edx
	movl %edx, -132(%ebp)
	movl $4, %eax
	movl $2, %edx
	imull %eax, %edx
	movl %edx, -136(%ebp)
	movl -136(%ebp), %eax
	movl -132(%ebp), %edx
	addl %eax, %edx
	movl %edx, -140(%ebp)
	movl -140(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -144(%ebp)
	leal -144(%ebp), %edx
	movl %edx, -148(%ebp)
	subl $12, %esp
	movl -148(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -152(%ebp)
	movl -152(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S28, %eax
	movl %eax, 0(%esp)
	call printf
	movl -148(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -156(%ebp)
	movl p.3, %eax
	movl (%eax), %edx
	movl %edx, -160(%ebp)
	movl $0, %edx
	movl -156(%ebp), %eax
	movl -160(%ebp), %ecx
	idivl %ecx
	movl %eax, -164(%ebp)
	movl -164(%ebp), %eax
	cmpl $1, %eax
	je .BB.7.10
	jmp .BB.7.11
.BB.7.10:
	subl $8, %esp
	movl $.S29, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.7.12
.BB.7.11:
	subl $8, %esp
	movl $.S30, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.7.12
.BB.7.12:
	leave
	ret
	.size arrayPtr,.-arrayPtr
	.comm a.2, 40, 4
	.comm p.3, 4, 4
	.section .rodata
.S23:
	.string "Setting array using for loop\n"
.S24:
	.string "loop1: a[%i]=%i\n"
.S25:
	.string "Copying array using memcpy()\n"
.S26:
	.string "loop2: a2[%i]=%i\n"
.S27:
	.string "a[2] = %i\n"
.S28:
	.string "a2[2] = %i\n"
.S29:
	.string "they are equal...\n"
.S30:
	.string "You should not see this!!!\n"
# Allocated offset 4 to IDENT m
# Allocated offset 8 to IDENT y
# Allocated offset 12 to %T43
# Allocated offset 16 to IDENT z
# Allocated offset 20 to %T44
	.text
	.globl pointers
pointers:
	pushl %ebp
	movl %esp, %ebp
	subl $24, %esp
.BB.8.1:
	subl $8, %esp
	movl $4, %eax
	movl %eax, 0(%esp)
	call malloc
	movl %eax, -4(%ebp)
	subl $8, %esp
	movl $.S31, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call inputInt
	movl %eax, -8(%ebp)
	movl -4(%ebp), %eax
	movl -8(%ebp), %edx
	movl %edx, (%eax)
	subl $16, %esp
	movl -4(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -12(%ebp)
	movl -12(%ebp), %eax
	movl %eax, 8(%esp)
	movl -8(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S32, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call inputInt
	movl %eax, -16(%ebp)
	leal -16(%ebp), %edx
	movl %edx, -4(%ebp)
	subl $12, %esp
	movl -16(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S33, %eax
	movl %eax, 0(%esp)
	call printf
	subl $12, %esp
	movl -4(%ebp), %eax
	movl (%eax), %edx
	movl %edx, -20(%ebp)
	movl -20(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S34, %eax
	movl %eax, 0(%esp)
	call printf
	leave
	ret
	.size pointers,.-pointers
	.comm p.3, 4, 4
	.section .rodata
.S31:
	.string "Setting and getting number via pointer...\n"
.S32:
	.string "(*m = %i) *m is %i\n"
.S33:
	.string "z = %i\n"
.S34:
	.string "(m = &z) *m is %i\n"
# Allocated offset 4 to IDENT m
# Allocated offset 8 to IDENT x
# Allocated offset 12 to IDENT y
# Allocated offset 16 to IDENT j
# Allocated offset 20 to IDENT y
# Allocated offset 24 to %T45
# Allocated offset 28 to %T46
# Allocated offset 32 to IDENT iterations
# Allocated offset 36 to %T48
# Allocated offset 40 to %T49
# Allocated offset 44 to %T47
# Allocated offset 48 to IDENT a
# Allocated offset 52 to IDENT b
# Allocated offset 56 to IDENT i
# Allocated offset 60 to IDENT c
# Allocated offset 64 to %T50
	.text
	.globl condExpr
condExpr:
	pushl %ebp
	movl %esp, %ebp
	subl $68, %esp
.BB.9.1:
	subl $8, %esp
	movl $.S35, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S36, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S37, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S38, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S39, %eax
	movl %eax, 0(%esp)
	call printf
.BB.9.2:
	movl $1, %eax
	cmpl $0, %eax
	jne .BB.9.3
	jmp .BB.9.4
.BB.9.3:
	subl $8, %esp
	movl $.S40, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call inputInt
	movl %eax, -4(%ebp)
	movl -4(%ebp), %eax
	cmpl $1, %eax
	je .BB.9.5
	jmp .BB.9.6
.BB.9.5:
	subl $8, %esp
	movl $.S41, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call inputInt
	movl %eax, -8(%ebp)
	movl -8(%ebp), %eax
	cmpl $20, %eax
	jge .BB.9.8
	jmp .BB.9.9
.BB.9.8:
	subl $8, %esp
	movl $.S42, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.10
.BB.9.9:
	subl $8, %esp
	movl $.S43, %eax
	movl %eax, 0(%esp)
	call printf
	subl $4, %esp
	call inputInt
	movl %eax, -12(%ebp)
	movl -8(%ebp), %eax
	cmpl -12(%ebp), %eax
	jl .BB.9.11
	jmp .BB.9.12
.BB.9.11:
	subl $16, %esp
	movl -12(%ebp), %eax
	movl %eax, 8(%esp)
	movl -8(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S44, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.13
.BB.9.12:
	movl -8(%ebp), %eax
	cmpl -12(%ebp), %eax
	je .BB.9.14
	jmp .BB.9.15
.BB.9.14:
	subl $8, %esp
	movl $.S45, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.16
.BB.9.15:
	subl $16, %esp
	movl -12(%ebp), %eax
	movl %eax, 8(%esp)
	movl -8(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S46, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.16
.BB.9.16:
	jmp .BB.9.13
.BB.9.13:
	jmp .BB.9.10
.BB.9.10:
	jmp .BB.9.7
.BB.9.6:
	movl -4(%ebp), %eax
	cmpl $2, %eax
	je .BB.9.17
	jmp .BB.9.18
.BB.9.17:
	subl $8, %esp
	movl $.S47, %eax
	movl %eax, 0(%esp)
	call printf
	movl $0, -16(%ebp)
	subl $4, %esp
	call inputInt
	movl %eax, -20(%ebp)
	subl $12, %esp
	movl x.4, %eax
	movl %eax, 4(%esp)
	movl $.S48, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S49, %eax
	movl %eax, 0(%esp)
	call printf
.BB.9.20:
	movl -16(%ebp), %eax
	cmpl -20(%ebp), %eax
	jl .BB.9.21
	jmp .BB.9.22
.BB.9.21:
	movl x.4, %eax
	movl %eax, -24(%ebp)
	incl x.4
	movl -16(%ebp), %eax
	movl %eax, -28(%ebp)
	incl -16(%ebp)
	jmp .BB.9.20
.BB.9.22:
	subl $12, %esp
	movl x.4, %eax
	movl %eax, 4(%esp)
	movl $.S50, %eax
	movl %eax, 0(%esp)
	call printf
	subl $8, %esp
	movl $.S51, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.19
.BB.9.18:
	movl -4(%ebp), %eax
	cmpl $3, %eax
	je .BB.9.23
	jmp .BB.9.24
.BB.9.23:
	subl $8, %esp
	movl $.S52, %eax
	movl %eax, 0(%esp)
	call printf
.BB.9.26:
	subl $12, %esp
	leal -32(%ebp), %edx
	movl %edx, -36(%ebp)
	movl -36(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S53, %eax
	movl %eax, 0(%esp)
	call scanf
	movl %eax, -40(%ebp)
	movl -40(%ebp), %eax
	cmpl $0, %eax
	jne .BB.9.29
	jmp .BB.9.30
.BB.9.29:
	movl $0, -44(%ebp)
	jmp .BB.9.31
.BB.9.30:
	movl $1, -44(%ebp)
	jmp .BB.9.31
.BB.9.31:
	movl -44(%ebp), %eax
	cmpl $0, %eax
	jne .BB.9.27
	jmp .BB.9.28
.BB.9.27:
	jmp .BB.9.26
.BB.9.28:
	movl $1, -48(%ebp)
	movl $1, -52(%ebp)
.BB.9.32:
	movl $0, -56(%ebp)
	movl -56(%ebp), %eax
	cmpl -32(%ebp), %eax
	jl .BB.9.33
	jmp .BB.9.35
.BB.9.33:
	movl -52(%ebp), %eax
	movl -48(%ebp), %edx
	addl %eax, %edx
	movl %edx, -60(%ebp)
	movl -52(%ebp), %eax
	movl %eax, -48(%ebp)
	movl -60(%ebp), %eax
	movl %eax, -52(%ebp)
	subl $12, %esp
	movl -60(%ebp), %eax
	movl %eax, 4(%esp)
	movl $.S54, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.34
.BB.9.34:
	movl -56(%ebp), %eax
	movl %eax, -64(%ebp)
	incl -56(%ebp)
	movl -56(%ebp), %eax
	cmpl -32(%ebp), %eax
	jl .BB.9.33
	jmp .BB.9.35
.BB.9.35:
	subl $8, %esp
	movl $.S55, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.25
.BB.9.24:
	movl -4(%ebp), %eax
	cmpl $0, %eax
	je .BB.9.36
	jmp .BB.9.37
.BB.9.36:
	subl $8, %esp
	movl $.S56, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.4
	jmp .BB.9.38
.BB.9.37:
	subl $8, %esp
	movl $.S57, %eax
	movl %eax, 0(%esp)
	call printf
	jmp .BB.9.38
.BB.9.38:
	jmp .BB.9.25
.BB.9.25:
	jmp .BB.9.19
.BB.9.19:
	jmp .BB.9.7
.BB.9.7:
	jmp .BB.9.2
.BB.9.4:
	leave
	ret
	.size condExpr,.-condExpr
	.comm x.4, 4, 4
	.section .rodata
.S35:
	.string "\nMenu - enter one of the following:\n"
.S36:
	.string "\t1 to demo IF-ELSE statements\n"
.S37:
	.string "\t2 to demo WHILE loops\n"
.S38:
	.string "\t3 to demo FOR loops\n"
.S39:
	.string "\t0 to leave this demo.\n"
.S40:
	.string "\n"
.S41:
	.string "Enter a number less than 20... "
.S42:
	.string "I said less than 20, you dingus\n"
.S43:
	.string "Enter another number to compare with the previous...\n"
.S44:
	.string "%i is less than %i\n"
.S45:
	.string "The two numbers are equal.\n"
.S46:
	.string "%i is greater than %i\n"
.S47:
	.string "This demo increments a global variable.\n"
.S48:
	.string "x is now %i\n"
.S49:
	.string "Running loop...\n"
.S50:
	.string "x is now %i\n"
.S51:
	.string "You can try this option again and increase x further.\n"
.S52:
	.string "Enter the number of iterations of Fibonacci numbers (FOR loop): "
.S53:
	.string "%d"
.S54:
	.string "%i "
.S55:
	.string "\n"
.S56:
	.string "Breaking out of WHILE loop\n"
.S57:
	.string "Invalid option, try again: "
