
#ifndef PAYMENT_SYSTEM_WRONGCHOICE_H
#define PAYMENT_SYSTEM_WRONGCHOICE_H
#include <iostream>

class WrongChoice: public std::exception{
public:
    WrongChoice() = default;
    ~WrongChoice() = default;
    const char *what() const noexcept override{
        return "Wrong password!!!";
    };
};
#endif //PAYMENT_SYSTEM_WRONGCHOICE_H
