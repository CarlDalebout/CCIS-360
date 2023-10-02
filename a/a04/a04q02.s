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

ascending_int_int_int: 
    # if(a0 > a1)
    ble     $a0, $a1 ascending_b1
        li      $v0, 0
        jr      $ra
    ascending_b1:
    # if(a1 > a2)
    ble     $a1, $a2 ascending_b2
        li      $v0, 0
        jr      $ra
    ascending_b2:
        li      $v0, 1
        jr      $ra

main:
    jal     read_int
    move    $s0, $v0
    jal     read_int
    move    $s1, $v0
    jal     read_int
    move    $s2, $v0
    
    move    $a0, $s0
    jal     print_int
    jal     print_space
    move    $a0, $s1
    jal     print_int
    jal     print_space
    move    $a0, $s2
    jal     print_int
    jal     print_space
    
    move    $a0, $s0
    move    $a0, $s1
    move    $a0, $s2

    jal     ascending_int_int_int
    move    $a0, $v0
    
    jal     print_int
    jal     newln

    li      $v0, 10
    syscall


    .data
NEWLINE:    .asciiz "\n"
SPACE:      .asciiz " "

