#include <iostream>
#include <vector>

void print_bits(uint32_t s)
{
    for(int i = 31; i >= 0; --i)
    {
        std::cout << (((s) >> i) & 1);
    }
    std::cout << std::endl;
}

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

uint32_t myaddu(uint32_t x, uint32_t y)
{
    uint32_t temp_x = x;
    uint32_t temp_y = y;
    uint32_t ret = 1;
    uint8_t  c = 0;
    uint32_t i = 31;
    while(temp_x != 0)
    {
        uint8_t x_bit = (((temp_x) >> i) & 1);
        uint8_t y_bit = (((temp_y) >> i) & 1);
        
        uint8_t s = (x_bit xor y_bit) xor c;
                c = (((x_bit xor y_bit) and c) or (x_bit and y_bit));
        
        // 0000 0010
        // 0000 0001
        //----------
        // 0000 0011
        // ret << 1
        // 0000 0110
        ret = (ret << 1);
        ret |= s;

        std::cout << "x_bit: " << (x_bit & 1) << std::endl;;
        std::cout << "y_bit: " << (y_bit & 1) << std::endl;;
        std::cout << "c: " << (c & 1) << std::endl;
        std::cout << "temp_x: "; print_bits(temp_x);
        std::cout << "temp_y: "; print_bits(temp_y);
        std::cout << "s: " << (s & 1) << std::endl;
        std::cout << "ret: "; print_bits(ret);
        std::cout << std::endl;
       
        temp_x = temp_x >> 1;
        temp_y = temp_y >> 1;

    }
    return ret;
}

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
    }

    uint32_t x = 15;
    uint32_t y = 2;
    std::cout << "x: "; print_bits(x);
    std::cout << "y: "; print_bits(y);
    std::cout << std::endl;
    uint32_t z = myaddu(x, y);
    print_bits(z);

    std::cout << std::endl;
    return 0;
}


