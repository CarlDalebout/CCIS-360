    .text
    .globl main

f:
    addiu   $sp, $sp, -8
    sw      $s0, 4($sp)
    sw      $s1, 0($sp)
    # randome computaition
    lw      $s0, 4($sp)
    lw      $s1, 0($sp)
    addiu   $sp, $sp, 8
    jr      $ra

# a0 - int, set v0 to a0 +1
incroment:
    addi    $v0, $a0, 1
    jr      $ra

# a0 - int store a0 + 2 in v0 must call incroment twice
incroment2:

    addiu   $sp, $sp, -4
    sw      $ra, 0($sp)
    jal     incroment
    move    $a0, $v0
    jal     incroment
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 4
    jr      $ra

# a0 - n, v0 = fibonacci of n (fib(0) = 1, fib(1) = 1, ..., fib(n) = fib(n-1) + fib(n-2))
fib:
    bne     $a0, $0, BASE
        li      $v0, 1
        jr      $ra
    BASE: # n > 0
        li      $t0, 1
        bne     $a0, $t0, REC
            li      $v0, 1
            jr      $ra
    REC:
        addiu   $sp, $sp, -8
        sw      $ra, 0($sp)
        sw      $a0, 4($sp)


main:
    li      $a0, 5
    jal     fib # a0 +2
    move    $a0, $v0
    li      $v0, 1
    syscall
    li      $v0, 10
    syscall
