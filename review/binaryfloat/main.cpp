#include <iostream>

int main()
{
    float x = 3.14;
    std::cout << x << '\n';

    unsigned int y = 135;
    std::cout << (y & 1) << '\n';
    std::cout << ((y >> 1) & 1) << '\n';

    int * p = (int *)(&x);
    std::cout << x << " = ";
    for(int i = 31; i >=0; --i)
    {
        std::cout << (((*p) >> i) & 1) << ' ';
    }
    std::cout << '\n';
    x = -0.625;
    std::cout << x << " = ";
    for(int i = 31; i >=0; --i)
    {
        std::cout << (((*p) >> i) & 1) << ' ';
    }
    std::cout << '\n';
    
    x = 0;
    std::cout << "x: " << x << '\n';
    *p = (1 << 31) | (0b01111110 << 23) | (1 << 21);
    std::cout << "x: " << x << '\n';

    return 0;
}