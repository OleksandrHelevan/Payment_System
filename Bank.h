
#ifndef PAYMENT_SYSTEM_BANK_H
#define PAYMENT_SYSTEM_BANK_H

#include <iostream>
using namespace std;

class Bank {
    string nameofBank;
    float tax;
    string city;

public:
    void getBank();
    Bank();
    Bank(string name);
    Bank(string name, float newTax);
    Bank(string name, float newTax, string newCity);
    ~Bank();
};


#endif //PAYMENT_SYSTEM_BANK_H
