#include <iostream>


int main()
{
    // input is an array of 2s and 3s of length n
    int state = 1;
    int n = 0;
    std::cin >> n;
    int input[n];

    for(int i = 0; i < n; ++i)
    {
        std::cin >> input[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int val = input[i];
        switch (state)
        {
            case 0:
            {
                switch (val)
                {
                    case 2: state = 0; break;
                    case 3: state = 1; break; // this assignment is redundant
                }
            }
            case 1:
            {
                switch (val)
                {
                    case 2: state = 0; break; // this assignment is redundant
                    case 3: state = 1; break;
                }
            }
        }
    }
    std::cout << state << std::endl;
}