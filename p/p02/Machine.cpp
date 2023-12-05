#include "Machine.h"
#include <cmath>

void printbits(uint32_t b, int format)
{
    switch (format)
    {
        case 0:
        {
            for(int i = 31; i >= 26; --i)
            {
                std::cout << ((b >> i) & 1);
            }
            for(int i = 25; i >=6; --i)
            {
                if(i % 5 == 0)
                    std::cout << ' ';
                std::cout << ((b >> i) & 1);
            }
            std::cout << ' ';
            for(int i = 5; i >= 0;  --i)
            {
                std::cout << ((b >> i) & 1);
            }
            std::cout << std::endl;
        }   break;
        case 1:
        {
            for(int i = 31; i >= 26; --i)
            {
                std::cout << ((b >> i) & 1);
            }
            for(int i = 25; i >=16; --i)
            {
                if(i % 5 == 0)
                    std::cout << ' ';
                std::cout << ((b >> i) & 1);
            }
            std::cout << ' ';
            for(int i = 15; i >= 0;  --i)
            {
                std::cout << ((b >> i) & 1);
            }
            std::cout << std::endl;
        }   break;
        default:
        {
            for(int i = format-1; i >= 0; --i)
            {
                std::cout << ((b >> i) & 1);
            }
        }break;
    }
}



Machine::Functions_Op Machine::functions_op_ = 
{
    {"sll",     off( 0,  0, 0)}, 
    {"j",       off( 2,  0, 2)},
    {"srl",     off( 0,  2, 0)},
    {"jal",     off( 3,  0, 2)},
    {"sra",     off( 0,  3, 0)},
    {"beq",     off( 4,  0, 1)},
    {"sllv",    off( 0,  4, 0)},
    {"bne",     off( 5,  0, 1)},
    {"blez",    off( 6,  0, 1)},
    {"srlv",    off( 0,  6, 0)},
    {"bgtz",    off( 7,  0, 1)},
    {"srav",    off( 0,  7, 0)},
    {"addi",    off( 8,  0, 1)},
    {"jr",      off( 0,  8, 0)},
    {"addiu",   off( 9,  0, 1)},
    {"jalr",    off( 0,  9, 0)},
    {"slti",    off(10,  0, 1)},
    {"movz",    off( 0, 10, 0)},
    {"sltiu",   off(11,  0, 1)},
    {"movn",    off( 0, 11, 0)},
    {"andi",    off(12,  0, 1)},
    {"syscall", off( 0, 12, 3)},
    {"ori",     off(13,  0, 1)},
    // {"break",off   ( 0, 13, 3)},
    {"xori",    off(14,  0, 1)},
    {"lui",     off(15,  0, 1)},
    // {"sync", off   ( 0, 15,  3)},
    {"mfhi",    off( 0, 16, 0)},
    {"mflo",    off( 0, 18, 0)},
    {"mult",    off( 0, 24, 3)},
    {"multu",   off( 0, 25, 3)}, //special
    {"div",     off( 0, 26, 3)}, //special
    {"divu",    off( 0, 27, 3)}, //special
    {"lb",      off(32,  0, 1)},
    {"add",     off( 0, 32, 0)},
    {"move",    off( 0, 32, 0)}, //special
    {"lh",      off(33,  0, 1)},
    {"addu",    off( 0, 33, 1)},
    {"lwl",     off(34,  0, 1)},
    {"sub",     off( 0, 34, 0)},
    {"lw",      off(35,  0, 1)}, //special
    {"subu",    off( 0, 35, 0)},
    {"lbu",     off(36,  0, 1)},
    {"and",     off( 0, 36, 0)},
    {"lhu",     off(37,  0, 1)},
    {"or",      off( 0, 37, 0)},
    {"lwr",     off(38,  0, 1)},
    {"xor",     off( 0, 38, 0)},
    {"nor",     off( 0, 39, 0)},
    {"sb",      off(40,  0, 1)},
    {"sh",      off(41,  0, 1)},
    {"swl",     off(42,  0, 1)},
    {"slt",     off( 0, 42, 0)}, //special
    {"sw",      off(43,  0, 1)}, //special
    {"sltu",    off( 0, 43, 0)},
    {"swr",     off(46,  0, 1)},
    // {"cache",   off(47,  0, 4)},
    {"ll",      off(48,  0, 1)},
    {"tge",     off( 0, 48, 0)},
    {"lwc1",    off(49,  0, 1)},
    {"tgeu",    off( 0, 49, 0)},
    {"lwc2",    off(50,  0, 1)},
    {"tlt",     off( 0, 50, 3)}, //special
    {"pref",    off(51,  0, 1)}, 
    {"tltu",    off( 0, 51, 3)}, //special
    {"teq",     off( 0, 52, 3)}, //special
    {"ldc1",    off(53,  0, 1)},
    {"ldc2",    off(54,  0, 1)},
    {"tne",     off( 0, 54, 3)}, //special
    {"sc",      off(56,  0, 1)}, 
    {"swc1",    off(57,  0, 1)},
    {"swc2",    off(58,  0, 1)},
    {"sdc1",    off(61,  0, 1)},
    {"sdc2",    off(62,  0, 1)}  
};

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
    if(tok[0] == '0')
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

uint32_t Machine::get_machine_code(std::vector<std::string> & tokens)
{
    std::map<std::string, off>::iterator it;
    it = functions_op_.find(tokens[0]);

    uint32_t mcode;
    if(it != functions_op_.end())
    {
        opcode_ = it->second.opcode_;
        funct_  = it->second.funct_;
        format_ = it->second.format_;
        
        // std::cout << "format_: " << (int)format_ << " bits: ";
        // printbits(format_, 5);
        // std::cout << std::endl;
        
        switch ((int)format_)
        {
            case 0:
            {
                std::cout << "opcode_: " << (int)opcode_ << " bits: ";
                printbits(opcode_, 8);

                rd_ = reg_to_index(tokens[1]);
                std::cout << ", rd_: $" << (int)rd_ << " bits: ";
                printbits(rd_, 8);
                
                rs_ = reg_to_index(tokens[2]);
                std::cout << ", rs_: $" << (int)rs_ << " bits: ";
                printbits(rs_, 8);
                
                rt_ = reg_to_index(tokens[3]);
                std::cout << ", rt_: $" << (int)rt_ << " bits: ";
                printbits(rt_, 8);
                
                std::cout << ", shamt_: " << (int)shamt_ << " bits: ";
                printbits(shamt_, 8);

                std::cout << ", funct_: " << (int)funct_ << " bits: ";
                printbits(funct_, 8);

                std::cout << std::endl;
                
                mcode = opcode_ << 26
                | rs_ << 21
                | rt_ << 16
                | rd_ << 11 
                | shamt_ << 6
                | funct_;
            } break;
            case 1:
            {
                std::cout << "opcode_: " << (int)opcode_ << " bits: ";
                printbits(opcode_, 8);

                rs_ = reg_to_index(tokens[2]);
                std::cout << ", rs_: " << (int)rs_ << " bits: ";
                printbits(rs_, 8);
                
                rt_ = reg_to_index(tokens[1]);
                std::cout << ", rt_: $" << (int)rt_ << " bits: ";
                printbits(rt_, 8);

                immediate_ = stoi(tokens[3]);
                std::cout << ", immediate" << (int)immediate_ << " bits: ";
                printbits(immediate_, 16);

                std::cout << std::endl;
                mcode = opcode_ << 26
                | rs_ << 21
                | rt_ << 16
                | immediate_;
            }break;
        }
        printbits(mcode, format_);
    }
    else
    {
        std::cout << "error " << tokens[0]<< " does not exist" << std::endl;
    }
      
    // for (int i = 31; i >= 0; --i)
    // {
    //     std::cout << ((mcode >> i) & 1);
    // }
    return mcode;
}