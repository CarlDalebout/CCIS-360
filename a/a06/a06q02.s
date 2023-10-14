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

print_string:
    li      $v0, 4
    syscall
    jr      $ra

print_newln:
    li      $v0, 4
    la      $a0, NEWLINE
    syscall
    jr      $ra

passfail: # a0 = flag
    bne    $a0, $0, passfail_pass # if(a0 != 0)
        li  $v0, 4
        la  $a0, FAIL
        syscall
        li  $v0, 0
        jr  $ra
    passfail_pass:
        li  $v0, 4
        la  $a0, PASS
        syscall
        li  $v0, 1
        jr  $ra

passfail_test:
    addiu   $sp, $sp, -4
    sw      $ra, 0($sp)

    li      $a0, 5
    jal     print_int
    jal     passfail
    move    $a0, $v0
    jal     print_int
    jal     print_newln

    li      $a0, -3
    jal     print_int
    jal     passfail
    move    $a0, $v0
    jal     print_int
    jal     print_newln
    
    li      $a0, 42
    jal     print_int
    jal     passfail
    move    $a0, $v0
    jal     print_int
    jal     print_newln
    
    li      $a0, 0
    jal     print_int
    jal     passfail
    move    $a0, $v0
    jal     print_int
    jal     print_newln
    
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 4
    jr      $ra

main:

    jal     passfail_test
    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
HELLO:      .asciiz "HELLO"
PASS:       .asciiz " PASS "
FAIL:       .asciiz " FAIL "
input:      .space  81 
input_size: .word   80