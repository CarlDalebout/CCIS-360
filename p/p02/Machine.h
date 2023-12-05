#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <map>
#include "Token.h"

// struct off
// {
//     int opcode_;
//     int funct_;
//     int format_;
//     off(int opcode, int funct, int format)
//     {
//         opcode_ = opcode;
//         funct_  = funct;
//         format_ = format;
//     }
// };

class Machine
{
public:
    Machine()
    {}
    
    void     get_instruction(std::string);
    uint8_t  reg_to_index(std::string tok);
    uint32_t get_machine_code(Token &);

private:
    uint32_t opcode_;
    uint32_t rs_;
    uint32_t rt_;
    uint32_t rd_;
    uint32_t shamt_;
    uint32_t funct_;
    // std::map<std::string, off> functions_op = 
    // {
    //     {"sll",     ( 0,  0, 0)}, 
    //     {"j",       ( 2,  0, 2)},
    //     {"srl",     ( 0,  2, 0)},
    //     {"jal",     ( 3,  0, 2)},
    //     {"sra",     ( 0,  3, 0)},
    //     {"beq",     ( 4,  0, 1)},
    //     {"sllv",    ( 0,  4, 0)},
    //     {"bne",     ( 5,  0, 1)},
    //     {"blez",    ( 6,  0, 1)},
    //     {"srlv",    ( 0,  6, 0)},
    //     {"bgtz",    ( 7,  0, 1)},
    //     {"srav",    ( 0,  7, 0)},
    //     {"addi",    ( 8,  0, 1)},
    //     {"jr",      ( 0,  8, 0)},
    //     {"addiu",   ( 9,  0, 1)},
    //     {"jalr",    ( 0,  9, 0)},
    //     {"slti",    (10,  0, 1)},
    //     {"movz",    ( 0, 10, 0)},
    //     {"sltiu",   (11,  0, 1)},
    //     {"movn",    ( 0, 11, 0)},
    //     {"andi",    (12,  0, 1)},
    //     {"syscall", ( 0, 12, 3)},
    //     {"ori",     (13,  0, 1)},
    //     // {"break",   ( 0, 13, 3)},
    //     {"xori",    (14,  0, 1)},
    //     {"lui",     (15,  0, 1)},
    //     // {"sync",    ( 0, 15,  3)},
    //     {"mfhi",    ( 0, 16, 4)},
    //     {"mthi",    ( 0, 17, 4)},
    //     {"mflo",    ( 0, 18, 4)},
    //     {"mtlo",    ( 0, 19, 4)},
    //     {"mult",    ( 0, 24, 4)},
    //     {"multu",   ( 0, 25, 4)},
    //     {"div",     ( 0, 26, 4)},
    //     {"divu",    ( 0, 27, 4)},
    //     {"lb",      (32,  0, 4)},
    //     {"add",     ( 0, 32, 0)},
    //     {"lh",      (33,  0, 4)},
    //     {"addu",    ( 0, 33, 4)},
    //     {"lwl",     (34,  0, 4)},
    //     {"sub",     ( 0, 34, 4)},
    //     {"lw",      (35,  0, 4)},
    //     {"subu",    ( 0, 35, 4)},
    //     {"lbu",     (36,  0, 4)},
    //     {"and",     ( 0, 36, 4)},
    //     {"lhu",     (37,  0, 4)},
    //     {"or",      ( 0, 37, 4)},
    //     {"lwr",     (38,  0, 4)},
    //     {"xor",     ( 0, 38, 4)},
    //     {"nor",     ( 0, 39, 4)},
    //     {"sb",      (40,  0, 4)},
    //     {"sh",      (41,  0, 4)},
    //     {"swl",     (42,  0, 4)},
    //     {"slt",     ( 0, 42, 4)},
    //     {"sw",      (43,  0, 4)},
    //     {"sltu",    ( 0, 43, 4)},
    //     {"swr",     (46,  0, 4)},
    //     {"cache",   (47,  0, 4)},
    //     {"ll",      (48,  0, 4)},
    //     {"tge",     ( 0, 48, 4)},
    //     {"lwc1",    (49,  0, 4)},
    //     {"tgeu",    ( 0, 49, 4)},
    //     {"lwc2",    (50,  0, 4)},
    //     {"tlt",     ( 0, 50, 4)},
    //     {"pref",    (51,  0, 4)},
    //     {"tltu",    ( 0, 51, 4)},
    //     {"teq",     ( 0, 52, 4)},
    //     {"ldc1",    (53,  0, 4)},
    //     {"ldc2",    (54,  0, 4)},
    //     {"tne",     ( 0, 54, 4)},
    //     {"sc",      (56,  0, 4)},
    //     {"swc1",    (57,  0, 4)},
    //     {"swc2",    (58,  0, 4)},
    //     {"sdc1",    (61,  0, 4)},
    //     {"sdc2",    (62,  0, 4)}  
    // };
};

#endif