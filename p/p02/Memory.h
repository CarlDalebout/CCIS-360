#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <stack>

class Memory
{
public:
    Memory()
    :sp_(2147481752), data_it_(268435456)
    {}

/*==========================================================================================
Functions
==========================================================================================*/
    uint32_t get_address(std::string);
    
    void  push_data(std::vector<std::string> &);
    void push_label(std::string, uint32_t);
    void push_stack(std::vector<std::string> &);
    
    void  print_data();
    void print_label();
    void print_stack();
    
/*==========================================================================================
Sets and Gets
==========================================================================================*/
    uint32_t            & sp()       {return sp_;}
    uint32_t              sp() const {return sp_;}
    std::vector<int> & stack()       {return stack_;} 
    std::vector<int>   stack() const {return stack_;} 

    uint32_t                        & data_it()       {return data_it_;}
    uint32_t                          data_it() const {return data_it_;}
    std::vector<std::vector<unsigned int>>              & data()       {return data_;}
    std::vector<std::vector<unsigned int>>                data() const {return data_;}

    std::map<std::string, unsigned int> & map()       {return lables_;}
    std::map<std::string, unsigned int>   map() const {return lables_;}


private:
    uint32_t sp_ ;
    std::vector<int> stack_;
    
    uint32_t data_it_;
    std::vector<std::vector<unsigned int>> data_;

    std::map<std::string, unsigned int> lables_;

};


#endif