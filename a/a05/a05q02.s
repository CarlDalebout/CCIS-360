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

print_tab:
    li      $v0, 4
    la      $a0, print_tab
    syscall
    jr      $ra

print_newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

get_cube:
    li      $t1, 3
    li      $v0, 1
    get_cube_loop:   
        beq     $t1, $0, get_cube_loop_break
        mul    $v0, $a0, $v0
        addi   $t1, $t1, -1
        j       get_cube_loop
    get_cube_loop_break:
    jr      $ra

main:
    jal     read_int
    move    $s1, $v0
    li      $s0, 0

    #  s0 = 0, s1 = 3
    # for(int i = 0; i < s1; ++i)
    main_loop:
    bgt     $s0, $s1, main_loop_break

    move    $a0, $s0
    jal     print_int
    jal     print_space
    jal     print_space
    
    move    $a0, $s0
    jal     get_cube
    
    move    $a0, $v0
    jal     print_int
    jal     print_newln
    
    addi    $s0, $s0, 1
    j       main_loop
    main_loop_break:
    li      $v0, 10
    syscall




    .data
NEWLINE:    .asciiz "\n"
SPACE:      .asciiz "    "
TAB:        .asciiz "\t"