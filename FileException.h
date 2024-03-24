
#ifndef PAYMENT_SYSTEM_FILEEXCEPTION_H
#define PAYMENT_SYSTEM_FILEEXCEPTION_H
#include <iostream>

class FileExcaption :public std::exception{
public:
    FileExcaption() = default;
    ~FileExcaption() = default;
    const char *what() const noexcept override{
        return "Problems with file)))";
    };
};
#endif //PAYMENT_SYSTEM_FILEEXCEPTION_H
