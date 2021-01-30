# xSpim Demo Program
# 
# By: Dan Stearns, Ziad Matni
# Modifications: 
#	4/10/03 knico Tabbed code
#	4/10/03 knico Modified to use s registers instead of t registers
#   1/1/2021 modified by Z.Matni for CS64, UCSB
#

#  Data Area - allocate and initialize variables
.data

welcome:
	.asciiz " This program adds two numbers \n\n"

prompt:
	.asciiz " Enter an integer: "

sumText: 
	.asciiz " \n Sum = "

# MyArray declaration allocates a 9 integer array, 
# initialized to the values listed below
# note - this is not used in the program
# this is here to illustrate how to declare it
myArray:
        .word 0x20040002 0x20080001 0x200b0001 0x8b502a 
        .word 0x15400003 0x1084020 0x20840000 0x800fffa 
        .word 0x1001020 

#Text Area (i.e. instructions)
.text

main:

	# Display the welcome message; 
	li $v0, 4			
	la	$a0, welcome
	syscall

	# Display prompt
	li $v0, 4	# redundant, but ok		
	la	$a0, prompt
	syscall

	# Read 1st integer from std.in
	li $v0, 5
	syscall

    # Put 1st integer into $s0, keeping a running
    # sum in $s0
    addu $s0, $v0, $zero
	
	# Display prompt
	li $v0, 4			
	la	$a0, prompt
	syscall

	# Read 2nd integer from std.in
	li $v0, 5
	syscall
	# $v0 now has the value of the second integer
	
	# Add 2nd integer to sum
	addu $s0, $v0, $s0

	# Display the sum text
	li $v0, 4			
	la	$a0, sumText
	syscall

	# Display the integer sum
	li $v0, 1		
	add $a0, $s0, $zero
	syscall

	# Exit
	li $v0, 10
	syscall

