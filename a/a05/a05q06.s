    .text
    .globl main
read_int:
    li      $v0, 5
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

DFA:    # a0 = &x[0] a1 = &x[sizeof.array()] v0 = state
    li      $v0, 1
    DFA_loop:
    bge     $a0, $a1, DFA_exit
        lw      $t0, 0($a0)
        bltz    $t0, DFA_exit
        li      $t1, 2
        bgt     $t0, $t1, DFA_loop_exit
        addu    $t2, $v0, $v0   
        addu    $t2, $t2, $t2           # t2 = 4 * v0
        la      $t3, jtable             # t3 = jtable
        addu    $t2, $t3, $t2           # t2 = &jtable[v0]
        lw      $t2, 0($t2)
        jr      $t2

        L0:
            lw      $t2, 0($a0)
            addiu   $t2, $t2, -2
            bltz    $t2, DFA_loop_exit
            bgt     $t2, $t1, DFA_loop_exit
            addu    $t2, $t2, $t2
            addu    $t2, $t2, $t2
            la      $t3, jtable
            addiu   $t3, $t3, 8
            addu    $t2, $t3, $t2
            lw      $t2, 0($t2)
            jr      $t2
        
            L0_0:
                li      $v0, 0
                j       DFA_loop_exit
            L0_1:
                li      $v0, 1
                j       DFA_loop_exit
        
        L1:
            lw      $t2, 0($a0)
            addiu   $t2, $t2, -2
            bltz    $t2, DFA_loop_exit
            bgt     $t2, $t1, DFA_loop_exit
            addu    $t2, $t2, $t2
            addu    $t2, $t2, $t2
            la      $t3, jtable
            addiu   $t3, $t3, 16
            addu    $t2, $t3, $t2
            lw      $t2, 0($t2)
            jr      $t2
        
            L1_0:
                li      $v0, 0
                j       DFA_loop_exit
            L1_1:
                li      $v0, 1
                j       DFA_loop_exit
        
        DFA_loop_exit:
            addiu   $a0, $a0, 4
            j   DFA_loop
    
    DFA_exit:
    jr      $ra

print_int:
    li      $v0, 1
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
    move    $a0, $v0
    jal     fill_arr
    la      $a0, x
    addu    $a1, $s0, $s0
    addu    $a1, $a1, $a1
    addu    $a1, $a0, $a1
    jal     DFA
    move    $a0, $v0
    jal     print_int
    jal     print_newln
    jal     print_newln
    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
jtable:     .word L0 L1 L0_0 L0_1 L1_0 L1_1
x:          .word 0