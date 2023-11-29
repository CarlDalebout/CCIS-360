#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <vector>

class Register
{
public:
    Register()
    {
        for(int i = 0; i < 32; ++i)
        {
            registers_[i] = 0;
        }
    }

    uint32_t & operator[](int index);


private:
    uint32_t registers_[32];
};

#endif