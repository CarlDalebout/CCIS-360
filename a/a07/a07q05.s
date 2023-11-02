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
