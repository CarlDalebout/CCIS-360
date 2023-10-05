    .text
    .globl main
main:
    lw $a0, x
    
    li $v0, 1
    syscall

    li $v0, 10
    syscall

    .data
x:  .word 5 5
    .word 6 6 7 7
    .word 8 8