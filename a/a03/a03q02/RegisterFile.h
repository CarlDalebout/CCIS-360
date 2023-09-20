// File : RegisterFile.h
// Author: smaug

#ifndef REGISTER_FILE
#define REGISTER_FILE

class RegisterFile
{
public:
    int32_t operator[](int i) const;
    int32_t & operator[](int i);
private:
    int32_t x_[32];
};

#endif
