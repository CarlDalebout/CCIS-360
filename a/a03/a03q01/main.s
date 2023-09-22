    .text
    .globl main
main:
    li      $v0, 5
    syscall
    move    $s0, $v0 # $s0 = a
            
    li      $v0, 5
    syscall
    move    $s1, $v0 # $s1 = b

    li      $v0, 5
    syscall
    move    $s2, $v0 # $s2 = c

    li      $v0, 5
    syscall
    move    $s3, $v0 # $s3 = d

#   (a * b) + (((b-c)/a) % d)

    sub     $t0, $s1, $s2
    div     $t0, $s0
    mflo    $t0 # t0 = (b-c) / a
    div     $t0, $s3
    mfhi    $t0 # t0 = ((b-c) /a ) % d
    mult    $s0, $s1
    mflo    $t1
    add     $t0, $t0, $t1

    li      $v0, 1
    move    $a0, $t0
    syscall