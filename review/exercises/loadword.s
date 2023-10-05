    .text
    .globl main

main:
    # la      $s0, 0x10010000
    # lw      $a0, 0($s0)
    # lw      $s1, 4($s0)
    # add     $a0, $a0, $s1
    
    # li      $v0, 1
    # syscall

    # sw      $a0, 8($s0)

    # li      $v0, 10
    # syscall

    # .data
    # .word 5 7 3 7

la      $s0, X
lw      $s0, 0($s0)
li      $v0, 10
syscall

    .data
X:  .word X
NEWLINE: .asciiz "\n"