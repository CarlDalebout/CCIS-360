#     .text  
#     .globl main
# main:
#     li $s1, 1
#     li $s2, 2
#     add $s0, $s1, $s2
#     sub $s3, $s0, $s1
#     li $v0, 10
#     syscall

#     .text
#     .globl main
# main:
#     li $s1, 1
#     li $s2, 2
#     li $s3, 3
#     li $s4, 4
#     add $s0, $s1, $s2
#     sub $s0, $s0, $s3
#     sub $s0, $s0, $s4
    
    .text
    .globl main
main:
    li $v0, 5
    syscall
    move $a0, $v0

    li $v0, 5
    syscall
    
    add $a0, $a0, $v0
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall