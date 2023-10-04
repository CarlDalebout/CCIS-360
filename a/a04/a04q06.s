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

newln:
    li      $v0, 4
    la      $a0, NEWLINE
    syscall
    jr      $ra

is_data:
    li      $t0, 10000
    div     $a0, $t0
    mflo    $t0                         # t0 = year
    addiu   $sp, $sp, -8
    sw      $a0, 4($sp)
    sw      $ra, 0($sp)
    move    $a0, $t0
    jal   print_int
    jal   print_space
    ble     $t0, $0, bad_date           # if(year == 0)
    lw      $a0, 4($sp)
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 8

    li      $t1, 100
    div     $a0, $t1
    mflo    $t2                         # t2 = 19900212 / 100
    div     $t2, $t1                    # t2 = 19900212 % 100
    mfhi    $t1                         # t1 = month
    addiu   $sp, $sp, -8
    sw      $a0, 4($sp)
    sw      $ra, 0($sp)
    move    $a0, $t1
    jal   print_int
    jal   print_space
    ble     $t1, $0, bad_date           # if(month == 0)
    lw      $a0, 4($sp)
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 8

    li      $t2, 100
    div     $a0, $t2
    mfhi    $t2                         # t2 = days
    addiu   $sp, $sp, -8
    sw      $a0, 4($sp)
    sw      $ra, 0($sp)
    move    $a0, $t2
    jal   print_int
    jal   print_space
    ble     $t2, $0, bad_date           # if(days == 0)
    lw      $a0, 4($sp)
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 8

    li      $t3, 2
    bne     $t1, $t3, notleapyear      # if(month != 2)

        li      $t3, 4
        div     $t0, $t3
        mfhi    $t3
        bne     $t3, $0, notleapyear    # if(year % 4 != 0)
            li      $t3, 100
            div     $t0, $t3
            mfhi    $t3
            bne     $t3, $0, leapyear   # if(year $ 100 != 0)
                li      $t3, 400
                div     $t0, $t3
                mfhi    $t3
                bne     $t3, $0, notleapyear
                leapyear:
                    li      $t1, 12
    notleapyear:
        la      $t3, Days
        addu    $t1, $t1, $t1
        addu    $t1, $t1, $t1
        addu    $t1, $t3, $t1
        lw      $t1, 0($t1)
    blt     $t1, $t2, bad_date
    li      $v0, 1
    jr      $ra
    bad_date:
    li      $v0, 0
    jr      $ra


main:
    jal     read_int
    move    $a0, $v0
    jal     is_data
    move    $a0, $v0
    jal     print_int
    jal     newln
    li      $v0, 10
    syscall

    .data
Days:       .word  31 28 31 30 31 30 31 31 30 31 30 31 29
NEWLINE:    .asciiz "\n"
SPACE:      .asciiz " "