    .text
    .globl main
main:

    li      $v0, 5
    syscall
    move    $s0, $v0      # x = s0

    li      $v0, 5
    syscall
    move    $s1, $v0      # a = s1

    li      $v0, 5
    syscall
    move    $s2, $v0      # b = s2

    li      $t0, 0

    blt     $s0, $t0 exit2
    li      $t0, 4
    bgt     $s0, $t0 exit2

    add     $t0, $s0, $s0
    add     $t0, $t0, $t0   # t0 = 4 * s0

    la      $t1, jtable
    add     $t0, $t1, $t0
    lw      $t0, 0($t0)
    jr      $t0

L0:
    add     $a0, $s1, $s2
    j       exit
L1:
    sub     $a0, $s1, $s2
    j       exit
L2:
    mult    $s1, $s2
    mflo    $a0
    j      exit
L3:
    div     $s1, $s2
    mflo    $a0
    j       exit
L4:
    div     $s1, $s2
    mfhi    $a0

exit:
    li      $v0, 1
    syscall
exit2:
    li      $v0, 10
    syscall

    .data
jtable: .word L0 L1 L2 L3 L4