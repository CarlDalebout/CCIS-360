#include "Memory.h"

std::string  addr_to_hex(uint32_t value, int spaces)
{
    if(value == 0)
    {   
        std::string ret = "";
        for (int i = 0; i < spaces; ++i)
        {
            ret += '0';
        }
        return ret;
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
    
    int i = spaces;
    while(i != 0)
    {
        if(i <= stack_temp.size())
        {
            // std::cout << "pushing " << stack_temp.top() << "to ret: " << ret << std::endl;
            ret += stack_temp.top();
            stack_temp.pop();
        }
        else
        {
            ret += '0';
        }
        i--;
    }
    return ret;
}

std::string  word_to_hex(uint32_t value, int spaces)
{
    if(value == 0)
    {   
        std::string ret = "";
        for (int i = 0; i < spaces; ++i)
        {
            if(i %3 == 0 && i != 0)
                ret += ' ';
            ret += '0';
        }
        return ret;
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
    }
    std::string ret;

    int i = spaces;
    while(i != 0)
    {
        if(i <= stack_temp.size())
        {
            // std::cout << "pushing " << stack_temp.top() << "to ret: " << ret << std::endl;
            if(i %3 == 0 && i != 0)
                ret += ' ';
            ret += stack_temp.top();
            stack_temp.pop();
        }
        else
        {
            if(i %3 == 0 && i != 0)
                ret += ' ';
            ret += '0';
        }
        i--;
    }
    return ret;
}

std::string word_to_char(uint32_t value, int spaces)
{
    if(value == 0)
    {   
        std::string ret = "";
        for (int i = 0; i < spaces; ++i)
        {
            if(i % 2 == 0 && i != 0)
                ret += ' ';
            ret += (char)0;
        }
        return ret;
    }
    std::string ret;
    return ret;
}

void Memory::push_label(std::string key, uint32_t pc)
{
    std::cout << "pushing " << key << ' ' << pc << " to lables map\n";
    lables_.insert({key, pc});
}


void Memory::push_data(std::string tokens)
{

}

void Memory::print_data()
{
    std::cout << "\n=====================================================================\n"
            << "DATA SEGMENT\n"
            << "=====================================================================\n"
            << "  addr  (int)|  addr  (hex)| value  (int)| value  (hex)| value (char)\n"
            << "-------------+-------------+-------------+-------------+-------------\n";
    for(int i = 0; i < data_.size(); ++i)
    {
       std::cout << "  "    << data_[i][0]  
                 << "|    " << addr_to_hex(data_[i][0], 8)
                 << "|  "   << data_[i][1]
                 << "|  "   << word_to_hex(data_[i][1], 8)
                 << "|  "   << word_to_char(data_[i][1], 7)
                 << std::endl;
    }
    std::cout << std::endl <<std::endl;
}   

void Memory::print_stack()
{
    uint32_t temp = sp_;
    std::cout << "\n=====================================================================\n"
          << "STACK SEGMENT\n"
          << "=====================================================================\n"
          << "  addr  (int)|  addr  (hex)| value  (int)| value  (hex)| value (char)\n"
          << "-------------+-------------+-------------+-------------+-------------\n";
    for(int i = stack_.size(); i >= 0; --i, temp -= 4)
    {
       std::cout << " "     << temp  
                 << "|    "  << addr_to_hex(temp, 8)
                 << "|  "   << data_[i][1]
                 << "|  "   << word_to_hex(stack_[i], 8)
                 << "|  "   << word_to_char(stack_[i], 7)
                 << std::endl;
    }
    std::cout << std::endl <<std::endl;
}