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

newln:
    li      $v0, 4
    la      $a0, NEWLINE
    syscall
    jr      $ra

second_largest:
    

main:
    jal     read_int
    move    $a0, $v0
    jal     read_int
    move    $a1, $v0
    jal     read_int
    move    $a2, $v0
    jal     read_int
    move    $a3, $v0
    jal     second_largest
    move    $a0, $v0
    jal     print_int
    jal     newln

    li      $v0, 10
    syscall

    .data
NEWLINE: .asciiz "\n"