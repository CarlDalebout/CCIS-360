#include <iostream>
#include <string>
#include <map>
#include "Register.h"
#include "Machine.h"
#include "Token.h"

void printbits(uint32_t b)
{
    for(int i = 31; i >= 0; --i)
    {
        std::cout << ((b >> i) & 1);
    }
    std::cout << '\n';
}


int main()
{
    Register reg;
    Machine  machine;
    std::string user_input;
    std::string seperators = " \t,$()";
    Token tok("", seperators);
    bool running = true;

    while(running)
    {
        getline(std::cin, user_input);
        tok.push_back(user_input);

        printbits(machine.get_machine_code(tok));
    }
    return 0;
}