    .text
    .globl main
######################################################################
#
# text Segment
#
######################################################################
main:
    li $v0, 5  # Read int and store in $s0
    syscall
    move $s0, $v0

    li $v0, 5  # Read int and store in $s1
    syscall
    move $s1, $v0

    li $v0, 5  # Read in and store in $s3
    syscall
    move $s3, $v0
    
    li $v0, 5  # Read in and store in $s4
    syscall
    move $s4, $v0
                                # $s0 = a
                                # $s1 = b
                                # $s3 = c
                                # $s4 = d
                                #
    # COMPUTATION OF s0,s1,s3,s4
    move    $t0, $s0            # int t0 = a;
    add     $t0, $t0, $t0       # int t0 = t0 + t0;
    add     $t0, $t0, $t0       # int t0 = t0 + t0;
    add     $t1, $s1, $s3       # int t1 = b + c;
    add     $t2, $s0, $s0       # int t2 = a + a;
    add     $t1, $t1, $t2       #     t1 = t1 + t2;
    sub     $t3, $s4, $s1       # int t3 = d - b;
    sub     $t5, $t0, $t1       # int t5 = t0 - t1;
    sub     $t6, $t5, $t3       # int t6 = t5 - t3;
    move    $s0, $t6            # a = t6;

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


    li $v0, 1 # Print int $s3
    move $a0, $s3
    syscall

    li $v0, 4 # Print newline
    la $a0, NEWLINE
    syscall


    li $v0, 1 # Print int $s4
    move $a0, $s4
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