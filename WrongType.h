
#ifndef PAYMENT_SYSTEM_WRONGTYPE_H
#define PAYMENT_SYSTEM_WRONGTYPE_H
#include <iostream>
class WrongType: public std::exception{
public:
    WrongType() = default;
    ~WrongType() = default;

    const char *what() const noexcept override{
        return "Wrong type of data!!!";
    };
};

#endif //PAYMENT_SYSTEM_WRONGTYPE_H
