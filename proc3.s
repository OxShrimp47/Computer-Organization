# Name:Tommy Lee Truong and Professor Chi Yan Leung
# Last Edit:Oct 28 2019
# Program Name: Procedure 3
	.data
x:	.word 5

y:	.word 10

	.text
main:	la      $t0, x
	lw      $s0, 0($t0)
	la      $t0, y
	lw      $s1, 0($t0)
	add $a0, $s0, $zero
	
	add $a1, $s1, $zero
	
	add $v0, $s1, $zero
	
	jal sum

	
	add $s1, $s0,$s1
	add $a0, $s1, $zero
	add $s1, $s1, $v0
	add $a0, $s1, $zero
	li $v0, 1
	syscall
	j end
	
sum:	add $t0, $a0, $zero
	addi $a0, $a1, 1
	add $t1,$a1,$zero
	addi $a1,$t0, 1
	add $t2, $ra, $zero
	jal sub
	add $v0, $v1, $zero
	addi $a0,$t0,-1
	addi $a1,$t1,-1
	jal sub
	add $s0, $v0, $zero
	add $s1, $v1, $zero
	add $v0, $s0,$s1
	add $ra, $t2, $zero
	add $s0, $t0, $zero
	add $s1, $t1, $zero
	jr $ra
sub:	sub $v1, $a1,$a0
	jr $ra
end:	li $v0,10
	syscall
