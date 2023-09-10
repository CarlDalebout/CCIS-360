    .text
    .globl main
######################################################################
#
# text Segment
#
######################################################################
#=====================================================================
# Input:
#
# Register Association:
#  $s0 = a
#  $s1 = b
#  $s2 = c
#  $s4 = d
# 
# Temporary Register Used:
#   
#  $t0
#  
# Output;
#
#======================================================================
main:
    li $v0, 5  # Read int and store in $s0
    syscall
    move $s0, $v0

    li $v0, 5  # Read int and store in $s1
    syscall
    move $s1, $v0

    li $v0, 5  # Read in and store in $s2
    syscall
    move $s2, $v0
    
    li $v0, 5  # Read in and store in $s3
    syscall
    move $s3, $v0

    # $s0 = a
    # $s1 = b
    # $s2 = c
    # $s3 = d
    #
    
    # COMPUTATION OF s0,s1,s2,s3

    add     $s0, $s0, $s0 
    add     $t0, $s0, $s1
    add     $t0, $t0, $s2
   
    add     $s0, $s0, $s0
    sub     $s0, $s0, $t0

    sub     $t0, $s3, $s1
    sub     $s0, $s0, $t0     

    # Printing of the values

    li $v0, 1 # Print int $s0
    move $a0, $s0
    syscall

    li $v0, 4 # Print newline
    la $a0, NEWLINE
    syscall

    
    li $v0, 1 # Print int $s1
    move $a0, $s1
    syscall

    li $v0, 4 # Print newline
    la $a0, NEWLINE
    syscall


    li $v0, 1 # Print int $s2
    move $a0, $s2
    syscall

    li $v0, 4 # Print newline
    la $a0, NEWLINE
    syscall


    li $v0, 1 # Print int $s3
    move $a0, $s3
    syscall

    li $v0, 4 # Print newline
    la $a0, NEWLINE
    syscall

    li $v0, 10
    syscall
    ######################################################################
    #
    # data Segment
    #
    ######################################################################
    .data
    NEWLINE: .asciiz "\n"