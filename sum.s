# Name:Tommy Lee Truong
# Last Edit:Oct 5 2019
# Program Name: Sum

.data
.text

addi $t0,$s0,0
addi $t1,$t0,1
addi $t2,$t1,2
addi $t3,$t2,3
addi $t4,$t3,4
addi $t5,$t4,5
addi $t6,$t5,6
addi $t7,$t6,7
addi $a0,$t7,0
li $v0,1
syscall 
li $v0,10
syscall

