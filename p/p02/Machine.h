#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Token.h"
#include "Memory.h"

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
    :print_mcode_(false)
    {}

/*==========================================================================================
Functions
==========================================================================================*/
    void       print_bits(uint32_t, int);
    
    uint8_t    reg_to_index(std::string);
    uint32_t   get_machine_code(std::vector<std::string> &, Memory & memory);
    

/*==========================================================================================
Sets and Gets
==========================================================================================*/
    uint8_t  & opcode()         { return opcode_; }
    uint8_t    opcode()   const { return opcode_; }

    uint8_t  & rs()             { return rs_; }
    uint8_t    rs()       const { return rs_; }
    
    uint8_t  & rt()             { return rt_; }
    uint8_t    rt()       const { return rt_; }
    
    uint8_t  & rd()             { return rd_; }
    uint8_t    rd()       const { return rd_; }
    
    uint32_t & immedite()       { return immediate_; }
    uint32_t   immedite() const { return immediate_; }
    
    uint8_t  & shamt()          { return shamt_; }
    uint8_t    shamt()    const { return shamt_; }
    
    uint8_t  & funct()          { return funct_; }
    uint8_t    funct()    const { return funct_; }

    int      & format()       {return format_;} 
    int        format() const {return format_;} 

    uint32_t & mcode()      { return mcode_; }
    uint32_t   mcode() const { return mcode_; }

    bool     & print_mcode()          { return print_mcode_;}
    bool       print_mcode()    const { return print_mcode_;}   

private:
    uint8_t  opcode_;
    uint8_t  rs_;
    uint8_t  rt_;
    uint8_t  rd_;
    uint32_t immediate_;
    uint8_t  shamt_;
    uint8_t  funct_;
    int      format_;
    uint32_t mcode_;
    bool     print_mcode_;
    typedef  std::map<std::string, off> Functions_Op;
    static   Functions_Op functions_op_;
};


#endif