#ifndef _USER_EXCEPTION_HPP_
#define _USER_EXCEPTION_HPP_

#include <iostream>
using namespace std;

class UserException : exception
{
    string message;
    static constexpr const char *message_def = "Undefined Exception";
public:
    UserException(string message_val = message_def) : message{message_val} {};
    virtual const char *what() const noexcept override 
    {
        return message.c_str();
    }
};

#endif /* _USER_EXCEPTION_HPP_ */