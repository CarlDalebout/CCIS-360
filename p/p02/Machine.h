#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Token.h"

struct off
{
    uint8_t opcode_;
    uint8_t funct_;
    uint8_t format_;
    off(uint8_t opcode, uint8_t funct, uint8_t format)
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
    
    uint8_t  reg_to_index(std::string);
    
    uint32_t get_machine_code(std::vector<std::string> &);

private:
    uint8_t opcode_;
    uint8_t rs_;
    uint8_t rt_;
    uint8_t rd_;
    uint16_t immediate_;
    uint8_t shamt_;
    uint8_t funct_;
    int      format_;
    typedef std::map<std::string, off> Functions_Op;
    static Functions_Op functions_op_;
};


#endif