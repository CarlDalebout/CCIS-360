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
    std::vector<std::string> & tokens()       { return tokens_; }
    std::vector<std::string>   tokens() const { return tokens_; }

    void add_separators(std::string);
    void push_back(std::string);
    void clear();

    std::string pop_front();
    std::string operator[](int);
    
private:
    std::vector<std::string> tokens_;
    std::string separators_;
};

std::ostream & operator<<(std::ostream &, Token);

#endif