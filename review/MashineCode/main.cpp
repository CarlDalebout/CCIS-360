#include <iostream>
#include <string>
#include <vector>

void printbits(uint32_t b)
{
    for(int i = 31; i >= 0; --i)
    {
        std::cout << ((b >> i) & 1);
    }
    std::cout << '\n';
}

std::ostream & operator<<(std::ostream & cout, std::vector<std::string> tokens)
{
    std::string delim = "";
    cout << '{';
    for(auto & token: tokens)
    {
        cout << delim << '"' <<token << '"'; delim = ", "; 
    }

    return cout;
}

uint8_t reg_to_code(std::string tok)
{
    if(tok == "$t0")
    {
        return 0x0000;
    }
    return 0x000;
}

bool found (char ch, std::string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(ch == s[i])
            return true;
    }
    return false;
}

int main()
{
    std::string s = "   add   $t0,    $t1     ,   $t2     ";
    // addi     $s0, $a0, -54
    // sllv     $a0, $a0, 5
    // lw       $s0, 4($t0)
    std::vector<std::string> tokens;
    int i = 0;
    std::string separators = " \t,";
    std::string token = "";
    while(s[i] != '\0')
    {
        char ch = s[i++];
        std::cout << "ch: " << ch << '\n';
        if(found(ch, separators))
        {   
            if(token != "")
            {
                tokens.push_back(token);
                std::cout << "token done ... " << token << '\n';
                token = "";
            }
        }
        else
        {
            token += ch;
            std::cout << "toke: [" << token << "]\n";
        }
        i++;
    }
    std::cout << "tokens: " << tokens << '\n';

    uint32_t opcode;
    uint32_t rs;
    uint32_t rt;
    uint32_t rd;
    uint32_t shamt;
    uint32_t funct;

    if(tokens[0] == "add")
    {
        opcode = 0;
        shamt = 0;
        funct = 32;
        // rs = reg_to_code(tokens[2]);
        // rt = reg_to_code(tokens[3]);
        // rd = reg_to_code(tokens[1]);
    }
    uint32_t mcode = opcode << 26
        | rs << 21
        | rt << 16
        | rd << 11
        | shamt << 6
        | funct;
    std::cout << "mcode: " << mcode << '\n';
    printbits(mcode);
    return 0;
}