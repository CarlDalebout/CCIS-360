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
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra 

int_pow_int_int:    # $a0 = x, $a1 = i
    li      $v0, 1
    pow_loop:   
        beq     $a1, $0, pow_break
        mul    $v0, $a0, $v0
        addi   $a1, $a1, -1
        j       pow_loop
    pow_break:
    jr      $ra

main:

    jal     read_int
    move    $s0, $v0
    jal     read_int
    move    $s1, $v0
    jal     read_int
    move    $s2, $v0
    jal     read_int
    move    $s3, $v0
    jal     read_int
    move    $s4, $v0
    # s0 = x, s1 = y, s2 = z, s3 = i, s4 = t

    add     $s2, $s2, $s3
    div     $s1, $s2
    mflo    $s1
    move    $a0, $s4
    li      $a1, 3
    jal     int_pow_int_int
    move    $s2, $v0
    mult    $s1, $s2
    mflo    $s1
    add     $a0, $s0, $s1
    jal     print_int
    jal     newln

    li      $v0, 10
    syscall    
    
    .data
NEWLINE: .asciiz "\n"