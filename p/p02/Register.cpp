#include <iostream>
#include "Register.h"

uint8_t & Register::operator[](int index)
{
    if(index >= 32)
    {
        std::cout << "!!! ERROR index out of bound, exiting!!!\n";
        exit(0);
    }
    return registers_[index];
}

void Register::update(Machine & machine)
{
    if(machine.opcode() == 0)
    {

    }
}

void Register::print()
{
    
}