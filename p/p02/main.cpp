#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include "Machine.h"
#include "Memory.h"
#include "Register.h"
#include "Token.h"

Register reg;
Machine  machine;
Memory   memory;
int mode = 0; // text_mode = 1, data_mode = 1, lables_mode = 2
bool reg_print = 0;

void printbits(uint32_t b)
{
    for(int i = 31; i >= 0; --i)
    {
        std::cout << ((b >> i) & 1);
    }
    std::cout << '\n';
}

std::string to_hex(int value)
{
    if(value == 0)
    {
        return "0";
    }
    std::stack<char> stack_temp;
    int remainder = -9999;
    while(value != 0)
    {
        remainder = value % 16;
        // std::cout << "remainder: " << remainder << '\n';
        value -= remainder;
        // std::cout << "value: " << value << '\n';
        switch (remainder)
        {
            case 0: 
                // std::cout << "pushing 0 to the stack\n";
                stack_temp.push('0');
                break;
            case 1:
                // std::cout << "pushing 1 to the stack\n";
                stack_temp.push('1');
                break;
            case 2:
                // std::cout << "pushing 2 to the stack\n";
                stack_temp.push('2');
                break;
            case 3:
                // std::cout << "pushing 3 to the stack\n";
                stack_temp.push('3');
                break;
            case 4:
                // std::cout << "pushing 4 to the stack\n";
                stack_temp.push('4');
                break;
            case 5:
                // std::cout << "pushing 5 to the stack\n";
                stack_temp.push('5');
                break;
            case 6:
                // std::cout << "pushing 6 to the stack\n";
                stack_temp.push('6');
                break;
            case 7:
                // std::cout << "pushing 7 to the stack\n";
                stack_temp.push('7');
                break;
            case 8:
                // std::cout << "pushing 8 to the stack\n";
                stack_temp.push('8');
                break;
            case 9:
                // std::cout << "pushing 9 to the stack\n";
                stack_temp.push('9');
                break;
            case 10:
                // std::cout << "pushing A to the stack\n";
                stack_temp.push('A');
                break;
            case 11:
                // std::cout << "pushing B to the stack\n";
                stack_temp.push('B');
                break;
            case 12:
                // std::cout << "pushing C to the stack\n";
                stack_temp.push('C');
                break;
            case 13:
                // std::cout << "pushing D to the stack\n";
                stack_temp.push('D');
                break;
            case 14:
                // std::cout << "pushing E to the stack\n";
                stack_temp.push('E');
                break;
            case 15:
                // std::cout << "pushing F to the stack\n";
                stack_temp.push('F');
                break;
            default:
                break;
        }
        value = value / 16;
        // std::cout << "value/16: " << value << '\n';
    }
    std::string ret;
    
    while(!(stack_temp.empty()))
    {
        // std::cout << "pushing " << stack_temp.top() << "to ret: " << ret << std::endl;
        ret += stack_temp.top();
        stack_temp.pop();
    }
    return ret;
}

bool check_at_functions(std::vector<std::string> tokens)
{
    if(tokens[0][0] == '@')
    {
        if(tokens[0] == "@print")
        {
            if(tokens[1] == "reg")
            {
                if(tokens.size() > 2)
                {
                    if (tokens[2] == "const" && tokens[3] == "true")
                        reg_print = true;
                    else if(tokens[2] == "const" && tokens[3] == "false")
                        reg_print = false;
                    else
                    {
                        std::cout << "invalid command { ";
                        std::string dir = ""; 
                        for(long unsigned int i = 0; i < tokens.size(); ++i) 
                        {
                            std::cout << dir << tokens[i]; dir = " ";
                        }
                        std::cout << "}\n"; 
                    }
                }
                else
                {
                    reg.print();
                }
            }
            else if(tokens[1] == "data")
            {
                memory.print_data();
            }
            else if(tokens[1] == "stack")
            {
                memory.print_stack();
            }
            else if(tokens[1] == "labels" || tokens[1] == "label")
            {
                memory.print_label();
            }
            else if(tokens[1] == "mcode")
            {
                if(tokens[2] == "true")
                {
                    std::cout << "\nprinting machine code\n\n";
                    machine.mcode() = true;
                    // std::cout << machine.mcode() << std::endl;
                }
                else if(tokens[2] == "false")
                {
                    std::cout << "\nnot printing machine code\n\n";
                    machine.mcode() = false;
                    // std::cout << machine.mcode() << std::endl;
                }
                else
                {
                    std::cout << "Error at code {";
                    std::string dir = ""; 
                    for(long unsigned int i = 0; i < tokens.size(); ++i)
                    {
                        std::cout << dir << tokens[i]; dir = " ";
                    }
                    std::cout << "} does not exist\n";
                }
            }
        }
        else if( tokens[0] == "@text")
        {
            std::cout << std::endl;
            mode = 0;
        }
        else if( tokens[0] == "@data")
        {
            std::cout << std::endl;
            std::cout << "=====================================================================\n"
            << "DATA SEGMENT\n"
            << "=====================================================================\n";
            mode = 1;
        }   
        else if( tokens[0] == "@labels")
        {   
            std::cout << "\n=====================================================================\n"
            << "Lables SEGMENT\n"
            << "=====================================================================\n";
            std::cout << std::endl;
            mode = 2;
        }
        else
        {
            std::cout << "Error at code {";
            std::string dir = ""; 
            for(long unsigned int i = 0; i < tokens.size(); ++i)
            {
                std::cout << dir << tokens[i]; dir = " ";
            }
            std::cout << "} does not exist\n";
        }
        return true;
    }
    return false;
}

bool check_for_labal(std::vector<std::string> tokens, int address)
{
    if(tokens[0][tokens[0].size()-1] == ':')
    {
        memory.push_label(tokens[0], address);
        return true;
    }
    return false;
}

int main()
{
    std::string user_input;
    std::string seperators = " \t,$()";
    Token tok("", seperators);
    
    bool running = true;
    reg.pc() = 4194304;
    while(running)
    {
        switch (mode)
        { 
            case 0: //text mode
            {
                std::cout << "TEXT: " << to_hex(reg.pc()) << "> "; 
                getline(std::cin, user_input);
                if(user_input == "")
                    continue;
                tok.push_back(user_input);
                
                if(check_at_functions(tok.tokens()))
                {
                    tok.clear();
                    continue;
                }
                
                if(check_for_labal(tok.tokens(), reg.pc()))
                {
                    tok.pop_front();
                }

                if(tok.size() == 0)
                {
                    continue;
                }
                
                machine.get_machine_code(tok.tokens(), memory);
                reg.update(machine, memory);
                
                if(reg_print)
                {
                    std::cout << "\nreg_print = true";
                    reg.print();
                }
                tok.clear();
                reg.pc() += 4;
                // printbits(mcode);
            } break;
            case 1: //data mode
            {
                std::cout << "Data: " << to_hex(memory.data_it()) << "> "; 
                getline(std::cin, user_input);
                if(user_input == "")
                    continue;
                tok.push_back(user_input);

                if(check_at_functions(tok.tokens()))
                {
                    tok.clear();
                    continue;
                }

                if(check_for_labal(tok.tokens(), memory.data_it()))
                {
                    tok.pop_front();
                }

                if(tok.size() == 0)
                {
                    continue;
                }
                memory.push_data(tok.tokens());
                tok.clear();
            }break;
            case 2: //labels mode
            {
                getline(std::cin, user_input);
                if(user_input == "")
                    continue;
                tok.push_back(user_input);

                if(check_at_functions(tok.tokens()))
                {
                    tok.clear();
                    continue;
                }

                if(tok.size() == 0)
                {
                    continue;
                }

            }break;
            default:
            {
                std::cout << "!!!error mode is not in valid state !!\n";
            }break;
        }
    }
    return 0;
}