#include <iostream>
#include "Register.h"

uint32_t & Register::operator[](int index)
{
    if(index >= 32)
    {
        std::cout << "!!! ERROR index out of bound, exiting!!!\n";
        exit(0);
    }
    return registers_[index];
}

void Register::update(u_int32_t mcode)
{

}

void Register::print()
{
    
}