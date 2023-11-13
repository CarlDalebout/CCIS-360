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

print_string:
    li      $v0, 4
    syscall
    jr      $ra

print_newln:
    li      $v0, 4 # Print newline
    la      $a0, NEWLINE
    syscall
    jr      $ra

init_dynamic_array: # a0 = n, a1 = address of board[]
    # finding the middle for 
    li      $t0, 2
    div     $a0, $t0
    mflo    $t0             # t0 = n/2
    mult    $a0, $t0
    mflo    $t1             # t1 = n * n/2 
    add     $t0, $t1, $t0   # t0 = n * n/2 + n/2 aka [n/2][n/2]
    add     $t0, $t0, $t0   
    add     $t0, $t0, $t0   # t0 = [n/2][n/2] * 4 for word size
    add     $t0, $a1, $t0   # t0 = board[n/2][n/2]

    # finding the end of board[]
    mult    $a0, $a0
    mflo    $a0
    add     $a0, $a0, $a0
    add     $a0, $a0, $a0   
    add     $a0, $a1, $a0   # a0 = end address of board[]
    la      $t1, Blank_chr

    # for(int i = 0; i < a1+a0; ++i)
    init_dynamic_array_loop:
    beq     $a1, $a0, init_dynamic_array_exit
        sw      $t1, 0($a1)
    addiu   $a1, $a1, 4
    j       init_dynamic_array_loop
    init_dynamic_array_exit:
    la      $t1, Computer_piece
    sw      $t1, 0($t0)

    jr      $ra

print_board: # a0 = n a1 = address of board[]
    li      $t0, 0          # row = 0
    li      $t1, 0          # col = 0
    add     $t3, $a0, $a0   # t3  = n * 2
    printboard_row_loop: # for(int row = 0; row < n*2; ++row)
    beq     $t0, $t3, print_board_row_loop_exit       
        li      $t1, 0
        print_board_col_loop:   #   for(int col = 0; col < n; ++col) 
        beq     $t1, $a0, print_board_col_loop_exit
            li      $t4, 2
            div     $t0, $t4
            mfhi    $t4                     # $t4 = row % 2
            bne     $t4, $0, print_board_if # if(t0 % 2 != 0) 
            addiu   $sp, $sp, -8
                sw      $ra, 0($sp)
                sw      $a0, 4($sp)
                la      $a0, Row_chr
                jal     print_string    # prints "+-"
                lw      $a0, 4($sp)
                lw      $ra, 0($sp)
            addiu   $sp, $sp, 8
            addiu   $t1, $t1, 1
            j       print_board_col_loop
            print_board_if:
            addiu   $sp, $sp, -8
                sw      $ra, 0($sp)
                sw      $a0, 4($sp)
                la      $a0, Col_chr
                jal     print_string    # prints "|"
                lw      $a0, 0($a1)
                jal     print_string    # prints "board[a1]"
                lw      $a0, 4($sp)
                lw      $ra, 0($sp)
            addiu   $sp, $sp, 8
            addiu   $a1, $a1, 4         # a1 = address of the next element
            addiu   $t1, $t1, 1
            j       print_board_col_loop
        print_board_col_loop_exit:
        li      $t4, 2
        div     $t0, $t4
        mfhi    $t4                     # t4 = row % 2
        bne     $t4, $0, print_board_col_loop_exit_if # if(t0 % 2 != 0) 
            addiu   $sp, $sp, -8
                sw      $ra, 0($sp)
                sw      $a0, 4($sp)
                la      $a0, End_row_chr
                jal     print_string    # prints "+"
                jal     print_newln     # prints "\n"
                lw      $a0, 4($sp)
                lw      $ra, 0($sp)
            addiu   $sp, $sp, 8
            addiu   $t0, $t0, 1
            j       printboard_row_loop
        print_board_col_loop_exit_if:
            addiu   $sp, $sp, -8
                sw      $ra, 0($sp)
                sw      $a0, 4($sp)
                la      $a0, Col_chr
                jal     print_string    # prints "|"
                jal     print_newln     # prints "\n"
                lw      $a0, 4($sp)
                lw      $ra, 0($sp)
            addiu   $sp, $sp, 8
            addiu   $t0, $t0, 1
            j       printboard_row_loop
    print_board_row_loop_exit:
    li      $t1, 0  
    print_board_last_row_loop:
    beq     $t1, $a0, print_board_last_row_loop_exit
        addiu   $sp, $sp, -8
            sw      $ra, 0($sp)
            sw      $a0, 4($sp)
            la      $a0, Row_chr
            jal     print_string    # prints "+-"
            lw      $a0, 4($sp)
            lw      $ra, 0($sp)
        addiu   $sp, $sp, 8
        addiu   $t1, $t1, 1
        j       print_board_last_row_loop
    print_board_last_row_loop_exit:
    addiu   $sp, $sp, -8
        sw      $ra, 0($sp)
        sw      $a0, 4($sp)
        la      $a0, End_row_chr
        jal     print_string    # prints "+"
        jal     print_newln     # prints "\n"
        lw      $a0, 4($sp)
        lw      $ra, 0($sp)
    addiu   $sp, $sp, 8
    jr      $ra

player_turn: # a0 = n, a1 = address of board[]
    addiu   $sp, $sp, -8
    sw      $a0, 4($sp)
    sw      $ra, 0($sp)
        la      $a0, Get_row_text
        jal     print_string
        jal     read_int
        move    $t0, $v0                # t0 = row
    
        la      $a0, Get_column_text
        jal     print_string
        jal     read_int
        move    $t1, $v0                # t1 = col
    lw      $ra, 0($sp)
    lw      $a0, 4($sp)
    addiu   $sp, $sp, 8
    # checking if row and col are in range 
    bge     $t0, $a0, player_turn_error_check   # row is larger then n
    blt     $t0, $0,  player_turn_error_check   # row is less then 0
    bge     $t1, $a0, player_turn_error_check   # col is larger then n
    blt     $t1, $0 , player_turn_error_check   # col is less then 0
    mult    $a0, $t0
    mflo    $t0
    add     $t0, $t0, $t1               # t0 = [row][col]
    add     $t0, $t0, $t0
    add     $t0, $t0, $t0
    add     $t0, $t0, $a1               # to = board[row][col]
    lw      $t1, 0($t0)
    la      $t2, Blank_chr
    
    beq     $t1, $t2, player_turn_place_piece
    player_turn_error_check:
        addiu   $sp, $sp, -8
        sw      $ra, 0($sp)
        sw      $a0, 4($sp)
            la      $a0, Input_error_text
            jal     print_string
        lw      $a0, 4($sp)
        lw      $ra, 0($sp)
        addiu   $sp, $sp, 8
        j   player_turn
    player_turn_place_piece:
    la      $t1, Player_piece
    sw      $t1, 0($t0)
    jr      $ra      

look_for_pieces: # a0 = n, a1 = board[] 
    li      $v0, 0  # address
    li      $t0, 0  # o_char
    li      $t1, 0  # x_char
    li      $t2, 0  # row
    look_for_pieces_rowcheck_row:
    beq     $t2, $a0, look_for_pieces_rowcheck_row_exit
        li      $t0, 0  # o_char
        li      $t1, 0  # x_char
        li      $t3, 0  # col
        look_for_pieces_rowcheck_col:
        beq     $t3, $a0, look_for_pieces_rowcheck_col_exit
            mult    $t2, $a0
            mflo    $t4             # [(row*a0)]
            addu    $t4, $t4, $t3
            addu    $t4, $t4, $t4
            addu    $t4, $t4, $t4
            addu    $t4, $t4, $a1   # a1[(row*a0) + col]
            lw      $t5, 0($t4)
            la      $t6, Blank_chr
            bne     $t5, $t6, look_for_pieces_rowcheck_notblank
                sub     $v0, $t4, $a1
                j       look_for_pieces_rowcheck_col_continue
            look_for_pieces_rowcheck_notblank:
                la      $t6, Computer_piece
                beq     $t5, $t6 look_for_pieces_rowcheck_found_O
                    addiu       $t1, $t1, 1
                    j       look_for_pieces_rowcheck_col_continue
                look_for_pieces_rowcheck_found_O:
                    addiu       $t0, $t0, 1
        look_for_pieces_rowcheck_col_continue:
        addiu   $t3, $t3, 1
        j       look_for_pieces_rowcheck_col
    look_for_pieces_rowcheck_col_exit:
    li      $t4, 1
    sub     $t4, $a0, $t4
    beq     $t0, $t4, look_for_pieces_rowcheck_winning
        j       look_for_pieces_rowcheck_winning_exit
    look_for_pieces_rowcheck_winning:
        beq $t1, $0, look_for_pieces_rowcheck_winning_check
            j       look_for_pieces_rowcheck_winning_exit
        look_for_pieces_rowcheck_winning_check:
            jr      $ra
    look_for_pieces_rowcheck_winning_exit:
    beq     $t1, $t4, look_for_pieces_rowcheck_blocking
        j       look_for_pieces_rowcheck_blocking_exit
    look_for_pieces_rowcheck_blocking:
        beq $t0, $0, look_for_pieces_rowcheck_blocking_check
            j       look_for_pieces_rowcheck_blocking_exit
        look_for_pieces_rowcheck_blocking_check:
            jr      $ra
    look_for_pieces_rowcheck_blocking_exit:
    addiu   $t2, $t2, 1
    j       look_for_pieces_rowcheck_row
    look_for_pieces_rowcheck_row_exit:

    li      $v0, 0  # address
    li      $t0, 0  # o_char
    li      $t1, 0  # x_char
    li      $t2, 0  # row
    li      $t3, 0  # col
    look_for_pieces_colcheck_col:
    beq     $t3, $a0, look_for_pieces_colcheck_col_exit
        li  $t0, 0  # o_char
        li  $t1, 0  # x_char
        li  $t2, 0  # row
        look_for_pieces_colcheck_row:
        beq     $t2, $a0, look_for_pieces_colcheck_row_exit
            mult    $t2, $a0
            mflo    $t4             # [(row*a0)]
            addu    $t4, $t4, $t3   # [(row*a0) + col]
            addu    $t4, $t4, $t4
            addu    $t4, $t4, $t4
            addu    $t4, $t4, $a1   # a1[(row*a0) + col]
            lw      $t5, 0($t4)
            la      $t6, Blank_chr
            bne     $t5, $t6, look_for_pieces_colcheck_notblank
                sub     $v0, $t4, $a1
                j       look_for_pieces_colcheck_row_continue
            look_for_pieces_colcheck_notblank:
                la      $t6, Computer_piece
                beq     $t5, $t6 look_for_pieces_colcheck_found_O
                    addiu       $t1, $t1, 1
                    j       look_for_pieces_colcheck_row_continue
                look_for_pieces_colcheck_found_O:
                    addiu       $t0, $t0, 1
        look_for_pieces_colcheck_row_continue:
        addiu   $t2, $t2, 1
        j       look_for_pieces_colcheck_row
        look_for_pieces_colcheck_row_exit:
    li      $t4, 1
    sub     $t4, $a0, $t4
    beq     $t0, $t4, look_for_pieces_colcheck_winning
        j       look_for_pieces_colcheck_winning_exit
    look_for_pieces_colcheck_winning:
        beq $t1, $0, look_for_pieces_colcheck_winning_check
            j       look_for_pieces_colcheck_winning_exit
        look_for_pieces_colcheck_winning_check:
            jr      $ra
    look_for_pieces_colcheck_winning_exit:
    beq     $t1, $t4, look_for_pieces_colcheck_blocking
        j       look_for_pieces_colcheck_blocking_exit
    look_for_pieces_colcheck_blocking:
        beq $t0, $0, look_for_pieces_colcheck_blocking_check
            j       look_for_pieces_colcheck_blocking_exit
        look_for_pieces_colcheck_blocking_check:
            jr      $ra
    look_for_pieces_colcheck_blocking_exit:
    addiu   $t3, $t3, 1
    j       look_for_pieces_colcheck_col
    look_for_pieces_colcheck_col_exit:

    li      $v0, 0  # address
    li      $t0, 0  # o_char
    li      $t1, 0  # x_char
    li      $t2, 0  # diag
    look_for_pieces_diag_lr_check:
    beq     $t2, $a0, look_for_pieces_diag_lr_check_exit
        mult    $t2, $a0
        mflo    $t3             # address[diag*a0]
        addu    $t3, $t3, $t2
        addu    $t3, $t3, $t3
        addu    $t3, $t3, $t3
        addu    $t3, $t3, $a1   #  a1[(diag*a0) + diag]
        lw      $t4, 0($t3)
        la      $t5, Blank_chr
        bne     $t4, $t5, look_for_pieces_diag_lr_check_notblank
            sub     $v0, $t3, $a1
            j       look_for_pieces_diag_lr_check_continue
        look_for_pieces_diag_lr_check_notblank:
            la      $t5, Computer_piece
            beq     $t4, $t5, look_for_pieces_diag_lr_check_found_O
                addiu   $t1, $t1, 1
                j   look_for_pieces_diag_lr_check_continue 
            look_for_pieces_diag_lr_check_found_O:
                addiu   $t0, $t0, 1
    look_for_pieces_diag_lr_check_continue:
    addiu   $t2, $t2, 1
    j       look_for_pieces_diag_lr_check
    look_for_pieces_diag_lr_check_exit:
    li      $t3, 1
    sub     $t3, $a0, $t3
    beq     $t0, $t3, look_for_pieces_diag_lr_winning
        j       look_for_pieces_diag_lr_winning_exit
    look_for_pieces_diag_lr_winning:
        beq $t1, $0, look_for_pieces_diag_lr_winning_check
            j       look_for_pieces_diag_lr_winning_exit
        look_for_pieces_diag_lr_winning_check:
            jr      $ra
    look_for_pieces_diag_lr_winning_exit:
    beq     $t1, $t4, look_for_pieces_diag_lr_blocking
        j       look_for_pieces_diag_lr_blocking_exit
    look_for_pieces_diag_lr_blocking:
        beq $t0, $0, look_for_pieces_diag_lr_blocking_check
            j       look_for_pieces_diag_lr_blocking_exit
        look_for_pieces_diag_lr_blocking_check:
            jr      $ra
    look_for_pieces_diag_lr_blocking_exit:

    li      $v0, 0  # address
    li      $t0, 0  # o_char
    li      $t1, 0  # x_char
    li      $t2, 0  # diag
    look_for_pieces_diag_rl_check:
    beq     $t2, $a0, look_for_pieces_diag_rl_check_exit
        mult    $t2, $a0
        mflo    $t3             # address[diag*a0]
        sub     $t4, $a0, $t2   # (a0 - diag)
        addiu   $t4, $t4, -1    # (a0 - diag) - 1
        addu    $t3, $t3, $t4   # (diag * a0) + (a0 - diag) - 1
        addu    $t3, $t3, $t3
        addu    $t3, $t3, $t3
        addu    $t3, $t3, $a1   #  a1[(diag*a0) + (a0 - diag) - 1]
        lw      $t4, 0($t3)
        la      $t5, Blank_chr
        bne     $t4, $t5, look_for_pieces_diag_rl_check_notblank
            sub     $v0, $t3, $a1
            j       look_for_pieces_diag_rl_check_continue
        look_for_pieces_diag_rl_check_notblank:
            la      $t5, Computer_piece
            beq     $t4, $t5, look_for_pieces_diag_rl_check_found_O
                addiu   $t1, $t1, 1
                j   look_for_pieces_diag_rl_check_continue 
            look_for_pieces_diag_rl_check_found_O:
                addiu   $t0, $t0, 1
    look_for_pieces_diag_rl_check_continue:
    addiu   $t2, $t2, 1
    j       look_for_pieces_diag_rl_check
    look_for_pieces_diag_rl_check_exit:
    li      $t3, 1
    sub     $t3, $a0, $t3   # a0-1
    beq     $t0, $t3, look_for_pieces_diag_rl_winning
        j       look_for_pieces_diag_rl_winning_exit
    look_for_pieces_diag_rl_winning:
        beq $t1, $0, look_for_pieces_diag_rl_winning_check
            j       look_for_pieces_diag_rl_winning_exit
        look_for_pieces_diag_rl_winning_check:
            jr      $ra
    look_for_pieces_diag_rl_winning_exit:
    beq     $t1, $t4, look_for_pieces_diag_rl_blocking
        j       look_for_pieces_diag_rl_blocking_exit
    look_for_pieces_diag_rl_blocking:
        beq $t0, $0, look_for_pieces_diag_rl_blocking_check
            j       look_for_pieces_diag_rl_blocking_exit
        look_for_pieces_diag_rl_blocking_check:
            jr      $ra
    look_for_pieces_diag_rl_blocking_exit:
    li      $v0, 0
    jr  $ra

computer_turn:  # a0 = n, a1 = board[]
    addiu   $sp, $sp, -12
    sw      $ra, 0($sp)
    sw      $a0, 4($sp)
    sw      $a1, 8($sp)
        jal     look_for_pieces
    lw      $a1, 8($sp)
    lw      $a0, 4($sp)
    lw      $ra, 0($sp)
    addiu   $sp, $sp, 12
    beq     $v0, $0, computer_turn_find_rand
        addu   $v0, $v0, $a1
        la      $t0, Computer_piece
        sw      $t0, 0($v0)
        jr      $ra
    computer_turn_find_rand:
    li      $t0, 0  # row
    computer_turn_find_rand_row:
    beq     $t0, $a0, computer_turn_find_rand_row_exit
        li      $t1, 0 # col
        computer_turn_find_rand_col:
        beq     $t1, $a0, computer_turn_find_rand_col_exit
            mult    $t0, $a0
            mflo    $t2             # address[(row*a0)]
            addu    $t2, $t2, $t1   # address[(row*a0) + col]
            addu    $t2, $t2, $t2
            addu    $t2, $t2, $t2
            addu    $t2, $t2, $a1   # a1[(row*a0) + col]
            lw      $t3, 0($t2)
            la      $t4, Blank_chr
            beq     $t3, $t4    computer_turn_find_rand_found_blank
                j       computer_turn_find_rand_continue
            computer_turn_find_rand_found_blank:
            la      $t4, Computer_piece
            sw      $t4, 0($t2)
            jr      $ra
        computer_turn_find_rand_continue:
        addiu   $t1, $t1, 1
        j       computer_turn_find_rand_col
        computer_turn_find_rand_col_exit:
    addiu   $t0, $t0, 1
    j       computer_turn_find_rand_row
    computer_turn_find_rand_row_exit:
    jr      $ra
    
check_game_state:
    li      $t0, 0  # 0_char
    li      $t1, 0  # x_char
    li      $t2, 0  # s_char
    li      $t3, 0  # row
    li      $t4, 0  # col
    check_game_state_rowcheck_row:
    beq     $t3, $a0, check_game_state_rowcheck_row_exit
        li      $t0, 0 
        li      $t1, 0 
        li      $t4, 0 
        check_game_state_rowcheck_col:
        beq     $t4, $a0, check_game_state_rowcheck_col_exit
            mult    $t3, $a0
            mflo    $t5             # address[(row*a0)]
            addu    $t5, $t5, $t4   # address[(row*a0) + col]
            addu    $t5, $t5, $t5
            addu    $t5, $t5, $t5   
            addu    $t5, $t5, $a1   # a1[(row*a0) + col]
            lw      $t6, 0($t5)
            la      $t7, Blank_chr
            bne     $t6, $t7, check_game_state_rowcheck_not_blank
                addiu   $t2, $t2, 1
                j   check_game_state_rowcheck_col_continue
            check_game_state_rowcheck_not_blank:
            la      $t7, Computer_piece
            beq     $t6, $t7, check_game_state_rowcheck_found_O
                addiu   $t1, $t1, 1
                j       check_game_state_rowcheck_col_continue
            check_game_state_rowcheck_found_O:
                addiu   $t0, $t0, 1
        check_game_state_rowcheck_col_continue:
        addiu   $t4, $t4, 1
        j       check_game_state_rowcheck_col
        check_game_state_rowcheck_col_exit:
        bne     $t0, $a0, check_game_state_rowcheck_check_player_winning
            li      $v0, 1
            jr      $ra
        check_game_state_rowcheck_check_player_winning:
        bne     $t1, $a0, check_game_state_rowcheck_row_continue
            li      $v0, 2
            jr      $ra
    check_game_state_rowcheck_row_continue:
    addiu   $t3, $t3, 1
    j       check_game_state_rowcheck_row
    check_game_state_rowcheck_row_exit:
    bne     $2, $0  check_game_state_rowcheck_draw
        li      $v0, 3
        jr      $ra
    check_game_state_rowcheck_draw:
    
    li      $t0, 0  # 0_char
    li      $t1, 0  # x_char
    li      $t2, 0  # s_char
    li      $t3, 0  # row
    li      $t4, 0  # col
    check_game_state_colcheck_col:
    beq     $t4, $a0, check_game_state_colcheck_col_exit
        li      $t0, 0
        li      $t1, 0
        li      $t3, 0
        check_game_state_colcheck_row:
        beq     $t3, $a0, check_game_state_colcheck_row_exit
            mult    $t3, $a0
            mflo    $t5             # address[(row * a0)]
            addu   $t5, $t5, $t4   # address[(row * a0) + col]
            addu   $t5, $t5, $t5   
            addu   $t5, $t5, $t5
            addu   $t5, $t5, $a1   # al[(row * a0) + col]
            lw      $t6, 0($t5)
            la      $t7, Blank_chr
            bne     $t6, $t7, check_game_state_colcheck_not_blank
                addiu   $t2, $t2, 1
                j       check_game_state_colcheck_row_continue
            check_game_state_colcheck_not_blank:
            la      $t7, Computer_piece
            beq     $t6, $t7, check_game_state_colcheck_found_O
                addiu   $t1, $t1, 1
                j       check_game_state_colcheck_row_continue
            check_game_state_colcheck_found_O:
                addiu   $t0, $t0, 1
        check_game_state_colcheck_row_continue:
        addiu   $t3, $t3, 1
        j       check_game_state_colcheck_row
        check_game_state_colcheck_row_exit:
        bne     $t0, $a0, check_game_state_colcheck_check_player_winning
            li      $v0, 1
            jr      $ra
        check_game_state_colcheck_check_player_winning:
        bne     $t1, $a0, check_game_state_colcheck_col_continue
            li      $v0, 2
            jr      $ra
    check_game_state_colcheck_col_continue:
    addiu   $t4, $t4, 1
    j   check_game_state_colcheck_col
    check_game_state_colcheck_col_exit:
    bne     $2, $0  check_game_state_colcheck_draw
        li      $v0, 3
        jr      $ra
    check_game_state_colcheck_draw:

    li      $t0, 0  # 0_char
    li      $t1, 0  # x_char
    li      $t2, 0  # s_char
    li      $t3, 0  # diag
    check_game_state_diag_rl:
    beq     $t3, $a0, check_game_state_diag_rl_exit
        mult    $t3, $a0
        mflo    $t4             # address[(diag*a0)]
        addu    $t4, $t4, $t3   # address[(diag*a0) + diag]
        addu    $t4, $t4, $t4
        addu    $t4, $t4, $t4
        addu    $t4, $t4, $a1   # a1[(diag*a0) + diag]
        lw      $t5, 0($t4)
        la      $t6, Blank_chr
        bne     $t5, $t6, check_game_state_diag_rl_not_blank
            addiu   $t2, $t2, 1
            j       check_game_state_diag_rl_continue
        check_game_state_diag_rl_not_blank:
        la      $t6, Computer_piece
        beq     $t5, $t6, check_game_state_diag_rl_found_O
            addiu   $t1, $t1, 1
            j       check_game_state_diag_rl_continue
        check_game_state_diag_rl_found_O:
            addiu   $t0, $t0, 1
    check_game_state_diag_rl_continue:
    addiu   $t3, $t3, 1
    j       check_game_state_diag_rl
    check_game_state_diag_rl_exit:
    bne     $t0, $a0, check_game_state_diag_rl_check_player_winning
        li      $v0, 1
        jr      $ra
    check_game_state_diag_rl_check_player_winning:
    bne     $t1, $a0, check_game_state_diag_rl_done
        li      $v0, 2
        jr      $ra
    check_game_state_diag_rl_done:

    li      $t0, 0  # 0_char
    li      $t1, 0  # x_char
    li      $t2, 0  # s_char
    li      $t3, 0  # diag
    check_game_state_diag_lr:
    beq     $t3, $a0, check_game_state_diag_lr_exit
        mult    $t3, $a0
        mflo    $t4             # address[(diag*a0)]
        sub     $t5, $a0, $t3   # (a0 - diag)
        addiu   $t5, $t5, -1    # (a0 - diag) -1
        addu    $t4, $t4, $t5   # address[(diag*a0) + (a0 -diag) -1]
        addu    $t4, $t4, $t4
        addu    $t4, $t4, $t4
        addu    $t4, $t4, $a1   # a1[(diag*a0) + diag]
        lw      $t5, 0($t4)
        la      $t6, Blank_chr
        bne     $t5, $t6, check_game_state_diag_lr_not_blank
            addiu   $t2, $t2, 1
            j       check_game_state_diag_lr_continue
        check_game_state_diag_lr_not_blank:
        la      $t6, Computer_piece
        beq     $t5, $t6, check_game_state_diag_lr_found_O
            addiu   $t1, $t1, 1
            j       check_game_state_diag_lr_continue
        check_game_state_diag_lr_found_O:
            addiu   $t0, $t0, 1
    check_game_state_diag_lr_continue:
    addiu   $t3, $t3, 1
    j       check_game_state_diag_lr
    check_game_state_diag_lr_exit:
    bne     $t0, $a0, check_game_state_diag_lr_check_player_winning
        li      $v0, 1
        jr      $ra
    check_game_state_diag_lr_check_player_winning:
    bne     $t1, $a0, check_game_state_diag_lr_done
        li      $v0, 2
        jr      $ra
    check_game_state_diag_lr_done:
    li      $v0, 0
    jr      $ra

main:
    la      $a0, Intro_1
    jal     print_string
    jal     read_int
    move    $s0, $v0        # s0 = n
    la      $a0, Intor_2
    jal     print_string
    mult    $s0, $s0
    mflo    $s1             # s1 = n * n
    addu    $s1, $s1, $s1
    addu    $s1, $s1, $s1   # s1 = size of board[]
    move    $a0, $s1
    li      $v0, 9
    syscall
    move    $s2, $v0        # s2 = address of board[]
    move    $a1, $v0        
    move    $a0, $s0
    jal     init_dynamic_array

    move    $a0, $s0        # a0 = n
    move    $a1, $s2        # a1 = address of board[]
    jal     print_board

    li      $v0, 0
    main_loop:
        move    $a0, $s0
        move    $a1, $s2
        jal     player_turn
        move    $a0, $s0
        move    $a1, $s2
        jal     print_board
        move    $a0, $s0
        move    $a1, $s2
        jal     check_game_state
    bne     $v0, $0, main_loop_exit
        move    $a0, $s0
        move    $a1, $s2
        jal     computer_turn
        move    $a0, $s0
        move    $a1, $s2
        jal     print_board
        move    $a0, $s0
        move    $a1, $s2
        jal     check_game_state

    bne     $v0, $0, main_loop_exit
    j       main_loop
    main_loop_exit:
    add     $t0, $v0, $v0
    add     $t0, $t0, $t0   # t0 = 4 * s0
    la      $t1, Jtable
    add     $t0, $t1, $t0
    lw      $t0, 0($t0)
    jr      $t0

    Broken:
        la      $a0, Broken_text
        jal     print_string
        j       exit
    
    Draw:
        la      $a0, Computer_wins_text
        jal     print_string
        j       exit
    
    Computer_wins:
        la      $a0, Player_wins_text
        jal     print_string
        j      exit
    
    Player_wins:
        la      $a0 Draw_text
        jal     print_string
    
    exit:
    li      $v0, 10
    syscall

    .data
Intro_1:            .asciiz "Lets play a game of tic-tac-toe\nEnter n: "
Intor_2:            .asciiz "Ill go first.\n"
Get_row_text:       .asciiz "Enter row: "
Get_column_text:    .asciiz "Enter column: "
Input_error_text:   .asciiz "Invalid arrument try again\n"
Row_chr:            .asciiz "+-"
End_row_chr:        .asciiz "+"
Col_chr:            .asciiz "|"
Blank_chr:          .asciiz " "
Computer_piece:     .asciiz "O"
Player_piece:       .asciiz "X"
NEWLINE:            .asciiz "\n"
Jtable:             .word   Broken, Draw, Computer_wins, Player_wins
Broken_text:        .asciiz "Something is broken"
Draw_text:          .asciiz "We have a draw!"
Computer_wins_text: .asciiz "I am the winner!"
Player_wins_text:   .asciiz "You are the winner!"
