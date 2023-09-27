    .text
    .globl main
# index version:
# main:
#         la      $s0, x
#         li      $s1, 7
#         lw      $s2, 0($s0)     # m = x[0]
#         li      $t0, 1          # i = 1
# Loop:   
#         beq     $t0, $s1, exit  # if(i < x.size())
#         addu    $t1, $t0, $t0
#         addu    $t1, $t1, $t1
#         addu    $t1, $s0, $t1
#         lw      $t1, 0($t1)

#         ble     $t1, $s2, ENDIF
#         move    $s2, $t1
# ENDIF:
#         addiu   $t0, $t0, 1
#         j Loop


main:

    # &x[0] - s0
    # p = s0
    # size = s1
    # q = s1
    #   

        la      $s0, x
        li      $s1, 6
        lw      $s2, 0($s0)
        addu    $s1, $s1, $s1
        addu    $s1, $s1, $s1
        addu    $s1, $s0, $s1
        addiu   $s0, $s0, 4
Loop:
        beq     $s0, $s1, exit
        lw      $t0, 0($s0)
        ble     $t0, $s2, ENDIF
        move    $s2, $t0
ENDIF:
        addiu   $s0, $s0, 4
        j       Loop
exit:
        move    $a0, $s2
        li      $v0, 1
        syscall
        li      $v0, 10
        syscall
    .data
x:  .word 7 5 1 9 2 0 6