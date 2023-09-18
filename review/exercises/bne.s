    .text
    .globl main
main:
    li      $v0, 5
    syscall
    move    $s0, $v0

    li      $v0, 5
    syscall
    move    $s1, $v0

    li      $v0, 5
    syscall
    
    beq     $s0, $0, Sum
    
    sub     $a0, $s1, $v0
    j       exit

Sum:
    add     $a0, $s1, $v0

exit:
    li      $v0, 1
    syscall
    
    li      $v0, 10
    syscall