#include <iostream>
#include <string>
#include <map>
#include "Register.h"
#include "Machine.h"
#include "Token.h"

void printbits(uint32_t b)
{
    for(int i = 31; i >= 0; --i)
    {
        std::cout << ((b >> i) & 1);
    }
    std::cout << '\n';
}

struct off
{
    int opcode_;
    int funct_;
    int format_;
    off(int opcode, int funct, int format)
    {
        opcode_ = opcode;
        funct_  = funct;
        format_ = format;
    }
};

std::map<std::string, off> functions_op = 
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
    {"lw",      off(35,  0, 1)},
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
    {"sw",      off(43,  0, 1)},
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


int main()
{
    Register reg;
    Machine  machine;
    std::string user_input;
    std::string seperators = " \t,$()";
    Token tok("", seperators);
    bool running = true;

    while(running)
    {
        getline(std::cin, user_input);
        tok.push_back(user_input);

        std::map<std::string, off>::iterator it;
        it = functions_op.find(tok[0]);

        if(it != functions_op.end())
        {
            // std::cout << "the key of " << it->first << " has a opcode of " << it->second.opcode_ << " has a funct of " << it->second.funct_ << " and a formate of " << it->second.format_ << std::endl;  
        
        }
    }
    return 0;
}