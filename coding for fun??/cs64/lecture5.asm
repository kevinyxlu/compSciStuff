.text

main:

li $a0, -3 # $a0 = -3
li $a1, 8 #a1 = 8

add $t0, $a0, $a1 # $t0 = -3 + 8
sub $t1, $a1, $a0 # $t1 = 8 - (-3)
addi $t0, $t0, -7 # $t0 = 5 - 7

li $v0, 1 #prepare to print int
move $a0, $t0 # $a0 = -2
syscall #prints $a0, which is -2
move $a0, $t1 # $a0 = 11
syscall #prints $a0, which is 11

#exit
li $v0, 10
syscall