#include <iostream>
#include <string>
#include "Register.h"
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
    std::string user_input;
    std::string seperators = " \t,$";
    Token tok("", seperators);
    bool running = true;

    uint32_t opcode;
    uint32_t rs;
    uint32_t rt;
    uint32_t rd;
    uint32_t shamt;
    uint32_t funct;

    getline(std::cin, user_input);
    tok.push_back(user_input);

    std::cout << tok << std::endl;

    opcode = 0;
    shamt = 0;
    funct = 32;
    rs = tok.reg_to_code(1);
    rt = tok.reg_to_code(2);
    rd = tok.reg_to_code(0);
    
    uint32_t mcode = opcode << 26
                    | rs << 21
                    | rt << 16
                    | rd << 11
                    | shamt << 6
                    | funct;

    std::cout << "add " << tok[0] << ' ' << tok[1] << ' ' << tok[2] << std::endl;
    std::cout << "mcode: " << mcode << std::endl;
    printbits(mcode);

    return 0;
}