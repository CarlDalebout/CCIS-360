#include <iostream>
#include <string>
#include "Token.h"

bool found (char ch, std::string input)
{
    for(int i = 0; i < input.size(); i++)
    {
        if(ch == input[i])
            return true;
    }
    return false;
}

uint8_t  Token::reg_to_code(int index)
{   
    std::string tok = tokens_[index];
    if(tok.size() > 2)
    {
         std::cout << "reg " << tok << " does not exist return 0\n";
        return 0x00000;
    }

    if(tok[0] == 0)
    {
        return 0x0000;
    }
    else if(tok[0] == 'v')
    {
        std::cout << "checking v's\n";
        if(tok[1] == '0' || tok[1] == '1')
            return 0x0000 + (int)tok[1] - 46;
    }
    else if (tok[0] == 'a')
    {
        std::cout << "checking a's\n";
        if((int)tok[1] - 48 >= 0 && (int)tok[1] - 48 < 4)
            return 0x0000 + (int)tok[1] - 44;
    }
    else if (tok[0] == 't')
    {
       std::cout << "checking t's\n";
        if((int)tok[1] - 48 >= 0 && (int)tok[1] - 48 < 8)
            return 0x0000 + (int)tok[1] - 40;
        else if((int)tok[1] - 48 >= 8 && (int)tok[1] - 48 < 10)
            return 0x0000 + (int)tok[1] - 32;
    }
    else if (tok[0] == 's')
    {
        std::cout << "checking s's\n";
        if((int)tok[1] - 48 >= 0 && (int)tok[1] - 48 < 8)
            return 0x0000 + (int)tok[1] - 32;
    }
    else if(tok == "ra")
    {
        std::cout << "checking ra\n";
        return 31;
    }

    std::cout << "reg " << tok << " does not exist return 0\n";
    return 0x00000;
}

Token::Token(std::string input, std::string separators)
:separators_(separators)
{
    int i = 0;
    std::string token = "";
    while(input[i] != '\0')
    {
        char ch = input[i];
        // std::cout << "ch: " << ch << '\n';
        if(found(ch, separators))
        {   
            if(token != "")
            {
                tokens_.push_back(token);
                // std::cout << "token done ... " << token << '\n';
                token = "";
            }
        }
        else
        {
            token += ch;
            // std::cout << "toke: [" << token << "]\n";
        }
        i++;
    }
    if (token != "")
        tokens_.push_back(token);
    // std::cout << "tok has made " << tokens_.size() << " tokens\n";
}

void Token::add_separators(std::string separators)
{
    for(int i = 0; i < separators.size(); ++i)
    {
        separators_ += separators[i];
    }
}

void Token::push_back(std::string input)
{
    Token temp(input, separators_);
    for(int i = 0; i < temp.size(); ++i)
    {
        tokens_.push_back(temp[i]);
    }
    // std::cout << "tok has " << tokens_.size() << " tokens\n";
}

void Token::clear()
{
    tokens_.clear();
}

std::string Token::pop_front()
{
    std::string ret = tokens_[0];
    tokens_.erase(tokens_.begin(), tokens_.begin()+1);
    return ret;
}

uint32_t Token::get_machine_code()
{
    if(tokens_[0] == "add")
    {

    }
    return 0x000;
}

std::string Token::operator[](int index)
{
    if(index >= tokens_.size())
    {
        std::cout << "!!! ERROR index out of bound !!!, Exiting\n";
        exit(0);
    }
    return tokens_[index];
}

std::ostream & operator<<(std::ostream & cout, Token tokens)
{
    std::string delim = "";
    cout << '{';
    for(int i = 0; i < tokens.size(); i++)
    {
        cout << delim << '"' << tokens[i] << '"'; delim = ", "; 
    }
    cout << '}';
    return cout;
}