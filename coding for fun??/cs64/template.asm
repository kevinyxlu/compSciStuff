#  template.asm

#  Data Area - allocate and initialize variables
.data
	# TODO: Write your string definitions here


#Text Area (i.e. instructions)
.text
main:
	# TODO: Write your code here


# Exit SPIM
exit:
	li $v0, 10
	syscall
