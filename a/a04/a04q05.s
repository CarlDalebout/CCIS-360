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

newln:
    li      $v0, 4
    la      $a0, NEWLINE
    syscall
    jr      $ra

second_largest:
    # t0 = largest 
    # v0 = second_largest
    li      $v0, 0
    move    $t0, $a0
    ble     $a1, $v0, second_largest_if2 # if(a1 > v0)
        ble     $a1, $t0, second_largest_if1 # if(a1 > t0)
            move    $v0, $t0
            move    $t0, $a1
            j       second_largest_if2
        second_largest_if1:
            move    $v0, $a1
    second_largest_if2:
    ble     $a2, $v0, second_largest_if4
        ble     $a2, $t0, second_largest_if3
            move    $v0, $t0
            move    $t0, $a2
            j       second_largest_if4
        second_largest_if3:
            move    $v0, $a2
    second_largest_if4:
    ble     $a3, $v0, second_largest_if6
        ble     $a3, $t0, second_largest_if5
            move    $v0, $t0
            move    $t0, $a3
            jal     second_largest_if6
        second_largest_if5:
            move    $v0, $a3
    second_largest_if6:
    jr      $ra

main:
    jal     read_int
    move    $a0, $v0
    jal     read_int
    move    $a1, $v0
    jal     read_int
    move    $a2, $v0
    jal     read_int
    move    $a3, $v0
    jal     second_largest
    move    $a0, $v0
    jal     print_int
    jal     newln

    li      $v0, 10
    syscall

    .data
NEWLINE: .asciiz "\n"