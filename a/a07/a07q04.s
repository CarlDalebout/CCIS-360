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
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

j_function: # a0 = n, a1 = k
    li      $t0, 1
    bne     $a0, $t0, j_function_case
        li      $v0, 1
        jr      $ra
    j_function_case:
    addiu   $sp, $sp, -12
    sw      $ra, 0($sp)
    sw      $a0, 4($sp)
    sw      $a1, 8($sp)
        addiu   $a0, $a0, -1
        jal     j_function
        lw      $a0, 4($sp)
        lw      $a1, 8($sp)
        add     $v0, $v0, $a1
        addi    $v0, $v0, -1
        div     $v0, $a0
        mfhi    $v0
        addi    $v0, $v0, 1
    lw      $a1, 8($sp)
    lw      $a0, 4($sp)
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 12
    jr      $ra
main:
    jal     read_int
    move    $a0, $v0
    jal     read_int
    move    $a1, $v0
    jal     j_function
    move    $a0, $v0
    jal     print_int
    jal     print_newln

    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"