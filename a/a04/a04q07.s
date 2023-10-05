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

newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

print_math:
    

main:
    jal     read_int
    move    $a0, $v0
    jal     read_int
    move    $a1, $v0
    jal     print_math
    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
SPACE:      .asciiz " "