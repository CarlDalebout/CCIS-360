    .text
    .globl main
main:
    li      $s0, 1
    li      $s1, 2

    bne     $s0, $s1, exit
    li      $s2, 3

exit:
    li      $v0, 10
    syscall