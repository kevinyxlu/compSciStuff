.text
main:	
    li $a0, 5
    addi $a0, $a0, -4
    move $v0, $a0
    sub $a0, $v0, $a0
    syscall
    li $v0, 10
    syscall