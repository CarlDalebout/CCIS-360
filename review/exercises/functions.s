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
    rj      $ra

print_int:
    li      $v0, 1
    syscall
    jr      $ra

print_newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

int_pow_int_int:    # $a0 = x, $a1 = i
    li      $v0, 1
    pow_loop:   
        beq     $a1, $0, pow_break
        mul     $v0, $a0, $v0
        addi    $a1, $a1, -1
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

#   a0 = x[0]
#   a1 = x[size of x]
#   a2 = int we are looking for 
#   int bin_search(int *s, int *e, int target)
#   {
#       while(s < e)
#       {
#           int *midpoint = s + (e - s) / 2
#           if(*midpoint == target) 
#               return midpoint
#           elseif(*midpoint < target)
#               s = midpoint + 1
#           else
#               e = midpoint
#       }
#   }
find_int: # not done
    ble     $a0, $a1, find_int_rec
    li      $v0, 0
    jr      $ra

    find_int_rec:
        addiu   $sp, $sp, -4
        sw      $ra, 0($sp)
        subu    $t0, $a1, $a0
        li      $t1, 2
        divu    $t0, $t1
        mflo    $t0
        addu    $t0, $a0, $t0 # t0 = m
        lw      $t1, 0($t0)
        bne     $t1, $a2    find_int_ne
            move    $v0, $t0
            jr      $ra
        find_int_ne:
            bgt     $t1, $a2
            addui   $a0, $t0, 1
            jal     find_int

# a0 = x
# a1 = y
max_int:

    blt     $a0 $a1, max_int_1   # if(a0 >= a1)
    move    $v0, $a0
    jr      $ra

    max_int_1: 
    move    $v0, $a1
    jr      $ra

# max_int_arr: # not done
#     max_int_arr_Loop:
#         beq     $a0, $a1, exit
#         lw      $t0, 0($s0)
#         ble     $t0, $t1, max_int_arr_endif
#         move    $t1, $t0
#     max_int_arr_endif:
#         addiu   $a0, $a0, 4
#         j       max_int_arr_Loop
#     move    $v0, $t0

C: # a0 = n, a1 = r
    # base case is r == n and r == 1
    li      $t0, 1
    beq     $a1, $t0, C_return_n
    beq     $a0, $a1, C_return_1
    j       C_rec
    C_return_n:
    move    $v0, $a0
    jr      $ra

    C_return_1:
    li      $v0, 1
    jr      $ra

    C_rec:
    addiu   $sp, $sp, -16
    sw      $a1, 12($sp)
    sw      $ra, 4($sp)
    addi    $a0, $a0, -1
    sw      $a0, 8($sp)
    addi    $a1, $a1, -1
    jal     C
    sw      $v0, 0($sp)
    lw      $a0, 8($sp)
    lw      $a1, 12($sp)
    addi    $a0, $a0, -1
    jal     C
    lw      $t0, 0($sp)
    add     $v0, $t0, $v0
    lw      $ra, 4($sp)
    addiu   $sp, $sp, 16
    jr      $ra

#

# a0 - n, v0 = fibonacci of n (fib(0) = 1, fib(1) = 1, ..., fib(n) = fib(n-1) + fib(n-2))
fib:
    li      $t0, 1
    bgt     $a0, $t0, fib_rec
        # fib base case
        li      $v0, 1
        jr      $ra
    fib_rec: # n > 0
        addiu   $sp, $sp, -12
        sw      $ra, 4($sp)
        sw      $a0, 8($sp)
        addi    $a0, $a0, -1
        jal     fib
        sw      $v0, 0($sp)
        lw      $a0, 8($sp)
        addi    $a0, $a0, -2
        jal     fib
        lw      $t0, 8($sp)
        add     $v0, $t0, $v0
        lw      $ra, 4($sp)
        addiu   $sp, $sp, 12
        jr      $ra

gcd:
    bne     $a1, $0 gcd_rec
        move    $a0, $v0
        jr      $ra
    gcd_rec:
        addiu   $sp, $sp, -4
        sw      $ra, 0($sp)
        div     $a0, $a1
        mfhi    $t0
        move    $a0, $a1
        move    $a1, $t0
        jal     gcd
        lw      $ra, 0($sp)
        addiu   $sp, $sp, 4
        jr      $ra

find_switch_jump: # a0 = value, a1 = Jtable
    add     $a0, $a0, $a0
    add     $a0, $a0, $a0   # t0 = 4 * s0
    add     $a0, $a1, $a0
    lw      $v0, 0($a0)
    jr      $ra

main:
    la      $a0, x
    la      $a1, y
    la      $a2, z
    lw      $a1, 0($a1)
    lw      $a2, 0($a2)
    add     $a1, $a1, $a1
    add     $a1, $a1, $a1
    add     $a1, $a0, $a1
    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
input:      .space  81
input_size: .word   80
x:          .word 2 3 10 11 15 20 100 101
y:          .word 8
z:          .word 15