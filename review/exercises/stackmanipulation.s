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
    li      $t0, 1
    bgt     $a0, $t0, fib_rec
        # fib base case
        li      $v0, 1
        jr      $ra
    fib_rec: # n > 0
        addiu   $sp, $sp, -12
        sw      $ra, 4($sp)
        sw      $a0, 8($sp)
        addi    $a0, $a0, -1
        jal     fib
        sw      $v0, 0($sp)
        lw      $a0, 8($sp)
        addi    $a0, $a0, -2
        jal     fib
        lw      $t0, 8($sp)
        add     $v0, $t0, $v0
        lw      $ra, 4($sp)
        addiu   $sp, $sp, 12
        jr      $ra

gcd:
    bne     $a1, $0 gcd_rec
        move    $a0, $v0
        jr      $ra
    gcd_rec:
        addiu   $sp, $sp, -4
        sw      $ra, 0($sp)
        div     $a0, $a1
        mfhi    $t0
        move    $a0, $a1
        move    $a1, $t0
        jal     gcd
        lw      $ra, 0($sp)
        addiu   $sp, $sp, 4
        jr      $ra
main:

    li      $v0, 5
    syscall
    move    $a0, $v0
    li      $v0, 5
    syscall
    move    $a1, $v0
    jal     gcd
    move    $a0, $v0
    li      $v0, 1
    syscall
    li      $v0, 4
    la      $a0, NEWLINE
    syscall

    li      $v0, 10
    syscall
    .data
NEWLINE:    .asciiz "\n"