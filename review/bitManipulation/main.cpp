#include <iostream>
#include <vector>

std::vector<int> bits(uint32_t x, int base = 2)
{
    std::vector<int> ret(32, 0);
    for(int i = 0; i < 32; ++i)
    {
        ret[i] = x % base;
        x /= base;
    }
    return ret;
}

std::vector<int> better_bits(uint32_t x)
{
    std::vector<int> ret(32, 0);
    for(int i = 0; i < 32; ++i)
    {
        ret[i] = x & 1;
        x >>= 1;
    }
    return ret;
}


//  i           c
// [0000000000][0000]
// union X
// {
//     ;
//     char c;
// };

union intfloat
{
    float f;
    unsigned int i;
};


void turn_on(uint32_t * r, int index)
{
    (*r) |= (1 << index);
}

void turn_off(uint32_t * r, int index)
{
    (*r) &= ~(1 << index);
}

void toggle(uint32_t * r, int index)
{
    (*r) ^= (1 << index);
}

void printbits(std::vector<int> & s)
{
    for(int i = 32; i > 0; --i)
    {
        std::cout << s[i] << ' ';
    }
    std::cout << '\n';
}

struct Two
{
    int a:16;
    int b:16;
};

int main()
{
    // std::cout << sizeof(int) << '\n';
    // uint32_t x = 42;
    // std::cout << x << '\n';
    
    // std::vector<int> b = bits(x);
    // for(int i = 31; i > 0; --i)
    // {
    //     std::cout << b[i] << ' ';
    // }
    // std::cout << '\n';

    // std::vector<int> c = bits(x, 4);
    // for(int i = 31; i > 0; --i)
    // {
    //     std::cout << c[i] << ' ';
    // }
    // std::cout << '\n';

    // uint32_t r0 = 1;
    // std::cout << r0 << '\n';
    // r0 = (r0 << 1);
    // std::cout << r0 << '\n';
    // r0 = (r0 << 1);
    // std::cout << r0 << '\n';
    
    // std::cout << 17 << '\n';
    // std::cout << 2 * 17 << '\n';
    // std::cout << (17 << 1) << '\n';

    // uint32_t r1 = (7 >> 1);
    // std::cout << r1 << '\n';

    // uint32_t r2 = 0xc; //0b1100;//(1 << 3) | (1 << 2); //12
    // uint32_t r3 =  1; //01
    // uint32_t r4 = r2 | r3;
    // std::cout << r4 << '\n';


    // std::cout << (10 & 3) << '\n';
    // std::cout << (15 ^ 3) << '\n';

    // uint32_t r5 = 42;
    // std::cout << "\n testing \n";
    // std::vector<int> s = better_bits(r5);
    // printbits(s);
    // s = bits(r5);
    // printbits(s);
    // std::cout << "testing turn_on\n";
    // turn_on(&r5, 4);
    // s = better_bits(r5);
    // printbits(s);
    // std::cout << "testing turn_off\n";
    // turn_off(&r5, 3);
    // s = better_bits(r5);
    // printbits(s);

    // std::cout << "testing toggle\n";
    // toggle(&r5, 3);
    // s = better_bits(r5);
    // printbits(s);
    // toggle(&r5, 3);
    // s = better_bits(r5);
    // printbits(s);
    // X x;
    // x.c = 'a';
    // std::cout << x.c << ' ' << x.i << "\n";
    
    // intfloat x;
    // x.f = 3.14;
    // std::cout << x.i << '\n';
    // // std::cout << ((f >> 1) & 1) << '\n';

    float f = 3.14;
    unsigned int * p = (unsigned int *)(&f); // RHS type = float *    
    for(int i = 31; i >= 0; --i)
    {
        std::cout << (((*p) >> i) & 1) << " ";
    }
    std::cout << '\n';

    double d = 3.14;
    p = (unsigned int *)(&d);
    for(int i = 63; i >= 0; --i)
    {
        std::cout << (((*p) >> i) & 1) << " ";
    }
    std::cout << std::endl;
    return 0;
}