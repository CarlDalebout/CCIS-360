    .text
    .globl main

read_int:
    li      $v0, 5
    syscall
    jr      $ra

print_int:
    li      $v0, 1
    syscall
    jr      $ra

print_newln:
    li      $v0, 4
    la      $a0, NEWLINE
    syscall
    jr      $ra

gcm: # a0 = m a1 = n
    gcm_recursion:
    bne     $a1, $0, gcm_not_base_case
        move    $v0, $a0
        jr      $ra
    gcm_not_base_case:
        div     $a0, $a1
        move    $a0, $a1
        mfhi    $a1
        j       gcm_recursion
main:
    jal     read_int
    move    $a0, $v0
    jal     read_int
    move    $a1, $v0
    jal     gcm
    move    $a0, $v0
    jal     print_int
    jal     print_newln
    li      $v0, 10
    syscall

    .data
NEWLINE: .asciiz "\n"
