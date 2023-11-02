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

void print_int_array(int *start, int *end )
{
    if(start == end)
    {
        std::cout << "\n";
        return;
    }
    else
    {
        std::cout << *start << " ";
        print_int_array(start+1, end);
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
    int n[] = {200, 3, 4, 11, 15, 20, 100, 101};
    print_int_array(&n[0], &n[8]);
    return 0;
}
