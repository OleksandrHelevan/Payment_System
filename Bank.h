
#ifndef PAYMENT_SYSTEM_BANK_H
#define PAYMENT_SYSTEM_BANK_H

#include <iostream>
using namespace std;

class Bank {
    string nameofBank;
    double tax;
    string city;

public:
    Bank();
    Bank(string name);
    Bank(string name, double newTax);
    Bank(string name, double newTax, string newCity);
    ~Bank(){};
    void getBank();
    friend ostream &operator<<(ostream &os, const Bank &obj);
};


#endif //PAYMENT_SYSTEM_BANK_H
