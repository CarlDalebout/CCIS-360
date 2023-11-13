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

print_plus:
    li      $v0, 4
    la      $a0, PLUS
    syscall
    jr      $ra

print_dash:
    li      $v0, 4
    la      $a0, DASH
    syscall
    jr      $ra

newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

print_math:
    li      $t0, 10
    div     $a0, $t0
    mfhi    $t0                     # t0 = a0_1
    li      $t1, 10
    div     $a1, $t1
    mfhi    $t1                     # t1 = a1_1
    
    li      $t3, 0                  
    add     $t2, $t0, $t1           # t2 = a0_1 + a1_1
    
    li      $t4, 10
    blt     $t2, $t4, not_carry_1     # if(t2 < 10)
        li      $t3, 1             
        addi    $t2, $t2, -10       # a0_1 + a1_1 - 10
        addiu   $sp, $sp, -8        # growing stack to save ra, and a0
        sw      $a0, 4($sp)         # saving a0
        sw      $ra, 0($sp)         # saving ra
        jal     print_space
        jal     print_space
        move    $a0, $t3
        jal     print_int
        jal     newln               # print("  1\n")
        lw      $a0, 4($sp)         # returning a0
        lw      $ra, 0($sp)         # returning ra
        addiu   $sp, $sp, 8         # deallocating stack
    not_carry_1:
    # t0 = a0_1, t1 = a1_1, t2 = a0_1 + a1_1, t3 = 1 or 0
             
    div     $a0, $t4
    mflo    $t4                 # t4 = a0_0
    
    addiu   $sp, $sp, -8        # growing stack to save ra, and a0
    sw      $a0, 4($sp)         # saving a0
    sw      $ra, 0($sp)         # saving ra
    jal     print_space
    jal     print_space
    move    $a0, $t4
    jal     print_int
    jal     print_space
    move    $a0, $t0
    jal     print_int
    jal     newln               # print("__'a0_0'_'a0_1'\n")
    lw      $a0, 4($sp)         # returning a0
    lw      $ra, 0($sp)         # returning ra
        
    li      $t5, 10
    div     $a1, $t5
    mflo    $t5                 # t5 = a1_0
    
    addiu   $sp, $sp, -8        # growing stack to save ra, and a0
    sw      $a0, 4($sp)         # saving a0
    sw      $ra, 0($sp)         # saving ra
    jal     print_plus        
    jal     print_space
    move    $a0, $t5
    jal     print_int
    jal     print_space
    move    $a0, $t1
    jal     print_int
    jal     newln               # print("+_'a1_0'_'a1_1'\n")
    
    jal     print_dash
    jal     print_dash
    jal     print_dash
    jal     print_dash
    jal     print_dash
    jal     newln             # print("-----\n")
    lw      $a0, 4($sp)         # returning a0
    lw      $ra, 0($sp)         # returning ra
    
                                # t2 = a0_1 + a1_1
    add     $t3, $t3, $t4
    add     $t3, $t3, $t5


    li      $t4, 10
    blt     $t3, $t4, not_carry_0   # if(t2 < 10)
        li      $t4, 1
        addi    $t3, $t3, -10       # a0_1 + a1_1 - 10
        addiu   $sp, $sp, -4        # growing stack to save ra, and a0
        sw      $ra, 0($sp)         # saving ra
        move    $a0, $t4
        jal     print_int
        jal     print_space
        move    $a0, $t3
        jal     print_int
        jal     print_space
        move    $a0, $t2
        jal     print_int
        jal     newln               # print("1 t3 t2\n")
        jal     print_dash
        jal     print_dash
        jal     print_dash
        jal     print_dash
        jal     print_dash
        jal     newln               # print("-----")
        lw      $ra, 0($sp)         # returning ra
        addiu   $sp, $sp, 4         # deallocating stack
        jr      $ra
    not_carry_0:
    addiu   $sp, $sp, -4
    sw      $ra, 0($sp)
    jal     print_space
    jal     print_space
    move    $a0, $t3
    jal     print_int
    jal     print_space
    move    $a0, $t2
    jal     print_int
    jal     newln
    jal     print_dash
    jal     print_dash
    jal     print_dash
    jal     print_dash
    jal     print_dash
    jal     newln
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 4
    jr      $ra

main:
    jal     read_int
    move    $a0, $v0
    jal     read_int
    move    $a1, $v0
    jal     print_math
    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
SPACE:      .asciiz " "
PLUS:       .asciiz "+"
DASH:       .asciiz "-"