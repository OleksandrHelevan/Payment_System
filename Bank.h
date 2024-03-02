
#ifndef PAYMENT_SYSTEM_BANK_H
#define PAYMENT_SYSTEM_BANK_H

#include <iostream>
using namespace std;

class Bank {
    string nameofBank;
    double tax;
    string city;

public:
    void getBank();
    Bank();
    Bank(string name);
    Bank(string name, double newTax);
    Bank(string name, double newTax, string newCity);
    ~Bank();
};


#endif //PAYMENT_SYSTEM_BANK_H
