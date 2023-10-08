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

print_space:
    li      $v0, 4
    la      $a0, SPACE
    syscall
    jr      $ra

print_newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

mod_9:
    li      $v0, 9
    div     $a0, $v0
    mfhi    $v0
    jr      $ra

digit_sum:
    li      $v0, 0
    digit_sum_loop:
    ble     $a0, $0, digit_sum_loop_end
    li      $t0, 10
    div     $a0, $t0
    mfhi    $t1
    add     $v0, $v0, $t1
    mflo    $a0
    j       digit_sum_loop
    digit_sum_loop_end:
    jr      $ra


main:
    jal     read_int
    move    $s0, $v0
    move    $a0, $s0
    jal     mod_9
    move    $a0, $v0
    jal     print_int
    jal     print_space
    move    $a0, $s0
    jal     digit_sum
    move    $s0, $v0
    move    $a0, $s0
    jal     print_int
    jal     print_space
    move    $a0, $s0
    jal     mod_9
    move    $a0, $v0
    jal     print_int

    jal     print_newln
    li      $v0, 10
    syscall

    .data
NEWLINE:     .asciiz "\n"
SPACE:       .asciiz " "