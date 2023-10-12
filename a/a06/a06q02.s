    .text
    .globl main



passfail: # a0 = flag
    bne    $a0, $0, else # if(a0 != 0)
        li  $v0, 1
        syscall
        li  $v0, 4
        la  $a0, FAIL
        syscall
        li  $a0, 0
        li  $v0, 1
        syscall
        li  $v0, 4
        la  $a0, NEWLINE
        syscall
        jr  $ra
    else:
        li  $v0, 1
        syscall
        li  $v0, 4
        la  $a0, pass
        syscall
        li  $a0, 1
        li  $v0, 1
        syscall
        li  $v0, 4
        la  $a0, NEWLINE
        syscall
        jr  $ra

passfail_test:
    addiu   $sp, $sp, -4
    sw      $ra, 0($sp)
    li      $a0, 5
    jal     passfail
    li      $a0, -3
    jal     passfail
    li      $a0, 42
    jal     passfail
    li      $a0, 0
    jal     passfail
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 4
    jr      $ra

main:
    jal passfail_test
    li      $v0, 10
    syscall

    .data
pass:       .asciiz " pass "
FAIL:       .asciiz " FAIL "
NEWLINE:     .asciiz "\n"