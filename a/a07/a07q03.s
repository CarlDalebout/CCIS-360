    .text
    .globl main

read_int:
    li      $v0, 5
    syscall
    jr      $ra

print_str:
    li      $v0, 4
    syscall
    jr      $ra

honoi: # a0 = n a1 = address of from, a2 = address of helper, a3 = address of to
    li  $t0, 1
    bne     $a0, $t0    honoi_rec_case
    addiu   $sp, $sp, -4
    sw      $ra, 0($sp)
        move    $a0, $a1
        jal     print_str
        la      $a0, ARROW
        jal     print_str
        move    $a0, $a3
        jal     print_str
        la      $a0, NEWLINE
        jal     print_str
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 4
    jr      $ra
    honoi_rec_case:
    addiu   $sp, $sp, -20
    sw      $ra,  0($sp)
    sw      $a0,  4($sp)    # n
    sw      $a1,  8($sp)    # from
    sw      $a2, 12($sp)    # helper
    sw      $a3, 16($sp)    # to

    addiu   $a0, $a0, -1
    lw      $a1,  8($sp)
    lw      $a2, 16($sp)
    lw      $a3, 12($sp)
    jal     honoi

    li      $a0,  1
    lw      $a1,  8($sp)
    lw      $a2, 12($sp)
    lw      $a3, 16($sp)
    jal     honoi

    lw      $a0,  4($sp)
    addiu   $a0, $a0, -1
    lw      $a1, 12($sp)
    lw      $a2,  8($sp)
    lw      $a3, 16($sp)
    jal     honoi

    lw      $a3, 16($sp)
    lw      $a2, 12($sp)
    lw      $a1,  8($sp)
    lw      $a0,  4($sp)
    lw      $ra,  0($sp)
    addiu   $sp, $sp, 20
    jr      $ra

main:
    jal     read_int
    move    $a0, $v0
    la      $a1, A
    la      $a2, B
    la      $a3, C
    jal     honoi

    li      $v0, 10
    syscall

    .data
A:          .asciiz "A"
B:          .asciiz "B"
C:          .asciiz "C"
ARROW:      .asciiz "->"
NEWLINE:    .asciiz "\n"