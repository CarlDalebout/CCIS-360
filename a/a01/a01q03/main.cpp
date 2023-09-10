#include <iostream>

int main()
{
    int x = 0;
    std::cin >> x;
    // for(int i = 0; i < x; ++i)
    // {
    //   std::cout << i << std::endl;
    // }
    int i = 0;
    if(i >= x)
        goto end;

loop:    
        std::cout << i << std::endl;
        i++;
        if(i < x)
            goto loop;

end:
    return 0;
}