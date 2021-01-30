# Factorial.asm program
# CS 64, Kevin Lu, klu@ucsb.edu
#

# Assembly (NON-RECURSIVE) version of:
#    int num;
#    int answer = 1;
#    int counter = 1;
#
#    cout << "Enter a number\n";
#    cin >> num;
#
#    while (counter < num + 1)
#    {
#        answer = answer * counter;
#        counter = counter + 1;
#    }
#    cout << "Factorial of " << num << " is:\n" << answer << endl;

.data
	enternum: .asciiz "Enter a number:\n"
	factorialof: .asciiz "Factorial of "
	is: .asciiz " is:\n"
	newline: .asciiz "\n"

#Text Area (i.e. instructions)
.text
main:
	# VARS: $t1 = num, $t2 = answer, $t3 = counter
	# CONSTS: $s1 = 1, $s2 = num + 1
	
### GETS USER INPUT AND DECLARES VARIABLES and CONSTS ###
	li $v0, 4
	la $a0, enternum # cout << "Enter a number";
	syscall
	li $v0, 5
	syscall # cin >> num;
	move $t1, $v0

	addi $s2, $t1, 1
	li $t2, 1
	li $t3, 1
	li $s1, 1
#########################################################

loop:
	beq $t3, $s2, continue
	mult $t2, $t3
	mflo $t2
	addi $t3, $t3, 1
	j loop

### PRINTS OUT THE ANSWER #######
continue:
	li $v0, 4
	la $a0, factorialof
	syscall
	li $v0, 1
	move $a0, $t1 # cout << num
	syscall
	li $v0, 4
	la $a0, is
	syscall 
	li $v0, 1
	move $a0, $t2
	syscall
	li $v0, 4
	la $a0, newline
	syscall
##################################

# Exit SPIM
exit:
	li $v0, 10
	syscall
