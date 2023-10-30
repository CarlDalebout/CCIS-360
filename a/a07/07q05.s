    .text
    .globl main

read_int:
    li      $v0, 5
    syscall
    jr      $ra

read_string:
    li      $v0, 8
    la      $a0, input
    lw      $a1, input_size
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

is_palindrome: # a0 = &string_start a1 = &string_end
    li      $t0, 80
    sub     $t0, $a1, $t0
    blt     $a0, $t0, is_palindrome_rec
        li      $v0, 1
        jr      $ra
    is_palindrome_rec:
    addiu   $sp, $sp, -12
    sw      $ra, 0($sp)
    sw      $a0, 4($sp)
    sw      $a1, 8($sp)

    lw      $t0, 0($t0)
    lw      $t1, 0($a0)
    beq     $t1, $t0, is_palindrome_rec_equal
        li      $v0, 0
        lw      $ra, 0($sp)
        addiu   $sp, $sp, 12
        jr      $ra
    is_palindrome_rec_equal:
    lb      $a0, 4($sp)
    lb      $a1, 8($sp)
    li      $t0, 80
    add     $a0, $a0, $t0
    sub     $a1, $a1, $t0
    jal     is_palindrome
    bne     $v0, $0,    is_palindrome_rec_equal_true
        li      $v0, 0
        lw      $ra, 0($sp)
        addiu   $sp, $sp, 12
        jr      $ra
    is_palindrome_rec_equal_true:
    li      $v0, 1
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 12
    jr      $ra

main:
    jal     read_string
    li      $t0, 80
    mult    $a1, $t0
    mflo    $a1
    addu    $a1, $a0, $a1
    jal     is_palindrome
    move    $a0, $v0
    jal     print_int
    jal     print_newln
    
    li      $v0, 10
    syscall
    
    .data
input:      .space  81
input_size: .word   80
NEWLINE:    .asciiz "\n"
