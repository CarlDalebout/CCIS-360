    .text
    .main
main:
    li $v0, 10
    syscall
    move $a0, $v0
    # ((n+2)n +3)n +4 "Horner's Rule"