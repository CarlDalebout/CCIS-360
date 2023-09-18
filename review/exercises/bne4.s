    .text
    .globl main
main:
    li      $v0, 5
    syscall
    # move    $s0, $v0

    beq     $v0, $0, sum

    li      $v0, 5
    syscall
    move    $s0, $v0

    li      $v0, 5
    syscall
    sub     $a0, $s0, $v0
    j       exit
sum:
    li      $v0, 5
    syscall
    move    $s0, $v0

    li      $v0, 5
    syscall
    add     $a0, $s0, $v0

exit:
    li      $v0, 1
    syscall

    li      $v0, 10
    syscall