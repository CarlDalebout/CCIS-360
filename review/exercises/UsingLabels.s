    .text
    .globl  main
main:

    li      $s0, 5
    la      $s1, l1
    sw      $s0, 4($s1)


    li      $v0, 10
    syscall

    .data
L:  .word 42 43 44
    .word 45 46 47
l1: .word 48 49 50
    .word 51 52 53