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

main:

    jal     read_int
    move    $s0, $v0
    jal     print_newln
    move    $a0, $s0
    jal     print_int
    jal     print_newln
    
    jal     read_string
    jal     print_newln
    la      $a0, input
    jal     print_string
    jal     print_newln
    
    jal     read_int
    move    $a0, $v0
    jal     print_int
    jal     read_string
    la      $a0, input
    jal     print_string
    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
HELLO:      .asciiz "HELLO"
input:      .space  81
input_size: .word   80