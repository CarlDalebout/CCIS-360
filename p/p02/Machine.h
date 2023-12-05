#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <map>
#include "Token.h"

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

class Machine
{
public:
    Machine()
    {}
    
    void     get(std::string);
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
    int      format_;
    typedef std::map<std::string, off> Functions_Op;
    static Functions_Op functions_op_;
};


#endif