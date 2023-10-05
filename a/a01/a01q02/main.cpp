#include <iostream>
int main()
{
    int x = 0;
    std::cin >> x;

    int y = 0;
    // if (x < 0)
    // {
    //     std::cout << "foo" << std::endl;
    //     y = 1;
    // }
    // else
    // {
    //     std::cout << "bar" << std::endl;
    //     y = 2;
    // }
    if(x >= 0)
        goto Else;
    
    std::cout << "foo" << std::endl;
    y = 1;
    goto End;

Else: 
    std::cout << "Bar" << std::endl;
    y = 2;
    goto End;

End:
    std::cout << y << std::endl;
    return 0;
}