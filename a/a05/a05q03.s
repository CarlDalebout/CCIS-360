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

print_newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

is_prime:
    li      $t0, 2  
    is_prime_loop:
    # if(t0 == a0)
    beq     $t0, $a0, is_prime_loop_break
    div     $a0, $t0
    mfhi    $t1
    # if(t0 > 0)
    bgt     $t1, $0, is_prime_else  
    li      $v0, 0
    jr      $ra
    
    is_prime_else: 
    addi    $t0, $t0, 1
    j   is_prime_loop
    
    is_prime_loop_break:
    li      $v0, 1
    jr      $ra

main:
    jal     read_int
    move    $a0, $v0
    jal     is_prime
    move    $a0, $v0
    jal     print_int
    jal     print_newln

    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"