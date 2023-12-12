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

Token::Token(std::string input, std::string separators)
:separators_(separators)
{
    int i = 0;
    std::string token = "";
    while(input[i] != '\0')
    {
        char ch = input[i];
        if(ch == '"')
        {   
            i++;
            ch = input[i];
            while(input[i] != '"')
            {
                ch = input[i];
                token += ch;
                i++;
            }
            std::cout << "pushing " << token << " to tokens\n";
            tokens_.push_back(token);
            token = "";
            i++;
        }
        else if(found(ch, separators))
        {   
            if(token != "")
            {
                tokens_.push_back(token);
                token = "";
            }
        }
        else
        {
            token += ch;
        }
        i++;
    }
    if (token != "")
        tokens_.push_back(token);
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
    if(!tokens_.empty())
        tokens_.erase(tokens_.begin());
    return ret;
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