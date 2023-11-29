#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
#include <vector>

class Token
{
public:
    Token()
    {}
    Token(std::string input, std::string separators);

    int size() {return tokens_.size();}

    void add_separators(std::string);
    void push_back(std::string);

    std::string pop_front();

    std::string operator[](int);

private:
    std::vector<std::string> tokens_;
    std::string separators_;
};

std::ostream & operator<<(std::ostream &, Token);

#endif