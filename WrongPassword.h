

#ifndef PAYMENT_SYSTEM_WRONGPASSWORD_H
#define PAYMENT_SYSTEM_WRONGPASSWORD_H
#include <iostream>

class WrongPassword: public std::exception{
public:
    WrongPassword() = default;
    ~WrongPassword() = default;
    const char *what() const noexcept override{
        return "Wrong password!!!";
    };
};
#endif //PAYMENT_SYSTEM_WRONGPASSWORD_H
