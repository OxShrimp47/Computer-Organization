# Name:Tommy Lee Truong and Professor Chi Yan Leung
# Last Edit:Nov 14 2018
# Program Name: Swap
	.text
main:
	la	$a0,n1
	la	$a1,n2
	jal	swap
	li	$v0,1	# print n1 and n2; should be 27 and 14
	lw	$a0,n1
	syscall
	li	$v0,11
	li	$a0,' '
	syscall
	li	$v0,1
	lw	$a0,n2
	syscall
	li	$v0,11
	li	$a0,'\n'
	syscall
	li	$v0,10	# exit
	syscall

swap:	# your code goes here
	la $a2, n3
	lw $v0, 0($a0)
	lw $v1, 0($a1)
	sw $v0, 4($a2)
	sw $v1, 4($a0)
	lw $a3, 0($a2)
	sw $a3, 4($a1)
	.data
n1:	.word	14
n2:	.word	27
n3:	.word
