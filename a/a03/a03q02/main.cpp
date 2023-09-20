#include <iostream>
#include <vector>
#include <string>

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
        std::cout << "number of tokens " << tokens.size() << std::endl;

        for(std::string i : tokens)
        {
            std::cout << '\t' << i << std::endl;
        }

        int switch_case = 0
        if()

        switch ()
        {
            case "li":
            {
                int sum = 0;
                for(unsigned int i = 0; i < tokens[2].size(); ++i)
                {
                    sum += int(tokens[2][i])-48;
                }
                s[int(tokens[1][2])-48] = sum;
                break;
            }

            case "add":
            {

                break;
            }

            case "sub":
            {

                break;
            }
        }

        std::cout << "$s0: " << s[0] << std::endl;
        std::cout << "$s1: " << s[1] << std::endl;
        std::cout << "$s2: " << s[2] << std::endl;

        tokens.clear();
    }
 
    std::cout << "END" << std::endl;
 
    return 0;
}