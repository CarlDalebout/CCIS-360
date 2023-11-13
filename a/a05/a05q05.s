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

fill_arr: # a0 = size of the array
    la      $t0, x
    fill_arr_loop:
    beq     $a0, $0, fill_arr_exit # if(a0 != 0)
        move    $t1, $a0
        li      $v0, 5
        syscall
        sw      $v0, 0($t0)
        move    $a0, $t1 
        addi    $t0, $t0, 4
        addi    $a0, $a0, -1
        j       fill_arr_loop
    fill_arr_exit:
    jr      $ra

print_arr: # a0 = size of the array
    la      $t0, x
    print_arr_loop:
    beq     $a0, $0, print_arr_exit
        move    $t1, $a0
        lw      $a0, 0($t0)
        li      $v0, 1
        syscall
        li      $v0, 4
        la      $a0, DIR
        syscall
        move    $a0, $t1
        addi    $t0, $t0, 4
        addi    $a0, $a0, -1
        j       print_arr_loop
    print_arr_exit:
    li      $v0, 4
    la      $a0, NEWLINE
    syscall
    jr      $ra

swap_int_int: # a0 = &x[i] a1 = &x[j]    
    lw      $t0, 0($a0)
    lw      $t1, 0($a1)
    sw      $t0, 0($a1)
    sw      $t1, 0($a0)
    jr      $ra

bubblesort: # a0 = start of x a1 = end of x
    move    $t0, $a1  # t0 = &x[sizeof.array_x()]
    bubblesort_for1:

    blt     $t0, $a0, bubblesort_for1_exit # if(t0 > &x[0]) 
        move        $t1, $a0 
        bubblesort_for2:
        bge     $t1, $t0, bubblesort_for2_exit # if( t1 < t0)
            lw      $t3, 0($t0) # t3 = *x[7]
            lw      $t2, 0($t1) # t2 = *x[0]
            blt     $t2, $t3, bubblesort_else # if(t2 < t3)
                
                addiu   $sp, $sp, -20
                sw      $a1, 16($sp)
                sw      $a0, 12($sp)
                sw      $ra, 8($sp)
                sw      $t1, 4($sp)
                sw      $t0, 0($sp)

                move    $a0, $t1
                move    $a1, $t0
                jal     swap_int_int

                lw      $a1, 16($sp)
                lw      $a0, 12($sp)
                lw      $ra, 8($sp)
                lw      $t1, 4($sp)
                lw      $t0, 0($sp)
                addiu   $sp, $sp, 20

            bubblesort_else:
            addiu       $t1, 4
            j       bubblesort_for2
        bubblesort_for2_exit:
        addiu       $t0, -4 
        j       bubblesort_for1
    bubblesort_for1_exit:
    jr      $ra

main:
    jal     read_int
    move    $a0, $v0
    move    $s0, $v0
    jal     fill_arr
    la      $a0, x
    
    addu    $a1, $s0, $s0
    addu    $a1, $a1, $a1
    addu    $a1, $a0, $a1
    addiu    $a1, $a1, -4
    # jal     swap_int_int
    jal     bubblesort
    move    $a0, $s0
    jal     print_arr
    jal     print_newln
    li      $v0, 10
    syscall


    .data
NEWLINE:    .asciiz " \n"
DIR:        .asciiz " "
x:          .word 1