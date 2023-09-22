#include <iostream>
#include <vector>
#include <string>
#include <cmath>

const int MAX_BUF = 1024;

std::vector<std::string>tokens;

void tokeniz(std::string input)
{
    int i = 0;
    std::string tok = "";
    while(input[i] != '\0')
    {
        if(input[i] != ' ' && input[i] != ',' && input[i] != '\t')
        {
            tok.push_back(input[i]);
        }
        else
        {
            while(input[i] == ' ' || input[i] == ',' || input[i] == '\t')
                i++;
            tokens.push_back(tok);
            tok.clear();
            continue;
        }
        i++;
    }
    if(tok.size() > 0)
        tokens.push_back(tok);
}

int getsum(std::string input)
{
    int sum = 0; 
    for(int i = 0; i < input.size(); ++i)
    {
        std::cout << "Sum = " << sum << " + " << (input[i]-48) * pow(10, input.size() - i - 1) << std::endl;
        sum += (input[i]-48) * pow(10, input.size() - i - 1);
    }
    return sum;
}

int main()
{
    int s[] = {0, 0, 0};
    std::string input;
 
    while (1)
    {
        std::cout << ">>> ";
        
        std::getline(std::cin, input);
        
        if(input == "")
            break;
        
        // perform computation here
        tokeniz(input);
        // std::cout << "number of tokens " << tokens.size() << std::endl;

        // for(std::string i : tokens)
        // {
        //     std::cout << "\t|" << i << '|' << std::endl;
        // }

        if(tokens[0] =="li")
        {
            s[int(tokens[1][2])-48] = getsum(tokens[2]);
        }
        else if(tokens[0] == "add")
        {
            s[int(tokens[1][2])-48] = s[int(tokens[2][2])-48];
            s[int(tokens[1][2])-48] += s[int(tokens[3][2])-48];
        }
        else if(tokens[0] == "sub")
        {
            s[int(tokens[1][2])-48] = s[int(tokens[2][2])-48];
            s[int(tokens[1][2])-48] -= s[int(tokens[3][2])-48];
        }
    

        std::cout << "$s0: " << s[0] << std::endl;
        std::cout << "$s1: " << s[1] << std::endl;
        std::cout << "$s2: " << s[2] << std::endl;

        tokens.clear();
    }
 
    std::cout << "END" << std::endl;
 
    return 0;
}