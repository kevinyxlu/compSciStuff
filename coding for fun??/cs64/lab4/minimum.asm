# minimum.asm program
# CS 64, Kevin Lu, klu@ucsb.edu

.data

	# TODO: Complete these declarations / initializations

	prompt: .asciiz "Enter the next number:\n"
	minimum: .asciiz "Minimum: "
    newline: .asciiz "\n"

#Text Area (i.e. instructions)
.text
main:
	#variables: t1 = num1, t2 = num2, t3 = num3, t4 = min, $s1 = 1
	li $s1, 1 #s1 is 1
### GETS USER INPUTS FOR 3 NUMBERS ###
	li $v0, 4
	la $a0, prompt
	syscall
	li $v0, 5
	syscall
	move $t1, $v0
	li $v0, 4
	la $a0, prompt
	syscall
	li $v0, 5
	syscall
	move $t2, $v0
	li $v0, 4
	la $a0, prompt
	syscall
	li $v0, 5
	syscall
	move $t3, $v0
	move $t4, $t1 #set min to num1
########################################

MAIN1:
	slt $t0, $t2, $t4 #set $t0 to 1 if t2 < t4

    beq $t0, $s1, UPDATEMIN2 #if $t0 is 1, branch to updatemin2
	li $t0, 0 #reset $t0 to 0

	slt $t0, $t3, $t4 #set $t0 to 1 if t3 < t4
	beq $t0, $s1, UPDATEMIN3
	j FINALIZE

UPDATEMIN2:
	move $t4, $t2 #t2 becomes minimum
	j MAIN1

UPDATEMIN3:
	move $t4, $t3 #t3 becomes minimum
	j MAIN1

FINALIZE:
### PRINTS MINIMUM ###
	li $v0, 4
	la $a0, minimum
	syscall
	li $v0, 1
	move $a0, $t4
	syscall
	li $v0 4
	la $a0, newline
	syscall
######################

# Exit SPIM
exit:
	li $v0, 10
	syscall
