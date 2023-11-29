#include <iostream>
#include <string>
#include "Register.h"
#include "Token.h"


int main()
{
    Register reg;
    std::string user_input;
    std::string seperators = " ,$";
    getline(std::cin, user_input);
    Token    tok(user_input, seperators);

    std::cout << tok << std::endl;
    std::cout << '|' << tok.pop_front() << '|' << std::endl;
    std::cout << tok << std::endl;

    getline(std::cin, user_input);

    tok.push_back(user_input);

    std::cout << tok << std::endl;


    return 0;
}