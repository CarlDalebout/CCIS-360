#include <iostream>
#include <vector>
#include "Machine.h"
#include "Token.h"

void Machine::get_instruction(std::string instruction)
{
   switch (int(instruction[0]))
   {
        case int('a'):
                if(instruction == "add")
                    funct_  = 32;
                    opcode_ = 0;
            break;
    
        default:
            break;
   }
}

uint32_t Machine::get_machine_code(Token & tok)
{
    uint32_t mcode;
    // get_format();
    // if(tok[0] == "add")
    // {
    //     funct_ = 32;
    //     opcode_ = 0;
    //     shamt_ = 0;
    //     rd_ = reg_to_index(tok[1]);
    //     rs_ = reg_to_index(tok[2]);
    //     rt_ = reg_to_index(tok[3]);

    // }
    // if(tok[0] == "li")
    // {

    // }
    // else
    // {
    //     funct_  = 0;
    //     opcode_ = 0;
    //     shamt_  = 0;
    //     rs_     = 0;
    //     rt_     = 0;
    //     rd_     = 0;
    // }
    
    mcode = opcode_ << 26
            | rs_ << 21
            | rt_ << 16
            | rd_ << 11
            | shamt_ << 6
            | funct_;

    for (int i = 31; i >= 0; --i)
    {
        std::cout << ((mcode >> i) & 1);
    }
    return mcode;
}

uint8_t  Machine::reg_to_index(std::string tok)
{   
    if(tok == "zero")
    {
        return 0x0000;
    }
    if(tok.size() > 2)
    {
         std::cout << "reg " << tok << " does not exist return 0\n";
        return 0x00000;
    }
    if(tok[0] == 0)
    {
        return 0x0000;
    }
    else if(tok[0] == 'v')
    {
        // std::cout << "checking v's\n";
        if(tok[1] == '0' || tok[1] == '1')
            return 0x0000 + (int)tok[1] - 46;
    }
    else if (tok[0] == 'a')
    {
        // std::cout << "checking a's\n";
        if((int)tok[1] - 48 >= 0 && (int)tok[1] - 48 < 4)
            return 0x0000 + (int)tok[1] - 44;
    }
    else if (tok[0] == 't')
    {
    //    std::cout << "checking t's\n";
        if((int)tok[1] - 48 >= 0 && (int)tok[1] - 48 < 8)
            return 0x0000 + (int)tok[1] - 40;
        else if((int)tok[1] - 48 >= 8 && (int)tok[1] - 48 < 10)
            return 0x0000 + (int)tok[1] - 32;
    }
    else if (tok[0] == 's')
    {
        // std::cout << "checking s's\n";
        if((int)tok[1] - 48 >= 0 && (int)tok[1] - 48 < 8)
            return 0x0000 + (int)tok[1] - 32;
    }
    else if(tok == "ra")
    {
        // std::cout << "checking ra\n";
        return 31;
    }

    std::cout << "reg " << tok << " does not exist return 0\n";
    return 0x00000;
}


