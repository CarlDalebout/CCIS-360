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

h: # a0 = n
    li      $t0, 5
    bgt     $a0, $t0, h_check_rec10_case
        li      $v0, 2
        jr      $ra
    h_check_rec10_case:
    li      $t0, 10
    bgt     $a0, $t0, h_rec_case
    addiu   $sp, $sp, -12
    sw      $ra, 4($sp)
    sw      $a0, 8($sp)
        addi    $a0, $a0, -1
        jal     h           # h(n-1)
        sw      $v0, 0($sp)
        lw      $a0, 8($sp)
        addi    $a0, $a0, -2
        jal     h           # h(n-2)
        lw      $t0, 0($sp)
        add     $v0, $v0, $t0
    lw      $a0, 8($sp)
    lw      $ra, 4($sp)
    addiu   $sp, $sp, 12
    jr      $ra
    h_rec_case: 
    addiu   $sp, $sp, -16
    sw      $ra,  8($sp)
    sw      $a0, 12($sp)
    addi    $a0, $a0, -1
    jal     h
    sw      $v0,  4($sp) # h(n-1)
    
    lw      $a0, 12($sp)
    addi    $a0, $a0, -2
    jal     h
    sll     $v0, $v0, 1
    sw      $v0, 0($sp) # 2*h(n-2)
    
    lw      $a0, 12($sp)
    addi    $a0, -3
    jal     h
    lw      $t0, 4($sp)
    add     $v0, $v0, $t0 # v0 = h(n-1) + h(n-3)
    lw      $t0, 0($sp)
    sub     $v0, $v0, $t0 # v0 = h(n-1) - 2*h(n-2) + h(n-3)
    lw      $ra,  8($sp)
    addiu   $sp, $sp, 16
    jr      $ra


main:
    jal     read_int
    move    $a0, $v0
    jal     h
    move    $a0, $v0
    jal     print_int
    jal     print_newln

    li      $v0, 10
    syscall

    .data
NEWLINE: .asciiz "\n"