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
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

# a0 = line1 start
# a1 = line1 end
# a2 = line2 start
# a3 = line2 end
is_overlaping: # if line1 and line2 overlap return 1 else return 0
    # if(a2 >= a0 && a2 <= a1) return 1
    blt     $a2, $a0, is_overlaping_b1
    bgt     $a2, $a1, is_overlaping_b1
    li      $v0, 1
    jr      $ra
    # else if(a3 >= a0 && a3 <= a1) return 1
    is_overlaping_b1:
    blt     $a3, $a0, is_overlaping_b2
    bgt     $a3, $a1, is_overlaping_b2
    li      $v0, 1
    jr      $ra
    # else if(a2 < a0 && a3 > a1)
    is_overlaping_b2:
    bge     $a2, $a0, is_overlaping_b3
    ble     $a3, $a1, is_overlaping_b3
    li      $v0, 1
    jr      $ra
    is_overlaping_b3:
    li      $v0, 0
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
    jal     is_overlaping
    move    $a0, $v0

    jal     print_int
    jal     newln

    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"