    .text
    .globl main
main:
        li      $s0, 42
while:  li      $v0, 5
        syscall
        bne     $v0, $s0, while

exit:   
        li      $v0, 10
        syscall
        