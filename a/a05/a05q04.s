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

Collatz_conjecture:
    li      $t0, 1
    Collatz_conjecture_loop:
        beq     $a0, $t0, Collatz_conjecture_break
        li      $t1, 2
        div     $a0, $t1
        mfhi    $t1
        #if(a0%2 == 0)
        bne     $t1, $0 Collatz_conjecture_odd  
            div     $a0, $t1
            mflo    $a0
            move    $t2, $a0
            li      $v0, 1
            syscall
            li      $v0, 4
            la      $a0, SPACE
            syscall
            move    $a0, $t2
            j   Collatz_conjecture_loop
        Collatz_conjecture_odd:
            li      $t1, 3
            mul     $a0, $a0, $t1
            addi    $a0, $a0, 1
            move    $t2, $a0
            li      $v0, 1
            syscall
            li      $v0, 4
            la      $a0, SPACE
            syscall
            move    $a0, $t2
            j   Collatz_conjecture_loop

    Collatz_conjecture_break:
    jr      $ra

main:
    jal     read_int
    move    $a0, $v0
    move    $s0, $v0
    jal     print_int
    jal     print_space
    move    $a0, $s0
    jal     Collatz_conjecture
    jal     print_newln
    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
SPACE:      .asciiz " "