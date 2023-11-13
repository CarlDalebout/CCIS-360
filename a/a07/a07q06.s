    .text
    .globl main

# bubblesort_iterate: # a0 = x[] # a1 = x[n]
#  bubblesort_iterate_loop:
#   bgt   $a0, $a1, bubblesort_iterate_loop_end
#     lw  $t1, 0($a0)
#     lw  $t2, 4($a0)
#     bgt $t1, $t2, bubblesort_iterate_swap # if(t1 > t2) {}
#       j bubblesort_iterate_loop_continue
#     bubblesort_iterate_swap:
#       sw  $t2, 0($a0)
#       sw  $t1, 4($a0)
#     bubblesort_iterate_loop_continue:
#   addiu $a0, $a0, 4
#   j   bubblesort_iterate_loop
#   bubblesort_iterate_loop_end:
#   jr    $ra

bubblesort_iterate: # a0 = &x, a1 = $x[n-1]
    addiu   $a1, $a1, -4
    bubblesort_iterate_loop:
    beq     $a0, $a1, bubblesort_iterate_loop_exit
        lw      $t0, 0($a0)
        lw      $t1, 4($a0)
        bgt     $t0, $t1, bubblesort_iterate_swap
            j   bubblesort_iterate_loop_continue
        bubblesort_iterate_swap:
            sw      $t0, 4($a0)
            sw      $t1, 0($a0)
        bubblesort_iterate_loop_continue:
        addiu   $a0, $a0, 4
        j       bubblesort_iterate_loop
    bubblesort_iterate_loop_exit:
    jr      $ra

bubblesort: # a0 = x[], a1 = n
  bubblesort_loop:
  beq   $a1, $a0, bubblesort_loop_exit
      addiu $sp, $sp, -12
      sw    $ra, 0($sp)
      sw    $a0, 4($sp)
      sw    $a1, 8($sp)
        jal   bubblesort_iterate
      lw    $a1, 8($sp)
      lw    $a0, 4($sp)
      lw    $ra, 0($sp)
  addiu $a1, $a1, -4 
  j     bubblesort_loop
  bubblesort_loop_exit:
  jr    $ra

print_int: # a0 = x[i]
    li      $v0, 1
    syscall
    jr      $ra

print_space:
    li      $v0, 4
    la      $a0, SPACE
    syscall
    jr      $ra

print_newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

# print_int_array: # a0 = &start, a1 =&end
#     blt    $a0, $a1 print_int_array_rec
#         addiu   $sp, $sp, -4
#         sw      $ra, 0($sp)
#             jal     print_newln
#         lw      $ra, 0($sp)
#         addiu   $sp, $sp, 4
#         jr      $ra
#     print_int_array_rec:
#         addiu   $sp, $sp, -8
#         sw      $ra, 0($sp)
#         sw      $a0, 4($sp)
#         lw      $a0, 0($a0)
#         jal     print_int
#         jal     print_space
#         lw      $a0, 4($sp)
#         lw      $ra, 0($sp)
#         addiu   $sp, $sp, 8
#         addiu   $a0, $a0, 4
#         jal     print_int_array
#         jr      $ra

print_int_array: # a0 = &x, a1 = x[n+1]
    beq     $a0, $a1, print_int_array_exit
        addiu   $sp, $sp, -8
        sw      $ra, 0($sp)
        sw      $a0, 4($sp)
            lw      $a0, 0($a0)
            jal     print_int
            jal     print_space
        lw      $a0, 4($sp)
        lw      $ra, 0($sp)
        addiu   $sp, $sp, 8
        addiu   $a0, $a0, 4
        j     print_int_array
    print_int_array_exit:
    addiu   $sp, $sp, -4
    sw      $ra, 0($sp)
    jal     print_newln
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 4
    jr      $ra

main:
    la      $a0, X
    li      $a1, 8
    addu    $a1, $a1, $a1
    addu    $a1, $a1, $a1
    addu    $a1, $a1, $a0
    jal     bubblesort
    la      $a0, X
    li      $a1, 8
    addu    $a1, $a1, $a1
    addu    $a1, $a1, $a1
    addu    $a1, $a1, $a0
    jal     print_int_array

    li      $v0, 10
    syscall

    .data
NEWLINE:    .asciiz "\n"
SPACE:      .asciiz " "
X:          .word   200 3 10 11d 20 100 101