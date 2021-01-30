# arithmetic.asm
# A simple calculator program in MIPS Assembly for CS64
#

.text
main:
	# TODO: Write your code here
	# VARS: $t0 = temp, $t1 = a, $t2 = b, $t3 = c

	#get input for A and store it in $t1
	li $v0, 5
	syscall
	move $t1, $v0

	#get input for B and store it in $t2
	li $v0, 5
	syscall
	move $t2, $v0
	
	#get input for C and store it in $t3
	li $v0, 5
	syscall
	move $t3, $v0

	sub $t4, $t1, $t2 #CALCULATIONS: $t4 = a - b
	sll $t4, $t4, 6 #CALCULATIONS: $t5 = 64*(a-b)
	move $t5, $t4 #store result in $t5

	li $t0, 100 #set temp var $t0 as 100
	mult $t3, $t0 #CALCULATIONS: $t6 = 100*c
	mflo $t6 #store result in $t6
	add $t7, $t5, $t6 #CALCULATIONS: add $t5 and $t6 and store result in $t7

	li $v0, 1
	move $a0, $t7
	syscall

exit:
	# Exit SPIM: Write your code here!
	li $v0, 10
	syscall