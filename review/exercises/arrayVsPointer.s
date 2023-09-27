    .text
    .globl main

# array 2 + 7n
# main:
    
#         li      $t0, 0          # i = 0
# Loop:   beq     $t0, $a1, end
#         add     $t1, $t0, $t0
#         add     $t1, $t1, $t1
#         add     $t1, $a0, $t1   # t1 = &a[i]
#         sw      $0, 0($t1)      # a[i] = 0
#                                 # t2 = 4*i = 4 * t0
#         addi    $t0, $t0, 1     # i++
#         j Loop

# end:

# pointers 5 + 4n
# main:
#         # t0 = q
#     add     $t0, $a1, $a1
#     add     $t0, $t0, $t0
#     add     $t0, $a0, $t0       # t0 = array + size;
#     move    $t1, $a0            # t1 = p

# Loop:
#     beq     $t1, $t0 end
#     sw      $0,  0($t1)
#     addiu    $t1, $t1, 4
#     j   Loop
# end:

