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

# a0 = a
# a1 = b
# a2 = c
is_triangle:    # if a^2 + b^2 == c^2 return 1 else return 0 in v0
    mul     $a0, $a0, $a0
    mul     $a1, $a1, $a1
    add     $a0, $a0, $a1
    mul     $a1, $a2, $a2
    beq     $a0, $a1  is_triangle_branch
    li      $v0, 0
    jr      $ra
    is_triangle_branch:
    li      $v0, 1
    jr      $ra


main:
    jal     read_int
    move    $a0, $v0
    jal     read_int
    move    $a1, $v0
    jal     read_int
    move    $a2, $v0
    jal     is_triangle
    move    $a0, $v0
    jal     print_int
    jal     newln

    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"