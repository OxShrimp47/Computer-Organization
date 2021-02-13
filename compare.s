# Name:Tommy Lee Truong and Professor Chi Yan Leung
# Last Edit:Oct 22 2019
# Program Name: Compare
	.data
n:		.word 25
str1:		.asciiz "Less than\n"
str2:		.asciiz "Less than or equal to\n"
str3:		.asciiz "Greater than\n"
str4:		.asciiz "Greater than or equal to\n"
	.text
		la      $t0, n
		lw      $t0, 0($t0)
		li $v0,5
		syscall
#		beq $v0,$t0, greatE
#		slt $t1,$v0,$t0
#		bne $t1, $zero, less
#greatE:	li $v0,4
#		la $a0,str4
#		syscall
#		j end 
#less:		li $v0,4
#		la $a0,str1
#		syscall
#		j end
		beq $v0,$t0, lessE
		slt $t1,$v0,$t0
		beq $t1, $zero, great
lessE:		li $v0,4
		la $a0,str2
		syscall
		j end
great:		li $v0,4
		la $a0,str3
		syscall
		j end
end:		li $v0, 10
		syscall
