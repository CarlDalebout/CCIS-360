#include <iostream>
#include <iomanip>
#include "Register.h"

std::string to_hex(int value, int spaces)
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

std::string to_reg(int value)
{
    switch (value)
    {
        case 0:
            return "r0";
            break;
        case 1:
            return "at";
            break;
        case 2:
            return "v0";
            break;
        case 3:
            return "v1";
            break;
        case 4:
            return "a0";
            break;
        case 5:
            return "a1";
            break;
        case 6:
            return "a2";
            break;
        case 7:
            return "a3";
            break;
        case 8:
            return "t0";
            break;
        case 9:
            return "t1";
            break;
        case 10:
            return "t2";
            break;
        case 11:
            return "t3";
            break;
        case 12:
            return "t4";
            break;
        case 13:
            return "t5";
            break;
        case 14:
            return "t6";
            break;
        case 15:
            return "t7";
            break;
        case 16:
            return "s0";
            break;
        case 17:
            return "s1";
            break;
        case 18:
            return "s2";
            break;
        case 19:
            return "s3";
            break;
        case 20:
            return "s4";
            break;
        case 21:
            return "s5";
            break;
        case 22:
            return "s6";
            break;
        case 23:
            return "s7";
            break;
        case 24:
            return "t8";
            break;
        case 25:
            return "t9";
            break;
        case 26:
            return "k0";
            break;
        case 27:
            return "k1";
            break;
        case 28:
            return "gp";
            break;
        case 29:
            return "sp";
            break;
        case 30:
            return "s8";
            break;
        case 31:
            return "ra";
            break;    
        default:
            break;
    }
    return "error";
}

uint32_t & Register::operator[](int index)
{
    if(index >= 32)
    {
        std::cout << "!!! ERROR index out of bound, exiting!!!\n";
        exit(0);
    }
    return registers_[index];
}

void Register::update(Machine & machine)
{
    switch (machine.opcode())
    {
        case  0:
        {
            switch (machine.funct())
            {   
                case  0:
                {
                    //sll
                    registers_[machine.rd()] = registers_[machine.rt()] << machine.shamt();
                }break;
                case  2:
                {
                    //srl
                    registers_[machine.rd()] = registers_[machine.rt()] >> machine.shamt();
                }break;
                case  3:
                {
                    //sra
                    registers_[machine.rd()] = registers_[machine.rt()] >> machine.shamt();
                }break;
                case  4:
                {
                    //sllv
                    registers_[machine.rd()] = registers_[machine.rt()] << registers_[machine.rs()];
                }break;
                case  6:
                {
                    //srlv
                    registers_[machine.rd()] = registers_[machine.rt()] >> registers_[machine.rs()];
                }break;
                case  7:
                {
                    //srav
                    registers_[machine.rd()] = registers_[machine.rt()] >> registers_[machine.rs()];
                }break;
                case  8:
                {
                    //jr
                    pc_ = registers_[machine.rs()];
                }break;
                case  9:
                {
                    //jalr
                    registers_[machine.rd()] = registers_[31];
                    pc_ = registers_[machine.rs()];
                }break;
                case 10:
                {
                    //movz
                    if (registers_[machine.rt()] == 0) 
                        registers_[machine.rd()] = registers_[machine.rs()];
                }break;
                case 11:
                {
                    //movn
                    if (registers_[machine.rt()] != 0) 
                        registers_[machine.rd()] = registers_[machine.rs()];
                }break;
                case 12:
                {
                    //syscall
                
                }break;
                case 13:
                {
                    //break
                }break;
                case 15:
                {
                    //sync
                }break;
                case 16:
                {
                    //mfhi
                    registers_[machine.rd()] = hi_;
                }break;
                case 18:
                {
                    //mflo
                    registers_[machine.rd()] = lo_;
                }break;
                case 24:
                {   
                    //mult
                    u_int64_t temp = registers_[machine.rs()] * registers_[machine.rt()];
                    hi_ = temp >> 32;
                    lo_ = temp & 0xFFFFFFFF;
                }break;
                case 25:
                {
                    //multu
                    u_int64_t temp = registers_[machine.rs()] * registers_[machine.rt()];
                    hi_ = temp >> 32;
                    lo_ = temp & 0xFFFFFFFF;
                }break;
                case 26:
                {
                    //div
                    hi_ = registers_[machine.rs()] % registers_[machine.rt()];
                    lo_ = registers_[machine.rs()] / registers_[machine.rt()]; 
                }break;
                case 27:
                {
                    //divu
                    hi_ = registers_[machine.rs()] % registers_[machine.rt()];
                    lo_ = registers_[machine.rs()] / registers_[machine.rt()]; 
                }break;
                case 32:
                {
                    //add or move
                    registers_[machine.rd()] = registers_[machine.rs()] + registers_[machine.rt()];
                }break;
                case 33:
                {
                    //addu
                    registers_[machine.rd()] = registers_[machine.rs()] + registers_[machine.rt()];
                }break;
                case 34:
                {
                    //sub
                    registers_[machine.rd()] = registers_[machine.rs()] - registers_[machine.rt()];
                }break;
                case 35:
                {
                    //subu
                    registers_[machine.rd()] = registers_[machine.rs()] - registers_[machine.rt()];
                }break;
                case 36:
                {
                    //and
                    registers_[machine.rd()] = registers_[machine.rs()] & registers_[machine.rt()];
                }break;
                case 37:
                {
                    //or
                    registers_[machine.rd()] = registers_[machine.rs()] | registers_[machine.rt()];
                }break;
                case 38:
                {
                    //xor
                    registers_[machine.rd()] = registers_[machine.rs()] ^ registers_[machine.rt()];
                }break;
                case 39:
                {
                    //nor
                    registers_[machine.rd()] = !(registers_[machine.rs()] | registers_[machine.rt()]);
                }break;
                case 42:
                {
                    //slt
                    registers_[machine.rd()] = (registers_[machine.rs()] < registers_[machine.rt()]) ? 1 : 0; 
                }break;
                case 43:
                {
                    //sltu
                    registers_[machine.rd()] = (registers_[machine.rs()] < registers_[machine.rt()]) ? 1 : 0; 
                }break;
                case 48:
                {
                    //tge
                    registers_[machine.rd()] = (registers_[machine.rs()] > registers_[machine.rt()]) ? 1 : 0; 
                }break;
                case 49:
                {
                    //tgeu
                    registers_[machine.rd()] = (registers_[machine.rs()] > registers_[machine.rt()]) ? 1 : 0; 
                }break;
                case 50:
                {
                    //tlt
                    if(registers_[machine.rs()] < registers_[machine.rt()]) 
                        std::cout << "stop its a trap\n";
                }break;
                case 51:
                {
                    //tltu
                    if(registers_[machine.rs()] < registers_[machine.rt()]) 
                        std::cout << "stop its a trap\n";
                }break;
                case 52:
                {
                    //teq
                    if(registers_[machine.rs()] == registers_[machine.rt()]) 
                        std::cout << "stop its a trap\n";
                }break;
                case 54:
                {
                    //tne
                    if(registers_[machine.rs()] != registers_[machine.rt()]) 
                        std::cout << "stop its a trap\n";
                }break;
                default:
                {
                    std::cout << "function does not exist\n";
                }break;
            }
        }break;
        case  1:
        {
            //li
            registers_[machine.rt()] = machine.immedite();
        }break;
        case  2:
        {
            //j
            pc_ = machine.immedite();
        }break;
        case  3:
        {
            //jal
            registers_[31] = pc_ + 8; 
            pc_ = machine.immedite();
        }break;
        case  4:
        {
            //beq
            if(registers_[machine.rs()] == registers_[machine.rt()])
                pc_ = pc_ + 4 + machine.immedite();            
        }break;
        case  5:
        {
            //bne
            if(registers_[machine.rs()] != registers_[machine.rt()])
                pc_ = pc_ + 4 + machine.immedite();            

        }break;
        case  6:
        {
            //blez
            if(registers_[machine.rs()] <= 0)
                pc_ = pc_ + 4 + machine.immedite();            
        }break;
        case  7:
        {
            //bgtz
            if(registers_[machine.rs()] > 0)
                pc_ = pc_ + 4 + machine.immedite();            
        }break;
        case  8:
        {
            //addi
            //  R[rt] = R[rs] + SignExtImm
            registers_[machine.rt()] = registers_[machine.rs()] + machine.immedite();
        }break;
        case  9:
        {
            //addiu
            //  R[rt] = R[rs] + SignExtImm
            registers_[machine.rt()] = registers_[machine.rs()] + machine.immedite();
        }break;
        case 10:
        {
            //slti
            registers_[machine.rt()] = (registers_[machine.rs()] < machine.immedite()) ? 1 : 0;
        }break;
        case 11:
        {
            //sltiu
            registers_[machine.rt()] = (registers_[machine.rs()] < machine.immedite()) ? 1 : 0;
        }break;
        case 12:
        {
            //andi
            registers_[machine.rt()] = registers_[machine.rs()] & machine.immedite();
        }break;
        case 13:
        {
            //ori
            registers_[machine.rt()] = registers_[machine.rs()] | machine.immedite();
        }break;
        case 14:
        {
            //xori
            registers_[machine.rt()] = registers_[machine.rs()] ^ machine.immedite();
        }break;
        case 15:
        {
            //lui
            registers_[machine.rt()] = machine.immedite();
        }break;
        case 32:
        {
            //lb
            // rt ← memory[base+offset]
        }break;
        case 33:
        {
            //lh
            // rt ← memory[base+offset]
        }break;
        case 34:
        {
            //lwl
            // rt ← rt MERGE memory[base+offset]
        }break;
        case 35:
        {
            //lw
            // rt ← memory[base+offset]
        }break;
        case 36:
        {
            //lbu
            // rt ← memory[base+offset]
        }break;
        case 37:
        {
            //lhu
            // rt ← memory[base+offset
        }break;
        case 38:
        {
            //lwr
            // rt ← rt MERGE memory[base+offset]
        }break;
        case 40:
        {
            //sb
            // memory[base+offset] ← rt
        }break;
        case 41:
        {
            //sh
            // memory[base+offset] ← rt
        }break;
        case 42:
        {
            //swl
            // rt MERGE memory[base+offset] ← rt 
        }break;
        case 43:
        {
            //sw
            // memory[R[rs]+SignExtImm] = R[rt]
        }break;
        case 46:
        {
            //swr
            // rt MERGE memory[base+offset] ← rt 
        }break;
        case 47:
        {
            //cache
        }break;
        case 48:
        {
            //ll
            // rt ← memory[base+offset]
        }break;
        case 49:
        {
            //lwc1
            // ft ← memory[base+offset]
        }break;
        case 50:
        {
            //lwc2
        }break;
        case 51:
        {
            //pref
        }break;
        case 53:
        {
            //ldc1
        }break;
        case 54:
        {
            //ldc2
        }break;
        case 56:
        {
            //sc
        }break;
        case 57:
        {
            //swc1
        }break;
        case 58:
        {
            //swc2
        }break;
        case 61:
        {
            //sdc1
        }break;
        case 62:
        {
            //sdc2
        }break;
        default:
        {
            std::cout << "operation does not exist\n";
        }break;
    }
    if(machine.opcode() == 0)
    {
        if(machine.funct() == 32)
        {
            registers_[machine.rd()] = registers_[machine.rs()] + registers_[machine.rt()];
        }
    }
}

void Register::print()
{   
    std::cout << "\n=================================================================\n";
    std::cout << "PC:\t"   << to_hex(pc_, 8) 
              << "\tHI:\t" << to_hex(hi_, 8)
              << "\tLO:\t" << to_hex(lo_, 8) << '\n';
    std::cout << "=================================================================\n";
    std::cout << "General Registers\n";
    std::cout << "=================================================================";
    std::string dir = "";
    for(int i = 0; i < 32; ++i)
    {
        if( i % 4 == 0 )
        {
            std::cout << '\n';
            dir = "";
        }
        std::cout << dir << 'R' << std::setw(2) << std::left << i << '\t'
                  << '(' << to_reg(i) << ") = " << to_hex(registers_[i], 8);
        dir = "  ";
    }
    std::cout << std::endl <<std::endl;
}