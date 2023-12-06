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
    
    uint8_t  & opcode()         { return opcode_; }
    uint8_t    opcode()   const { return opcode_; }

    uint8_t  & rs()             { return rs_; }
    uint8_t    rs()       const { return rs_; }
    
    uint8_t  & rt()             { return rt_; }
    uint8_t    rt()       const { return rt_; }
    
    uint8_t  & rd()             { return rd_; }
    uint8_t    rd()       const { return rd_; }
    
    uint16_t & immedite()       { return immediate_; }
    uint16_t   immedite() const { return immediate_; }
    
    uint8_t  & shamt()          { return shamt_; }
    uint8_t    shamt()    const { return shamt_; }
    
    uint8_t  & funct()          { return funct_; }
    uint8_t    funct()    const { return funct_; }

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