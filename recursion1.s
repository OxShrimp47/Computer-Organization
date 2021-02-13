# Name:Tommy Lee Truong and Professor Chi Yan Leung
# Last Edit:Nov 13 2019
# Program Name: Recursion 1
        .data

# TPS 2 #3 (statement to be displayed)

request: .asciiz "Please enter an interger: "
        .text
main: 		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
		# TPS 2 #3 (display statement)
		li $v0, 4
		la $a0, request
		syscall
		
		# TPS 2 #4 (read user input)
		li $v0,5
		syscall
		move $a0,$v0
		addi $v0,$zero,0	
		addi $t2,$zero,0
		jal recursion	# Call recursion(x)
		
		# TPS 2 #6 (read user input)
		sw $v0, 0($sp)
		lw $a0, 0($sp)
		li      $v0, 1		
		syscall	
		j end		# Jump to end of program


# Implementing recursion
recursion:	addi $sp, $sp, -12	# Push stack frame for local storage

		# TPS 2 #7 
		
		sw $ra, 8($sp)
		
		addi $t0, $a0,0
		addi $t1, $zero,10
		bne $t0, $t1, not_minus_one
		
		# TPS 2 #8 (update returned value)
		addi $v0, $v0,2
		
		j end_recur
			
not_minus_one:	addi $t1, $zero, 11
		bne $a0, $t1, not_zero

		# TPS 2 #9 (update returned value)
		addi $v0,$v0,1
		
		j end_recur		

not_zero:	sw $a0, 4($sp) 	
		# TPS 2 #11 (Prepare new input argument, i.e. m - 2)
		
		addi $a0,$a0,2
		
		jal recursion	# Call recursion(m - 2)
		
		# TPS 2 #12 
		lw $a0,4($sp)
		
		# TPS 2 #13 (Prepare new input argument, i.e. m - 1)
		
		addi $a0,$a0,1
		
		jal recursion	# Call recursion(m - 1)
		
		# TPS 2 #14 (update returned value)
		add $v0, $v0,$a0
		addi $v0,$v0,-2
	
		j end_recur
		

# End of recursion function	
end_recur:	# TPS 2 #15 
		lw $ra, 8($sp)
		addi $sp, $sp, 12	# Pop stack frame 
		jr $ra

# Terminating the program
end:		addi $sp, $sp 4	# Moving stack pointer back (pop the stack frame)
		li $v0, 10 
		syscall
