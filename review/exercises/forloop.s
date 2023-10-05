    .text
    .globl main
main:
    # li      $v0, 5
    # syscall
    # move    $s0, $v0   
    li      $s0, 5
    li      $s1, 0 # s = 0
    li      $t0, 0 # t0 = 0
loop:   
    beq     $t0 $s0 exit

    add     $s1, $s1, $t0
    # li      $v0, 1
    # move    $a0, $s1
    # syscall

    # li $v0, 4 # Print newline
    # la $a0, NEWLINE
    # syscall
    
    addi    $t0, $t0, 1 
    j   loop

exit:
    li      $v0, 10
    syscall

    .data
NEWLINE: .asciiz "\n"
