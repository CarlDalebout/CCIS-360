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

int_pow_int_int:    # $a0 = x, $a1 = i
    li      $v0, 1
    pow_loop:   
        beq     $a1, $0, pow_break
        mul    $v0, $a0, $v0
        addi   $a1, $a1, -1
        j       pow_loop
    pow_break:
    jr      $ra

swap_pint_int_int:   # $a0 = bass address of x $a1 = i $a2 = j
    addu        $a1, $a1, $a1
    addu        $a1, $a1, $a1
    addu        $a1, $a0, $a1 # a1 = &x[i]

    addu        $a2, $a2, $a2
    addu        $a2, $a2, $a2
    addu        $a2, $a0, $a2 # a2 = &x[j]

    lw          $t0, 0($a1) # t0 = x[i]
    lw          $a0, 0($a2) # a0 = x[j]
    sw          $t0, 0($a2) 
    sw          $a0, 0($a1)
    jr          $ra

# a0 = base of array
# a1 = end of array
bubblesort: # not done
    sub     $t0, $a0, $a1      
    bubblesort_for1:
        beq $t0, $0, bubblesort_exit

        bubblesort_for2:


    bubblesort_exit:

# a0 = x
# a1 = y
max_int:

    blt     $a0 $a1, max_int_1   # if(a0 >= a1)
    move    $v0, $a0
    jr      $ra

    max_int_1: 
    move    $v0, $a1
    jr      $ra

max_int_arr: # not done
    max_int_arr_Loop:
        beq     $a0, $a1, exit
        lw      $t0, 0($s0)
        ble     $t0, $t1, max_int_arr_endif
        move    $t1, $t0
    max_int_arr_endif:
        addiu   $a0, $a0, 4
        j       max_int_arr_Loop
    move    $v0, $t0



main:

    # jal     read_int
    # move    $a0, $v0
    
    # jal     read_int
    # move    $a1, $v0
    # jal     max_int
    
    # la      $s0, x
    # li      $s1, 6
    # lw      $s2, 0($s0)
    # addu    $s1, $s1, $s1
    # addu    $s1, $s1, $s1
    # addu    $s1, $s0, $s1
    # addiu   $s0, $s0, 4
    
    la      $a0, x
    li      $a1, 7
    lw      $t1, 0($s0)
    addu    $a1, $a1, $a1
    addu    $a1, $a1, $a1
    addu    $a1, $a0, $a1
    addiu   $a1, $a0, 4
    


    move    $a0, $v0
    jal     print_int
    jal     newln

    li      $v0, 10
    syscall

    .data
NEWLINE: .asciiz "\n"
x:  .word 7 5 1 9 2 0 6