#include <iostream>
#include <vector>
std::vector<int> bits(int n, int base)
{
    std::vector<int> ret
    while(n != 0)
    {
        ret.push_back(n % base);
        n /= base;
    }
    // reverse the vector
    return ret;
}
int main()
{

    return 0;
}