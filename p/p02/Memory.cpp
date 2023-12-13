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
            if(i % 2 == 0 && i != 0)
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
            if(i %2 == 0 && i != 0)
                ret += ' ';
            ret += stack_temp.top();
            stack_temp.pop();
        }
        else
        {
            if(i %2 == 0 && i != 0)
                ret += ' ';
            ret += '0';
        }
        i--;
    }
    return ret;
}

//NEED TO WORK ON
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
    std::string temp = addr_to_hex(value, 8);
    while(!temp.empty())
    {
        std::string sub_temp = temp.substr(0, 2);
        temp.erase(0, 2);
        std::cout << ' ' << (char)stoi(sub_temp, 0 , 16);
    }
    std::string ret;
    return ret;
}

std::string string_to_hex(std::string value)
{
    std::string ret;
    for(int i = 0; i < value.size(); ++i)
    {
        uint32_t temp = value[i];
        ret += addr_to_hex(temp, 2);
    }
    return ret;
}

uint32_t Memory::get_address(std::string key)
{
    std::map<std::string, unsigned int>::iterator it_lable;
    it_lable = lables_.find(key);
    if(it_lable != lables_.end())
        return it_lable->second;

    std::cout << "!!! Error Address does not exits !!!\n";
    return 0; 
}

void Memory::push_label(std::string key, uint32_t address)
{
    key.pop_back();
    std::cout << "pushing " << key << " 0x" << addr_to_hex(address, 8) << " to lables map\n";
    lables_.insert({key, address});
}

void Memory::push_data(std::vector<std::string> & tokens)
{
    if(tokens[0] == ".asciiz")
    {
        std::string data_value_char;
        while(!tokens[1].empty())
        {
            if (tokens[1].size() >= 4)
            {
                data_value_char = tokens[1].substr(0, 4);
                tokens[1].erase(0, 4);
            }
            else
            {
                data_value_char = tokens[1].substr(*tokens[1].begin() - tokens[1][0]);
                tokens[1].erase();
            }

            std::string value = string_to_hex(data_value_char);
            // std::cout << "hex code is " << value << std::endl;
            std::vector<unsigned int> segment = {data_it_, (unsigned)stoi(value, 0, 16)};
            data_.push_back(segment);
            data_it_ += 4;
        }   
    }
}

void Memory::push_stack(std::vector<std::string> & tokens)
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
       std::cout << " "      << std::setw(12) << std::right << data_[i][0]  
                 << "|     " << std::setw(8) << std::right << addr_to_hex(data_[i][0], 8)
                 << "|  "    << std::setw(11) << std::right << data_[i][1]
                 << "| "    << std::setw(11) << std::right << word_to_hex(data_[i][1], 8)
                 << "|  "    << std::setw(2) << std::right << word_to_char(data_[i][1], 7)
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

void Memory::print_label()
{
    uint32_t temp = sp_;
    std::cout << "\n=====================================================================\n"
          << "Labels\n"
          << "=====================================================================\n";
    for(auto it = lables_.begin(); it != lables_.end(); it++)
    {
       std::cout << "   " << std::setw(9) << std::right <<(it->second)
                 << "|  " << std::setw(8) << std::right << (it ->first)
                 << std::endl;
    }
    std::cout << std::endl <<std::endl;
}