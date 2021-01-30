# hello.asm
# A "Hello World" program in MIPS Assembly for CS64
#
#  Data Area - allocate and initialize variables
.data
	# TODO: Write your string definitions here
	enter: .asciiz "Enter an integer:\n"
	hello: .asciiz "Hello Pandemic World of 2021!\n"
	magic: .asciiz "The magic number is "
	exclamation: .asciiz "!!!\n"

#Text Area (i.e. instructions)
.text
main:
	# TODO: Write your code here

	#PRINTS LINE 1
	li $v0, 4
	la $a0, enter #loads first line to $a0
	syscall

	#USER INPUT LINE 2
	li $v0, 5
	syscall
	move $t0, $v0 #stores user inputted number in $t1

	#PRINTS LINE 3
	li $v0, 4
	la $a0, hello #loads third line to $a0
	syscall

	#PRINTS LINE 4
	li $v0, 4
	la $a0, magic #prints pt1 of magic number line
	syscall
	li $v0, 1 #prints magic number
	move $a0, $t0
	syscall
	li $v0, 4
	la $a0, exclamation #prints exclamation marks
	syscall

exit:
	# Exit SPIM: Write your code here!
	li $v0, 10
	syscall
