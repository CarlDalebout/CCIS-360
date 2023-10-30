#include <iostream>

void hanoi(int n, char from, char helper, char to)
{
    if (n == 1)
    {
        std::cout << from << "->" << to << std::endl;
    }
    else
    {
        hanoi(n - 1, from, to, helper);
        hanoi(1, from, helper, to);
        hanoi(n - 1, helper, from, to);
    }
}

int j(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (j(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int n = 0;
    int k = 0;
    std::cin >> n;
    std::cin >> k;
    std::cout << j(n, k) << std::endl;
    return 0;
}
