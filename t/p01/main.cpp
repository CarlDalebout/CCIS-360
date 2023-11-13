#include <iostream>
#include <string>

void init_dynamic_array(int a0, char a1[])
{
    for(int row = 0; row < a0; ++row)
    {
        for(int col = 0; col < a0; ++col)
        {
            a1[(row*a0) + col] = ' ';
        }
    }
    a1[(a0/2 * a0) + a0/2] = 'O';
}

void print_board(int a0, char a1[])
{
    std::string dir = "";
    for(int row = 0; row < a0; ++row)
    {
        dir = "{";
        for(int col = 0; col < a0; ++col)
        {
            std::cout << dir << a1[(row*a0) + col]; dir = "|";
        }
        std::cout << "}"<< std::endl;
    }
}

void player_turn(int a0, char a1[])
{
    int row = 0;
    int col = 0;
    std::cout   << "row: ";
    std::cin    >> row;
    std::cout   << "col: ";
    std::cin    >>  col;
    while((row < 0 || row >= a0) || (col < 0 || col >= a0) || a1[(row*a0) + col] != ' ')
    {
        std::cout << "Sorry invalid input\n";
        std::cout   << "row: ";
        std::cin    >> row;
        std::cout   << "col: ";
        std::cin    >>  col;
    }
    a1[(row*a0) + col] = 'X';
}

int look_for_pieces(int a0, char a1[])
{
    int ret = -1;
    int o_char = 0;
    int x_char = 0;
    int row = 0;
    int col = 0;
    while(row < a0)
    {
        o_char = 0;
        x_char = 0;
        col = 0;
        while(col < a0)
        {
            int address = (row*a0) + col;
            if(a1[address] != ' ')
            {
                if(a1[address] == 'O')
                    o_char++;
                else
                    x_char++;
            }
            else
            {
                ret = address;
            }
            col++;
        }
        if(o_char == a0-1)
        {
            if(x_char == 0)
            {
                std::cout << "winning returning row check ret: " << ret << std::endl;
                return ret; 
            }
        }
        if(x_char == a0-1)
        {
            if(o_char == 0)
            {
                std::cout << "blocking returning row check ret: " << ret << std::endl;
                return ret;
            }
        }
        row++;
    }

    ret = -1;
    o_char = 0;
    x_char = 0;
    col = 0;
    while(col< a0)
    {
        row = 0;
        o_char = 0;
        x_char = 0;
        while(row < a0)
        {
            if(a1[(row*a0) + col] != ' ')
            {
                if(a1[(row*a0) + col] == 'O')
                    o_char++;
                else
                    x_char++;
                
            }
            else
            {
                ret = (row*a0) + col;
            }
            row++;
        }
        if(o_char == a0-1)
        {
            if(x_char == 0)
            {
                std::cout << "winning returning row check ret: " << ret << std::endl;
                return ret; 
            }
        }
        if(x_char == a0-1)
        {
            if(o_char == 0)
            {
                std::cout << "blocking returning row check ret: " << ret << std::endl;
                return ret;
            }
        }
        col++;
    }

    ret = -1;
    o_char = 0;
    x_char = 0;
    int diag = 0;
    while(diag < a0)
    {
        if(a1[(diag*a0)+diag] != ' ')
        {
            if(a1[(diag*a0)+diag] == 'O')
                o_char++;
            else
                x_char++;
        }
        else
        {
            ret = (diag*a0)+diag;
        }
        diag++;
    }
    if(o_char == a0-1)
    {
        if(x_char == 0)
        {
            std::cout << "winning returning row check ret: " << ret << std::endl;
            return ret; 
        }
    }
    if(x_char == a0-1)
    {
        if(o_char == 0)
        {
            std::cout << "blocking returning row check ret: " << ret << std::endl;
            return ret;
        }
    }

    ret = -1;
    o_char = 0;
    x_char = 0;
    diag = 0;
    while( diag< a0)
    {
        if(a1[(diag*a0) + (a0-diag)-1] != ' ')
        {
            if(a1[(diag*a0) + (a0-diag)-1] == 'O')
                o_char++;
            else
                x_char++;
        }
        else
        {   
            ret = (diag*a0) + (a0-diag)-1;
        }
        diag++;
    }
    if(o_char == a0-1)
    {
        if(x_char == 0)
        {
            std::cout << "winning returning row check ret: " << ret << std::endl;
            return ret; 
        }
    }
    if(x_char == a0-1)
    {
        if(o_char == 0)
        {
            std::cout << "blocking returning row check ret: " << ret << std::endl;
            return ret;
        }
    }
    
    ret = -1;
    return ret;
}

void computer_turn(int a0, char a1[])
{
    int address = look_for_pieces(a0, a1);
    if(address != -1)
    {
        a1[address] = 'O';
        return;
    }
    std::cout << "finding random place\n";

    int ret = a1[0];
    int count = 0;
    for(int row = 0; row < a0; ++row)
    {
        for(int col = 0; col < a0; ++col)
        {
            if(a1[(row*a0) + col] == ' ')
            {
                std::cout << "setting " << row << ", " << col << "to 'O'\n";
                a1[(row*a0) + col] = 'O';
                return;
            }
        }
    }
    std::cout << "something is broken\n";
}

int check_game_status(int a0, char a1[])
{
    int o_char = 0;
    int x_char = 0;
    int s_char = 0;
    int row = 0;
    int col = 0;
    while(row < a0)
    {
        o_char = 0;
        x_char = 0;
        col = 0;
        while(col < a0)
        {
            if(a1[(row*a0) + col] != ' ')
            {
                if(a1[(row*a0) + col] == 'O')
                    o_char++;
                else
                    x_char++;
            }
            else
                s_char++;
            col++;
        }
        if(o_char == a0)
        {
            std::cout << "row check\n";
            return 1;
        }
        if(x_char == a0)
        {
            std::cout << "row check\n";
            return 2;
        }
        row++;
    }
    if(s_char == 0)
    {
        std::cout << "row check\n";
        return 3;
    }

    col = 0;
    o_char = 0;
    x_char = 0;
    s_char = 0;
    while(col < a0)
    {
        row = 0;
        o_char = 0;
        x_char = 0;
        while(row < a0)
        {
            if(a1[(row*a0) + col] != ' ')
            {
                if(a1[(row*a0) + col] == 'O')
                    o_char++;
                else
                    x_char++;
            }
            else
                s_char++;
            row++;
        }
        if(o_char == a0)
        {
            std::cout << "col check\n";
            return 1;
        }
        if(x_char == a0)
        {
            std::cout << "col check\n";
            return 2;
        }
        col++;
    }
    if(s_char == 0)
    {
        std::cout << "col check\n";
        return 3;
    }

    row = 0;
    o_char = 0;
    x_char = 0;
    s_char = 0;
    while(row < a0)
    {   
        if(a1[(row*a0) + row] != ' ')
        {
            if(a1[(row*a0) + row] == 'O')
                o_char++;
            else
                x_char++;
        }
        else
            s_char++;
        row++;
    }
    if(o_char == a0)
    {
        std::cout << "diag rl check\n";
        return 1;
    }
    if(x_char == a0)
    {
        std::cout << "diag rl check\n";
        return 2;
    }
    
    row = 0;
    o_char = 0;
    x_char = 0;
    s_char = 0;
    while(row < a0)
    {
        if(a1[(row*a0) + (a0-row)-1] != ' ')
        {
            if(a1[(row*a0) + (a0-row)-1] == 'O')
                o_char++;
            else
                x_char++;
        }
        else
            s_char++;
        row++;
    }
    if(o_char == a0)
    {
        std::cout << "diag lr check\n";
        return 1;
    }
    if(x_char == a0)
    {
        std::cout << "diag lr check\n";
        return 2;
    }
    return 0;
}

int main()
{
    int a0 = 0; 
    std::cout << "Hello lets play a game of tic-tac-toe\nEnter n: ";
    std::cin  >> a0;
    int n = a0*a0;
    std::cout << "n: " << n << std::endl; 
    char a1[n];
    std::cout << "ill go first\n";
    init_dynamic_array(a0, a1);
    print_board(a0, a1);
    int game_state = 0;
    while(true)
    {
        player_turn(a0, a1);
        print_board(a0, a1);
        std::cout << std::endl;
        game_state = check_game_status(a0, a1);
        if( game_state != 0)
            break;
        computer_turn(a0, a1);
        print_board(a0, a1);
        std::cout << std::endl;
        game_state = check_game_status(a0, a1);
        if(game_state != 0)
            break;
    }
    switch (game_state)
    {
        case 0:
            std::cout << "something broke\n";
            break;
        case 1:
            std::cout << "I win better luck next time\n"; 
            break;
        case 2:
            std::cout << "You win well done\n";
            break;
        case 3:
            std::cout << "Its a draw how about another game to see who wins\n";
            break;
    }
    return 0;
}