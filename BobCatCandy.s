# Name:Tommy Lee Truong
# Last Edit:Dec 3 2018
# Program Name: Bobcat Candy
.data 
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!"
# Declare any necessary data here



.text

main:
		#This is the main program.
		addi $sp, $sp -4	# Feel free to change the increment if you need for space.
		sw $ra, 0($sp)
		# Implement your main here
		#It first asks user to enter the price of each BobCat Bar.
		addi $s1, $zero, 8196
		lw $s2, 0($s1)
		#It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
		lw $s3, 0($s1)
		#It then asks user to enter how much money he/she has.
		lw $s4, 0($s1)
		#It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered. 
		jal maxBars
		#It then prints out a statement about the maximum BobCat Bars the user will receive.
		
		





		jal maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars

		# Print out final statement here
		addi $s1, $zero, 8200
		sw $s5, 0($s1)

		j end			# Jump to end of program



maxBars:
		# This function calculates the maximum number of BobCat Bars.
		addi $s5, $zero, 0
		# It takes in 3 arguments ($a0, $a1, $a0) as n, price, and money. It returns the maximum number of bars
		
		

		jal newBars 	# Call a helper function to keep track of the number of bars.
		add $s4, $zero, $t5
		add $s2, $zero, $t3
		jal newBars
loop:		add $s4,$zero, $t6
		jal newBars
		slt $t7,$s6,$s2
		beq $s6,$zero, loop
		jr $ra
		# End of maxBars

newBars:
		# This function calculates the number of BobCat Bars a user will receive based on n.
		# It takes in 2 arguments ($a0, $a1) as number of bars so far and n.
		addi $s6, $zero, 0
		sub $s4, $s4, $s2
		addi $s6, $s6,1
		slt $t7, $s4, $s2
		beq $t7, $zero, newBars
		add $s5,$s5,$s6
		
		
		
		
		
		jr $ra
		# End of newBars

end: 
		# Terminating the program
		lw $ra, 0($sp)
		addi $sp, $sp 4
		li $v0, 10 
		syscall
