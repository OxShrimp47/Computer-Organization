# Name:Tommy Lee Truong
# Last Edit:Oct 22 2019
# Program Name: Sum All
	.data
request:	.asciiz "Please enter a number: "
psum:		.asciiz "Sum of positive number is:\n "
nsum:		.asciiz "Sum of negative number is: \n"
next:		.asciiz "\n"
	.text
		add $t0,$zero,$zero
		add $t1,$zero,$zero
loop:		li $v0, 4
		la $a0, request
		syscall
		li $v0,5
		syscall
		beq $v0, $zero, terminate
		slt $t2, $v0,$zero
		bne $t2, $zero,neg
		beq $t2, $zero,pos
		j terminate	
pos:		add $t0,$t0,$v0
		j loop
neg:		add $t1,$t1,$v0	
		j loop
terminate:	li $v0, 4
		la $a0,psum
		syscall
		li $v0, 1
		move $a0, $t0
		syscall
		li $v0, 4
		la $a0, next
		syscall
		li $v0, 4
		la $a0,nsum
		syscall
		li $v0, 1
		move $a0, $t1
		syscall
		li $v0, 4
		la $a0, next
		syscall
		li $v0,10
		syscall
		
		
